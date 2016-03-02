#include <ansi.h>

inherit NPC;
inherit F_SAVE;

void create()
{
        set_name( "老者", ({ "old man", "man", "old" }) );
        if( !restore() ) {
                set("short", "在桐柏山中采药的" HIC "老者" NOR "(old man)");
                set("long",
                        "他白发苍苍,宽五尺，高三尺，神光内敛.\n"
                        "他终年采药于深山，当有些不同凡响之处。\n"
                        "你实在无法理解他怎么这么的胖。\n" );
                set("gender", "男性" );
                set("race", "赛亚人");
                set("chat_chance", 70);
                set("chat_msg", ({
                        (: this_object(), "random_move" :),
                        CYN "老者说道：可怜的孩子，瞧？\n" NOR,
                        CYN "老者骨碌碌打了个滚。\n" NOR,
               }) );
                set("chat_msg_coombat", ({
                        CYN "\n扮个:-)，说道：我们爱吃山药蛋.\n" NOR,
                        CYN "\n说道：这一招是爷爷教我的，厉害吧！\n" NOR,
                }) );

                // We have 7 pills per reset.
                set("pills", 7);

                // This is the initial apply for his race.
                set("perm_apply", ([
                        "attack":       10,
                        "dodge":        10,
                        "damage":       5,
                ]) );

                set("age", 9);
                set("str", 44);
                set("cor", 24);
                set("cps", 18);
                set("per", 24);
                set("int", 42);
                set_skill("unarmed", 1);
                set_skill("dodge", 1);
                set_skill("force", 1);
                set_skill("parry", 1);
        }

        set_temp("apply", query("perm_apply"));
        setup();
        carry_object(__DIR__"obj/kame_suit")->wear();
}

string query_save_file()
{
        return __DIR__"data/oldman";
}

void reset()
{
        int learn;

        // Restore the pills.
        set("pills", 7);
        if( (int)query("potential") > (int)query("learned_points") ) {
                learn = (int)query("potential") - (int)query("learned_points");
                add_temp("apply/attack", learn / 3);
                add_temp("apply/dodge", learn / 3);
                add_temp("apply/damage", learn / 3);
                add("learned_points", (learn / 3) * 3);
        }

        save();
}

int accept_fight(object who)
{
        if( is_fighting() ) {
                if( random(query("eff_kee")) > (int)query("kee") ) {
                        say( CYN "老者大叫：这么多人我打一个？不行不行，等我打
败这些人再跟你打！\n" NOR);
                        return 0;
                } else {
                        say( CYN "老者大叫：这么多人我打一个？没关系，我一定让
你们好看！\n" NOR);
                        return 1;
                }
        }
        return 1;
}

int receive_damage(string type, int pts)
{
        int damage;

        damage = ::receive_damage(type, pts);
        if( (type=="kee") && (damage > (int)query("max_kee") / 5) ) {
                say( CYN "老者捂著受伤的地方，说道：好痛啊...真有你的....\n" NOR);
                if( random(query("kee")) < damage)
                        random_move();
        }

        if( (int)query("pills")
        &&      (((int)query("kee")) < 20
                || ((int)query("gin") < 20)
                || ((int)query("sen") < 20) )) {
                say( HIY "老者从口袋摸出一粒花梨塔猫仙人给他的仙豆吞了下去。\n
" NOR);
                set("gin", query("eff_gin"));
                set("kee", query("eff_kee"));
                set("sen", query("eff_sen"));
                add("pills", -1);
        }
        return damage;
}

varargs void improve_skill(string skill, int amount, int raw)
{
        // Thus we can gain skill levels from direct fighting.
        ::improve_skill(skill, amount);
}

void revive()
{
        // This is a feature of sungoku's race. See the comic :P.
        add("combat_exp", (int)query("combat_exp") / 3 + 10);
        reset();
        ::revive();
}

void kill_ob(object ob)
{
     int i;
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 50);
        set_temp("apply/parry", 60);
        set_temp("apply/damage", 20);
        set("title", "桐柏山妖  山药蛋");
        set("nickname", HIR "好大的山药蛋" NOR);
                HIY "采药老者眼放异光，说道：你真的不喜欢山药蛋吗？
\n\n"
                "沉吟半响道：既然如此，老头子今天豁出去了，纳命来！\n" NOR
                "\n",
                environment(), this_object() );
        set("pursuer", 1);
        set("attitude", "aggressive");
        set("vendetta/authority", 1);
        set("chat_msg_combat", ({
                (: random_move :)
        }) );
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        set("bellicosity", 10000);
        set("combat_exp", 50000);
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() ) continue;
                kill_ob(ob[i]);
                ob[i]->fight_ob(this_object());
        }
//        carry_object(__DIR__"obj/tomatoo");
        set("revealed", 1);
        return 0;


}
void defeated_enemy(object ob)
{
        say(CYN "老者作出一个 V 字型的手势，说道：我赢了！" NOR);
        remove_killer(ob);
}      








