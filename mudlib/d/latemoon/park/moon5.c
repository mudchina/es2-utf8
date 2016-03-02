inherit ROOM;

void create()
{
   set("short", "桂花园");
	set("long", @LONG
这是一片桂花园，园内种植桂花树十万多株，枝干苍劲，枝叶  
茂盛，树冠完整，富有生气。放眼展望，满遍披翠盖绿，葱郁的桂
花树斑烂绚丽，优雅大方，碧海银花，清香阵阵。薰的游人醉，衣
发常留馀香。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "south" :__DIR__"moon3",
       "north" :__DIR__"moon2",

]));

    set("objects", ([
        "/d/latemoon/park/npc/flwgirl" : 4 ]) );
	setup();
}
