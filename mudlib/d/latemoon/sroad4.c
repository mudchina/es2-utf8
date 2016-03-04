inherit ROOM;

void create()
{
	set("short", "蜿蜒小径");
	set("long", @LONG
这条蜿蜒的小径通往西南方, 西边是一片茂密的竹林, 小
径两旁是绿油油的草地，凉风从草地上吹拂而过，像嬉戏的儿
童般溜过你的足畔，使你不知不觉间脚步轻快了起来。
LONG
	);
	set("exits", ([
		"west" :__DIR__"sroad3",
		"south" :__DIR__"sroad5",
	]));

	set("objects", ([
	   "/d/latemoon/npc/butterfly" : 1 ]) );
	set("outdoors", "lateroom");
	setup();
	replace_program(ROOM);
}
