// monk.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("独眼头陀", ({ "one-eyed monk", "monk" }) );
	set("gender", "男性" );
	set("class", "bonze");
	set("age", 46);
	set("str", 26);
	set("cor", 24);
	set("cps", 12);
	set("int", 20);
	set("long",
		"瞧这个头陀的模样与服色，似乎不是山烟寺的僧人，但是他大喇喇地站在\n"
		"这里，一副不可一世的样子。\n" );

	set("combat_exp", 60000);
    set("attitude", "heroism");
	set("pursuer", 1);

	set("max_force", 1700);
	set("force", 1700);
	set("force_factor", 3);

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: random_move :),
		(: command, "hehe" :)
	}) );

	set_skill("force", 90);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("blade", 80);
	set_skill("lotusforce", 90);
	set_skill("move", 60);

	map_skill("force", "lotusforce");

	set_temp("apply/attack", 60);
	set_temp("aplpy/defense", 60);
	set_temp("apply/dodge", 70);

	setup();

	carry_object(__DIR__"obj/blade")->wield();
	carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/eye_patch")->wear();
	carry_object(__DIR__"obj/shoe")->wear();
}

