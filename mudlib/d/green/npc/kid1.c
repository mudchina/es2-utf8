// kid1.c
inherit NPC;
void create()
{
	seteuid(getuid());
        set_name("工匠的小孩",({"kid","child"}));
        set("gender","男性");
        set("age",7);
        set("str",25);
        set("con",20);
        set("combat_exp",10);
        set("score",50);
        set_temp("apply/dodge",5);
        add_money("coin",5);
        setup();
	carry_object("/obj/cloth")->wear();
}
