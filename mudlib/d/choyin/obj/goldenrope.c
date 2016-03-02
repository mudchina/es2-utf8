#include <ansi.h>
inherit ITEM;

void create()
{
         set_name(HIW "缚仙绳" NOR, ({ "golden rope","rope" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long",@LONG
这是一条由上等金丝编成的绳索, 可缚(tie)禽兽鬼怪。上刻有无数咒文，发出耀目金光.
LONG );
                set("value", 1000);
                set("no_drop", 1);
              
        }
}

void init()
{
    add_action("do_tie","tie");
}

int do_tie(string arg)
{
    string name;
    name = (string)this_player()->query("name");

    if( !arg ) return notify_fail("你要缚何物? \n");
    {
        if ( arg == "crane" )
        
            message_vision("$N双手合掌，随风而起，落于仙鹤背上......\n",
            this_player() );
            this_player()->receive_damage("sen",50);
            tell_room(environment(this_player()),
                "仙鹤的身影扶摇直上，消失于云端。\n",this_player() );
            tell_room("/d/choyin/platform",
                 name+"的身影出现在云雾中。\n",this_player() );
            this_player()->move("/d/choyin/platform");
         }
     return 1;
}
