// Room: /d/snow/mstreet3.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "雪亭镇街道");
	set("long", @LONG
这里是雪亭镇的大街，东边有一栋陈旧的建筑，看起来像是什么店
铺，但是并没有任何招牌，只有一扇门(door)上面写著一个大大的「当
」字，往西是一间药铺，大街往南北两个方向延伸。
LONG
	);

	set("exits", ([
		"south"	: __DIR__"mstreet2",
		"north"	: __DIR__"mstreet4",
		"east"	: __DIR__"hockshop",
		"west"	: __DIR__"herbshop",
	]));
	set("outdoors", "snow");

	setup();

	create_door("east", "店铺门", "west", DOOR_CLOSED);

	replace_program(ROOM);
}
