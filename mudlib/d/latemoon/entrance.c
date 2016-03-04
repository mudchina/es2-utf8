// Room: /u/cloud/latemoon/entrance.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "碎石小径");
	set("long", @LONG
这是条用鹅卵石铺成的小路，往西可以看到一座用淡青色围墙围住
的庭院，有两个身着彩衣的女子笑盈盈的站在那里说笑着，她们身后的
一扇拱门(door)，檐顶下面写着「晚月庄」。院墙那边飘出的阵阵曲声勾
人魂魄，隐约还可闻到一股香气。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"gate",
  "east" : "/u/cloud/wroad0",
]));
	set("outdoors", "cloud");

        set("item_desc", ([
                "door": (: look_door, "west" :),
        ]) );

	set("objects", ([
		"/u/cloud/npc/lm_guard": 2 ]) );

	create_door("west", "拱门", "east", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}

/*
void init()
{
	exist_door(ob);
}

void exist_door(object ob)
{
        if( (string)ob->query("gender") == "女性"  )
	        create_door("west", "拱门", "east", DOOR_CLOSED);
}
*/
