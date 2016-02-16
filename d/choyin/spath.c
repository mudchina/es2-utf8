inherit ROOM;

void create()
{
        set("short", "土路");

        set("long", @LONG
这是一条土路，路旁隐约可见房舍，皆已破败。往南是一座高山，
据说有鬼怪出没。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"s_gate",
            "south" : __DIR__"rockroad",]));
        set("outdoors", "choyin");

        setup();
        replace_program(ROOM);
}

