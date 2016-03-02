// Room: /d/chuenyu/sunnyroad.c

inherit ROOM;

void create()
{
	set("short", "山脚乡田");
	set("long", @LONG
你的两侧是茂盛的稻田，还有一条清澈见底的小溪。许多乡民在田里
辛苦的忙碌着。再北面是黑松山。眺望山顶，你似乎可以看到一个颇具规
模的城堡。城堡的最顶端插着一面大旗，大旗上绣着两个斗大的金字：淳于。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/flower_seller" : 1,
]));
	set("no_magic", 1);
	set("outdoors", "chuenyu");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"base_b_m",
  //"south" : __DIR__"dustyroad3",
  "southwest" : __DIR__"croad2",
]));
	set("no_fight", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
