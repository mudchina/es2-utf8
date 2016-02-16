// summon command..

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;
	int i;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("咦... 有这个人吗?\n");
	// moving
	tell_room(environment(ob),"天空中伸出一只大手把"+
	(string)ob->query("name")+"抓了起来, 然後不见了.\n", ob);
	tell_object(ob,"一只手把你抓了起来, 你眼前一阵黑....\n");
	ob->move(environment(me));
        tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
	tell_object(ob,".... 醒来时发现是"+(string)me->query("name")+
	"把你弄过来的.\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然出现"+
	"在你眼前\n",({me,ob}));
	// ok ..
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : summon <某人>

此指令可让你(□)将某人抓到你面前。
HELP
    );
    return 1;
}
