inherit ROOM;

void create()
{
        set("short", "小径");
        set("long", @LONG
条蜿蜒的小径通往东南方, 在你的东面是一道峭壁, 而在你的
南边是一片浓密的竹林。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "northwest" :__DIR__"sroad2",
          "east" :__DIR__"sroad4",
]));

        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
