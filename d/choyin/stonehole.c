// Room: /d/choyin/stonehole.c

inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
石室黑漆漆的,双目不见物.你的双手好象触到了什么东西(object),惧意顿生.
LONG
	);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
