inherit ROOM;

void create()
{
   set("short", "甬路");
	set("long", @LONG
你走在石子墁的花园甬路上，只见两边翠竹夹路，土地下苍苔
布满，往东北你看到凤尾森森，龙吟细细，通往暖香榭。南面则是
一个小门。西方通往园中小桥。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "northwest" :__DIR__"bridge2",
       "northeast" :__DIR__"moon4",
       "south" :__DIR__"moondoor",

]));

	setup();
	replace_program(ROOM);
}
