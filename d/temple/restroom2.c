// Room: /u/k/karrimor/temple/restroom2.c

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这是一间供香客或其他江湖同道休息挂单的客房, 屋子里只是简
单地摆放著几件家俱。你闻到天井中传来淡淡的花香。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
     "west" : __DIR__"corridor3",
]));

    create_door("west","木门","east");
	setup();
}
