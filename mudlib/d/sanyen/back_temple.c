// Room: /d/sanyen/back_temple.c

inherit ROOM;

void create()
{
	set("short", "后殿");
	set("long", @LONG
一间宽大的后殿, 正中有一尊药师如来的金身塑像。四周的墙上
唯妙唯肖地彩绘著十八罗汉, 每个罗汉的旁边并写著他得道升天的过
程。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/sanyen/corridor",
  "east" : "/d/sanyen/tower",
]));

     set("objects", ([
         __DIR__"npc/little_bonze" : 1 ]) );

	setup();
	replace_program(ROOM);
}
