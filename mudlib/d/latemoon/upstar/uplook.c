
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "观景台");
	set("long", @LONG
这是晚月庄的前堂楼观景台，站在台前你可以看到整个庄院的  
布局，瀚烟山美丽景色尽收眼里。微微的山风轻拂你的脸庞，有种
说不出的轻爽。远处山寺的钟声，飞鸟的鸣啼，与眼前的景色构成
一幅山林风光的风景画。正下方是前院。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"upstarc",
    "jump" : "/d/latemoon/park/yard1",

]));

    set("objects", ([
        __DIR__"npc/bird" : 2,
    ]) );
    set("outdoors", "latemoon");
    create_door("west","楼门","east", DOOR_CLOSED);
    setup();
	replace_program(ROOM);
}
