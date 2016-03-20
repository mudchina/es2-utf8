// Room: /d/snow/sroad4.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条宽敞坚实的青石板大道，大道两旁种著整齐的花木，从这
里往北通往水烟阁，往东则是衔接雪亭镇街道的路口。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"sroad5",
  "east" : __DIR__"sroad3",
  "southwest" : "/d/canyon/road",
]));
	set("outdoors", "snow");
	set("objects", ([
		__DIR__"npc/crazy_dog": 1 ]) );

	setup();
	replace_program(ROOM);
}
