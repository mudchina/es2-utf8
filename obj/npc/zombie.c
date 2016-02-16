// zombie.c

#include <ansi.h>

inherit NPC;

void do_bite();

void create()
{
        set_name("僵尸", ({ "zombie" }) );
        set("long",
                
"这是一具被人用符咒控制的僵尸，从它苍白的脸上看不出任何喜怒哀乐。\n");
        set("max_gin", 400);
        set("max_kee", 400);
        set("max_sen", 60);
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        set("str", 60);
        set("cor", 40);
        set("chat_chance", 15);
        set("chat_msg_combat", ({
                "僵尸口中发出荷荷的叫声。\n",
                "僵尸的脸上开始痉挛，一阵抽搐，发狂似地大叫。\n",
                "僵尸五指箕张，咬牙切齿，露出狰狞的笑容。\n",
                (: do_bite :),
        }) );
        set_skill("unarmed", 30);
        set_skill("dodge", 30);

        set_temp("apply/damage", 15);

        setup();
}

int is_zombie() { return 1; }

void animate(object who, int time)
{
        set("possessed", who);
        set_leader(who);
}

void dispell()
{
        object corpse;

        if( environment() ) {
                say( name() + "缓缓地倒了下来，化为一滩血水。\n");
        }

        destruct(this_object());
}

int heal_up()
{
        object master;

	if (this_object()->query("end_tag") == 1) {
		if( environment() && !is_fighting() ) {
                	call_out("dispell", 1);
                	return 1;
        		}
		}
 
        if( objectp(master = query("possessed")) 
        &&      (int)master->query("atman") > 10 ) {
                message("tell",
                        HIR + name() + 
"告诉你：我...需...要...你...的...力...量...\n" NOR,
                        master );
                master->add("atman", -10);
                master->receive_damage("gin", 1);
                ::heal_up();
                return 1;               // Always acquire power from master.
   		}
       	   else {
                call_out("dispell", 1);
                return ::heal_up();
        	} 
}

void do_bite()
{
        object *enemy;

        say( name() + "口中喷出一股中人欲呕的臭气，使你觉得头晕脑胀。\n" );
        enemy = query_enemy();
        for(int i=0; i<sizeof(enemy); i++) {
                if( !enemy[i] ) continue;
                enemy[i]->receive_damage("gin", 20);
                COMBAT_D->report_status(enemy[i], "gin");
        }
}
 
