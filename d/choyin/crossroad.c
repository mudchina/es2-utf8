// Room: /d/choyin/crossroad.c

inherit ROOM;

void create()
{
	set("short", "十字路口");
	set("long", @LONG
这里是昌平街跟承安街的交叉路口，往南就是乔阴县城的南门，往
北不远处则是衙门的所在地，乔阴县到了这里显得格外安静，路人大多
沈默地走著，不敢大声喧哗，和城东的花花世界相比，这里显得宁静许
多。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"s_gate",
		"north" : __DIR__"court1",
		"east" : __DIR__"s_street5",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
