// reclaim.c

int main(object me, string arg)
{
	int mem;

	write("整理结果，共清除 " + reclaim_objects() + " 个变数。\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : reclaim

用处 : 将存在於记忆体里无用的变数清除掉, 以减少记忆体的使用。
HELP
     );
     return 1;
}
