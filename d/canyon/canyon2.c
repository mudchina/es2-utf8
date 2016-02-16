// ROOM:__DIR__"canyon2"

inherit ROOM;
void create()
{
        set("short","隘口小路");
	set("long",@LONG                                   
来到这□，脚下的黄土仍是厚厚的一层，可见得来往这条道路的人必
不多，向北即是隘口尾，往南一直通达天驼关口，两侧依旧是荒冷的山壁
，但似乎更为严峻。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
        	"northeast" : __DIR__"canyon1",
        	"south" : __DIR__"canyon3",
	]) ); //eof(exits)
	
	setup();
	
	replace_program(ROOM);
} //EOF
