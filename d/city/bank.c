// bank.c

inherit BANK;

void create()
{
	set("short", "旺金钱庄");
	set("long", @LONG
这是一间素来不讲信用的钱庄，钱庄的老板倒是读过几年书，脑筋
很活络，你可以看到钱庄里里外外都打扫得乾乾净净，一个精瘦精瘦的
中年人坐在柜台后面，柜台上放著一块牌子(sign)，往南是通往京城街
道的大门。
LONG
	);
	set("exits", ([ 
  "south" : "/d/city/street8",
]));

	set("objects", ([
 		"/d/city/npc/microsof" : 1 ]) );






	set("item_desc", ([
		"sign": @TEXT
我们提供的服务有：

convert     兑换钱币，自点数目，出门后发现少钱概不负责。

TEXT
	]) );
    set("no_fight", 1);
    set("no_magic", 1);
	setup();
}
