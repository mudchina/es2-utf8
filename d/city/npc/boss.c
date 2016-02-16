// boss.c

inherit NPC;

void create()
{
        set_name("钱掌柜", ({ "boss qian", "qian", "boss" }) );
	set("nickname", "钱千万");
        set("long",
"钱掌柜长得如一个大面团般，白白胖胖的，虽说早已步入知天命\n"
"的年龄，可保养得很好。一双小眼睛如俩枣核嵌在脸上，不时滴\n"
"溜溜地乱转。他开的「太白酒楼」可是京城最大的。\n"
	);

        set("age", 53);
        set("attitude", "peaceful");
        set("combat_exp", 1000);
        set("inquiry", ([
                "name": "在下姓钱，因少有资产，别人叫我钱千万。\n",
                "太白酒楼": "这里就是，客倌是第一次来吗？\n",
		"皇上": "小声点。偷偷地告述你，我真见过皇上的。\n",
		"作官": "瞧见没有，上面的人才是你应去打听的。\n"
        ]) );
        setup();
        add_money("gold", 1);
        carry_object("/obj/cloth")->wear();
}


void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
	        }
}

void greeting (object ob)
{
	if( !ob || environment(ob) != environment() ) 
		return;

	if (!ob->query("rank")) 
		say ("钱千万皱了皱眉，说:这里是可不是为你们开的，吃完了快走。\n");
	    else 
		say ("钱千万堆满了笑脸引上去：哪阵香风把你迎来了。\n");
}

