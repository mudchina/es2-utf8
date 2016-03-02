#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷阵");
	set("long", @LONG
从这里向四周望去，只见铅云低沉，忽然一道闪电，跟着一阵巨雷，
远山为之回响，身旁似乎罩着一层神密的薄雾，渐渐地远处的景色
模糊起来，你觉得自己正深处一个飘忽的所在。你一回身，看见有
一个路牌(sign)树在那里。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"closed",
	  "north" : __DIR__"eight5"  ,
	  "west"  : __DIR__"eight4"  ,
	  "east"  : __DIR__"eight3"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上写着：  震--"
		 "震为雷，遇青龙而涉，遇玄武而生，"
		 "遇白虎而困，遇朱雀而死。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


