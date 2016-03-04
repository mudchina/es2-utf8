// Room: /u/cloud/square.c

inherit ROOM;

void create()
{
        set("short", "十字路口");
        set("long", @LONG
绮云镇的两条青石路在这里交叉，路旁栽着棵古槐，有两个汉子合
抱那么粗。槐树下有个告示，象是官府立的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wroad2",
  "north" : __DIR__"nroad2",
  "south" : __DIR__"sroad1",
  "east" : __DIR__"eroad1",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

