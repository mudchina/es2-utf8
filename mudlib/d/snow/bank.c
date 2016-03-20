// bank.c

inherit BANK;

void create()
{
	set("short", "安记钱庄");
	set("long", @LONG
这是一间素来以公平信用著称的钱庄，钱庄的老板还是个曾经中过
举人的读书人，你可以看到钱庄里里外外都打扫得乾乾净净，一个胖胖
的中年人坐在柜台后面，柜台上放著一块牌子(sign)，往东是通往雪亭
镇大街的大门。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"mstreet1",
]));

	set("objects", ([
 		__DIR__"npc/annihir" : 1 ]) );

	set("item_desc", ([
		"sign": @TEXT
这里是钱庄，目前我们提供的服务有：
兑换(convert)钱币。

TEXT
	]) );
//    set("no_fight", 1);
//    set("no_magic", 1);
	setup();
}
