
inherit ROOM;

void create()
{
    set("short", "上等厢房");
	set("long", @LONG
这是一间上等厢房，光线适中。近窗边有一张桌子，旁有书橱!
还有一个古琴放在平台上! 墙上除了美丽的饰物外，还挂了一些书画
有一浓郁清新的书香气息! 通常是给远道而来的贵客休憩夜宿的一间
上等厢房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
      "north" :__DIR__"two2",

]));

    set("objects", ([
        __DIR__"npc/tguest" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
