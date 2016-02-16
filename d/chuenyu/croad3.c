// croad3.c
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "北驿道");
        set("long", @LONG
这里是条宽阔的大道。路旁杂草茂盛，足有半人多高，躲在里
面肯定不会有人发现。远处可见一个小村庄和周围的稻田。
    往南是京师，东北通往天驼关。
LONG
        );

        set("exits", ([
                "northwest"      : __DIR__"croad2",
		"south"	 	 : "/d/city/nroad2" ]) );

/*        set("objects", ([
                "/u/cp/chater2" : 1, ]) );*/
        set("outdoors", "chuenyu");
        setup();
        replace_program(ROOM);
}

