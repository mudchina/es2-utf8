// marry_card.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("婚约", ({"marrycard"}) );
        set_weight(10);
        set("no_get",1);
        set("no_drop","你的婚约不能丢弃,只能去红娘庄解除婚约。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
        }
}

void init()
{
        add_action("do_coupletalk", "coupletalk");
        add_action("do_coupletalk", "ct");
        add_action("do_cemote", "ce" );
}

int do_cemote(string arg)
{
        object *list, me;
        object couple_ob;
        string target, tmpstr1, tmpstr2,str1,str2;
        string cardname;
        int i;

        me = this_player();
        list = all_inventory(this_player());
        i = sizeof(list);
        while (i--) {
              if (((string)list[i]->query("id")) == "marrycard")
                cardname = list[i]->query("name");
        }

        if (sscanf(cardname,"你和%s的婚约" ,target)!=1)
                return notify_fail("你没有伴侣.\n");

        couple_ob = find_player(target);
        if( !couple_ob )
                return
        notify_fail("你的伴侣现在无法听见你，或者已经离开游戏了。\n");
        if ((string)couple_ob->query("gender") != "女性") {
                tmpstr1 = "老婆"; tmpstr2 = "老公";
                str1 = "她"; str2 = "他";
        } else {
                tmpstr1 = "老公"; tmpstr2 = "老婆";
                str1 = "他"; str2 = "她";
        }

        if (!arg) {
                write( MAG "你又深情的想念你的爱侣了。\n" NOR);
                tell_room(environment(me), CYN+(string)me->name()+
                "又深情的想念"+str1+"的爱侣"+ (string)couple_ob->name()+
                "了。\n" +NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(MAG "%s %s 
                又在深情的想你了\n"NOR, tmpstr1,me->name(1) )); 

                return 1;
        }
        if (environment(me) == environment(couple_ob ) ) {       
           if (arg == "kiss") {
              write( MAG "你拥住你的爱侣，深深的一吻，许久...许久...\n" NOR);
              tell_room(environment(me), CYN+(string)me->name()+
              "拥住"+(string)couple_ob->name()+"，深深的一吻。\n" 
                +NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(MAG "%s %s
                拥住你，深深的一吻，许久...许久...\n"NOR,tmpstr1,me->name(1) 
));               }         
        }                 

        return 1;
}


int do_coupletalk(string arg)
{
        object *list, me;
        object couple_ob;
        string target, tmpstr1, tmpstr2;
        string cardname;
        int i;

        me = this_player();
        list = all_inventory(this_player());
        i = sizeof(list);
        while (i--) {
              if (((string)list[i]->query("id")) == "marrycard")
                cardname = list[i]->query("name");
        }

        if (sscanf(cardname,"你和%s的婚约" ,target)!=1)
                return notify_fail("你没有伴侣.\n");

        couple_ob = find_player(target);
        if( !couple_ob )
                return 
        notify_fail("你的伴侣现在无法听见你，或者已经离开游戏了。\n");
        if ((string)couple_ob->query("gender") != "女性") {
                tmpstr1 = "老婆";
                tmpstr2 = "老公";
        } else {
                tmpstr1 = "老公";
                tmpstr2 = "老婆";
        }

        write(sprintf(MAG"你对%s %s 说：%s\n"NOR,
                tmpstr2,couple_ob->name(1), arg ));
        tell_object(couple_ob, sprintf(MAG "%s %s 对你说：%s\n"NOR, 
               tmpstr1,me->name(1), arg ));

        return 1;
}

string query_autoload()
{
        object *list, me;
        object couple_ob;
        string target,cardname;
        int i;

        me = this_player();
        list = all_inventory(this_player());
        i = sizeof(list);
        while (i--) {
              if (((string)list[i]->query("id")) == "marrycard")
                cardname = list[i]->query("name");
        }

        sscanf(cardname,"你和%s的婚约" ,target);
      
        return target;
}

void autoload(string arg)
{
        int i;
        object couple_ob;
        object me;
        string tmpstr, tmpstr1;

//        me = this_player();
        couple_ob = find_player(arg);
        if (couple_ob){
                if ((string)couple_ob->query("gender") != "女性"){
                        tmpstr1 = "老公"; 
                        tmpstr = "老婆";
                } else {
                        tmpstr1 = "老婆";
                        tmpstr = "老公";
                }
                
         write(sprintf( MAG "你的%s也在这里，快去找啦...\n"NOR,tmpstr1));
                tell_object(couple_ob ,
                sprintf( MAG "你的%s来啦,快去接...\n" NOR, tmpstr));

//me->name(1)+"("+me->query("id")+")",environment(me))->query("name") ); 
                
                
        }
        set("name","你和"+arg+"的婚约");

}

