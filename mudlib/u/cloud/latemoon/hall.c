// Room: /u/cloud/latemoon/hall.c

#include <room.h>

inherit ROOM;

string look_flower();

void create()
{
        set("short", "晚月庄");
        set("long", @LONG
这是一间歌舞院，许多美貌的女孩子正在这里学习着歌艺和舞蹈。
一位天仙般的女子正带着她们翩然起舞。望着那婀娜的舞姿，你几乎
难以自持，也想加入其中。
    院中种了些花草，一股淡淡的幽香仿佛是南墙下那盆紫蓝色的花
(flower)发出来的。
    一扇拱门(door)通往庄外。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"entrance",
]));

        set("item_desc", ([
                "door": (: look_door, "east" :),
		"flower": (: look_flower :),
        ]) );

        set("objects", ([
                CLASS_D("dancer") + "/master":1 ]) );

        create_door("east", "拱门", "west", DOOR_CLOSED);

        set("valid_startroom", 1);
        setup();
        "obj/board/dancer_b"->foo();
}

string look_flower()
{
	return "这种花你仿佛从未在其它地方见过，青茎蓝叶紫花。\n";
}

