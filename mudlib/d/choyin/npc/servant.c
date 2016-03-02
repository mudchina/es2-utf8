// acrobat.c

inherit NPC;

void create()
{
	set_name("家丁", ({ "servant" }) );
	set("long", "一个穿著家人服色的男子，必恭必敬地垂手站在一旁。\n");
	set("age", 32);
	set("attitude", "peaceful");
	set("combat_exp", 500);
	set("env/wimpy", 30);
	set("str", 23);
	set("cor", 17);
	set("cps", 22);
	set_skill("dodge", 10);
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	setup();
	carry_object("/obj/cloth")->wear();
}

