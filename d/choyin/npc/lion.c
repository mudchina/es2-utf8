// lion.c

inherit NPC;

void create()
{
        set_name("护草神兽", ({ "guarder" }) );
        set("long", "看守忘忧草的护草神兽。\n");

        set("race", "野兽");
        set("age", 100);
        set("attitude", "aggressive");

        set("max_gin", 300);
        set("max_kee", 1000);
        set("max_sen", 300);

        set("str", 30);
        set("cor", 70);
        set("spi", 20);
        set("int", 10);

        set("limbs", ({ "头部", "躯干", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_temp("apply/attack", 30);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 50);
        set_temp("apply/dodge", 40);

        set("combat_exp",100000);
        set("score", 1000);
        setup();
}


void die()
{
	object killer,obj;
	string id ;

	killer = query_temp("last_damage_from");
	obj = new("/d/choyin/obj/grass");
	id = (string) killer->query("id");
	obj->set("master_id",id);
	obj->move(this_object());
	return ::die();
}

