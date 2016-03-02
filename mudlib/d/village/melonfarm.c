// Room: /d/village/melonfarm.c

inherit ROOM;

int do_pick (string arg);

void create()
{
	set("short", "瓜地");
	set("long", @LONG
这是一片很大的西瓜地，沙质的土壤，种出来的瓜肯定是又甜又砂瓤，
熟透了的西瓜(melon)已与瓜蒂脱开，就等人们去摘(pick)呢。不过看瓜农
的篷子就在瓜地的南面，他的警惕性可是很高呀。北面是村里的小路。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"melonguard",
  "northup" : __DIR__"road4",
]));

	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action ("do_pick", "pick");
}

int do_pick (string arg) 
{
 	object ob;
	object room;
	object me;
	object melon;

	me=this_player();

	room = find_object("/d/village/melonguard");
	if (arg == "melon" || arg == "瓜") {
	  if( random(me->query("kar"))>random(30) )
	  {
	    message_vision("$N找来找去，终于找到了一个熟透了的大西瓜抱在怀中。\n",me );
	    melon = new(__DIR__"obj/melon");
	    melon->move(me);
	    if( objectp(room) && objectp(ob=present("meloner",room)))
	    {
	      if( random(me->query("kar"))>random(10) )
	      {
	        message_vision( "糟糕，瓜农发现了$N偷瓜，向这边冲过来！\n", me );
		ob->move(__DIR__"melonfarm");
		ob->set_temp("melon/catch_thief",1);
		me->set_temp("melon/catch_thief",1);
		ob->set_leader(me);
		ob->kill_ob(me);
		//me->kill_ok(ob);
		return 1; 
	      }
	      else {
		message_vision( "瓜农似乎正在打瞌睡，没有发现$N的小动作。\n", me );
		return 1;
	      } 
	    }
	    else{
	      message_vision( "$N真幸运，瓜农没有在瓜棚看瓜。\n", me );
	      return 1; 
	    }
	  }
          else {
	    message_vision( "$N找来找去，终于还是没找到熟透的西瓜。\n", me );
	    return 1;
	  }
	}

	return notify_fail("你要摘什么？\n");

}

int valid_leave(object me,string dir)
{
	if( dir=="northup" || dir=="south" )
	  if( me->query_temp("melon/catch_thief") )
	    return notify_fail( "你的去路被瓜农拦住了。\n" );
	return ::valid_leave(me,dir);
}
