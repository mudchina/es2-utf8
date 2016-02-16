#include <room.h>

inherit ROOM;

void create()
{
        set("short", "北驿道");
        set("long", @LONG
你正走在一条青石铺地的大驿道上，四周人来人往。挑担子的
苦力，赶着大车的马夫，赴京传书的军人，熙熙攘攘，非常热闹。
不时还有两三骑快马从身边飞驰而过，引起一阵骚动。道路两旁各
有一片小树林，南边就是京师。
LONG
        );

        set("exits", ([
                "north"          : "/d/city/nroad2",
                "enter"          : "/d/city/northdoor" ]) );

        set("outdoors", "city"); 
        create_door("enter", "城门", "out" );
        setup();
        replace_program(ROOM); 
}
void init()
{
	add_action("do_yell","yell");
}
void do_yell()
{
	if(!query("exit/up")) 
	   set("exits/up",__DIR__"room");
}
