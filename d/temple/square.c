// Room: /u/k/karrimor/temple/entrance.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "灵心观广场");
	set("long", @LONG
你正站在灵心观前的广场前, 一片用石英岩铺成的广场。一对雄
伟的石狮子站在庙门的两侧, 狮子的两侧立著两根雕著龙纹的石柱。
广场的中央还有一个大香炉, 香炉里正冒著袅袅的香烟。
LONG
	);

     set("item_desc", ([
         "door": (:this_object(), ({"look_door", "north"}): ),
     ]) );

	set("exits", ([ /* sizeof() == 2 */
     "north" : __DIR__"temple1",
     "south" : __DIR__"entrance",
]));

     create_door("north", "红漆木门", "south");

     set("outdoors", "temple");

	setup();
//	replace_program(ROOM);
}
