// enchant.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || !sscanf(arg, "%d", pts) ) 
		return notify_fail("指令格式：enchant <灵力点数>\n");

	if( pts > ((int)me->query("atman")/50+1) )
		return notify_fail("你的灵力不足，发不出那麽强的威力。\n");

	if( pts < 0 ) return notify_fail("灵力点数必须是正数。\n");	
	me->set("mana_factor", pts);
	write("Ok.\n");
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: enchant <灵力点数>
 
这个指令让你设定使用魔法武器时要用来导引武器魔力所用的灵力强度。
不同的武器所需的灵力不同，威力也不一样，有些魔力强大的武器如果使用者
无法发出足以驾驭它的灵力，就有可能产生可怕的後果。

HELP
	);
	return 1;
}
