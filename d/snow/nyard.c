// Room: /d/snow/nyard.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是一间整理得相当乾净的书房，红木桌椅上铺著蓝绸巾，显得
十分考究，西面的立著一个书架，上面放著一排排的古书，往南走出房
门可以看到天井。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/snow/inneryard",
]));

	set("objects", ([
		__DIR__"npc/girl":1 ]) );

	setup();
	replace_program(ROOM);
}
