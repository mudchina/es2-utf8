inherit NPC;

void create()
{
     set_name("明心", ({"ming-shin","ming","shin"}) );
     set("gender", "男性");
     set("age", 24);
     set("class", "taoist");
     set("title", "茅山派第七代弟子");
set("long", "一位身材魁武的年轻道士, 他正在练拳, 你看他舞得虎虎生风\n");
     set("attitude", "heroism");
     set("combat_exp",5000);

     set("str",30);
     set("con",30);
 
     set("max_force",300);
     set("force",300);
     set("force_factor",4);
     set("max_mana",450);
     set("mana",450);
     set("max_atman", 250);
     set("atman", 250);
     
     set_skill("unarmed", 20);
     set_skill("dodge", 20);
     set_skill("force", 25);
     set_skill("parry", 20);
     set_skill("gouyee", 30);
     set_skill("spells", 25);
     set_skill("necromancy", 28);
     set_skill("magic", 27);
     set_skill("taoism", 30);
     
     map_skill("force", "gouyee");
     map_skill("spells", "necromancy");
     map_skill("magic", "taoism");

     setup();

     carry_object(__DIR__"obj/robe")->wear();
     carry_object(__DIR__"obj/hat")->wear();
     carry_object(__DIR__"obj/boots")->wear();
}
