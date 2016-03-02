// Room: /d/sanyen/corridor1.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你正走在一条长廊上, 两旁分别是流云轩及后殿的外墙, 墙上画
著大慈大悲观世音菩萨救苦救难的事迹。长廊往东西两边延伸, 西边
的尽是一间相当大的房屋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kitchen",
  "east" : __DIR__"corridor",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
