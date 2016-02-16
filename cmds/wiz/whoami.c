// whoami.c

int main()
{
	write("你的 User ID = " + getuid(this_player()) + "\n" );
	write("你的 Effective User ID = " + geteuid(this_player()) + "\n" );
	return 1;
}

int help (object me)
{
write(@HELP
指令格式 : whoami 

Show 出你的 User ID 及 Effective User ID 。
HELP
     );
    return 1;
}
