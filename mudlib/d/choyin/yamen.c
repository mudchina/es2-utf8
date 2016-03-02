// Room: /d/choyin/yamen.c
# include <room.h>
inherit ROOM;

void create()
{
	set("short", "大堂");
	set("long", @LONG
正中高悬一匾(borad),匾下的书案上放着笔,墨,纸,砚,惊堂木等物.两旁各置屏风.堂下摆着各式刑具,你从未见过.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"yamen_iner",
                "south" : __DIR__"yamen_yard",
                      ]));
   create_door("south", "铜钉大门", "north", DOOR_CLOSED);
	set("no_clean_up", 0);
 set("objects", ([
                __DIR__"npc/judgeman" : 1,     
                __DIR__"npc/magistra" : 2,
                __DIR__"npc/yamen_po" : 8     
                 ]) ); 	
        setup();
	replace_program(ROOM);
}
