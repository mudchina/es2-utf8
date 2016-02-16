inherit NPC;
 
void create()
{
        set_name("袭人", ({ "Shi Ren", "shi ren","shi" }) );
        set("gender", "女性" );
        set("age",28);
        set("long", @TEXT
她有著春花般的脸儿，青山似的眉黛，灵活如秋波的眼睛，
高低适宜如玉□的鼻子，珊珊似的小口。她的特点就是清秀
大方，如花中之牡丹，鸟中之鸾凤。
TEXT
);
       set("class", "dancer");
       set("combat_exp", 2000);
        set_skill("unarmed", 10);
        set_skill("dodge", 40);
        set_skill("force", 40);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 2);

        create_family("晚月庄",4,"弟子");
        setup();
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/belt")->wear();
        carry_object(__DIR__"obj/skirt4")->wear();
}

