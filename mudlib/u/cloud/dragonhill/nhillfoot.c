// Room: /u/cloud/dragonhill/nhillfoot.c

inherit ROOM;

void create()
{
        set("short", "卧龙岗北坡");
        set("long", @LONG
从这往西北有条路通往雪亭镇，向南爬就是卧龙岗。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"nroad",
  "southup" : __DIR__"hummock",
]));
        set("outdoors", "dragonhill");

        setup();
        replace_program(ROOM);
}
