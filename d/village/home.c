// Room: /d/village/home.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "刘家小房");
	set("long", @LONG
这是一所很破旧的木屋。每当山风吹来，都会发出“吱吱呀呀”
的声音。南侧是一个小小的厨房。木屋的后面是一个精巧的花园，花
园里穿来阵阵打闹之声。一个翠绿的小草坪就在西面。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
	]));
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"smallstorage",
  "south" : __DIR__"littlegarden",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldliu" : 1,
]));
	create_door("south", "木门", "north", DOOR_CLOSED);
	set("no_clean_up", 0);

	setup();
}
