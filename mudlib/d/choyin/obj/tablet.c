inherit COMBINED_ITEM;

void create()
{
        set_name("仙丹", ({"tablet"}));
        set("long",     "这是一粒仙丹，服食可位列仙班。\n"
);
        set("unit", "粒");
        set("value",100); 
        set("base_unit", "粒");
        set("base_weight", 10000);
        set_amount(1);
}

void init()
{
        if( this_player()==environment() )
                add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        if( !arg || arg != "tablet")  return notify_fail("你要吃甚么呢? \n");
        message_vision(
           "$N拿出一粒仙丹，纳入口中. 吃的太急, 鼻涕眼泪流了满脸..\n"
           ,this_player()  );
        this_player()->receive_heal("gin", 5);
        this_player()->receive_heal("kee", 30);
        this_player()->receive_heal("sen", 5);

        add_amount(-1);
        return 1;
} 
