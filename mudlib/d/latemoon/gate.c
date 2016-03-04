#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "晚月庄大门");
	set("long", @LONG
你来到了这个小径的尽头，一个有著朱红漆大门大宅
院矗立在你的面前，门口挂著两串灯笼(lantern),上面写
得有字，像这样一间豪华的大宅院出现在这样的乡间野外
，使你觉得有些突兀，大宅的南边、东边都是茂密的林子
，看来也没有其他的路。
LONG
	);
	set("item_desc", ([
		"lantern" : "灯笼上几个娟秀的字迹写著：\n"
			BRED HIW "晚霞西照人影依稀 \n月影高挂和风婉约 \n" NOR
	]) );

	set("exits", ([
		"east"	:	__DIR__"entrance",
		"west" :		__DIR__"front_yard",
	]));
	
	create_door ("east", "拱门", "west", DOOR_CLOSED);
 
	set("outdoors", "latemoon");

	setup();
	replace_program(ROOM);
}
