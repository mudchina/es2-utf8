// Room: /u/cloud/dragonhill/hummock.c

inherit ROOM;

void create()
{
        set("short", "卧龙岗");
        set("long", @LONG
这是位于雪亭和绮云两镇间的一道山梁。据说山上时常有强盗拦路
抢劫。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"nhillfoot",
  "southdown" : __DIR__"shillfoot",
]));

        set("objects", ([
                "/u/cloud/npc/gangster" : 2
]) );

        set("outdoors", "dragonhill");

        setup();
}
