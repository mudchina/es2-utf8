// Room: /d/canyon/bamboo/bamboo2.c

inherit ROOM;

void create()
{
	set("short", "竹林道");
	set("long", @LONG
此处的竹林比起入口的竹子更为高大耸直，也有些小动物在这四
周跳来跳去，跑来跑去的，更是生气盎然，不时有也黄莺唱吟著美妙
的诗句，清新宛然，人间仙境，只是偶尔有那怪异的强风袭卷而致，
另人难以忍受，在往入探头，有一似人大的黄石挺立于内，而其四周
隐隐约约有些许正气溢散而出。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"bamboo3",
		"south" : __DIR__"bamboo1",
]));

	setup();
	replace_program(ROOM);
}
