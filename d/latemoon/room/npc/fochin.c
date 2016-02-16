inherit NPC;
 
void create()
{
        set_name("曲馥琪", ({ "fochin","chin" }) );
        set("gender", "女性" );
        set("age", 27);
        set("long", @TEXT
她国色天香，娇丽无伦；温柔娴静，秀绝人寰。
她姿容绝美，世所罕见。从她身旁你闻道一寒谷
幽香。
TEXT
);
       set("class", "dancer");
       set("combat_exp", 99000);
        set_skill("unarmed", 50);
        set_skill("dodge", 70);
        set_skill("stormdance", 50);
        set_skill("tenderzhi", 70);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 1000);
        set("max_force", 500);
       set_temp("apply/armor", 70);

        create_family("晚月庄",2,"弟子");
        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/belt")->wear();
        carry_object("/d/latemoon/obj/clasp")->wear();
        carry_object(__DIR__"obj/fire");
}

