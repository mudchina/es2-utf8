#include <room.h>

inherit ROOM;

void create()
{
	set("short","黑暗山洞");
	set("long",@LONG
山洞很矮，几乎站不直身子，脚下偶尔踩到石头或是些莫名其妙的东西，
洞内奇寒澈骨，南面是一扇木门，北面隐隐地有些亮光。
LONG
);
	set("exits",([
	"south":__DIR__"cave0",
	"north":__DIR__"cave2",
	]) );
	create_door("south","木门","north",DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

