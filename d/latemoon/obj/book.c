#include <ansi.h>
inherit ITEM;

void create()
{
         set_name(HIW "舞曲谱" NOR, ({ "dance book","book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("long",
                        
"这是一卷由上等丝绸编成，以湘绣作成的舞曲图。上有记载一些舞曲 \n"
"每一曲都有它独特的风格与内涵。一幅幅玄天玉女翩然起舞，十分壮观。\n"
 "\n  曲目： \n \n"
MAG "  广陵散 \n" "  春宫怨 \n \n" NOR
"对你而言基本舞步你可以参悟，至于较高深步法似乎需人指导了。 \n");
                set("value", 1000);
                set("material", "silk");
                set("no_drop", 1);
                set("skill", ([
                        "name":                 "music",
                  "exp_required": 5000,
                        "sen_cost": 30,            
                     "class" : "dancer",
                        "difficulty":   20,
                        "max_skill":   60 ,
                ]) );
        }
}

void init()
{
    add_action("do_dance","dancing");
}

int do_dance(string arg)
{
    string name;
    name = (string)this_player()->query("name");

    if( !arg ) return notify_fail("你要跳什么舞? \n");
    {
        if ( arg == "home" )
        {
            message_vision("$N双手合掌，脚步轻盈。一曲" +
              HIM "『 春宫怨 』" NOR "......\n",this_player() );
            this_player()->receive_damage("sen",50);
            tell_room(environment(this_player()),
                 name+"的身影消失在空气中。\n",this_player() );
            tell_room("/d/latemoon/latemoon1",
                 name+"的身影出现在一曲凄美的曲调中。\n",this_player() );
            this_player()->move("/d/latemoon/latemoon1");
         }
     }
     return 1;
}
