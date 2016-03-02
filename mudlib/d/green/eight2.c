#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷阵");
	set("long", @LONG
从这里向四周望去，只见四面环水，只有脚下一点陆地，水面上
似乎罩着一层神密的薄雾，渐渐地远处的景色模糊起来，你觉得
自己正深处一个飘忽的所在。你一回身，看见有一个路牌(sign)树
在那里。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight2",
	  "north" : __DIR__"eight1"  ,
	  "west"  : __DIR__"eight3"  ,
	  "east"  : __DIR__"closed"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上写着：  坎--"
		 "坎为水，遇青龙而死，遇玄武而涉，"
		 "遇白虎而生，遇朱雀而困。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


