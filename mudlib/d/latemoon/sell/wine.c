inherit COMBINED_ITEM;

void create()
{
        set_name("女儿红", ({"wine"}));
        set("long",
   "这是一坛香味浓郁的陈年老酒，是存给待嫁女儿喝的酒。\n"
   "你闻了闻，好香好香哦!你有点想喝它 (drink)\n");
        set("unit", "坛");
        set("base_unit", "坛");
        set("base_weight", 20000);
        set_amount(1);
}

void init()
{
        if( this_player()==environment() )
            add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        if( !arg ) return notify_fail("你要喝甚么呢? \n");
        message_vision(
           "$N提起一坛酒，呼噜呼噜的大口喝了下去。\n"
           "只见$N脸上泛起一阵红晕，身子不觉晃了起来! \n",this_player()  );
        this_player()->receive_damage("gin",10);
        this_player()->receive_heal("sen",20);

        add_amount(-1);
        return 1;
}
