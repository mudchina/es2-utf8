// Room: /d/city/street9.c
inherit ROOM;
void create()
{
        set("short", "京师街道");
        set("long", @LONG
你现在正走在京师的大街上。东边就是京师的东一门了，隐约
传来官兵搜查行人的吆喝声。在你的北边是京城的武器店，据说江
湖上半数以上的武器精品出于此店。从店中走出的人都是一副心满
意足的模样。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "east"  :    __DIR__"eastdoor1",
             "north" :    __DIR__"weapon",
             "west"  :    __DIR__"street8",]));
        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}
