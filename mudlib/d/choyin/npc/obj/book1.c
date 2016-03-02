// book1.c

inherit ITEM;

void create()
{
         string *names = ({
                "「笑傲江湖」", "「天龙八部」", 
                "「七剑下天山」", "「游侠郭解传」",
                "「七种武器」", "「楚留香传奇之血海飘香」",
                "「四大名捕」", "「洪武剑侠图」" });     
        set_name( names[random(sizeof(names))], ({ "book" }));
        set_weight(600);
        set("unit", "本");
        set("long", "这是隐士们常看的书籍。\n");
        set("value", 100);
        set("skill", ([
                "name":                 "unarmed",
                "exp_required": 100, 
                "sen_cost":             20, 
                "difficulty":   30,
                "max_skill":    80,  
        ]) );
}    
