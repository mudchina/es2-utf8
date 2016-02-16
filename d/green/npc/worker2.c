inherit NPC;
void create()
{
	seteuid(getuid());
        set_name("采石工",({"worker"}));
        set("gender","男性");
        set("age",(random(10)+32));
        set("str",30);
        set("con",20);
        set("combat_exp",(100+random(40)));
        set_temp("apply/dodge",(10+random(5)));
        add_money("coin",50);
        setup();
	carry_object("/obj/cloth")->wear();
	if (random(50) > 40)
	carry_object("/d/green/obj/hammer")->wield();
	else
	carry_object("/d/green/obj/rope");
}
