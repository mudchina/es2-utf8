// time.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	write("现在是" + NATURE_D->game_time() + "。\n");
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: time

这个指令让你(□)知道现在的时辰。

HELP
    );
    return 1;
}
