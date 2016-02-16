// 7-19-96 /d/village/npc/woman1.c

inherit NPC;

void wield_weapon();
void converse_one();

void create()
{
//	seteuid(geteuid());
        set_name("农妇",({"woman"}));
        set("gender","女性");
        set("age",30);
       
	set("chat_chance",20);
	set("chat_msg", ({
		"农妇道：我可怜的儿啊，你到那里去了？\n",
		"农妇道：你有见到我的儿吗？，他头上梳着两个小抓揪，只有七岁。\n",
	"农妇叹道：儿啊！\n",
	}) ); 
	set("inquiry",([
		"儿":"我的儿前两天不见了，我和他爹到处找都找不到。听说黑松山总抓小孩子。\n",
	]) );
	
	set("combat_exp",(20+random(40)));
        set_temp("apply/dodge",(10+random(5)));
        add_money("coin",90);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: wield_weapon :),
        (: converse_one :) }) );
        
	setup();
        carry_object("/obj/cloth")->wear();
        //carry_object(__DIR__"obj/ricewine");
        carry_object(__DIR__"obj/knife");
}

void wield_weapon()
{
    if (!query_temp("weapon")) {
        command("say 没见识过我的菜刀神功\是吧, 接招!");
        command("wield knife");
        set("chat_chance_combat", 10);
    }
        return;
}

void converse_one()
{
    object ob;
    ob = this_player();
    if ((int)ob->query("age") < (int)query("age")) {
        command("say 唉，我那可怜的儿啊，年龄比你还小。!");
        command("slap "+(string)ob->query("id"));
    }
    else
        command("say 以大欺小啊你...");
    return;
}

