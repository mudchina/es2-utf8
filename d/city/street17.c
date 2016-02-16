// Room: /d/city/street17.c
inherit ROOM;
void create()
{
        set("short", "京师街道");
        set("long", @LONG
你来到京师的大街上。南边是京师的南门，出了南门就可去南
方重镇……南海镇。北边是天桥，人声鼎沸。西边是刑场，一个一
般人极少去的地方。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
/*             "west"   :    __DIR__"xingchang", */
             "north"  :    __DIR__"bridge",
             "south"  :    __DIR__"southdoor",]));
        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

