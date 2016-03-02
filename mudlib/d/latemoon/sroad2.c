inherit ROOM;

void create()
{
        set("short", "蜿蜒小径"),
        set("long", @LONG
你走在这条蜿蜒的小径上, 本来向北走的小径被一道峭壁挡住了,
因此小径从这弯向东边去, 在你的西边是一片杂草和几棵小树。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "northwest" :__DIR__"sroad1",
          "east" :__DIR__"sroad3",
]));

        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
