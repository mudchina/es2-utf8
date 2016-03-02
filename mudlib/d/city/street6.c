// /d/city/street6

inherit ROOM;

void create()
{
        set("short", "京师西街");
        set("long", @LONG
你现在正走在京师的街道上。往东走便是紫禁城的后门--神武门
，南面似乎有一家酒楼，酒肉的香味一阵阵飘来。北边是一个废园，
据说里面经常闹鬼，所以没人敢去。
LONG
        );

        set("exits", ([
                "east":         __DIR__"shenwumen",
                "south" :       __DIR__"street5",
		"west":         __DIR__"cloth",
                "north" :       __DIR__"feiyuan",
                ]));
        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

