inherit ROOM;

void create()
{
   set("short", "甬路");
	set("long", @LONG
桂花园的石子甬道是以不同颜色的细石砌成各种图案。路面
的图案组成，全员是一个整体。但每幅图案又有独立的内容，总
计花石子路上约有二百幅。沿路观赏，美不胜收。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "southeast" :__DIR__"paroad2",
       "north" :__DIR__"moon5",
       "west" :__DIR__"moroom",

]));

	setup();
	replace_program(ROOM);
}
