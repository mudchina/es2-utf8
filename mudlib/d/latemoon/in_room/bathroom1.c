#include <room.h>

inherit ROOM;

void create()
{
   set("short", "沐浴更衣室");
	set("long", @LONG
这是一间更衣室，你看到许多柜子，衣架上挂了许多的衣服饰
品。墙上的架上挂了一些丝巾，你可以闻到淡淡的香气围绕四周。
东侧一蓝青洒花软帘，隔帘望去，隐约可看到小花池，一团的雾气
你有点想去冲凉沐浴，让精神好些。当然此处是禁止男性进入!
LONG
	);
    set("objects", ([

     "/d/latemoon/npc/shinyu" : 1 ]) );
	set("exits", ([ /* sizeof() == 2 */
     "west" :__DIR__"flower1",
     "east" :__DIR__"bathroom",

]));

    create_door("west","小帘门","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
