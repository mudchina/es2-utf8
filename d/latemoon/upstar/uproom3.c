
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "缀芳阁");
	set("long", @LONG
这是晚月庄让弟子们静修的地方, 名曰「缀芳」。简单的布置加上
一座檀香炉, 你觉得这绝对是一个静修(ponder)的好场所。空气中弥漫
著一股肃穆的气息, 使人很容易进入忘我的境界。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"upstar3",

]));

    set("objects", ([
        __DIR__"npc/huei" : 1,
     "/d/latemoon/obj/cake" : 1,
    ]) );
    create_door("north","木门","south", DOOR_CLOSED);
	setup();
}
void init()
{
       add_action("do_ponder","ponder");
}
int do_ponder(string arg)
{
       object who;

       who = this_player();
       message_vision("$N双手合掌，安静的坐在地上。\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N彷佛变的较为祥合慈善了! \n" , who);
    return 1;
}
