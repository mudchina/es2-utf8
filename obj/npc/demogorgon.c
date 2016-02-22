// demongorgon.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "侮天鬼王" NOR, ({ "demogorgon" }) );
	set("long",
		"侮天鬼王神情倨傲地站在你面前，他高大的身躯跟一股令人窒息的\n"
		"可怕杀气正压得你几乎喘不过气来，你的心里似乎有一个声音在告\n"
		"诉你：「 快 逃 ！！」\n");

	set("age", 7006);
	set("pursuer", 1);

	set("max_gin", 5000);
	set("max_kee", 5000);
	set("max_sen", 5000);

	set("max_atman", 9999);
	set("atman", 9999);
	set("max_force", 5000);
	set("force", 5000);
	set("max_mana", 5000);
	set("mana", 5000);

	set("str", 100);
	set("cor", 100);
	set("cps", 100);
	set("spi", 100);
	set("int", 100);
	set("con", 100);
	set("kar", 0);
	set("per", 0);

	set("combat_exp", 5000000);

	set_skill("staff", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	setup();

	carry_object(__DIR__"obj/demon_staff")->wield();
}

void start_shutdown()
{
	if( geteuid(previous_object()) != ROOT_UID ) return;

	message("system",
		HIR "\n你听到天空中传来一阵可怕的咆哮 ....\n\n"
		HIW	"侮天鬼王" HIR "用震耳欲聋的声音喝道：\n\n"
			"\t\t全 天 下 的 众 生 给 我 听 著 ！\n\n"
			"\t\t限你们十五分钟内把我的头颅交出来 ！\n\n"
			"\t\t不 然 的 话 ..... 哼 .. 哼 ！\n\n" NOR,
		users() );
	call_out("countdown", 60, 15);
}

void countdown(int min)
{
	min--;
	if( min ) {
		message("system",
			HIW "\n侮天鬼王" HIR "用震耳欲聋的声音喝道：\n\n"
				"\t\t你们还有" + chinese_number(min) + "分钟的时间交出我的头颅！\n\n"
				"\t\t—不—要—命—的—就—给—我—慢—慢—拖—吧—！\n\n" NOR,
			users() );
		call_out("countdown", 60, min);
	} else {
		message("system",
			HIW "\n侮天鬼王" HIR "用震耳欲聋的声音喝道：\n\n"
				"\t\t可恨.....真是可恨....\n\n"
				"\t\t苍天啊～ 大地啊～  海洋啊～  众生啊～\n\n" NOR,
			users() );
		call_out("do_shutdown", 3);
	}
}

void do_shutdown()
{
	message("system",
		HIW "\n\n侮天鬼王" HIR "用震耳欲聋的声音喝道：\n\n"
		HIW "\t\t通 通 和 我 一 起 下 地 狱 吧 ～～～～ ！\n\n"
		HIR "\t\t声音一毕，天空立刻变得血红，不....你眼前的一切都变得血红...\n\n"
			"\t\t所有的一切都在瞬间陷入火海....\n\n"
			"\t\t然後你的眼前是一片黑暗....无止尽的黑暗....\n\n" NOR,
		users() );
	shutdown(0);
}

void die()
{
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);

	if( !ob ) return;

	message("system",
		HIR "\n\n你听到一声带著愤恨、惊恐、与野兽般的咆哮声响彻整个天空。\n\n"
		HIW "侮天鬼王" HIR "嘶哑地吼著：可恶的" + ob->name(1) + "，我一定会报仇的～～～\n\n"
			"然後一道黑色火焰呼啸著冲上云端，大地又恢复了宁静。\n\n" NOR,
		users() );
	destruct(this_object());
}
