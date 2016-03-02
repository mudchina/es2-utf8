#include <room.h>

inherit ROOM;

void create()
{
   set("short", "西厢房");
	set("long", @LONG
你进入西厢房来，地下面西放著四张椅子，都搭著银红撒花椅被
椅子两边有一对高几，右边几上文王鼎，匙筋香盒；左边几上汝窑美
人瓶内插著花卉茗琬棰壶等物。隔窗望去，隐约可看见花园景色。.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"wroad2",

]));

       set("objects", ([
        __DIR__"npc/servant" : 1,
        __DIR__"npc/annihi" : 1 ]) );
    create_door("east","雕饰房门","west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
