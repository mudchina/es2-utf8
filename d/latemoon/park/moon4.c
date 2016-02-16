inherit ROOM;

void create()
{
   set("short", "暖香榭");
	set("long", @LONG
暖香榭位于水池东岸，秋水山房之西，依岩为屋，结构曲折，
极幽致，室小而精，尚朴去华，渊然静修，古香袭人。走进这里
你有一种心源湛澈，天地虚灵，彷佛置身于仙境的感觉。往西面
望去，水底亭台，历历可鉴。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "southwest" :__DIR__"paroad1",
       "north" :__DIR__"bridge3",

]));

    set("objects", ([
        __DIR__"npc/bird" : 2,
        __DIR__"npc/maysan" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
