// Room: /d/green/path2.c

inherit ROOM;

void create()
{
	set("short", "三叉路口");
	set("long", @LONG
小路到了这里往北就算是出了村子. 西边有一间小小的土地庙, 东
边是一栋民宅似的建筑, 不过入口不在这边. 往南是一个交叉路口.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : "/d/green/path3",
  "north" : "/d/green/path1",
  "west" : "/d/green/temple0",
]));
	set("outdoors", "green");
	set("objects", ([
	"/d/green/npc/kid2" : 2,
	]) );

	setup();
	replace_program(ROOM);
}
