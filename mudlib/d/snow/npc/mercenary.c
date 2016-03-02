// mercenary.c

inherit NPC;
inherit F_MERCENARY;

void create()
{
	set_name("逄义", ({ "pangyi" }) );
	set("age", 33);
	set("race", "人类");
	set("long",
		"逄义是封山派中和柳淳风同辈的弟子，但是生性好赌的他并不受师父\n"
		"及同门师兄弟的喜爱，因此辈分虽高，却未曾担任门中任何重要职务\n"
		"。逄义经常外出，美其名曰：旅行，实则避债，碍于门规又不敢做那\n"
		"打家劫舍的勾当，因此经常四处寻找赚钱发财的机会。\n");
	set("max_force", 600);
	set("force", 1000);

	set("inquiry", ([
		"赚钱": "真的？哪里有钱赚？",
		"发财": "发财我倒不敢想，只要有人肯雇用(employment)我，手边有几百两银子就好了。",
		"employment": "是的，一天一百两银子，只要不违背侠义道，我可以做任何事。",
		"柳淳风": "柳淳风是在下同门师兄。",
		"赌": ({ (: command, "hmm" :),
				 (: command, "grin" :),
				 "阁下如果也爱好此道，不如改天兄弟陪阁下玩几手？" }),
	]) );
	create_family("封山剑派", 13, "弟子");
	set_skill("sword", 70);
	set_skill("dodge", 70);
	set_skill("unarmed", 80);
	set_skill("move", 80);
	set_skill("force", 65);
	set_skill("fonxanforce", 80);
	set_skill("fonxansword", 80);
	set_skill("chaos-steps", 70);
	set_skill("liuh-ken", 80);
	set_skill("literate", 60);
	map_skill("sword", "fonxansword");
	map_skill("unarmed", "liuh-ken");
	map_skill("dodge", "chaos-steos");
	map_skill("force", "fonxanforce");
	
	setup();

	carry_object("/obj/longsword")->wield();
	carry_object("/obj/cloth")->wear();
}

int accept_object(object me, object ob)
{
	if( query("on_duty") ) {
		command("say 对不起，在下目前已受人所雇，请过几天再来。");
		return 0;
	}
	if( (int)ob->value() < 10000 ) {
		command("say 这 ... 阁下好意在下心领就是，请回吧。");
		return 0;
	}
	command("smile");
	command("say 太好了，阁下但有吩咐，逄某定当竭力以赴！");
	command("follow " + me->query("id"));
	set("boss_id", me->query("id"));
	set("on_duty", 1);
	call_out("duty_end", ((int)ob->value() / 10000) * 1440 );
	return 1;
}

void duty_end()
{
	object home;

	delete("on_duty");
	command("tell " + query("boss_id") + " 今天就到此为止，承蒙阁下照顾，后会有期。");
	command("say 逄某告辞。");
	home = find_object(query("startroom"));
	if( home ) return_home(home);
	else destruct(this_object());
}

