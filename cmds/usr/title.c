// title.c (Mon  09-04-95)
 
#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string str)
{
    printf(BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(me), me->short(1));
    return 1;
}
 
int help(object me)
{
    write(@HELP
指令格式: title
 
显示你目前的阶级和头衔。
 
HELP
    );
}
 
