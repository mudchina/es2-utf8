// Room: /d/canyon/canyon7.c

inherit ROOM;

void create()
{
	set("short", "天驼关谷地");
	set("long", @LONG
天驼关两边是悬崖，中间是谷地，形状很象骆驼的双峰，由此得名。
这里地势险峻，南下通往京师，北上除了“关外绿洲”雪亭镇外就是异族
的领地了，历来是兵家必争之地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : "/d/village/road1",
  		"north" : __DIR__"canyon6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
