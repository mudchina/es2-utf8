// trainee.c

inherit NPC;

void create()
{
	set_name("武馆弟子", ({ "trainee" }) );
	set("gender", "男性" );
	set("age", 19);
	set("long", "你看到一位身材高大的汉子，正在辛苦地操练著。\n");
	set("combat_exp", 100);
	setup();
	carry_object(__DIR__"obj/linen")->wear();
}
