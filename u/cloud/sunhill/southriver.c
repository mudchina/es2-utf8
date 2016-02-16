// Room: /u/sunhill/southriver.c

inherit ROOM;

void create()
{
        set("short", "泓水南侧");
        set("long", @LONG
这里靠近南岸，江水甚是寒冷。从这儿已能望到山烟寺的一角。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"midriver",
  "south" : __DIR__"dukou",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

