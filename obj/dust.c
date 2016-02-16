// dust.c

inherit COMBINED_ITEM;

void create()
{
        set_name("化尸粉", ({"dust"}));
        set("long",
                "这是一包用来毁尸灭迹的化尸粉，只要用一丁点就可以\n"
                "化去(dissolve)一具尸体！\n");
        set("value", 1000);
        set("unit", "包");
        set("base_unit", "份");
        set("base_weight", 1);
        set_amount(1);
}

void init()
{
        if( this_player()==environment() )
                add_action("do_dissolve", "dissolve");
}

int do_dissolve(string arg)
{
        object ob;

        if( !arg ) return notify_fail("你要用化尸粉溶解什麽东西？\n");
        if( !objectp(ob = present(arg, environment(this_player()))) )
                return notify_fail("这里没有这样东西。\n");
        if( living(ob) || !ob->id("corpse") )
                return notify_fail("化尸粉只能用来溶解尸体。\n");
        message_vision(
                "$N用指甲挑了一点化尸粉在$n上，只听见一阵「嗤嗤」声响带著\n"
                "一股可怕的恶臭，$n只剩下一滩黄水。\n", this_player(), ob);
        destruct(ob);
        add_amount(-1);
        return 1;
}

