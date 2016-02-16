// Room: /d/choyin/hollow2.c

inherit ROOM;

void create()
{
	set("short", "寒谷");
	set("long", @LONG
    两面皆为峭壁，光滑无物。一阵寒谷幽香，沁人心脾，却不知来自何方。。。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hollow3",
  "south" : __DIR__"hollow1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
