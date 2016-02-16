// Room: /u/sunhill/northriver.c

inherit ROOM;

void cross_river();
void no_boat();

void create()
{
        set("short", "泓水北侧");
        set("long", @LONG
这里已靠近北岸，江水齐胸深，偶尔一个湍流卷过来，仿佛要将人
打入江底似的。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/u/cloud/dukou",
  "south" : __DIR__"midriver",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

void init()
{
        cross_river();
}

void cross_river()
{
        if( this_object()->query("marks/船夫") ) {
                set("exits/south", __DIR__"sunhill/midriver");
                call_out("no_boat", 5);
        }
}

void no_boat()
{
        if( !query("exits/south") ) return;
        message("vision","小船驶向江南。\n", this_object() );
        delete("exits/south");
	this_object()->set("marks/船夫", 0);
}

