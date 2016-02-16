// master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("柳淳风", ({ "master swordsman", "swordsman", "master" }) );
	set("nickname", "风雨双侠");
	set("gender", "男性" );
	set("age", 44);
	set("str", 27);
	set("cor", 30);
	set("cps", 27);
	set("int", 24);

	set("max_force", 1200);
	set("force", 1200);

	set("long",
		"柳淳风是个相当高大的中年儒生，若不是从他腰间挂著的「玄苏剑」你\n"
		"大概猜不到眼前这个温文儒雅的中年人竟是家大武馆的馆主。\n");

	create_family("封山剑派", 13, "掌门人");

	set("combat_exp", 1000000);
	set("score", 200000);

	set_skill("unarmed", 40);
	set_skill("parry", 100);
	set_skill("dodge", 80);
	set_skill("sword", 100);
	set_skill("force", 40);
	set_skill("literate", 60);

	set_skill("fonxanforce", 60);
	set_skill("fonxansword", 100);
	set_skill("liuh-ken", 60);
	set_skill("chaos-steps", 100);
	set_skill("spider-array", 85);

	map_skill("unarmed", "liuh-ken");
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");
	map_skill("dodge", "chaos-steps");

	set("inquiry", ([
		"淳风武馆" : "淳风武馆是先父所创，在下辱承其名，虽忝掌封山门户，不敢忘了先人遗志。",
		"先人遗志" : "先父临终之时将这武馆交到在下手中，需得好好照看。",
		"刘安禄" : "刘兄弟在寒舍管事已经五年了，过去之事不须再提。"
	]) );

	setup();
	carry_object(__DIR__"blackthorn")->wield();
	carry_object(__DIR__"silk_cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if( ((int)ob->query("cor") < 20) 
	||	((int)ob->query("cps") < 20)) {
		command("say 学剑之人必须胆大心细，依我看" + RANK_D->query_respect(ob) + "的资质似乎不宜？");
		return;
	}
	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
	command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "swordsman");
}
