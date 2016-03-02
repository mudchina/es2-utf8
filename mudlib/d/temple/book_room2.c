// Room: /d/temple/broom2.c

inherit ROOM;

void create()
{
	set("short", "经楼");
	set("long", @LONG
上了楼来, 首先你看到一幅张天师的画像挂在对面的墙上, 画像
的下方摆著一张覆著红布的桌子, 桌上整齐地放著茅山的镇教秘籍。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/temple/book_room1",
]));

	setup();
	replace_program(ROOM);
}
