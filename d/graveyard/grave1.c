// Room: /d/graveyard/grave1.c

inherit ROOM;

void create()
{
	set("short", "乱葬岗");
	set("long", @LONG
你现在正站在一处乱葬岗的草丛里，放眼望去四面都是一坟坟的土
堆，里面想必埋的都是一些客死异乡，又无亲无故的可怜人，被好心的
乡人收埋在这里，因为长年乏人整理，这里的杂草密布，几达人腰，岗
上到处开满了俗称「望乡红」的小红花，也许是吸收了土里尸骨的养分
，这里的红花开得又大又诡异。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"southeast" : __DIR__"road1",
]));
	set("outdoors", "graveyard");

	setup();
	replace_program(ROOM);
}
