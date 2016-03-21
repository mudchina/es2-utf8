// Room: /u/k/karrimor/temple/trainroom.c

inherit ROOM;

void create()
{
    set("short", "练功房");
	set("long", @LONG
你正站在一间宽阔的大房间里, 这里是茅山派弟子打坐练功的地
方, 空气中弥漫著一股股汗臭味。四周的墙壁上画著一幅幅经脉穴道
图。靠近墙壁的地上则摆著一个个练功用的木人。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
     "south" : __DIR__"corridor4",
]));

     set("objects", ([ /* sizeof() == 1 */
     __DIR__"npc/taoist" : 1,
     __DIR__"npc/taoist2" : 1,
     ]) );

    create_door("south", "木门", "north");
	setup();
}
