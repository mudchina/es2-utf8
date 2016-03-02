
#include <room.h>
inherit ROOM;

void create()
{
    set("short","内厅穿堂");
	set("long", @LONG
你从后廊往西出了内厅进入穿堂。往北是内院，一条宽过道，西  
面立著一个粉油大影壁，后有一大半门，小小的一所庭宇。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" :__DIR__"latemoonc",
		"south" : "/d/latemoon/room/twoc",
		"east" : "/d/latemoon/latemoon2",
	]));


	create_door("east","仪门","west", DOOR_CLOSED);
	setup();
}
