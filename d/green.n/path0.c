// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "小路的尽头");
	set("long", @LONG
小路到了这里以后往北变得很不明显, 往南还可以依稀看到村子的
入口, 路的四周长满了杂草和小树之类的, 看来相当的荒凉. 
LONG
	);
    set("exits", ([
    "north" : __DIR__"cave0",
    "south" : __DIR__"path1",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
