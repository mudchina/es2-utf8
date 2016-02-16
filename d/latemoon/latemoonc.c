inherit ROOM;

void create()
{
    set("short","大厅后院");
	set("long", @LONG
这是晚月庄后的小小庭院，面积似乎不大，但花木扶疏，举目四望，
竟种满了无数梅花，婉约娟秀，别有一番滋味。清风徐来，梅花特有的
清香弥漫在风中.....
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"latemoon5",
    "west" :__DIR__"latemoon7",
    "east" :__DIR__"latemoon1",
    "south" :__DIR__"latemoon4"

]));

	setup();
	replace_program(ROOM);
}
