// glass.c

inherit EQUIP;

void create()
{
	set_name("战斗力探测器", ({ "detector", "glass", "device" }) );
	set_weight(300);
	set("unit", "个");
	set("long",
		"这是来自「七龙珠」的战斗力探测器，你可以用它来探测(detect)别人\n"
		"的战斗力。\n");
	set("value", 500);
	set("type", "misc");
	set("apply", ([
		"头部":	0,
	]) );
}

void init()
{
	add_action("do_detect", "detect");
}

int do_detect(string arg)
{
	object ob;
	int sen, sk;
	string skill;

	if( arg ) ob = present(arg, environment(this_player()));
	else ob = this_player()->query_opponent();

	if( !ob ) return notify_fail("你要探测谁的战斗力？\n");

	sen = (int)ob->query("sen");
	if( stringp(skill = ob->query("attack_skill")) )
		sk = ob->query_skill(skill);
	else
		sk = 0;

	printf("探测器显示%s的战斗力是：%d\n",
		ob->query("name"), 
		(sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("combat_exp") );

	return 1;
}

