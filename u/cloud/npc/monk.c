// monk.c

inherit NPC;

void create()
{
	set_name("化缘和尚", ({ "monk" }) );
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
    这和尚是从南边山烟寺来的，寺院常在此化缘施斋。
LONG
);
	set("attitude", "friendly");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"和尚道：我佛慈悲，望住持不会怪罪我。\n"
	}) );
	set("inquiry", ([
		"山烟寺": "贫僧即是山烟寺来的，从此南行便是。",
	]) );

        set("atman", 1000);
        set("max_atman", 1000);

        set("force", 500);
        set("max_force", 500);
        set("force_factor", 2);

        set("mana", 100);
        set("max_mana", 100);

        set("combat_exp", 10000);
        set("score", 100);

        set_skill("staff", 60);
        set_skill("unarmed", 80);
        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("literate", 50);
        set_skill("chanting", 30);
        set_skill("parry", 60);

        set_skill("cloudstaff", 20);
        set_skill("lotusforce", 20);

        map_skill("parry", "cloudstaff");
        map_skill("force", "lotusforce");

	setup();

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

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "和尚说道：这位" + RANK_D->query_respect(ob)
                + "，捐点香火钱吧。\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("本寺不收物品的捐献。\n");
        else if( val > 100 ) {
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", - 
(random((int)who->query("kar")) + val/1000) );
        }
        say( "和尚说道：多谢这位" + RANK_D->query_respect(who)
                + "，佛祖一定会保佑你的。\n");

        return 1;
}

