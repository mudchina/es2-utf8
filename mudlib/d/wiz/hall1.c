// Room: /d/wiz/hall1.c

inherit ROOM;

void create()
{
	set("short", "巫师交谊厅");
	set("long", @LONG
这里是巫师聊天讨论的地方，如果巫师们要开会的话，也多半会选在这
里举行，往东是巫师会客室。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/wiz/jobroom",
  "east" : "/d/wiz/entrance",
]));
	set("no_clean_up", 0);

	setup();
	call_other("/obj/board/wizard_b", "???");
	replace_program(ROOM);
}
