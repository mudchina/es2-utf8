#include <room.h>

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",HIY "密室" NOR);
	set("long", @LONG
这是一间密室。地上铺著可以合地打坐的大理石床。四周挂了一
些兵器，正面墙上写了偌大的 『 舞 』字！ 地板上隐约看到一幅先
天八卦图。中央画著两仪，八个角落分别是：乾坤兑离震巽坎艮、等
卦相。墙上画著几幅玄天玉女翩然起舞的美妙步法。
LONG
	);

    set("exits", ([
        "north" :__DIR__"miroom2",
    ]) );
    set("objects", ([
       __DIR__"obj/hankie" : 1,
     ]) );
	create_door("north","垂花门","south",DOOR_CLOSED);

	setup();
}
void init()
{
         add_action("do_dancing", "dancing");
         add_action("do_get", "get");
}

int do_dancing(string arg)
{
   object me;

   me = this_player();

   if( (string)me->query("gender") == "男性" ) {
   if ( (int)me->query("sen") < 100 )
        return notify_fail("你现在的神太少了，无法专注跳出舞步！\n");
        me->receive_damage("sen",80);
   }
   if( (string)me->query("gender") == "女性" ) {
   if ( (int)me->query("sen") < 50 )
        return notify_fail("你现在的神太少了，无法专注跳出舞步！\n");
        me->receive_damage("sen", 50);
   }
     if ( arg!="out" )
     return notify_fail("你在卦象中跳起舞来。但似乎不得要领！\n" );
     if( arg == "out" )
       message_vision("$N在卦象中跳起舞来..一曲"+HIG"「 西出阳关 」"+
          NOR"突然...\n",
                        this_player() );
         this_player()->move(__DIR__"bamboo");

         return 1;
}
int do_get(string arg)
{
     object me;
     
     me = this_player();

	if (arg !="dance-book")
	return 0;
	else me->receive_damage("sen",50);
	return 0;
}
