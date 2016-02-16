// Room: /d/goathill/mroad3.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你现在正走在一条崎岖的山路上，东边的路旁一个山壁的裂缝里有
一间小庙，从这里看过去黑漆漆的似乎没有人照顾，山路往北是一段陡
峭的上坡，往西南的山路就平缓得多。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"northup" : __DIR__"mroad4",
		"east" : __DIR__"temple1",
		"southwest" : __DIR__"mroad2",
]));
	set("outdoors", "goathill");

	setup();
	replace_program(ROOM);
}
