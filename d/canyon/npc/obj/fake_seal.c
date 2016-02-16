//seal.c

inherit ITEM;

void create()
{
    set_name( "印鉴" ,({ "seal" }) );
	set("long", "上面刻著镇国大将军。\n");
	set("unit", "颗");
	set("base_weight", 300);
	set("value", 3000);
	
	set("no_sell", 1);
}


