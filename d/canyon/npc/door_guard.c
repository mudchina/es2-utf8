// door_guard.c

inherit NPC;

void create()
{
	set_name("小兵", ({ "guard" }) );
	set("gender", "男性");
	set("age", 24);
	set("long",
        	"他看起来有点精悍，手中紧握著刀，惊惊颤颤的样子。\n");

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 24);

	set("combat_exp", 60000);
	
	set("force", 600);
	set("max_force", 600);
	set("force_factor", 5);
	
	set_skill("blade", 50);
	set_skill("unarmed", 40);
	set_skill("parry", 60);
	set_skill("dodge", 50);

	setup();

	carry_object( __DIR__"obj/blade")->wield();
}
