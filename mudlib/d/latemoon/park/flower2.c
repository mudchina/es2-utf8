inherit ROOM;

void create()
{
    set("short", "月洞门");
	set("long", @LONG
走进月洞门，只见迎面一带翠嶂，挡在南面。只见白石岭□，  
或如鬼怪，或如猛兽，纵横拱立，上边苔藓成斑，藤萝掩映，其
中微露羊肠小径。往南进入翠嶂，往北是小花厅。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
      "north" :__DIR__"yard1",
      "south" :__DIR__"moonc",

]));

	setup();
	replace_program(ROOM);
}
