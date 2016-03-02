// phantomforce.c

inherit ITEM;

void create()
{
//	seteuid(geteuid());

	set_name("一具已经腐朽的骸骨", ({ "skeleton" }));
	set_weight(3500);
	set("unit", "具");
	set("long",
		"一具已经腐朽的骸骨静静地不知躺了多久。\n"
	);
	set("no_get", "不能丢弃");
}
