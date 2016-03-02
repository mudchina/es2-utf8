// tea_corridor.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
	set("short", "场院");
	set("long", @LONG
    这里好象是大户人家子弟玩乐的场院, 原来建有秋千架的草地，
已经成了荆棘丛生的荒草场了。再往西是一座凉亭，亭子似乎也快要倒塌了...
LONG
        );

        set("exits", ([
                "east"          : "/u/cloud/woodboxy",
	        "west"          : "/u/cloud/god2" ]) );

//	set("objects", ([
//	]) );

        create_door("east", "木门", "west", DOOR_CLOSED);

        setup();

}


