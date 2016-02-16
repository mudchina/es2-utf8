// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;
int time_period(int timep, object me);
int main(object me, string arg)
{
        int nowtime = time();
        mapping quest;
        if(!(quest =  me->query("quest")))
               return notify_fail("你现在没有任何任务！\n");
        write("你现在的任务是" + quest["quest_type"] +
 "『" + quest["quest"] + "』。\n");
        nowtime = (int) me->query("task_time") - time();
        if( nowtime  > 0 )
                time_period(nowtime, me);
        else
                write("但是你已经没有足够的时间来完成它了。\n");

        return 1;
}
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        tell_object(me,"你还有" + time + "去完成它。\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quest
HELP
        );
        return 1;
}

