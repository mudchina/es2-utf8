
#include <room.h>
inherit ROOM;

void create()
{
   set("short", "仪门");
	set("long", @LONG
你走在后厅内院的仪门，是晚月庄后厅内院长廊走道的相接路
口。东北方是往膳房的夹道，西面是长廊夹道，南面是到后厅，往北
则可走出大门前往前院。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" : "/d/latemoon/latemoon4",
    "south" :__DIR__"lcenter",
    "east" :__DIR__"eat1",
    "west" :__DIR__"two1",

]));

    create_door("south","后厅大门","north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
