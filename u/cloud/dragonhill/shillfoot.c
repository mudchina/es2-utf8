// Room: /u/cloud/dragonhill/shill.c

inherit ROOM;

void create()
{
        set("short", "卧龙岗南坡");
        set("long", @LONG
这是卧龙岗的东南坡。东南的路通向绮云镇，往北就要过岗了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"hummock",
  "southeast" : "u/cloud/entrance"
]));
        set("outdoors", "dragonhill");

        setup();
        replace_program(ROOM);
}
