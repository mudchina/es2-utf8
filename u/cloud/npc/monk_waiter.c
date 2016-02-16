// monk_waiter.c

inherit NPC;

void create()
{
	set_name("知客僧", ({ "monk waiter", "waiter" }) );
	set("gender", "男性" );
	set("age", 46);
	set("str", 29);
	set("cor", 26);
	set("cps", 29);
	set("int", 22);
	set("per", 18);
	set("spi", 23);
	set("kar", 25);
	set("con", 27);
	set("long", @LONG
    知客僧伫立在佛像前，那虚闭的双眼中似乎透出一道仁慈而有力的
光芒。
LONG
);
	set("attitude", "friendly");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"知客僧说道：佛门清净，施主还是放下屠刀吧！\n",
		"知客僧说道：趁住持不在此，施主还是速速离开的好！\n",
		"知客僧招数出到一半又收回，似乎有些疑虑。\n",
		"知客僧说道：我佛慈悲，愿施主手下留情。\n"
	}) );
	set("inquiry", ([
		"山烟寺": "这里就是山烟寺，施主有何贵干?",
	]) );

        set("atman", 1000);
        set("max_atman", 1000);

        set("force", 800);
        set("max_force", 800);
        set("force_factor", 3);

        set("mana", 200);
        set("max_mana", 200);

        set("combat_exp", 10000);
        set("score", 1000);

        set_skill("staff", 60);
        set_skill("unarmed", 80);
        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("literate", 50);
        set_skill("chanting", 30);
        set_skill("parry", 60);
        set_skill("magic", 30);

        set_skill("cloudstaff", 20);
        set_skill("lotusforce", 20);
        set_skill("buddhism", 20);
        set_skill("essencemagic", 20);

        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        map_skill("force", "lotusforce");
        map_skill("magic", "essencemagic");

	setup();

//	carry_object("/u/cloud/obj/npc/monk/stick")->wield();
        carry_object("/u/cloud/obj/npc/monk/jiasha")->wear();
}

int accept_fight(object me)
{
        if( (string)me->query("class")=="bonze" )
                command("say 阿弥陀佛！出家人戒逞强恶斗！贫僧不敢违反清规。");
        else
                command("say 施主既然身负绝艺，贫僧佩服便是，也不必较量了。");
	return 0;
}

