// jiading , added by kindman

inherit NPC;	

void create()
{
        set_name("家丁", ({ "jiading" }) );
        set("title", "张府家丁");
        set("gender", "男性" );	 
        set("age", 35);
	set("long", 
		"张府的家丁的俸禄极高，当然能在张府做事武功也不弱\n");

	set("combat_exp", 40000);
	set_skill("dodge", 70);
	set_skill("parry", 90);
	set_skill("blade", 70);
	set_skill("spring-blade", 40);

	map_skill("blade", "spring-blade");

	setup();
	carry_object("/obj/weapon/blade")->wield();    
}


