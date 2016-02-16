// Room: /u/sunhill/road2.c

inherit ROOM;

void create()
{
        set("short", "盘山小径");
        set("long", @LONG
这是条崎岖的黄土小径。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"road1",
  "westup" : __DIR__"road3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

