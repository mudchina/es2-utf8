// Room: /d/snow/sroad4.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条宽敞坚实的青石板大道，大道两旁种著整齐的花木，从这
里往西通往水烟阁，往南则是衔接雪亭镇街道的路口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/waterfog/sroad1",
  "south" : "/d/snow/sroad3",
]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
