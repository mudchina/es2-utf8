// ROOM:__DIR__"canyon5"

inherit ROOM;
void create()
{
        set("short","关外小路");
	set("long",@LONG                                   
南边即为天驼关的关口，两片诺大的铁门(door)，若非由关内打开恐
怕难以进入，往东侧看去，铁栅的映满你整双眼眸，转向西侧，看到的还
是一片光秃秃的山壁，不由得使你想早点离开这个地方。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
		"south" : __DIR__"canyon6",	
		"north" : __DIR__"canyon4",
	]) ); //eof(exits)

	set("item_desc", ([
		"door": "这巨大的铁门锈迹斑斑，它是上下开合的，现在已经高高的抬起，\n"
			"若它失控砸下，可能什么东西都会被砸扁。\n",
	]) );	
	setup();
	
	replace_program(ROOM);
} //EOF
