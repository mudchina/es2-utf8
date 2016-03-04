// Room: /d/sanyen/sroad2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这条山路到这里转了个弯，往东穿过一个山壁上凿出来的隧道，往
南则顺著山势缓缓下山。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
 "east": __DIR__"sroad1",
 "north": __DIR__"gate",
]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
