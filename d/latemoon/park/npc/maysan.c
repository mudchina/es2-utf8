inherit NPC;
 
void create()
{
        set_name("美珊", ({ "maysan","may" }) );
        set("gender", "女性" );
        set("age",20);
        set("long", @TEXT
她看起来成熟中带有一些韵味。飘逸的长发
十分迷人。
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

