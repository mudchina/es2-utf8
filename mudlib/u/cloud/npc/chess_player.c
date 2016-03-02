// chess_player.c

inherit NPC;

string play_chess();

void create()
{
        set_name("弈者", ({ "chess player", "player" }) );
        set("gender", "男性" );
        set("age", 43);
        set("long", "一位十分文气的男子，装束象个雅儒。\n");
	set("str", 12);
	set("int", 28);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("dodge", 80);
	set_skill("throwing", 30);

        set("inquiry", ([
		"下棋" : (: play_chess :),
        ]) );

	setup();
	add_money("coin", 50);
        carry_object("/obj/cloth")->wear();
//	for(int i=1; i<=100; i++){
		carry_object("/u/cloud/obj/npc/chess_player/chess")->wield();
//	}
}

string	play_chess()
{
        command("say 要比试一盘？好啊！");
	if(random(100)<50)
	{
		command("say 好棋技！佩服。无以为报，就给您两枚棋子防身吧！");
		printf("%s", name(this_player()) );
		command( "give chess to " + name(this_player()) );
		return "0";
	}
	else
		command("say 承让承让！");
	return "1";
}

