// Room: /d/city/street10.c
inherit ROOM;
void create()
{
        set("short", "京师街道");
        set("long", @LONG
这里是京师的大街。东边是京师的东二门，一些刚进城的行人
坐在路边休息，不时发出一阵哄笑声。往西就可以到京师中心了。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "east"   :    __DIR__"eastdoor2",
             "west"   :    __DIR__"street11",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

