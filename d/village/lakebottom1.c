// Room: /d/village/lakebottom1.c

inherit ROOM;

void create()
{
	set("short", "水下岩洞");
	set("long", @LONG
这个岩洞中全都是冰，冰的色泽纯正洁白，很象是北极的玄冰，却不
知怎么会在这里出现。四周气温极低，阵阵寒冷袭来，常人难以站立片刻。
在玄冰上面长着发光的藻类植物，所以从入口看去非常明亮。刚才进入岩
洞的入口处又迅速地结了一层薄冰，奇怪的是水压并没有把它压破。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "westup" : __DIR__"lakebottom2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
