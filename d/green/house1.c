// Room: /d/green/house1.c

inherit ROOM;

void create()
{
	set("short", "工匠的家");
	set("long", @LONG
这是一间普通的民宅，矮小的屋内整齐地堆著一排排的石板，墙上则
挂著各式各样的雕刻，切割的工具。屋角放著各式的成品及半成品如石桌
、石椅、墓碑等。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/green/path8",
]));
	set("objects", ([
	"/d/green/npc/worker1" : 1,
	]) );


	setup();
	replace_program(ROOM);
}
