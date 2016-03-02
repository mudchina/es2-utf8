// shadow.c

inherit NPC;

void create()
{
	set_name("朦胧鬼影", ({ "shadow" }) );
	set("long",
		"一个高大的身影，看起来像是个人，不过 ....\n");
	set("age", 91);
	
	set("str", 44);
	set("cor", 37);
	set("max_gin", 400);
	set("max_kee", 600);
	set("max_sen", 400);

	set("combat_exp", 200000);

	set("attitude", "aggressive");

	set_temp("apply/attack", 80);
	set_temp("apply/blade", 80);
	set_temp("apply/parry", 80);
	set_temp("apply/armor", 70);
	set_temp("apply/damage", 30);
	set_temp("apply/dodge", 70);
	set_temp("apply/armor_vs_force", 1000);

	setup();

	carry_object(__DIR__"obj/blade")->wield();
}

int is_ghost() { return 1; }
