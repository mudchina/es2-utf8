#include <room.h>

inherit ROOM;

void create()
{
	set("short","石室大厅");
	set("long",@LONG
这就是传说中的绝尘子的修行之所，北面是一座佛像，佛像顶部
有一颗夜明珠发出莹莹的光芒。室内设施古朴，但却一尘不染。
LONG
);
	set("exits",([
	"south" :__DIR__"outdoor",
	]) );
        set("objects", ([
                CLASS_D("juechen")+"/master" : 1,
                ]) );

	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}


