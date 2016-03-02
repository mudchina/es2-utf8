// Room: /u/sunhill/road1.c

inherit ROOM;

void create()
{
        set("short", "山脚小路");
        set("long", @LONG
这是条崎岖的黄土小径，北面通向渡口，往南小路蜿蜒而上，通往
山顶。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dukou",
  "southup" : __DIR__"road2",
  "east" : "/d/choyin/n_gate",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

