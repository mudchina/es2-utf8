// Room: /u/sunhill/hillsmoke/yard.c

inherit ROOM;

void create()
{
        set("short", "寺院前庭");
        set("long", @LONG
这是寺院前庭。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west"  : __DIR__"guestroom",
  "north" : __DIR__"entrance",
  "south" : __DIR__"hall",
  "east"  : __DIR__"woodroom",
]));

        set("outdoors", "sunhill");

        set("objects", ([
                "/u/cloud/npc/monk_guard":2,
        ]) );

        setup();
        replace_program(ROOM);
}

