// ROOM:__DIR__"canyon3"

inherit ROOM;
void create()
{
        set("short","隘口小路");
	set("long",@LONG                                   
黄土、黄石还是平铺于小路上，崎岖的道路来到这□是比北方平缓多
了，向南二十里就是天驼关口了，东侧为军营，但军营四周为铁栅所包围
，想从这□进入军营内似乎是不太可能。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
        	"north" : __DIR__"canyon2",
        	"south" : __DIR__"canyon4",
	]) ); //eof(exits)
	
	setup();
	
	replace_program(ROOM);
} //EOF
