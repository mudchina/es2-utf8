// Room: /u/q/quit/ftp/gee_room.c

inherit ROOM;

void create()
{
	set("short", "游侠同盟总堂");
	set("long", @LONG
这是一间宽敞的大厅，高高的穹窿下面的摆设庄严而朴直。中间一张古色
古香的圆桌，围著圈细腰高背椅。你对面的墙上挂著一幅对联(couplet) 。
桌上摆著一个颇大的天平(Balance) ，似乎是个泊来品。西边有一扇大铁门
开了门往北走，就可以到乔阴县城门。
LONG
	);
	set("item_desc", ([ /* sizeof() == 2 */
		"balance" : "天平上写著:
 	曲曲直直, 明人不说暗话
	恩恩怨怨, 有理休怪无情
",
		"couplet" : "你看到对联上的行书苍劲有力，下笔入木三分：

	游 侠 江 湖，今 古 英 雄 义 聚
	同 盟 武 林，从 来 奸 邪 难 逃

			下联末还有一行小字：游侠同盟
					    戊申年六月二十九日申时二刻。
",
]));
	set("exits", ([ /* sizeof() == 1 */
		"west" : "/d/choyin/n_gate",
]));

	setup();
//        call_other( "/obj/board/association_b", "???" );
}
