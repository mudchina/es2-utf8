// Room: /d/village/lordhouse1.c

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "财主家前院");
	set("long", @LONG
地主田老财的家似乎并不与老财的名字相适应，灰色的低矮院墙围着
三间屋子。田老财家的前院，中间有一棵大槐树，伸开的枝叶遮出一大片
阴凉，这里连接东房和南房。前院的西面是一扇漆黑的大门。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lordhouse3",
  "west" : __DIR__"road9",
  "east" : __DIR__"lordhouse2",
]));
	create_door("west","田老财家大门","east",DOOR_CLOSED);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
