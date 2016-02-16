// ROOM:__DIR__"camp2"

inherit ROOM;
void create()
{
        set("short","营火区");
	set("long",@LONG
地上有些食物的残渣，而中央地带则有一营火，在边边则有一个水
井，想必是官兵们用来汲水用的，南北两侧为小队长的营帐，东方则是
副将军的营帐，如果没有事情冒然进入是会被斥责。
LONG
	); // eof(long)
	
	set("resource/water",1);

	set("exits",([ /* sizeof()==4 */
        	"north" : __DIR__"camp5",
        	"south" : __DIR__"camp6",
        	"east" : __DIR__"camp7",
        	"west" : __DIR__"camp1",
	]) ); //eof(exits)

	
	setup();
	
	replace_program(ROOM);
} //EOF
