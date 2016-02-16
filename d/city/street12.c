// Room: /d/city/street12.c
inherit ROOM;
void create()
{
        set("short", "京师街道");
        set("long", @LONG
这里是京师的大街，青石铺道，街面很干净。东边是京师的热
闹场所天桥，来到京师可不能不去哦。南边是京师的刑场，逢上处
决一些重要的犯人的时候，那里肯定是人山人海，不过平时人就少
得多了。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "east"   :    __DIR__"bridge",
             "west"   :    __DIR__"street13",]));
//             "south"  :    __DIR__"xingchang",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}
