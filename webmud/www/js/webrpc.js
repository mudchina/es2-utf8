'use strict';

(function(){

function WebRPCServer(io) {
  if(this && (this instanceof WebRPCServer)) {
    this.reset();
    if(io) this.bind(io);
  } else {
    return new WebRPCServer(io);
  }
};

WebRPCServer.prototype = {
  reset: function() {
    this.io = null;
    this.rpcs = {};
    this.logTraffic = false;

    this.isRunning = false;
    this.timer = 0;
    this.lastTick = 0;

    this.sockets = {};  // sid -> socket
    this.socketsCount = 0;
  },

  showTraffic: function(y) {
    this.logTraffic = y;
  },

  // func(req, reply(err, ret));
  on: function(key, func) {
    if(typeof func === 'function') {
      var fList = this.rpcs[key];
      if(!fList) fList = this.rpcs[key] = [];
      fList.push(func);
    }
  },

  off: function(key, func) {
    if(key in this.rpcs) {
      var fList = this.rpcs[key];
      for(var i=fList.length-1; i>=0; i--) {
        if(fList[i] === func) fList.slice(i,1);
      }
      if(fList.length === 0) delete this.rpcs[key];
    }
  },

  bind: function(io) {
    if(this.isRunning) throw new Error('WebRPCServer is already running.');

    var server = this;
    server.io = io;

    io.on('connection', function(webSock){
      if(server.logTraffic) console.log('rpc client connected, socket id: ' + webSock.id);
      server.onConnected(webSock);
    });

    server.lastTick = Date.now();
    server.isRunning = true;

    // init tick() timer
    server.tick();
    server.timer = setInterval(function(){
      server.tick();
    }, 1000);
    
    return this;
  },

  shutdown: function() {
    if(!this.isRunning) return;

    // clear tick() timer
    if(this.timer) clearInterval(this.timer);

    this.reset();

    return this;
  },

  tick: function() {
    var server = this;
    server.lastTick = Date.now();
  },

  onDisconnected: function(webSock) {
    var server = this;

    delete server.sockets[ webSock.id ];
    server.socketsCount --;
  },

  onConnected: function(webSock) {
    var server = this;

    webSock.on('disconnect', function(){
      if(server.logTraffic) console.log('rpc client disconnected, socket id: ' + webSock.id);
      server.onDisconnected(webSock);
    });

    // implement the rpc interface, so we can reuse webclient.js
    /* {
      uid, // optional
      pin, // optional
      seq: seq,
      f: method,
      args: args,
    } */
    webSock.on('rpc', function(req){
      var callbacks = server.rpcs[req.f];
      if(callbacks && callbacks.length > 0) {
        var reply = function(err, ret) {
          webSock.emit('reply', {
            seq: req.seq,
            err: err,
            ret: ret,
          });
        };
        for(var i=callbacks.length-1; i>=0; i--) {
          var func = callbacks[i];
          if(typeof func === 'function') func(req.args, reply);
        }
      } else {
        if(server.logTraffic) console.log('rpc unhandled: ', req.f);
      }
    });

    server.sockets[webSock.id] = webSock;
    server.socketsCount ++;
  },
};

function WebRPCClient() {
  if(this && (this instanceof WebRPCClient)) {
    this.reset();
  } else {
    return new WebRPCClient();
  }
};

WebRPCClient.prototype = {
  reset: function() {
    this.sock = null;
    this.uid = '';
    this.pin = '';
    this.rpc_seq = 1;
    this.rpc_callbacks = {};
    this.events = {};
    this.logTraffic = false;
  },

  showTraffic: function(y) {
    this.logTraffic = y;
    if(this.sock) this.sock.logTraffic = y;
  },

  on: function(event, func) {
    var callbacks = this.events[event];
    if(!callbacks) callbacks = this.events[event] = [];
    callbacks.push(func);
    return this;
  },

  off: function(event, func) {
    if(func) {
      var callbacks = this.events[event];
      if(!callbacks) return;
      var index = -1;
      while((index = callbacks.indexOf(func)) >= 0) {
        callbacks.splice(index, 1);
      }
    } else {
      this.events[event] = [];
    }
    return this;
  },

  fireEvent: function(event, args) {
    var callbacks = this.events[event];
    if(!callbacks || !Array.isArray(callbacks)) return;
    callbacks.forEach(function(func){
      if(typeof func === 'function') func(event, args);
    });
  },

  callback: function(seq, msg) {
    if(this.sock.logTraffic) console.log(seq, msg);
    var item = this.rpc_callbacks[seq];
    if(item) {
      delete this.rpc_callbacks[seq];
      var func = item.func;
      if(typeof func === 'function') func(msg.err, msg.ret);
    }
  },

  bind: function(sock) {
    var client = this;
    this.sock = sock;
    if(this.logTraffic) sock.logTraffic = this.logTraffic;

    sock.on('hello', function(msg){
      if(sock.logTraffic) console.log('hello', msg);
      if(!msg || (typeof msg!=='object')) return;
      client.fireEvent('hello', msg);
    });

    sock.on('notify', function(msg){
      if(sock.logTraffic) console.log('notify', msg);
      if(!msg || (typeof msg!=='object') || !msg.e) return;
      client.fireEvent(msg.e, msg.args);
    });

    sock.on('reply', function(msg){
      if(sock.logTraffic) console.log('reply', msg);
      if(!msg || (typeof msg!=='object') || !msg.seq) return;
      client.callback(msg.seq, msg);
    });
  },

/*
 * accepted methods and args:
 *
 * fastsignup, 0
 * signup, {uid, passwd, name, email, phone, uuid}
 * login, {uid, passwd}
 * logout, 0
 */

  rpc: function(method, args, reply) {
    if(!reply) {
      reply = function dummy(err, ret){};
    } else if(typeof reply !== 'function') {
      throw new Error('rpc: callback func(err, ret) required');
    }

    var client = this;
    var callback_func = reply;
    switch(method) {
    case 'login':
      callback_func = function(err, ret) {
        if(!err) {
          client.uid = ret.token.uid;
          client.pin = ret.token.pin;
        }
        reply(err, ret);
      };
      break;
    case 'fastsignup':
    case 'signup':
    default:
      break;
    }

    var seq = this.rpc_seq++;

    this.rpc_callbacks[seq] = {
      seq: seq,
      func: callback_func,
      t: Date.now(),
    };

    var req = {
      seq: seq,
      f: method,
      args: args,
    };
    if(client.uid) req.uid = client.uid;
    if(client.pin) req.pin = client.pin;

    if(this.sock.logTraffic) console.log('rpc', req);
    this.sock.emit('rpc', req);
    return this;
  },
};

if(typeof window === 'object') {
  window.WebRPCClient = WebRPCClient;
} else {
  exports = module.exports = {
    Server: WebRPCServer,
    Client: WebRPCClient,
  };
}

})();
