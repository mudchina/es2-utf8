// Room: /d/oldpine/clearing.c

inherit ROOM;

void create()
{
	set("short", "林间空地");
	set("long", @LONG
这是一块林间空地，四周的树木花草像是被人修剪过一般，环绕著
空地围成一个整齐的圆形，空地中央一株巨大的松树(pine)像平地上撑
起一把大伞，树上针叶茂密得遮去了大半的阳光，空地四周有三条小路
分别通往东、西、南三个方向，往南的小路旁竖著一个牌子(sign)。
LONG
	);
	set("item_desc", ([
		"pine": "一株又高又大的松树，当你抬头往上看的时候似乎有个人影\n"
				"在树梢之间移动，不过也许\是风吹动所造成的错觉。\n",
		"sign": "「官府告示：此处常有歹人出没。」\n"
	]) );
	set("exits", ([
		"west" : "/d/oldpine/npath3",
		"north" : "/d/oldpine/spath1",
		"east" : "/d/oldpine/epath1"
]));

	setup();
}

void init()
{
	add_action("do_climb", "climb");
	if( this_player() ) {
		tell_room(__DIR__"tree1", this_player()->name() + "往树下走了过来。\n");
	}
}

int do_climb(string arg)
{
	if( arg!="pine" ) return 0;

	message_vision("$N手脚并用，敏捷地爬上了空地中央的大松树。\n",
		this_player());

	tell_room(__DIR__"tree1", this_player()->name() + "从树下爬了上来。\n");
	this_player()->move(__DIR__"tree1");

	return 1;
}

int valid_leave(object me, string dir)
{
	tell_room(__DIR__"tree1",
		"树下的" + me->name() + "往" + to_chinese(dir) + "离开了。\n");
	return 1;
}
