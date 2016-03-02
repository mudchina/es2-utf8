// Room: /d/goathill/slope1.c

inherit ROOM;

void create()
{
	set("short", "岩石坡");
	set("long", @LONG
这里是一处岩石斜坡，斜坡上到处布满乱石及杂草，东边的岩壁边
有一间石屋，往西跟往北则可以回到铺满碎石的山路。
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"mroad6",
		"west" : __DIR__"mroad5",
]));

	setup();
	replace_program(ROOM);
}
