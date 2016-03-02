// Room: /u/k/karrimor/temple/entrance.c

inherit ROOM;

void create()
{
	set("short", "灵心观前");
	set("long", @LONG
在你眼前是一座古色古香的山门, 上面以龙飞凤舞的笔迹书写著
「灵心观」三字, 据说是当年太阳神君「杞庸」亲笔所题。往北方看
过去是一个颇大的广场。门前则是一条石英岩铺设的阶梯沿著山腰往
东而下。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" : __DIR__"square",
     "eastdown" : __DIR__"ladder1",
]));

    set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
