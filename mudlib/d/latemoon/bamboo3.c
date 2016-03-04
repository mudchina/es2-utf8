inherit ROOM;

void create()
{
        set("short", "竹林");
        set("long", @LONG
这是一座茂密的竹林。当你进入后彷佛迷失了方向！
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "north" :__DIR__"sroad5",
        "east" :__DIR__"bamboo",
        "west" :__DIR__"bamboo2",
        "south" :__DIR__"bamboo",
        ]));
        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
