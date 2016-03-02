// Room: /d/city/street8.c

inherit ROOM;

void create()
{
	set("short", "京师街道");
	set("long", @LONG
你现在正走在京师的大街上，往东可以隐约看到城门铜扣上的反
光，在你的北边是京城唯一的钱庄，往西有熙熙攘攘的人群，偶尔还
能见到一俩个僧侣。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"street9",
  "north" : "/d/city/bank",
  "west" : "/d/city/street7",]));
	set("objects", ([
		"d/snow/npc/scavenger": 1 ]) );

	set("outdoors", "city");

	setup();
	replace_program(ROOM);
}
