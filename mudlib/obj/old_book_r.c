// old_book_r.c

inherit ITEM;

void create()
{
	set_name("旧书", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"一本民间赖以决定播种、施肥时机的农民历，对你而言显然没有多大用处。\n");
		set("value", 30);
		set("material", "paper");
	}
}
