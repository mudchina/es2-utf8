// unwield.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, *inv;
	string str;
	int i;

	if( !arg ) return notify_fail("你要脱掉什麽？\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( (string)ob->query("equipped")!="wielded" )
		return notify_fail("你并没有装备这样东西作为武器。\n");

	if( ob->unequip() ) {
		if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N放下手中的$n。\n";
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
  write(@HELP
指令格式 : unwield <物品名>
 
这个指令让你放下手中的武器。
 
HELP
    );
    return 1;
}
 
