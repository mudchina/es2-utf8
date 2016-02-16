// Room: /d/chuenyu/croad2.c

inherit ROOM;

void create()
{
	set("short", "路口");
	set("long", @LONG
这里是个交叉路口，过往行人很多。路边有一个茶馆，是供行
人歇息的地方。
    东南是通往京师的北驿道，东北方可见阴森的黑松山，西北是
一条通往天驼关的黄土大道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"sunnyroad",
  "southeast" : __DIR__"croad3",
  "northwest" : __DIR__"croad1",
]));
	set("no_clean_up", 0);
	set("outdoors", "chuenyu");

	setup();
	replace_program(ROOM);
}
