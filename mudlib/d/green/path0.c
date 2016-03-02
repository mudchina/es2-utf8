// Room: /d/green/path0.c

inherit ROOM;

void create()
{
	set("short", "小路的尽头");
	set("long", @LONG
小路到了这里以后往北变得很不明显, 往南还可以依稀看到村子的
入口, 路的四周长满了杂草和小树之类的, 看来相当的荒凉. 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"north" : "/d/green/cave0",
  "south" : "/d/green/path1",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
