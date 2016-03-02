inherit NPC;
 
void create()
{
	object ob;

    set_name("蓝雨梅", ({ "yu-may","yumay","may" }) );
	set("gender", "女性" );
	set("age",18);
	set("long", @TEXT
蓝雨梅是晚月庄主蓝止萍的养女，由于庄主不信任男子，因此
晚月庄接待外宾的工作向来由她负责。
TEXT
);
	set("per", 30);
	set("class", "dancer");
    set("combat_exp", 60000);

	set_skill("unarmed",60);
    set_skill("throwing", 90);
    set_skill("dodge", 70);
     set_skill("stormdance" , 30);
	set_skill("force",50);
     map_skill("dodge", "stormdance");

    set("force", 2000);
	set("max_force", 500);
	set("force_factor",2);

	set("chat_chance", 7);
	set("chat_msg", ({
        "蓝雨梅微笑著说道：我们晚月庄是『 以舞会友，以神换技 』\n",
        "蓝雨梅看你一脸疑惑！笑著说：我教你跳一曲『西出阳关』好吗?\n",
		"蓝雨梅微笑著说道：我跳支舞给您看好不好？\n",
        "蓝雨梅微笑著说道：我的舞跳得不好，待会儿我请芳绫跳舞给您看，别走远喔。\n"
	}) );
	set("inquiry", ([
		"西出阳关" : "『西出阳关』是一种幻影式舞步。可以移形换影。\n",
        "学舞" : "来!我教你...『西出阳关』(dancing out)是 ..... \n" +
               "经过雨梅指导后你渐渐懂了! \n",
		"舞" : "我会的舞是属于「幻影式舞步」。\n",
		"芳绫" : "她是个可爱的女孩。不过有点任性，听说她贪玩被关在 \n"+
                  "禁闭室。听说她爱玩竹蜻蜓哦。\n",
		"竹蜻蜓" : "庄内有人会用竹子作成不同物品。\n",
        "沧海龙吟" : "是一种失传以久的「寒谷龙舞」\n",
	]));
	create_family("晚月庄", 3, "大弟子");

	setup();
	ob = carry_object(__DIR__"obj/needle");
	ob->set_amount(30);
    ob->wield();
	carry_object(__DIR__"obj/deer_boot")->wear();
	carry_object(__DIR__"obj/skirt3")->wear();
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
void greeting(object ob)
{
    object teacup;
	if( !ob || environment(ob)!=environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "雨梅对你微笑，和善的对你说：\n  这位" + 
				RANK_D->query_respect(ob)
				+ "，你好！欢迎来到晚月庄。请坐！\n");
			break;
		case 1:
            {
			say( "雨梅对你微笑，纤细的双手捧著茶，\n 说道：这位" +
				RANK_D->query_respect(ob)
				+ "，你好！欢迎来到晚月庄。请用茶！\n");
             if ( ob->query_temp("latemoon/茶") ) 
                 command("smile");
                 else  {
                teacup = new("/d/latemoon/obj/teacup");
                teacup->move(ob);
                ob->set_temp("latemoon/茶", 1);
                say ("这是上等金轩茶!您品尝一下。\n");
                   }
            }
		}
}
