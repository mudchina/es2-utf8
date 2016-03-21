// Room: /d/snow/guestroom.c

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这里是一间布置得相当雅致的厢房，从窗子可以看到北边的天井跟
南边的庭园中各式各样的奇花异草，以及他们所带来的淡淡香气。
东面墙上挂著一幅仕女图(painting)。往北是通往天井的出口。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/snow/inneryard",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "painting" : "画中是一位宫妆美妇，端庄美丽，你觉得依稀在哪里见过。",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
