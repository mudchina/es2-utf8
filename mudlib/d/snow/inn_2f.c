// Room: /d/snow/inn_2f.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "饮风客栈二楼");
	set("long", @LONG
你现在来到了饮风客栈的二楼，这家客栈有个很奇怪的规矩，就是只留宿
名头够大的客人，如果你只是一个无名小卒，不论出再多银两都租不到一间空
房，墙边有一道楼梯通往一楼的茶座。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"w_room",
		"north" : __DIR__"n_room",
		"down" : __DIR__"inn",
		"east" : __DIR__"e_room",
	]));
	
	set("objects", ([
		__DIR__"npc/rat":	6,
		]));

	create_door("north", "房门", "south", DOOR_CLOSED);
	create_door("east", "房门", "west", DOOR_CLOSED);
	create_door("west", "房门", "east", DOOR_CLOSED);

	setup();
}
