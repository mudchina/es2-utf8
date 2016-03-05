(function(){

function Client() {
  this.reset();
};

Client.prototype = {
  reset: function() {
    this.uid = '';
    this.pin = '';
    this.rpc_seq = 1;
    this.rpc_callbacks = {};
    this.events = {};
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

  bind: function(sock, debugMode) {
    var client = this;
    this.sock = sock;
    if(debugMode) sock.log_traffic = true;

    sock.on('hello', function(msg){
      if(sock.log_traffic) console.log('hello', msg);
      if(!msg || (typeof msg!=='object')) return;
      client.fireEvent('hello', msg);
    });

    sock.on('notify', function(msg){
      if(sock.log_traffic) console.log('notify', msg);
      if(!msg || (typeof msg!=='object') || !msg.e) return;
      client.fireEvent(msg.e, msg.args);
    });

    sock.on('reply', function(msg){
      if(sock.log_traffic) console.log('reply', msg);
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
    if(typeof reply !== 'function') throw new Error('rpc: callback func(err, ret) required');

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

    if(this.sock.log_traffic) console.log('rpc', req);
    this.sock.emit('rpc', req);
    return this;
  },
};

if(typeof module === 'object' && typeof module.exports === 'object')
  module.exports = Client;

if(window && typeof window === 'object')
  window.WebClient = Client;

})();
