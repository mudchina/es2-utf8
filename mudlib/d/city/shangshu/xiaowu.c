// /d/city/shangshu/xiaowu

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "小屋");
        set("long",@LONG
你步入尚书府内的一间小屋。小屋内很黑，什么也看不见，但莫
名地感到一股杀气，让人有转身就跑的念头。
LONG
        );

        set("exits", ([
		"west":		__DIR__"road1"
                ]));

	create_door ("west", "小木门", "east", DOOR_CLOSED);

        setup();
        replace_program(ROOM);
}

