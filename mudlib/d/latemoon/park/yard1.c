
inherit ROOM;

void create()
{
    set("short","前院");
	set("long", @LONG
你走到前院，你看到几块山石，东面一处假山小池。其上植有藤  
萝、青芷，异草芬芳荔薛。池中几尾小鱼自在的游来游去。假山外隔
著围篱，有一种山怀中的小花园的感觉。.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" : "/d/latemoon/front_yard",
     "south" :__DIR__"flower2",

]));
    set("outdoors", "latemoon");

	setup();
	replace_program(ROOM);
}
