// Room: /d/waterfog/entrance.c

inherit ROOM;

void create()
{
	set("short", "水烟阁正门");
	set("long", @LONG
这里是水烟阁的正门，一股沁人心脾的檀香使你精神为之一振，正
门共分三进，全部都是上等的檀木雕成，最里的门上悬著一块匾额，上
面龙飞凤舞地写著几个大字，可是你全然看不出到底是什么字。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"frontyard",
		"west" : __DIR__"westhall",
		"east" : __DIR__"easthall",
		"north" : CLASS_D("fighter") + "/guildhall",
	]));
	set("objects", ([
		__DIR__"npc/guard": 2
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir != "north" || wizardp(me) ) return 1;
	if( me->query_temp("weapon")
	&&	present("waterfog guard", this_object()) ) {
		message("vision", "水烟阁武士喝道：慢著，进水烟阁，先放下你的兵刃！\n", this_object());
		return notify_fail("水烟阁武士挡住了你的去路。\n");
	}
	return 1;
}
