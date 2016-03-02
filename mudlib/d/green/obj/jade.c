inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("玉佩", ({ "jade" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long",@LONG
上面刻著一些字:
行气, 深则蓄, 蓄则伸, 伸则下, 下则定, 定则固, 固则萌, 萌则长, 长则退,
退则天. 天几舂在上, 地几舂在下, 顺则生, 逆则死.
LONG
        );
                set("value", 1000);
                set("material", "jade");
                set("skill", ([
                        "name":                 "force",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 25,
                        "max_skill":    40
                ]) );
        }
}
