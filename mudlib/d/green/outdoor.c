#include <room.h>

inherit ROOM;

void create()
{
	set("short","石室");
	set("long",@LONG
这是一间石室，室内透着一种说不清的神秘力量，西边有两张石椅
东首墙上挂这一把木剑。北边通往大厅，但墙上写了两行字，走近仔细
辨认，是：非我弟子，莫入此门。
LONG
);
	set("exits",([
	"enter" :__DIR__"cavehall",
	"south" :__DIR__"entrance",
	]) );
	create_door("south","大石门","north",DOOR_CLOSED);
	setup();
}

int valid_leave(object me,string dir)
{
	if ( dir == "enter" && me->query("family/master_id") != "master outer" )
		return notify_fail("入口被魔法封住了！\n");
	return ::valid_leave(me,dir);
}

