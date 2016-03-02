#include <ansi.h>

#include <armor.h>
inherit WRISTS;

void create()
{
    set_name(HIC "玛瑙手镯" NOR, ({"bracelet onyx","bracelet"}) );
     set_weight(50);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", "一个由玛瑙作成的美丽手镯。\n"
            "再仔细玩看，似乎有其它作用 (info bracelet)。\n");
            set("unit", "串");
            set("value", 5000);
            set("no_drop", 1);
            set("armor_prop/armor",2);
            set("armor_prop/dodge", 2);
            set("armor_prop/spells", 2);
            set("wear_msg", "$N把$n带在手上。\n");
     }
     setup();
}

void init()
{
        if( this_player()==environment() )
            add_action("do_info","info");
            add_action("do_pray","pray");
}

int do_info(string arg)
{
        if( !arg ) return notify_fail("你想知道什么? \n");
        write("使用 (pray start) ，它会传送你回起点。\n");
         return 1;
}

int do_pray(string arg)
{
      string name;
       name = (string)this_player()->query("name");

         if( !arg || arg!="start" ) return notify_fail("你要祈求什么? \n");
         {
         message_vision("$N双手合掌，虔诚的祈祷。\n"
             "手上的镯子嗡嗡作响。 突然一阵烟雾.... \n",this_player() );
         this_player()->receive_damage("sen",50);
         tell_room(environment(this_player()),
               name+"的身影消失在空气中。\n",this_player() );
         tell_room("/d/snow/inn",
              name+"的身影出现在一阵烟雾之中。\n",this_player() );
         this_player()->move("/d/snow/temple");
          }
          return 1;
}
