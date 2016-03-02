// Room: /d/goathill/mroad6.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你现在正走在一条崎岖的山路上，往北是一个峡谷，通过「飞火崖
」的正下方，从这里可以看到一条五、六丈宽的石梁魏颤颤地跨过峡谷
，山路往西南转过，南边则是一片岩石斜坡。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"canyon1",
		"southwest" : __DIR__"mroad5",
		"south" : __DIR__"slope1",
]));
	set("outdoors", "goathill");

	setup();
	replace_program(ROOM);
}
