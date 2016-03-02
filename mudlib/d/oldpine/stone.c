// Room: /d/oldpine/stone.c

inherit ROOM;

void create()
{
	set("short", "大青石上");
	set("long", @LONG
你现在正站在一块突出的大青石上, 虽然有点滑, 你还是能站稳,
往四周看, 除了长满了青苔的石壁, 好象无路可走了。
LONG
	);

	set("objects", ([
		__DIR__"npc/venomsnake":	1,
	]) );

	setup();
}

void init ()
{
	add_action ("do_climb", "climb");
}

int do_climb(string arg)
{
	if (!arg || arg != "down")
		return notify_fail ("想爬下去(down)吗？\n");

	message_vision ("$N迅速地爬下大青石。\n",this_player());
	this_player()->move(__DIR__"cave1");
	return 1;
}

