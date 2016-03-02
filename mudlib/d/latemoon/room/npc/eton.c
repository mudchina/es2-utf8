inherit NPC;
 
void create()
{
        set_name("金仪彤", ({ "eton","zhin" }) );
        set("gender", "女性" );
        set("age", 27);
        set("long", @TEXT
她国色天香，娇丽无伦；温柔娴静，秀绝人寰。
可惜眉心上有一道地煞纹干犯紫斗，恐要玉手
染血，浩劫武林。
TEXT
);
       set("class", "dancer");
       set("combat_exp", 70000);
        set_skill("unarmed", 50);
        set_skill("dodge", 40);
        set_skill("stormdance", 50);
        set_skill("tenderzhi", 50);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 1000);
        set("max_force", 500);

        create_family("晚月庄",3,"弟子");
        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/necklace");
}

