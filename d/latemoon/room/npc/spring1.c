inherit NPC;
 
void create()
{
        set_name("惜春", ({ "shi-chung","shi","chung" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她看起来成熟中带有一些稚气。飘逸的长发
十分迷人。她是个孤儿，从小与妹妹圆春被
庄主收留，她很聪明，在第四代弟子中算是
武功很出色的一个。
TEXT
);
       set("class", "dancer");
       set("combat_exp", 5000);
        set_skill("unarmed",40);
        set_skill("dodge", 40);
        set_skill("stormdance", 5);
        set_skill("tenderzhi", 10);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 300);
        set("max_force", 300);

       create_family("晚月庄",4,"弟子");
        setup();
        carry_object("/d/latemoon/obj/flower_boot")->wear();
}

