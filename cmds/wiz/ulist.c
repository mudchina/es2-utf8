// user list

inherit F_CLEAN_UP;

int main(string str)
{
        object *ob;
        int i;
        ob=users();
        i = sizeof(ob);
        while (i--) {
        write(sprintf("%15s : %30s\n",ob[i]->query("id"),
        file_name(ob[i])));
        }
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : ulist

将线上所有玩家的/obj/user number 显示出来。
HELP
    );
    return 1;
}
