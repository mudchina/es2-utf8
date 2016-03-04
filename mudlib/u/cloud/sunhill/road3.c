// Room: /u/sunhill/road3.c

inherit ROOM;

void create()
{
        set("short", "盘山小径");
        set("long", @LONG
这是条崎岖的黄土小径。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road2",
  "south" : __DIR__"road4",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

