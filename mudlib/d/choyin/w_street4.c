// Room: /d/choyin/w_street4.c

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这里是乔阴县城的西大街.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
              "south" : __DIR__"w_street2",
              "east" : __DIR__"nw_street",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
