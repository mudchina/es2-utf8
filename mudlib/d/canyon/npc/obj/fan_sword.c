// sword:__DIR__"obj/fan_sword.c" 铁扇剑一把

#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("铁扇剑",({ "fan sword","fan","sword" }));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "柄");
		set("long", "这是一柄羽状的铁剑，看起来蛮尖锐的。\n");
		set("value", 600);
		set("material", "iron");
                set("wield_msg", "$N「唰」地一声从袖口抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n收入袖内。\n");
        }
	init_sword(20);
	setup();
}

