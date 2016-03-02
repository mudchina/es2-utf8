// leader.c

inherit NPC;

void create()
{
	set_name("小队长", ({ "leader" }));
	set("gender", "男性");
	set("age", 30);
	set("long",
        	"不苟言笑的样子，带领著小兵驻守隘口的小队长。\n");

	set("attitude", "peaceful");

	set("str", 27);
	set("int", 25);

	set("combat_exp", 80000);
	
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 5);

	set_skill("dodge", 60);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("unarmed", 65);
	
	setup();

	carry_object( __DIR__"obj/sword")->wield();
}

		
