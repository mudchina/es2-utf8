// Room: /d/death/spath1.c

inherit ROOM;

void create()
{
	set("short", "墙边小路");
	set("long", @LONG
这是一条沿著城墙的小路，东边是一座高大巍峨的城楼，城楼前有
一条长长的石桥，桥上许多模糊的影子正列队走进城门。小路往西南延
伸进入一片沼地。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"gateway",
]));
	set("outdoors", "death");

	setup();
	replace_program(ROOM);
}
