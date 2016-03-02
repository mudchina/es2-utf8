// ROOM:__DIR__"camp5"

inherit ROOM;
void create()
{
        set("short","小队长营帐");
	set("long",@LONG                                   
这□是小队长的营帐，四周仍旧和小兵营帐一样的空旷，但营帐的布
料倒是比小兵营帐好多了，北侧有两把凉椅，看来定是小队长偷懒时休息
的地方。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"south" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/leader1" : 2,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
