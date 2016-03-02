#include <room.h>

inherit ROOM;

void create()
{
	set("short","山路");
	set("long",@LONG
这是一段荒芜的山路，显然很少有人走过，东面是陡峭的
山壁，山壁上零星的长着几棵小树，西面是深不见底的悬崖，
仔细一听，仿佛下面有潺潺的流水声。山路的南边有一个山洞
黑乎乎的看不清里面的景色，山路一直向北蜿蜒。
LONG
);
	set("exits",([
	"south":__DIR__"cave2",
	"north":__DIR__"mpath1",
	]) );
	setup();
	replace_program(ROOM);
}

