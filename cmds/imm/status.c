// status.c

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string msg;

	msg = (string)mud_status(arg=="detail" ? 1 : 0);
	if( stringp(msg) ) write(msg);

	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : status [detail]
 
这个指令可以显示出目前游戏的一些相关资料及状况.
 
HELP
    );
    return 1;
}
 
