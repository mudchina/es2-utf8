// Room: /d/city/street15.c
inherit ROOM;
void create()
{
        set("short", "京师街道");
        set("long", @LONG
你来到京师的大街。北边是护国寺的大门，寺内香烟缭绕。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
//             "north" :    __DIR__"templegate",
             "west"  :    __DIR__"street14",
             "east"  :    __DIR__"street7",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

