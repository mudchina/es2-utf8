// Room: /d/sanyen/inner_yard.c

inherit ROOM;

void create()
{
	set("short", "庭园");
	set("long", @LONG
你正站在山烟寺的庭园里, 这庭园里不但花草茂盛, 而且小桥流
水, 假山凉亭, 应有尽有, 气派非凡。北边有间雅房, 东边穿过拱门
则是大殿。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"heal_room",
		"east" : __DIR__"temple",
	]));
	set("outdoors", "sanyen");

	set("objects", ([
		__DIR__"npc/cripple" :1
	]) );
	setup();
	replace_program(ROOM);
}
