// whip_book.c

inherit ITEM;

void create()
{
        set_name("寒雪鞭法", ({ "whipbook" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"这似乎是一本寒雪鞭法的前几页，虽然并没有关於招式的详细解说，可是\n"
                        "前面有关鞭法的总纲与精义倒是不少。\n");
                set("value", 260);
                set("material", "paper");
                set("skill", ([
                        "name":                 "snowwhip",        
                        "exp_required": 1000,
                        "sen_cost":             30,       
                        "difficulty":   20,   
                        "max_skill":    20    
                ]) );
        }
}

 
