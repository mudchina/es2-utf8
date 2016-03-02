
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("密函", ({ "secret letter","letter"  }) );
    set("unit", "封");
    set("long","这是一封用蜡密封起来的信件，上面有一奇怪的图案。\n");
    set_weight(50);
    setup();
}
void init()
{
             seteuid(getuid(environment()));
             add_action("do_fire","fire");
}

int do_fire(string arg)
{
       object me,obj;
       string item;

       me = this_player();
       item = "fire";
       if( !objectp(obj = present(item, me)) )
           return notify_fail("你身上没有火没法烧。\n");
       tell_object(me, HIY "你看见密函上出现几行字 : \n" +
           HIM "师父: \n" +
               "      展信愉悦 \n" +
               "    徒儿在晚月庄作客已有一阵子了!\n" +
               "在这徒儿无意中发现晚月庄的秘密。\n" +
               "一、原来晚月庄主是同性恋，她似乎在对男人失望之馀，\n" +
               "    对比自己年轻的姑娘由恨转而成一种变相畸型的爱。\n" +
               "二、在密室之中藏有一秘笈。以及庄内有一处有神奇宝物\n" +
               "    玛瑙手镯。在另一神秘的地方有通往庄主秘密情人的\n" +
               "    密室入口。\n" +
               "三、在庄内小花池中有火神族的神像。小花池似乎有神奇\n" +
               "    的力量在里头。\n" +
               "\n\n" NOR);
       return 1;
}
