// melon.c

inherit ITEM;
//inherit F_LIQUID;
inherit F_FOOD;

void create()
{
	set_name("西瓜", ({ "water melon", "melon" }) );
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个绿皮墨纹的大西瓜，不但解渴，还能填肚子。\n");
		set("unit", "个");
		set("value", 60);
		set("drink_func",1);
		set("food_remaining", 8);
		set("water_supply", 40 );
		set("food_supply", 20);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "西瓜汁",
		"remaining": 15,
	]) );
}

int finish_eat()
{
	set_name("西瓜皮", ({ "bone" }) );
	set_weight(150);
	set("long", "一块啃得精光的西瓜皮。\n");
	return 1;
}
