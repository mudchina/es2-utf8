// Room: /d/choyin/nw_street.c

inherit ROOM;

void create()
{
	set("short", "石板空地");
	set("long", @LONG
这里是树王坟西北边的石板空地，因为树王的根范围太广，因此树
王坟周围十几丈都没有办法盖房子，因此这里铺了石板，平时便当作百
姓散步休憩的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"w_street4",
  "south" : __DIR__"w_street3",
  "east" : __DIR__"n_street3",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
