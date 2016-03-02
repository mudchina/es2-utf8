// Room: /d/oldpine/epath3.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
你现在正走在一条松树林间的小路，西边有一座小石桥横跨在一条
山涧上，往东不远处似乎是林子的出口，一条破旧的栈道沿著山壁通往
山上，你发现地上有一些湿漉漉的脚印(footprints)，但是因为脚印太
多，分不出是往哪里去。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
		"footprints" : "一些杂乱的脚印，不但有人的脚印，看起来还有不少马蹄印。\n",
	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"epath2",
	]));
	set("objects", ([
                __DIR__"npc/maniac": 1
//		__DIR__"npc/venomsnake": 2
	]) );
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
