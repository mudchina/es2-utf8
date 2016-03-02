#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷阵");
	set("long", @LONG
从这里向四周望去，只见寒风阵阵，奇寒澈骨，如入北极风洞，四周
似乎罩着一层神密的薄雾，风吹不散，渐渐地远处的景色模糊起来，你
觉得自己正深处一个飘忽的所在。你一回身，看见有一个路牌(sign)树
在那里。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"eight3",
	  "north" : __DIR__"closed"  ,
	  "west"  : __DIR__"eight2"  ,
	  "east"  : __DIR__"eight4"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上写着：  巽--"
		 "巽为风，遇青龙而生，遇玄武而死，"
		 "遇白虎而涉，遇朱雀而困。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


