// config.c

#include <runtime_config.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 ) {
		write("Mud 名称：\t\t" + get_config(__MUD_NAME__) + "\n"); 
		write("网路地址名称伺服器埠号：" + get_config(__ADDR_SERVER_IP__) + "\n"); 
		write("Mudlib 路径：\t\t" + get_config(__MUD_LIB_DIR__) + "\n"); 
		write("MudOS 执行档路径：\t" + get_config(__BIN_DIR__) + "\n"); 
		return 1;
	}

	printf("get_config(%d) = %O\n", num, get_config(num));
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : config

Show 出本 MUD 的 Startup Configuration 。
HELP
     );
     return 1;
}
