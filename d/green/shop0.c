// Room: /d/green/shop0.c

inherit ROOM;

void create()
{
	set("short", "沈记商行");
	set("long", @LONG
这里是青石村唯一的商店 -- 沈记商行, 在这里村民可以购买
日常生活用品, 工具, 甚至于棺材. 真可以说是一间「杂」货店.
屋内相当的拥挤, 到处都是箱子和杂物.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/green/path4",
]));
	set("objects", ([
	"/d/green/npc/shen" : 1,
	"/d/green/npc/woman1" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
