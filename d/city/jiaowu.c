// Room: /d/city/jiaowu.c
inherit ROOM;
void create()
{
        set("short", "校武场");
        set("long", @LONG
这里是京师的校武场。一些御林军正在这里日夜操练，喊杀声
此起彼伏。几个骑着高头大马的将领，在场上来回地巡视。每年武
考也是在此举行的，当年淤兰天武、萧避尘、蓝芷萍就是在此出尽
了风头，一时间声名传遍长城内外、大江南北。
    北边是午门，南边是热闹的天桥了。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "south"  :    __DIR__"bridge",
             "north"  :    __DIR__"wumen",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

