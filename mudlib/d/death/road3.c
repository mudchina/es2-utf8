// Room: /d/death/road3.c

inherit ROOM;

void create()
{
	set("short", "路的尽头");
	set("long", @LONG

..... 还没想到 ....

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
          "south" : "/d/death/road2",
        ]));

	setup();
	replace_program(ROOM);
}
