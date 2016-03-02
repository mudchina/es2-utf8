// Room: /d/oldpine/pine1.c

inherit ROOM;

void create()
{
	set("short", "松树林");
	set("long", @LONG
你现在正站在一个松树林里，嗯....这是一个松树林....你所知就
这么多，茂密的松树遮蔽了整个天空，使你连方向都弄不清楚，最好在
天黑之前赶紧找道路径出去吧。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"pine" + (random(5)+2),
	  "north" : __DIR__"pine" + (random(5)+2),
	  "west" : __DIR__"pine" + (random(5)+2),
	  "east" : __DIR__"pine" + (random(5)+2),
//	  "east" : __DIR__"epath3",
	]));
	set("outdoors", "oldpine");

	setup();
}

int valid_leave(object me, string dir)
{
	write("你实在弄不清楚方向....");
	switch(dir) {
		case "north":	write("北边....北边是哪里呢？....");	break;
		case "east":	write("东边....东边....");	break;
		case "south":	write("南边....哪里是南边？....");	break;
		case "west":	write("西边....嗯....");	break;
		default:
			write("该往哪里走呢....");
	}
	write("就是这个方向吧。\n");
	return 1;
}
