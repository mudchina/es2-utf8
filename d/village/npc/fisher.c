// fisher.c

inherit NPC;

void create()
{
	set_name("渔夫", ({ "fisher" }) );
	set("gender", "男性" );
	set("age", 35);
       	set("long", @LONG 
一个精壮的汉子，头戴斗笠，身披蓑衣。偶尔抬头一看的眼神
中精光大盛，很有可能是江湖中人。
LONG
);
	set("combat_exp", 20000);
	set("attitude", "friendly");
        set("chat_chance", 2);
       	set("chat_msg", ({
"渔夫嘀咕着：不知这水怪又吃了几个人。\n",
       }) );

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
"有种的去杀了那水怪，打我算什么英雄？！\n",
        }) );
	set("inquiry", ([
		"桂花" : "华中理工大学的桂花树比晚月庄多多了，你知道吗？",
	]) );

	set_skill("parry", 30);
	set_skill("dodge", 70);
	set_skill("unarmed", 120);
	set_skill("throwing", 150);
       	set_skill("stormdance", 45);

        map_skill("dodge", "stormdance");
        set_skill("force", 15);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 0);

	setup();
	carry_object("/obj/cloth")->wear();

}
