// cat.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    if (!arg) return notify_fail("你想要显示那个档案?\n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("没有这个档案。\n");
	cat(file);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : cat <档案>

此指令可让你(□)直接读取某档案之程式。
HELP
    );
    return 1;
}
