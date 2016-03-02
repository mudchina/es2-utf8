// Room: /d/city/street11.c
inherit ROOM;
void create()
{
        set("short", "京师街道");
        set("long", @LONG
这里是京师的大街。西边是京师的热闹场所天桥，一些行人匆
匆往西走去。据说天桥的夜市也不差哦。南边是一片民宅，炊烟缭
绕。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "west"   :    __DIR__"bridge",
	     "north"  :    __DIR__"boots",
             "east"   :    __DIR__"street10",
             "south"  :    __DIR__"house1",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

