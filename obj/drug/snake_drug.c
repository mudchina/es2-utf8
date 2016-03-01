//snake_drug.c

inherit COMBINED_ITEM;

void create()
{
  set_name("蛇药",({"drug","snake drug"}));
  set("long",
      "这是一包用来解蛇毒的药\n"
      "可以用(apply)来解蛇毒!\n");
  set("value",1000);
  set("unit","包");
  set("base_unit","份");
  set("base_weiht",100);
  set_amount(1);
}

void init()
{
  add_action("do_apply","apply");
}

int do_apply()
{
        object me;
        me=this_player();
  if(((int) (me->query_condition("snake_poison"))) <= 0)
        return notify_fail("你没有中蛇毒。\n");
  message_vision("$N服下蛇药，顿时感觉好多了。",me);
        me->apply_condition("snake_poison",
                (int)me->query_condition("snake_poison") - 1);
  if((int) (me->query_condition("snake_poison")))
        message_vision("但是$N中的蛇毒并没有完全清除。\n",me);
        else
        message_vision("$N终于清除了体内所有的蛇毒！\n",me);
  add_amount(-1);

  return 1;
}


