// book2.c

inherit ITEM;

void create()
{
        string *names = ({
                "「秘传八步赶蝉」", "「陆地飞行之法」", "「寒梅弄影之法」", "「穿花绕树要诀」",
                "「八卦步法」",   });

        set_name( names[random(sizeof(names))], ({ "book" }));
        set_weight(600);
        set("unit", "本");
        set("long", "这是隐士们常看的书籍。\n");
        set("value", 100);
        set("skill", ([
                "name":                 "dodge",
                "exp_required": 100, 
                "sen_cost":     20, 
                "difficulty":   30,
                "max_skill":    80,  
        ]) );
} 
