// Room: /d/snow/w_room.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这是一间打扫得相当乾净的客房，虽然所有的家俱看起来都相当朴
素，比不上县城里几家著名的大酒馆，但是自有一种敦厚亲切的感觉，
你在这里相信可以安心的休息。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"inn_2f",
	]));

	create_door("east", "房门", "west", DOOR_CLOSED);
	
	setup();
}
