// Room: /d/choyin/hollow.c

inherit ROOM;

void create()
{
	set("short", "寒谷");
	set("long", @LONG
两面皆为峭壁，光滑无物。一阵寒谷幽香，沁人心脾，却不知来自何方。。。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hollow1",
]));
	set("no_magic", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
