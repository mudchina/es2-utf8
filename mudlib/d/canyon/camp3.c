// ROOM:__DIR__"camp3"

inherit ROOM;
void create()
{
        set("short","小兵营帐");
	set("long",@LONG                                   
这是个由粗略的布料所搭成的小营帐，□面只有三二个小兵，其他的
小兵，大概在另一个小兵营帐□赌博聊天吧，而东边则是小队长的营帐。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1*/
		"south" : __DIR__"camp1",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/guard1" : 2,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
