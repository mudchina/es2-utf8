// Room: /d/snow/school.c

inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
这里是一间宽敞的书院，虽然房子看起来很老旧了，但是打扫得很
整洁。墙壁上挂著一幅山水画，意境颇为不俗。书院的大门开在北边，
西边有一扇木门通往边厢。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"sroad2",
  ]));

	set("objects", ([
		__DIR__"npc/teacher": 1 
	]) );
	setup();
	replace_program(ROOM);
}
