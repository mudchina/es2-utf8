#include <room.h>

inherit ROOM;

int DOOR_OPEN = 0;

void create()
{
	set("short","石室");
	set("long",@LONG
这是一间石室，西边有一个大厅，大厅中有光线透出来，因此可以看清
石室中的东西，南边有两个蒲团，似是用来打坐的，此外别无他物。
LONG
);
	set("exits",([
	"west" :__DIR__"cavehall",
	"south":__DIR__"water",
	]) );
	create_door("south","密门","north",DOOR_CLOSED);
	setup();
}

