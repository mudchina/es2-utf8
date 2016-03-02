// chess.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("棋子", ({ "chess" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"棋子是一种较轻的暗器。\n");
		set("unit", "把");
		set("base_unit", "枚");
		set("base_weight", 2);
		set("base_value", 1);
	}
	set_amount(100);
	init_throwing(2);
	setup();
}
