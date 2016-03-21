// Room: /d/oldpine/lake.c

inherit ROOM;

void create()
{
	set("short", "水潭");
	set("long", @LONG
你现在正站在一个深不见底的水潭边上，从潭底不时有气泡冒上来
，散发著一股诡异的香味，水潭边长满了黄色叶子的怪草，四周陡峭的
山壁近乎直立，抬头只见一个半圆形的天空，唯一的出路大概只有往北
山泉流入水潭的缺口。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"riverbank1",
  ]));
	set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/serpent" : 5,
  ]));
	set("resource/water", 1);
	setup();
	replace_program(ROOM);
}
