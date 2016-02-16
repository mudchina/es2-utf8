#include <room.h>
inherit ROOM;

void create()
{
   set("short", "西厢房走道");
	set("long", @LONG
你走在西厢房走道上。长长的走道中，纯金成的长灯架上挂了一排
饰丽的宫灯! 走道两旁摆设了许多奇花异草，空气中弥漫一种淡淡的香
气。在一柱柱雕饰华丽的长柱，刻画许多彩绘的图形，美不胜收。西面
你看到一扇门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
   "north" :__DIR__"wroad1",
   "east" :__DIR__"corridor7",
   "west" :__DIR__"westroom",
   "southup" : "/d/latemoon/upstar/upstar2",

]));

   create_door("west","雕饰厢门","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
