inherit ROOM;

void create()
{
   set("short", "湘园小径");
	set("long", @LONG
湘园的桂花小径是以不同颜色的细石砌成各种图案。路面的
图案组成，全员是一个整体。但每幅图案又有独立的内容，总计
花石子路上约有二百幅。沿路观赏，美不胜收。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "south" :__DIR__"moon5",
       "east" :__DIR__"moonc",

]));

	setup();
	replace_program(ROOM);
}
