
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "佛堂");
	set("long", @LONG
这是专供庄内祭祀的佛堂，是一座精构楼阁，屋顶覆以琉璃瓦，四
角钻尖覆以鎏金铜瓦。堂内供奉  人灵「区冥」，旁有雨神「天龙」、
火神「凤凰」。两翼有琉璃鹤照壁，姿态生动。四周置陈神□佛像，□
盘塔磬，及一股檀香的气息。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"upcenter",

]));

    set("objects", ([
        __DIR__"npc/statue" : 1,
    ]) );
    create_door("east","檀香木门","west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
