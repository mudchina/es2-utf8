// cloud_armor

#include <armor.h>
#include <ansi.h>

inherit ARMOR;
//inherit F_UNIQUE;

void create()
{
	set_name(RED"火 云 "HIB"战 甲"NOR,({ "cloud armor","armor" }) );
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloud");
		set("value",12000);
		set("armor_prop/armor", 40);
        set("replica_ob", __DIR__"armor");
	}
	setup();
}

