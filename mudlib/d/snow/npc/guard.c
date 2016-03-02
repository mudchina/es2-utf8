// guard.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("刘安禄", ({ "liu anru", "liu" }) );
	set("title", "门房");
	set("gender", "男性" );
	set("age", 26);
	set("str", 29);
	set("cor", 30);
	set("cps", 30);
	set("int", 11);
	set("long",
		"刘安禄是淳风武馆的门房，除了馆主柳淳风没有人知道他的出身来历，只知\n"
		"到他的武艺不弱，一手快刀在这一带罕有敌手。\n" );
	set("combat_exp", 20000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"刘安禄说道：你当这里是什么地方，敢来这里撒野？\n",
		"刘安禄说道：想我堂堂....呃....连我这个淳风武馆的小小的门房都可以收拾你！\n",
		"刘安录忽然挥出一刀，招数精奇，但是刀到中途忽然像是想起什么，急忙收招。\n",
		"刘安禄说道：你快走吧，就算我输了你啦....\n"
	}) );
	set("inquiry", ([
		"刘老三": (: ask_me :),
		"血手刘三": (: ask_me :)
	]) );

	set_skill("blade", 40);
	set_skill("parry", 40);
	
	setup();
	
	carry_object(__DIR__"obj/blade")->wield();
	carry_object("/obj/cloth")->wear();
}

string ask_me(object who)
{
	int i;
	object *ob;

	if (who->query("combat_exp") < 20000)
		return 0;

	if( query("revealed") ) {
		if( is_killing(who) ) return "你既然知道了我的身分，今日休想活命！\n";
		else {
			kill_ob(who);
			who->fight_ob(this_object());
			return "老子就是血手刘三，血手刘三就是你老子！纳命来！\n";
		}
	}

	if( random(10) < 5 )
		return "我...不知道！\n";
	set_temp("apply/attack", 70);
	set_temp("apply/dodge", 50);
	set_temp("apply/parry", 60);
	set_temp("apply/damage", 20);
	set("title", "野羊山寨二寨主");
	set("nickname", HIR "血手刘三" NOR);
	message("vision",
		HIY "刘安禄眼中突然放出异样的光芒，颤声说道：看来...你都知道了？\n\n"
		"刘安禄大喝一声，叫道：既然如此，老子今天豁出去了，纳命来！\n" NOR
		"刘安禄使开单刀，招数精奇，沈猛狠辣，和刚才简直判若两人！\n",
		environment(), this_object() );
	set("pursuer", 1);
	set("attitude", "aggressive");
	set("vendetta/authority", 1);
	set("chat_msg_combat", ({
		(: random_move :)
	}) );
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("bellicosity", 10000);
	set("combat_exp", 50000);
	ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
		if( !ob[i]->is_character() || ob[i]==this_object() ) continue;
		kill_ob(ob[i]);
		ob[i]->fight_ob(this_object());
	}
	carry_object(__DIR__"obj/blade_book");
	set("revealed", 1);
	return 0;
}

