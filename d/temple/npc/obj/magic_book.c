// magic_book.c

inherit ITEM;

void create()
{
        set_name("魔法入门", ({ "magicbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",

"这似乎是一本魔法的入门书，里面说了一些稀奇古怪的和一般的武学不同的东西\n"
                );
                set("value", 260);
                set("material", "paper");
                set("skill", ([
                        "name":     "magic",    // name of the skill
                    "exp_required": 100, // minimum combat experience equired
                        "sen_cost":  30, // gin cost every time study this
                      "difficulty":  10,//the base int to learn this skill
        // modify is gin_cost's (difficulty - int)*5%�)
                    "max_skill":  20 // the maximum level you can learn

        // from this object.
                ]) );
        }
}
