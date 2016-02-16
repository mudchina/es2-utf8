// Room: /d/choyin/dragon_temple.c

inherit ROOM;

void create()
{
	set("short", "火龙将军庙");
	set("long", @LONG
这里是乔阴县城香火最盛的火龙将军庙，火龙将军据说就是两百年
前率领官兵和杀死树王的骷髅妖怪作战的黎方黎将军，这里就是当年火
龙将军驻兵扎营之处，如果你想知道火龙将军的事迹，不妨问问附近的
年长的居民，将军庙的建筑十分奇特，一条道路东西贯通庙的中央，而
火龙将军的神像立在横跨道路的一个高台上，往来的行人都从火龙将军
的脚底走过，要上香的信徒必须从南北两边的阶梯爬上高台。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"up" : __DIR__"altar",
		"west" : __DIR__"s_gate",
		"east" : __DIR__"sw_road1",
	]));

	set("objects", ([
		__DIR__"npc/crone" : 1
	]) );

	set("no_fight", "1");
	set("no_magic", "1");

	setup();
	replace_program(ROOM);
}
