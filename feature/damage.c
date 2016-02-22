// damage.c

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

int ghost = 0;

int is_ghost() { return ghost; }

varargs int receive_damage(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
	if( type!="gin" && type!="kee" && type!="sen" )
		error("F_DAMAGE: 伤害种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

	if( objectp(who) ) set_temp("last_damage_from", who);
	val = (int)query(type) - damage;

	if( val >= 0 ) set(type, val);
	else set( type, -1 );

	set_heart_beat(1);

	return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
	if( type!="gin" && type!="kee" && type!="sen" )
		error("F_DAMAGE: 伤害种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

	if( objectp(who) ) set_temp("last_damage_from", who);
	val = (int)query("eff_" + type) - damage;

	if( val >= 0 ) set("eff_" + type, val);
	else {
		set( "eff_" + type, -1 );
		val = -1;
	}

	if( (int)query(type) > val ) set(type, val);

	set_heart_beat(1);

	return damage;
}

int receive_heal(string type, int heal)
{
	int val;

	if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
	if( type!="gin" && type!="kee" && type!="sen" )
		error("F_DAMAGE: 恢复种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

	val = (int)query(type) + heal;

	if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
	else set( type, val );

	return heal;
}

int receive_curing(string type, int heal)
{
	int max, val;

	if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
	if( type!="gin" && type!="kee" && type!="sen" )
		error("F_DAMAGE: 恢复种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

	val = (int)query("eff_" + type);
	max = (int)query("max_" + type);

	if( val + heal > max ) {
		set("eff_" + type, max);
		return max - val;
	} else {
		set( "eff_" + type, val + heal);
		return heal;
	}
}

void unconcious()
{
	object defeater;

	if( !living(this_object()) ) return;
	if( wizardp(this_object()) && query("env/immortal") ) return;

	if( objectp(defeater = query_temp("last_damage_from")) )
		COMBAT_D->winner_reward(defeater, this_object());

	this_object()->remove_all_enemy();

	message("system", HIR "\n你的眼前一黑，接著什麽也不知道了....\n\n" NOR,
		this_object());
	this_object()->disable_player(" <昏迷不醒>");
	set("gin", 0);
	set("kee", 0);
	set("sen", 0);
	set_temp("block_msg/all", 1);
	COMBAT_D->announce(this_object(), "unconcious");

	call_out("revive", random(100 - query("con")) + 30);
}

varargs void revive(int quiet)
{
	remove_call_out("revive");
	while( environment()->is_character() )
		this_object()->move(environment(environment()));
	this_object()->enable_player();
	if( !quiet ) {
		COMBAT_D->announce(this_object(), "revive");
		set_temp("block_msg/all", 0);
		message("system", HIY "\n慢慢地你终於又有了知觉....\n\n" NOR,
			this_object());
	} else
		set_temp("block_msg/all", 0);
}

void die()
{
	object corpse, killer;

	if( !living(this_object()) ) revive(1);
	if( wizardp(this_object()) && query("env/immortal") ) return;

	// Clear all the conditions by death.
	this_object()->clear_condition();

	COMBAT_D->announce(this_object(), "dead");
	if( objectp(killer = query_temp("last_damage_from")) ) {
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, this_object());
	}

	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
		corpse->move(environment());

	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());

	this_object()->dismiss_team();
	if( userp(this_object()) ) {
		set("gin", 1);	set("eff_gin", 1);
		set("kee", 1);	set("eff_kee", 1);
		set("sen", 1);	set("eff_sen", 1);
		ghost = 1;
		this_object()->move(DEATH_ROOM);
		DEATH_ROOM->start_death(this_object());
	} else
		destruct(this_object());
}

void reincarnate()
{
	ghost = 0;
	set("eff_gin", query("max_gin"));
	set("eff_kee", query("max_kee"));
	set("eff_sen", query("max_sen"));
}

int max_food_capacity() { return query_weight() / 200; }

int max_water_capacity() { return query_weight() / 200; }

int heal_up()
{
	int update_flag;
	mapping my;

//	if( this_object()->is_fighting() ) return -1;

	update_flag = 0;

	my = query_entire_dbase();

	if( my["water"] > 0 ) { my["water"] -= 1; update_flag++; }
	if( my["food"] > 0 ) { my["food"] -= 1; update_flag++; }

	if( my["water"] < 1 && userp(this_object()) ) return update_flag;
	
	my["gin"] += my["con"] / 3 + my["atman"] / 10;
	if( my["gin"] >= my["eff_gin"] ) {
		my["gin"] = my["eff_gin"];
		if( my["eff_gin"] < my["max_gin"] ) { my["eff_gin"] ++; update_flag++; }
	} else update_flag++;

	my["kee"] += my["con"] / 3 + my["force"] / 10;
	if( my["kee"] >= my["eff_kee"] ) {
		my["kee"] = my["eff_kee"];
		if( my["eff_kee"] < my["max_kee"] )	{ my["eff_kee"] ++; update_flag++; }
	} else update_flag++;

	my["sen"] += my["con"] / 3 + my["mana"] / 10;
	if( my["sen"] >= my["eff_sen"] ) {
		my["sen"] = my["eff_sen"];
		if( my["eff_sen"] < my["max_sen"] )	{ my["eff_sen"] ++; update_flag++; }
	} else update_flag++;

	if( my["food"] < 1 && userp(this_object()) ) return update_flag;

	if( my["max_atman"] && my["atman"] < my["max_atman"] ) {
		my["atman"] += (int)this_object()->query_skill("magic", 1) / 2;
		if( my["atman"] > my["max_atman"] ) my["atman"] = my["max_atman"];
		update_flag++;
	}

	if( my["max_force"] && my["force"] < my["max_force"] ) {
		my["force"] += (int)this_object()->query_skill("force", 1) / 2;
		if( my["force"] > my["max_force"] ) my["force"] = my["max_force"];
		update_flag++;
	}

	if( my["max_mana"] && my["mana"] < my["max_mana"] ) {
		my["mana"] += (int)this_object()->query_skill("spells", 1) / 2;
		if( my["mana"] > my["max_mana"] ) my["mana"] = my["max_mana"];
		update_flag++;
	}

	return update_flag;
}
