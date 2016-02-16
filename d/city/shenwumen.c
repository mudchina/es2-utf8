// Room: /d/city/shenwumen.c

inherit ROOM;

void create()
{
        set("short", "神武门");
        set("long", @LONG
你来到紫禁城的北门--神武门。南向的大门通向紫禁城，但这门
很少开。门上缠着大铁链，还有士兵把守。往北走是皇家祭坛，不是
一年一度祭天时那总很冷清。东西向的道路分别通向京师东，西路。
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"jitan",
//		"south":	__DIR__"zijincheng",
		"east":		__DIR__"street1",
		"west":		__DIR__"street6",
		]));

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

