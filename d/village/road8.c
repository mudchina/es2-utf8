// Room: /d/village/road8.c

inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
小路的西侧是玉螺湖，东南是地主田老财的宅院，西南是一片稻田。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road9",
  "north" : __DIR__"road7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
