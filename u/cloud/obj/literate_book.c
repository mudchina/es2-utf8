// sword_book.c

inherit ITEM;

void create()
{
        set_name("说文解字", ({ "literate book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"这是一本介绍读书识字的入门书籍。\n"
                        "开篇上赫然写着人之初，性本善什么的。\n");
                set("value", 2000);
                set("material", "paper");
                set("skill", ([
                        "name":                 "literate",        
                        "exp_required": 0,
                        "sen_cost":             30,       
                        "difficulty":   20,   
                        "max_skill":    30    
                ]) );
        }
}

 
