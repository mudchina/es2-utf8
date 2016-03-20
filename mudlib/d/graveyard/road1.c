// Room: /d/graveyard/road1.c

inherit ROOM;

void create()
{
	set("short", "黄土小径");
	set("long", @LONG
这是一条铺著黄土的小径，弯弯曲曲地穿过一片夹杂著矮树丛跟杂
草的斜坡，往西南通往一条比较开阔的大路，西北边则是一片乱葬岗。
LONG
	);
	set("outdoors", "graveyard");
	set("exits", ([ /* sizeof() == 1 */
    "northwest" : __DIR__"grave1",
  ]));

	setup();
	replace_program(ROOM);
}
