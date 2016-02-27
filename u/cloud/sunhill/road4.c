// Room: /u/sunhill/road4.c

inherit ROOM;

void create()
{
        set("short", "盘山小径");
        set("long", @LONG
这是条崎岖的黄土小径。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"road3",
  "southup" : "/d/sanyen/sroad2",
//"southup" : __DIR__"hillsmoke/entrance",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

