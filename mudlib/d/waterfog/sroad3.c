// Room: /d/waterfog/sroad3.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条宽敞坚实的青石大道，大道沿著山腰往东向山下延伸，一
道长长的白石阶梯从这里往北边上山，从这里仰望阶梯的尽头有一座雄
伟的楼阁，那就是著名的「水烟阁」。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/d/waterfog/stair1",
  "east" : "/d/waterfog/sroad2",
//  "west" : "/d/temple/sroad"
]));
	set("objects", ([
		__DIR__"npc/guard": 2 ]) );

	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
