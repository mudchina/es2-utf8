// Room: /d/choyin/tomb3.c

inherit ROOM;

void create()
{
	set("short", "树王坟内部");
	set("long", @LONG
这里是树王坟树洞的内部，你在这里可以闻到一股浓郁的檀香，奇
怪的是，这棵大树并不是檀木，却不知这股香味从哪里来？往南的出口
通往树洞的另一端。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"tomb1",
	]));
	set("objects", ([
		__DIR__"obj/chest": 1
	]) );

	setup();
	replace_program(ROOM);
}
