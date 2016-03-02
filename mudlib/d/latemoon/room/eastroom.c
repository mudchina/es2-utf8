#include <room.h>

inherit ROOM;

void create()
{
   set("short", "东厢房");
	set("long", @LONG
你进入东厢房来，临窗的地上铺著猩红毛毯，正面设著大红金钱
蟒靠背，石青金钱蟒引枕，秋香色金钱蟒大条褥。两边设一对梅花式
红漆小几，几上茗琬瓶花俱备。这是一间上等厢房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"eroad1",

]));

      set("objects", ([
          __DIR__"npc/servant" : 1,
          __DIR__"npc/elon" : 1 ]) );
    create_door("west","雕饰房门","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
