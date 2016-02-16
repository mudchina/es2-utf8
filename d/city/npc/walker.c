//walker.c

inherit NPC;

void create()
{
        set_name("行人", ({ "walker" }) );
	set("age", 20 + random (45));
	
        switch (random (3)) {
		case 0:
			set("gender", "女性");
			break;
		default:	
			set("gender", "男性" );
			break;
		}

        set("combat_exp", 30000);
	if (random(4) == 0) {
		set_skill("unarmed", 40);
		set_skill("spicyclaw", 20);
		set_skill("parry", 40);
		map_skill("unarmed", "spicyclaw");
		}

        set("attitude", "friendly");
        set("chat_chance", random (20));
        set("chat_msg", ({
                "行人摇了摇头，说：世事无常，只苦了我们这些老百姓。\n",
                "行人愤愤地说：这年头，几个臭钱就能买到官。哼！\n",
                "行人叹了口气：皇上太年幼了，朝廷就让那个老不死的把持着。咳！\n",
		(: random_move :),
        }) );

        set("inquiry", ([
                "买官" : (: "全是那个该死的尚书作的孽。\n" :),
	        ]) );
        setup();
}

