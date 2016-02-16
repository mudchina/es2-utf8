// Room: /d/waterfog/sroad2.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条宽敞坚实的青石板大道，从这里沿著山势弯向西边与南边
，往西不远处就是通往水烟阁的石阶。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/waterfog/sroad1",
  "west" : "/d/waterfog/sroad3",
]));
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
