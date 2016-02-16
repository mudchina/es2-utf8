#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷阵");
	set("long", @LONG
从这里向四周望去，只见一片无垠的绿野，然而地面上似乎
罩着一层神密的薄雾，渐渐地远处的景色模糊起来，你觉得
自己正深处一个飘忽的所在。你一回身，看见有一个路牌(sign)树
在那里。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"entrance",
	  "north" : __DIR__"closed"  ,
	  "west"  : __DIR__"eight0"  ,
	  "east"  : __DIR__"eight1"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上写着：  坤--"
		 "坤为地，遇青龙而生，遇玄武而死，"
		 "遇白虎而困，遇朱雀而涉。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


