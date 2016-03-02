#include <ansi.h>

#include <armor.h>
inherit WAIST;

void create()
{                              
     set_name(HIG "碧玉"+ HIM "红裎带" NOR, ({"Red belt","belt"}) );
     set_weight(500);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
     set("long", "这是一条丝绸制的彩带，质感佳，上绣有彩□江水纹。\n");
            set("unit", "条");
            set("value", 2000);
            set("material", "cloth");
            set("armor_prop/armor", 4);
     set("wear_msg", "$N将$n拿出系在腰上。\n");
    }
    setup();
}
