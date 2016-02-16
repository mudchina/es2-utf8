#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷阵");
	set("long", @LONG
从这里向四周望去，只见身处一个大湖泊之中，脚下只有四尺见方的
一块陆地，湖上似乎罩着一层神密的薄雾，渐渐地远处的景色模糊起来，
你觉得自己正深处一个飘忽的所在。你一回身，看见有一个路牌(sign)
树在那里。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight5",
	  "north" : __DIR__"eight7"  ,
	  "west"  : __DIR__"closed"  ,
	  "east"  : __DIR__"eight6"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上写着：  兑--"
		 "兑为泽，遇青龙而困，遇玄武而生，"
		 "遇白虎而死，遇朱雀而涉。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


