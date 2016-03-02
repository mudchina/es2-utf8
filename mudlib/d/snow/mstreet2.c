// Room: /d/snow/mstreet2.c

inherit ROOM;

void create()
{
	set("short", "雪亭镇街道");
	set("long", @LONG
你现在正走在雪亭镇的大街，往南直走不远处是镇上的广场，在你
的东边是一间大宅院，不过正门不在这个方向，往西是一家打铁铺子，
叮叮当当的声音大老远可以听得到，街道往北边一直通往镇外。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : "/d/snow/mstreet3",
  "south" : "/d/snow/mstreet1",
  "west" : "/d/snow/smithy",
  "east" : "/d/snow/workplace",]));
	set("objects", ([
	__DIR__"npc/drunk" : 1,
		__DIR__"npc/scavenger": 1 ]) );

	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
