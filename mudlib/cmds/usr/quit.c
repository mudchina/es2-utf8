// quit.c

#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
	seteuid(getuid());
	set("name", "离线指令");
	set("id", "quit");
}

int main(object me, string arg)
{
	int i;
	object *inv, link_ob;

	if( !wizardp(me) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(me, inv[i]);
	}

	link_ob = me->query_temp("link_ob");

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {

		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}

		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		destruct(link_ob);
	}

	write("欢迎下次再来！\n");
	message("system", me->name() + "离开游戏。\n", environment(me), me);

	CHANNEL_D->do_channel(this_object(), "sys",
		me->name() + "离开游戏了。");

	me->save();
	destruct(me);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : quit

当你(□)想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}
