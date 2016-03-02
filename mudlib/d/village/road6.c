// Room: /d/village/road6.c

inherit ROOM;

void roadgone();

void create()
{
	set("short", "青石小路");
	set("long", @LONG
青石小路在这里到了尽头，被茂密的茅草(grass)挡住了去路。一阵
东风吹过，飘来阵阵花香，南面是面积很大的湖泊，湖上的水汽映的西边
的群山更加影影绰绰。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road5",
]));
	set("item_desc",([
		"grass":"高高的茅草，可以拨开(pushaside)。\n",
	]) );
	
	set("no_clean_up", 0);

	setup();
	//replace_program(ROOM);
}

void init()
{
	add_action("do_pushaside","pushaside");
}

int do_pushaside(string arg)
{
	if( !arg || arg=="" )
		return notify_fail("你想拨开什么？\n");
	if( arg!="grass" )
		return notify_fail("明明只有草可以拨开。\n");
	set("exits/west",__DIR__"valley2");
	message_vision("$N拨开茅草，发现了一条向西的路。\n",this_player() );
	call_out("roadgone",5);
	return 1;
}

void roadgone()
{
	if( !query("exits/west") ) return;
	message("vision","茅草晃了晃，又遮住了向西的路。\n",this_object() );
	delete("exits/west");
}


