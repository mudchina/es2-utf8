// Room: /u/k/karrimor/temple/temple1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "灵心观大殿");
	set("long", @LONG
你现在来到灵心观的大殿, 在你的眼前是一尊真武大帝的金身。
在金身的下方是一张朱红色的大供桌, 上面排满了鲜花素果。在桌子
的前方则摆放著三四个蒲团。东西两侧的圆形拱门通往连接后殿的回
廊。走过南边的红漆木门就是广场。
LONG
	);

	set("item_desc", ([
		"door": (: this_object(), ({"look_door", "south"}) :),
	]) );
	set("exits", ([ /* sizeof() == 3 */
		"west" : __DIR__"corridor2",
		"south" : __DIR__"square",
		"east" : __DIR__"corridor1",
	]));

	set("valid_startroom", 1);
	set("objects", ([
		CLASS_D("taoist") + "/taolord" :1,
		__DIR__"npc/trainer"  :1,
		__DIR__"npc/tfighter" :1,
	 ]) );
	
	setup();

	// To cause the taoist's board to be loaded.
	call_other("/obj/board/taoist_b", "???");

    create_door("south", "红漆木门", "north");

//	replace_program(ROOM);
}
