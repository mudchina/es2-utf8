// /d/city/shangshu/huayuan
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "花园");
        set("long",@LONG
尚书府的花园里搜集了许多名贵花卉。从洛阳的牡丹到扬州的琼
花，你不能不惊诧于这里的全来。四时的花卉竞相开放着，发出沁人
的香味。从花园东行就是内宅，而西边似乎有一间破屋。
LONG
        );

        set("exits", ([
		"north":	__DIR__"road3",
		"east":		__DIR__"neizhai",
		"west":		__DIR__"road4",
                ]));

	set("objects", ([
		__DIR__"npc/gardener":	1,
		]));

	create_door("east", "帘子", "west", DOOR_CLOSED);

	set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

