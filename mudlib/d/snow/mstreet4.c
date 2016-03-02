// Room: /d/snow/mstreet4.c

inherit ROOM;

void create()
{
	set("short", "雪亭镇街道");
	set("long", @LONG
这里是雪亭镇的大街，一条小巷子通往东边，西边则是一间驿站，
由于雪亭镇来往的商旅、官员并不很多，因此虽然是官府的驿站，也接
受百姓的信件，大街往北是一处山坳，从这里远远地可以望见北方的野
羊山，出了山坳就是一条碎石路通往山上。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : "/d/snow/crossroad",
  "south" : "/d/snow/mstreet3",
  "west" : "/d/snow/postoffice",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
