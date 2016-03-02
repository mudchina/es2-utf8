// sword_book.c

inherit ITEM;

void create()
{
        set_name("残破剑谱", ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                et("long",
                        
"这似乎是一本什麽剑谱的前几页，虽然并没有关於招式的详细解说，可是\n"
                        "前面有关剑法的总纲与精义倒是不少。\n");
                set("value", 260);
                set("material", "paper");
                set("skill", ([
                        "name":                 "sword",        
                        "exp_required": 1000,
                        "sen_cost":             30,       
                        "difficulty":   20,   
                        "max_skill":    40    
                ]) );
        }
}

 
