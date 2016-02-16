#include <room.h>

inherit ROOM;

void create()
{
	set("short", "迷阵");
	set("long", @LONG
从这里向四周望去，只见长天一碧，沃野千里，正自心旷神怡，
那层神密的薄雾又起，渐渐地远处的景色模糊起来，你觉得自
己正深处一个飘忽的所在。你一回身，看见有一个路牌(sign)
树在那里。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"stoneroom",
	  "north" : __DIR__"eight7"  ,
	  "west"  : __DIR__"eight6"  ,
	  "east"  : __DIR__"closed"  ,
	]));

	set("item_desc",([/* sizeof() == 1 */
	"sign" : "路牌上写着：  乾--"
		 "乾为天，遇青龙而死，遇玄武而困，"
		 "遇白虎而涉，遇朱雀而生。\n"
	])
	);
	
	set("outdoors","green");
	set("no_clean_up",0);
	setup();
}

int valid_leave(object me,string dir)
{
	if ( dir == "south" )
		me->set("八卦阵",1);
	return ::valid_leave(me,dir);
}

