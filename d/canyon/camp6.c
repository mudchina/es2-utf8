// ROOM:__DIR__"camp6"

inherit ROOM;
void create()
{
        set("short","小队长营帐");
	set("long",@LONG                                   
类似北边的营帐，空空荡荡的，看起来一点也不像是军营，一点威武
的感觉也没有，在这也有两把简易的凉椅，两位队长，平常小兵没有尢许
是不能擅自进入这□的，向东北是副将营帐，但没有经过「允许」是不得
进入的。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/captain" : 1,
		__DIR__"npc/leader2" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
