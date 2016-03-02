
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "佛堂门前");
	set("long", @LONG
这里是庄院二楼的佛堂门前，你可以闻到一股浓郁的檀香气息。
走在这里你有一种庄严肃静的感觉，在闲暇之馀你觉得来到这可以
暂时忘去周遭的烦人琐事，彷佛可以放开一切� 所有时空都静止般
的虚空幽静。西面你看到一扇檀香木门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"uproom",
    "north" :__DIR__"upstar1",
    "south" :__DIR__"upstar2",

]));

    create_door("west","檀香木门","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
