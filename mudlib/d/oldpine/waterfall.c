// Room: /d/oldpine/waterfall.c

inherit ROOM;

void create()
{
	set("short", "瀑布前");
	set("long", @LONG
你现在正站在瀑布前的一个小水潭里，水潭大约深可及胸，淹不死
人，一条白练般的瀑布(waterfall)从数百丈高的悬崖上冲激而下，溅
得你全身湿透，水潭三面都被高耸的山壁(cliff)所包围，只有南面沿
著一条山涧可以出去。
LONG
	);
	set("item_desc", ([
		"waterfall":
			"这个瀑布水势并不是很大，但是高度却极高，水珠溅在你的脸上\n"
			"打得隐隐生疼。你注意到瀑布后面似乎有什么东西在发著光。\n",
		"cliff":
			"水潭四周的山壁都有数百丈高，想要爬上去「肯定」是休想。\n"
	]) );
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/oldpine/riverbank2",
]));
	set("resource/water", 1);
	setup();
	replace_program(ROOM);
}
