// Room: /u/k/karrimor/temple/corridor7.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
你现在走在围绕著天井的回廊上, 回廊往东西两侧延伸, 南边就
是天井, 你也许可以走过去赏赏花, 散散心。在你的北方, 走过那扇
红漆木门就是后殿, 也是茅山派供奉历代掌门人灵位的地方。
LONG
	);
     set("item_desc", ([
         "door": (: this_object(), ({ "look_door", "north"}) :),
     ]));
	set("exits", ([ /* sizeof() == 3 */
     "west" : __DIR__"corridor4",
     "east" : __DIR__"corridor3",
     "south" : __DIR__"inneryard",
     "north" : __DIR__"temple2",
]));

     create_door("north", "红漆木门", "south", DOOR_CLOSED);
	setup();
}
