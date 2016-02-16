// Room: /u/sunhill/hillsmoke/entrance.c

inherit ROOM;

void create()
{
        set("short", "山烟寺外");
        set("long", @LONG
这是是山烟寺外。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yard",
  "northdown" : "/u/cloud/sunhill/road4",
]));
        set("outdoors", "sunhill");

        setup();
        replace_program(ROOM);
}

