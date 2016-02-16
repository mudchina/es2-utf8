// /d/city/street4

inherit ROOM;

void create()
{
        set("short", "京师西街");
        set("long", @LONG
你现在正走在京师的街道上。东边是进出紫禁城的午门，西边则
是当朝地位显赫的相国的府宅，而北边不远处“太白酒楼”的喧哗声
依稀可闻。
LONG
        );

        set("exits", ([
                "east":         __DIR__"wumen",
                "west" :        __DIR__"xiangguo/gate",
                "north" :       __DIR__"street5",
                ]));

	set("objects", ([
		__DIR__"npc/walker":	1,
		__DIR__"npc/trader":	1,
		]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

