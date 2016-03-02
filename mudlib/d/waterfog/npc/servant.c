// servant.c

inherit NPC;

void create()
{
	set_name("仆役", ({ "servant" }) );
	set("gender", "男性");
	set("age", 34);
	set("long", "这个人看起来十分和蔼可亲，看起来不像是会武功\的人。\n");

	set("attitude", "friendly");
	set("combat_exp", 100);

	set("str", 25);
	set("cor", 23);
	set("cps", 23);
	set("con", 27);

	setup();
}
