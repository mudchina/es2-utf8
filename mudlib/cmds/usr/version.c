// version.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	write(__VERSION__+"\n");
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : version
 
这个指令会显示游戏目前所用的 MudOS driver 版本.
 
HELP
    );
    return 1;
}
 
