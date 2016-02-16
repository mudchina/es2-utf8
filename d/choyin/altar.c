// Room: /d/choyin/altar.c

inherit ROOM;

void create()
{
	set("short", "火龙将军庙");
	set("long", @LONG
这里就是奉祀火龙将军的大殿，火龙将军高大威武的神像(statue)
就立在你的面前，旁边还有火龙将军的部属虎豹熊鹰四位将军，你现在
所站的地方是横过街道而建的一个高台，隔著栏杆可以看见下面的街道
川流不息的人群，南北各有一道阶梯往下回到街道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"dragon_temple",
]));
	set("no_fight", "1");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"obj/denotation" : 1,
		__DIR__"npc/lady" : 1,
]));
	set("no_clean_up", 0);
	set("no_magic", "1");
	set("valid_startroom", "1");

	setup();
	replace_program(ROOM);
}
