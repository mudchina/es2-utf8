// Room: /u/sunhill/dukou.c

inherit ROOM;

void create()
{
        set("short", "江南渡口");
        set("long", @LONG
这里是泓水南岸，再往南不远就是日照山了。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"southriver",
  "south" : __DIR__"road1",
]));
        set("outdoors", "cloud");

        setup();
}

