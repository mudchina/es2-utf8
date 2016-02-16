inherit ROOM;

void create()
{
   set("short", "朱栏板桥");
	set("long", @LONG
走在桥上，可以远观山坡帏脉，两边飞楼插空，雕饰□栏，隐
于亭园树木之间；俯而视之，则清流泻雪石磴穿云。朱红玉石为栏
，环抱池沿，柳垂金线，桃吐丹霞。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "south" :__DIR__"moon4",
       "northwest" :__DIR__"moon1",

]));

	setup();
	replace_program(ROOM);
}
