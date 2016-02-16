// Room: /d/city/street3.c

inherit ROOM;

void do_climb (string arg);

void create()
{
        set("short", "京师东街");
        set("long", @LONG
这是京师东街的南段。整个东街都被掌管天下兵马印的尚书府占
据了，东边便是尚书府的大门，南边则是尚书府高耸的围墙(wall)，
北去的道路一直通向振远总局。
LONG
        );
        set("exits", ([ 
		"east":		__DIR__"shangshu/gate",
		"west":		__DIR__"wumen",
		"north":	__DIR__"street2",
		]));

	set("item_desc", ([
		"wall": (: "一段高高的院墙，但对轻功好的人爬上(climb)似非难事。\n" :),
		]) );

        set("outdoors", "city");

        setup();
}

void init ()
{
	add_action ("do_climb", "climb");
}

void do_climb (string arg)
{
	if ((arg == "wall") || (arg == "up") || (arg == "墙")) 
		this_player()->move(__DIR__"wall");
}
	
