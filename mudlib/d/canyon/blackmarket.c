// ROOM:__DIR__"blackmarket"

inherit ROOM;

void create()
{
	set("short","兵器库");
	set("long",@LONG                                   
在这里你可以看到墙上挂满了各式各样的武器，不难明了这里是存放
武器的地方，而墙上写了个诺大的「武」字。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
		"east" : __DIR__"canyon4",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/seller" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
