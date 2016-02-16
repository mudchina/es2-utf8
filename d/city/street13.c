// Room: /d/city/street13.c
inherit ROOM;
void create()
{
        set("short", "京师街道");
        set("long", @LONG
你来到京师的大街上。西边是京师的西二门，西去的人不时经
过这里。南边是京师的监狱，关押着一些重要的犯人。站在这里可
以清楚地听到狱卒拷打犯人的皮鞭声和犯人的惨叫声。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "west"   :    __DIR__"westdoor2",
             "east"   :    __DIR__"street12",]));
//             "south"  :    __DIR__"jial",]));
        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}
