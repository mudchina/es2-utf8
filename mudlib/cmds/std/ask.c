// ask.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *msg_dunno = ({
  "$n摇摇头，说道：没听说过。\n",
  "$n睁大眼睛望著$N，显然不知道$P在说什麽。\n",
  "$n耸了耸肩，很抱歉地说：无可奉告。\n",
  "$n说道：嗯....这我可不清楚，你最好问问别人吧。\n",
  "$n想了一会儿，说道：对不起，你问的事我实在没有印象。\n"
});

int main(object me, string arg)
{
  string dest, topic, msg, att, *id;
  object ob;
  mapping inq;
  int i;

  seteuid(getuid());

  if( !arg )
      return notify_fail("你要问谁什麽事？\n");

  if( sscanf(arg, "%s about %s", dest, topic)==2 )
    ;
  else if( sscanf(arg, "%s", dest)==1 ) {
    topic = "";
  } else
      return notify_fail("你要问谁什麽事？\n");

  if( !objectp(ob = present(dest, environment(me))) )
      return notify_fail("这里没有这个人。\n");

  if( !ob->is_character() ) {
      message_vision("$N对著$n自言自语....\n", me, ob);
      return 1;
  }

  if(topic == "") {
    if( mapp(inq = ob->query("inquiry")) ) {
      id = keys(inq);
      msg = "你可以打听这些事情：\n";
      msg += sprintf("※『这里』\n※『名字』\n※『传闻』\n" );
      for(i=0; i<sizeof(id); i++) {
        msg += sprintf("※『%s』\n", id[i] );
      }
      write(msg);
      return 1;
    } else {
      topic = "询问";
    }
  }

  if( !ob->query("can_speak") ) {
    message_vision("$N向$n打听有关『" + topic + "』的消息，但是$p显然听不懂人话。\n", me, ob);
    return 1;
  }

  if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
    message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);

  if( userp(ob) ) return 1;
  if( !living(ob) ) {
    message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n", me, ob);
    return 1;
  }

  if( msg = ob->query("inquiry/" + topic) ) {
    if( stringp(msg) ) {
        message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
        return 1;
    } else if( arrayp(msg) ) {
      for(i=0; i<sizeof(msg); i++) {
        if(stringp(msg[i])) {
          message_vision( CYN "$N说道：" + msg[i] + "\n" NOR, ob);
        } else if(functionp(msg[i])) {
        }
      }
    }
  } else if ( ob->query("name") == topic || topic == "name" || topic == "名字" ) {
      att = ob->query("attitude");
      switch (att)
      {
      case "aggressive":
      case "killer":
          message_vision(YEL"$N对$n把眼一瞪："+RANK_D->query_self_rude(ob)
              +"的名字是可以随便提的吗？！我看你这"+RANK_D->query_rude(me)
              +"是活腻了！\n"NOR, ob, me);
          break;	
      case "heroism":
          message_vision(CYN"$N对$n哈哈一笑："+ob->query("name")+"便是"
              +RANK_D->query_self_rude(ob)+"！\n"NOR, ob, me);
          break;
      case "peaceful":
      case "friendly":
      default:
          message_vision(CYN"$N对$n作了一揖：这位"+RANK_D->query_respect(me)
              +"可真会开玩笑，怎么会突然问起"+RANK_D->query_self(ob)
              +"的名字？\n"NOR, ob, me);
          EMOTE_D->do_emote(ob, "sigh", ob->query("id"), 0);
          break;
      }	

      return 1;

  } else {
    switch(topic)
    {
    case "here":
    case "这里":
      message_vision(CYN "$n对$N说道：这里是" + environment(ob)->query("short") + "，至于其它的，" + RANK_D->query_self(ob) + "不便多说。\n" NOR, me, ob);
      break;
    default:
      message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
    }
  }

  return 1;
}

int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>

这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
HELP
   );
   return 1;
}
