// Room: /d/choyin/hollow1.c

inherit ROOM;

void create()
{
	set("short", "寒谷");
	set("long", @LONG
两面皆为峭壁，光滑无物。一阵寒谷幽香，沁人心脾，却不知来自何方。。。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"hollow2",
  "south" : __DIR__"hollow1",
  "west" : __DIR__"hollow"
]));
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
