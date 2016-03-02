// Room: /d/choyin/sw_road1.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
这是一条沿著湖岸的街道，往东北可以通到人车来往的南门广场，
这一带原本是在乔阴县城的旧南门之外，因此仍然保留浓厚的乡村气息
，往南是一条小路继续沿著湖岸通往翠柳湖南岸，街道往东通往著名的
火龙将军庙。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"s_street1",
		"west" : __DIR__"dragon_temple",
]));
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
