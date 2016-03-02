// Room: /d/snow/weapon_storage.c

inherit ROOM;

void create()
{
	set("short", "兵器储藏室");
	set("long", @LONG
这是一间堆满各式兵器、刀械的储藏室，各式武器都依照种类、长
短、依次放在一起，并且擦拭得一尘不染，储藏室的出口在你的南边，
面对出口的左手边有一个架子(shelf)。
LONG
	);
	set("exits", ([
		"south" : __DIR__"school2",
	]));
	set("objects", ([
		__DIR__"npc/obj/bamboo_sword": 1,
	]) );
	set("item_desc", ([
		"shelf": "这个架子上空荡荡的，什么也没有——连灰尘也没有。\n"
	]) );

	setup();
}

void init()
{
	add_action("do_push", "push");
}

void check_trigger()
{
	object room;

	if( (int)query("left_trigger")==3
	&&	(int)query("right_trigger")==5
	&&	!query("exits/down") ) {
		message("vision", "地板忽然发出轧轧的声音，一块地面缓缓移动著，露出一个向下的阶梯。\n",
			this_object() );
		set("exits/down", __DIR__"secrect_storage");
		if( room = find_object(__DIR__"secrect_storage") ) {
			room->set("exits/up", __FILE__);
			message("vision", "天花板忽然发出轧轧的声音，露出一个向上的阶梯。\n",
				room );
		}
		delete("left_trigger");
		delete("right_trigger");
		call_out("close_passage", 10);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision", "地板忽然发出轧轧的声音，一块地面缓缓移动著，将向下的通道盖\住了。\n",
		this_object() );
	if( room = find_object(__DIR__"secrect_storage") ) {
		room->delete("exits/up");
		message("vision", "天花板忽然发出轧轧的声音，向上的阶梯又缓缓地收了回去。\n",
			room );
	}
	delete("exits/down");
}


int do_push(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="shelf" ) {
		write("你试著推动这个架子，似乎可以左右滑动....\n");
		return 1;
	}
	if( sscanf(arg, "shelf %s", dir)==1 ) {
		if( dir=="right" ) {
			message_vision("$N将架子往右推...，忽然「喀」一声架子又移回原位。\n", this_player());
			add("right_trigger", 1);
			check_trigger();
			return 1;
		} else if( dir=="left" ) {
			message_vision("$N将架子往左推...，忽然「喀」一声架子又移回原位。\n", this_player());
			add("left_trigger", 1);
			check_trigger();
			return 1;
		} else {
			write("你要将架子推向那个方向？\n");
			return 1;
		}
	}
}


void reset()
{
	::reset();
	delete("left_trigger");
	delete("right_trigger");
}
