// Room: /d/death/bridge.c

inherit ROOM;

void create()
{
	set("short", "奈何桥");
	set("long", @LONG
你现在正站在一条极长的石桥上，桥头一块石碑上面刻著「奈何桥
」三个古篆，东、西两面都是大雾，连桥底下是不是水都看不到，浓雾
中有许多朦胧的人影鱼贯地向北走去，奈何桥往南延伸到一片大雾之中
，北边引隐约约有一座城楼的影子。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"gate",
		"south" : __DIR__"bridge1",
	]));
	set("objects", ([
		__DIR__"npc/hell_guard": 4,
	]) );

	setup();
	replace_program(ROOM);
}
