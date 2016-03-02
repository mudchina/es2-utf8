// /d/city/wumen
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "午门");
        set("long", @LONG
这里是京师的午门。午门进出紫禁城的要道，北面那庄严的大门
(gate)后面便是神秘的紫禁城。大门的两侧放着一对石狮(statue)，
虎视眈眈地盯着来往的人群。南面是历年选武状元的校武场，也不知
现在有没有人。东西向的街道围绕着紫禁城。
LONG
        );

        set("exits", ([
		"east":		__DIR__"street3",
		"west" :	__DIR__"street4",
		"south" :	__DIR__"jiaowu",
//		"north":	__DIR__"zijincheng",
		]));
        set("outdoors", "city");

//	create_door("north", "铁门", "south", DOOR_CLOSED);

        setup();
        replace_program(ROOM);
}

