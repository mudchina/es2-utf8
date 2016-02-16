// Room: /d/snow/postoffice.c

inherit ROOM;

void create()
{
	set("short", "雪亭驿");
	set("long", @LONG
这里是负责雪亭镇官府文书跟军令往来的雪亭驿，但是因为出了雪
亭镇往北的野羊山近年来有盗匪盘据，官府的信差最近都改走东边的飞
鸢栈道，所以雪亭驿来往的人就少了，驿站的官员索性就开始接一些百
姓的信件，一方面打发时间，一方面也有点事做以免被上级裁撤。驿站
大门口上悬著一块木牌(sign)，上面写了些字。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "牌子上写道：
    奉乔阴府知县令喻，本驿著日起收发事宜扩及官员百姓上下人
等通办，官员及兵部该管军士、官府衙役免费，一般良民百姓书信
收费每通十文，收信免费，物品收费依份量大小另计，贵重细软倘
有遗失退费加五成赔偿，不得异议。
",
]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"mstreet4",
	]));
	set("objects", ([
		__DIR__"npc/post_officer": 5, 
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "你将信箱交回驿站。\n");
		destruct(mbox);
	}
	return 1;
}
