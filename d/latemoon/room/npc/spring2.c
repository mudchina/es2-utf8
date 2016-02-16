inherit NPC;
 
void create()
{
        set_name("圆春", ({ "yuan chung","yuan","chung" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她是惜春的妹妹，跟姐姐从小就在晚月庄
长大。因为与双亲失散，被庄主收留。平
常帮忙庄内琐碎事务。
TEXT
);
       set("class", "dancer");
       set("combat_exp", 5000);
        set_skill("unarmed", 25);
        set_skill("dodge", 25);
        set_skill("stormdance", 5);
        set_skill("tenderzhi", 5);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 300);
        set("max_force", 300);

       create_family("晚月庄",4,"弟子");
        setup();
        carry_object("/d/latemoon/obj/skirt5")->wear();
}

