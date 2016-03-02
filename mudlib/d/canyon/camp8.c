// ROOM:__DIR__"camp8"

inherit ROOM;
void create()
{
        set("short","将军营帐");
	set("long",@LONG                                   
虎头挂于营顶，虎皮披于帐上，威武无比，帐中龙柱顶天，双龙吐珠
图挂于前，严然有天子之势，金椅银桌，□、簋、爵、角、鉴，样样俱全
，一磬、一鼓、一笙、一笛、一萧，文墨章笔擎于旁，将军在上，参谋在
右，由不得令人生畏。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1*/
        	"west" : __DIR__"camp7",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/general" : 1,
		__DIR__"npc/adviser" : 1,
	]) );
	
	setup();
	
//	replace_program(ROOM);
} //EOF
