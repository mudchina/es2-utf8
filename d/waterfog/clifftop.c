// Room: /d/waterfog/clifftop.c

inherit ROOM;

void create()
{
	set("short", "水烟阁半山亭");
	set("long", @LONG
这里是一个用白石砌成的亭子，亭子的东面和北面都是深不见底的
悬崖，从这里望出去只见一片云雾之中突出几座山峰，云雾之中隐隐可
以看到好似水波的微光，使你一时之间彷佛以为这座亭子是建在一个湖
中，往西北望去可以看到水烟阁漂浮在云雾之中。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : "/d/waterfog/stair5",
  "southdown" : "/d/waterfog/stair4",
]));
	set("objects", ([
		__DIR__"npc/watcher": 1,
		__DIR__"npc/celes_tiger": 1 ]) );
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
