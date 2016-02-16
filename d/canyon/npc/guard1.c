// shiao.c

inherit NPC;

void create()
{
	set_name("小兵", ({ "guard" }) );
	set("gender", "男性");
	set("age", 24);
	set("long",
        	"风沙满面，无精打采，毫无生气的样子，真难以想像是这\n"
                "□的守军。\n");

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 24);

	set("combat_exp", 40000);
	
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 5);
	
	set_skill("unarmed", 40);
	set_skill("parry", 60);
	set_skill("dodge", 50);

	setup();

}
