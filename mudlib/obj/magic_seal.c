// magic_seal.c

inherit ITEM;

void create()
{
	set_name("符咒", ({"seal"}) );
	set_weight(5);
	set("long",
		"这是一张画好的符咒，用 attach 指令可以将它贴在某人(或某物)身上。\n");
	set("unit", "张");
}

int unequip()
{
	set("equipped", 0);
	return 1;
}

void init()
{
	add_action("do_attach", "attach");
}

int do_attach(string arg)
{
	string sheet, dest;
	object ob;
	function f;

	if( !arg || sscanf(arg, "%s to %s", sheet, dest)!=2 )
		return notify_fail("指令格式：attach <符咒> to <目标>\n");
	
	if( !id(sheet) ) return 0;

	ob = present(dest, this_player());
	if( !ob ) ob = present(dest, environment(this_player()));
	if( !ob ) return notify_fail("你要对什麽东西使用这张符咒？\n");

	if( !functionp(f = query("attach_func", 1)) )
		return notify_fail("这张符没有用。\n");

	if( evaluate(f, ob) ) {
		if( ob!=this_player() )
			message_vision("$N拿出一张" + name() + "往$n一贴。\n", this_player(), ob);
		if( ob && ob->is_character() ) {
			move(ob);
			set("equipped", "sealed");
			set("no_drop", "这样东西不能丢弃，必须用 detach。\n");
		} else destruct(this_object());
		return 1;
	} else 
		return 0;
}
