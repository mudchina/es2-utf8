// ROOM:__DIR__"camp1"

inherit ROOM;
void create()
{
        set("short","军营入口");
	set("long",@LONG                                   
此处为黄石隘口驻军的入口，东方为军队饮食的地方，在门口的两侧
有两位小兵正在值勤。南、北两侧为小兵的营帐。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==4 */
		"west" : __DIR__"canyon4",
        	"north" : __DIR__"camp3",
        	"south" : __DIR__"camp4",
        	"east" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/door_guard" : 2,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
