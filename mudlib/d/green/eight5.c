#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷阵");
	set("long", @LONG
从这里向四周望去，只见火光冲天，炽热难当，身旁似乎罩着一层
神密的薄雾，渐渐地远处的景色模糊起来，你觉得自己正深处一个
飘忽的所在。你一回身，看见有一个路牌(sign)树在那里。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight5",
	  "north" : __DIR__"eight4"  ,
	  "west"  : __DIR__"eight6"  ,
	  "east"  : __DIR__"closed"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上写着：  离--"
		 "离为火，遇青龙而死，遇玄武而涉，"
		 "遇白虎而生，遇朱雀而困。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


