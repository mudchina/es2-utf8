#include <ansi.h>

inherit NPC;
inherit F_SAVE;

void create()
{
        set_name( "老者", ({ "old man", "man", "old" }) );
        if( !restore() ) {
                set("short", "在桐柏山中采药的" HIC "老者" NOR "(old man)");
                set("long",
                        "他白发苍苍,老态龙钟.\n"
                        "他终年采药于深山，当有些不同凡响之处。\n"
                        "他宽五尺，高三尺.你实在无法理解他怎么这么的胖。\n" );
                set("gender", "男性" );
                set("chat_chance", 70);
                set("chat_msg", ({
                        (: this_object(), "random_move" :),
                        CYN "老者说道：哎。。。你这可怜的孩子，饿得面黄肌瘦的。\n" NOR,
                        CYN "老者抚摸着你的头，老泪纵横。\n" NOR,
                        CYN "老者拈起衣角擦了擦眼角的浊泪。\n" NOR,
               }) );
                set("chat_msg_coombat", ({
                        CYN "\n老者说道：山药蛋!!我们爱吃!!!!!!\n" NOR,
                        CYN "\n老者说道：你这孩子长得多象山药蛋啊。\n" NOR,
                }) );

                set("pills", 9);

                // This is the initial apply for his race.
                set("perm_apply", ([
                        "attack":       10,
                        "dodge":        10,
                        "damage":       5,
                ]) );

                set("age", 99);
                set("str", 44);
                set("cor", 24);
                set("cps", 18);
                set("per", 24);
                set("int", 42);
                set_skill("unarmed", 1);
                set_skill("dodge", 150);
                set_skill("force", 1);
                set_skill("parry", 1);
        }

        set_temp("apply", query("perm_apply"));
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}
void greeting(object ob)
{   string item;  
    object foods;
 
 item = "tomatoo";  

 if( !ob || environment(ob)!=environment() ) return;   
 else if( objectp(foods = present(item, ob)) )  {
                tell_object(ob, "我给你的山药蛋好吃吗??\n" NOR );
        }  else  {
                  command("sigh");
                  message_vision("老者抚摸着$N的头，老泪纵横。\n 说道: " +
          "说道：哎。。。$N这可怜的孩子，饿得面黄肌瘦的。\n" +
          "老者哆哆嗦嗦从怀里拿出个小布包，打开一层又一层，打开一层又一层.." +
          "最后拿出个小山药蛋塞到$N手里。\n",ob);   
                foods = new("/d/choyin/npc/obj/tomatoo");
                foods->move(ob);
                ob->set_temp("choyin/山药蛋", 1);
                  }
 return;              
}        




void reset()
{
        int learn;

   
        set("pills", 9);
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
set("short", "桐柏山妖  山药蛋(yam)"); 
        if( is_fighting() ) {
                if( random(query("eff_kee")) > (int)query("kee") ) {
                        say( CYN "老者颤声道：我这一把年纪，哎！老者气得几乎晕倒在地。\n" NOR);
                        return 0;
                } else {
                        say( CYN "老者正色道：我得管教管教你！！\n" NOR);
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
                say( CYN "老者捂著受伤的地方，白发散乱，勉强稳住身行。\n" NOR);
                if( random(query("kee")) < damage)
                        random_move();
        }

        if( (int)query("pills")
        &&      (((int)query("kee")) < 20
                || ((int)query("gin") < 20)
                || ((int)query("sen") < 20) )) {
                say( HIY "老者从口袋摸出一粒象小山药蛋的仙豆吞了下去。\n
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
{   object me;
        me=this_player();      
        set("short", "桐柏山妖  山药蛋(yam)"); 

        message_vision("采药老者眼放异光，说道：你真的不喜欢山药蛋吗??\n\n"
+ "沉吟半响道：既然如此，老头子今天豁出去了，纳命来！\n" + "山药蛋双手一招，一团黑雾涌起......\n",me);
        message_vision("只听见「砰」地一声，$N像一捆稻草般飞了出去！！\n",me);
        message_vision("$N死了。\n\n",me);
        message_vision(HIW"鬼门关 \n",me);
        message_vision("    这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座高大的\n",me);
        message_vision("黑色城楼，许多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无法再\n",me);
        message_vision("回阳间了。\n",me);
        message_vision("    这里明显的出口是 north 和 south。\n",me);
        message_vision("黑无常(black gargoyle)\n",me);
        message_vision("黑无常发出一阵像呻吟的声音，当他发现你正注视著他的时候，瞪了你一眼。\n",me);
        message_vision("黑无常说道：喂！新来的，你叫什么名字？ \n\n",me);
        message_vision("黑无常「哼」的一声，从袖中掏出一本像帐册的东西翻看著。\n\n",me);
        message_vision("黑无常阁上册子，说道：咦？阳寿未尽？怎么可能？\n\n",me);
        message_vision("黑无常搔了搔头，叹道：罢了罢了，你走吧。\n\n",me);
        message_vision("一股阴冷的浓雾突然出现，很快地包围了你。\n\n",me);
        message_vision("$N觉得有什么地方不对了，使劲掐了一下自己，＄N惨叫了一声:哇，好痛啊～～～～～～\n",me);
        message_vision("$N出窍的真魂绕了一大圈，终于归位了。\n",me);
        message_vision("黑雾慢慢消散了\n",me);
        message_vision("山药蛋就地一滚，没入土中不见了......\n"NOR,me);
        destruct(this_object());                   
        return 0;


}
void defeated_enemy(object ob)
{       command("fear"); 
        say(CYN "老者骨碌碌就地打了个滚，说道：我赢了！" NOR);
        remove_killer(ob);
}      



