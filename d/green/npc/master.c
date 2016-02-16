#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("龙若法王", ({ "master neon", "master", "neon" }) );

        set("gender", "男性");
        set("age", 62);
        set("long",
                "龙若法王本是释家中人，后得奇人点化，佛道双修，齐入化境，\n"
                "于二十九年前创下绝尘一派。\n");
        set("attitude", "peaceful");

        set("str", 21);
        set("int", 30);
        set("spi", 30);
        set("per", 22);
        set("cps", 30);
	set("cor", 23);
	set("con", 21);

        set("force", 3000);
        set("max_force", 2000);
        set("force_factor", 5);

        set("atman", 3000);
        set("max_atman", 2000);

        set("max_mana", 4000);
	set("mana", 2000);
        set("mana_factor", 5);

        set("combat_exp", 3000000);
        set("score", 200000);

//        set("chat_chance_combat", 30);
//        set("chat_msg_combat", ({
//                (: exert_function, "chillgaze" :),
//        }) );

        set_skill("unarmed", 80);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 120);
        set_skill("perception", 100);
        set_skill("spells", 150);
	set_skill("magic", 150);
	set_skill("staff",100);
	set_skill("tao-mystery",100);

	set_skill("magic-array",100);
        set_skill("jingang-staff",120);
	set_skill("wu-shun",120);

        map_skill("force", "wu-shun");
        map_skill("staff", "jingang-staff");
	map_skill("spells",magic-array);

        create_family("绝尘派", 0, "法师");

        setup();

}

