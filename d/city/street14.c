// Room: /d/city/street14.c
inherit ROOM;
void create()
{
        set("short", "京师街道");
        set("long", @LONG
这里是京师的大街上。西边是京师的西一门，护国寺的僧人西
去取经必经此地。福缘好的话还可以看到几个有道高僧路过。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "west"  :    __DIR__"westdoor1",
             "east"  :    __DIR__"street15",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

