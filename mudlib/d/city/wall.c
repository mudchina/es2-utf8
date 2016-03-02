// Room: /d/city/wall.c

inherit ROOM;

int do_jump (string arg);

void create()
{
	set("short", "院墙");
	set("long", @LONG
你爬上了尚书府的院墙，墙里面人来人往的，很是
热闹。你是跳进去(jump in)，还是回去(jump out)呢？
LONG
	);

	set("exits", ([
		]));

	set("objects", ([
		]) );

	set("no_clean_up", 0);

	setup();
}

void init ()
{
	add_action("do_jump", "jump");
}

int do_jump (string arg)
{
	if (arg == "in")  {
		this_player()->move(__DIR__"shangshu/feiwu");
		return 1;
		}
	    else if (arg == "out") {
		this_player()->move(__DIR__"street3");
		return 1;
		}
	
	return 0;
}	
