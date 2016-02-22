// attack.c

#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>

#define MAX_OPPONENT	4

static object *enemy = ({});
static string *killer = ({});
static string *biwuer = ({});

// prototypes

object *query_enemy() { return enemy; }
string *query_killer() { return killer; }

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob)
{
	if( !ob ) return sizeof(enemy) > 0;

	return member_array(ob, enemy)!=-1;
}

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(mixed id)
{
	if( objectp(id) ) id = id->query("id");

	if( !id ) return sizeof(killer) > 0;

	return member_array(id, killer)!=-1;
}

//This function starts fight between this_object() and ob
void fight_ob(object ob)
{
	if(!ob || ob==this_object()) return;

	set_heart_beat(1);

	if( member_array(ob, enemy)==-1 ) 
		enemy += ({ ob });
}

// this function starts biwu between this_object() & ob
// added in July 13th
void biwu_ob(object ob)
{
	object me;
	int mycor, obcor, mykee, obkee;
	int turn, flag, i;
	float count, count_total = 0.0;
	
	me = this_object();
	if (!ob || ob == me)	return;

	// check cor, decide attack turns
	mycor = me->query_cor();
	obcor = ob->query_cor();
	if (mycor > obcor) {
		turn = mycor / obcor;
		count = (float) mycor / (float) obcor - turn;
		flag = 0;
		}
	    else {
		turn = obcor / mycor;
		count = (float) obcor / (float) mycor - turn;
		flag = 1;
		}

	// attack until one failed
	for (;;) {
	// 1. fight
		if (!flag) {
			for (i=0; i<= turn; i++)
				COMBAT_D->do_attack(me, ob, query_temp("weapon"));
			COMBAT_D->do_attack(ob, me, query_temp("weapon"));
			count_total += count;
			if (count_total > 1) {
				COMBAT_D->do_attack(me, ob, query_temp("weapon"));
				count_total -= 1;
				}
			}
		    else {
			for (i=0; i<= turn; i++)
                                COMBAT_D->do_attack(ob, me, query_temp("weapon"));
                        COMBAT_D->do_attack(me, ob, query_temp("weapon"));
                        count_total += count;
                        if (count_total > 1) {
                                COMBAT_D->do_attack(me, ob, query_temp("weapon"));
                                count_total -= 1;
                                }
                        }

	// 2.check if can continue
		mykee = me->query("kee");
		obkee = ob->query("kee");
		if (mykee <= 0) {
			me->set("kee", 1);
			message_vision("$N拱了拱手，说：“阁下武功不凡，佩服佩服！”\n", me);
			return;
			}
		if (obkee <= 0) {
			ob->set("kee", 1);
			message_vision("$N拱了拱手，说：“阁下武功不凡，佩服佩服！”\n", ob);
			return;
			} 		
	}
}

// This function starts killing between this_object() and ob
void kill_ob(object ob)
{
	if( member_array(ob->query("id"), killer)==-1 )
		killer += ({ ob->query("id") });

	tell_object(ob, HIR "看起来" + this_object()->name() + "想杀死你！\n" NOR);

	fight_ob(ob);
}

void clean_up_enemy()
{
	if( sizeof(enemy) > 0 ) {
		for(int i=0; i<sizeof(enemy); i++) {
			if( !objectp(enemy[i])
			||	environment(enemy[i])!=environment()
			||	(!living(enemy[i]) && !is_killing(enemy[i]->query("id"))) )
				enemy[i] = 0;
		}
		enemy -= ({ 0 });
	}
}

// This function checks if the current opponent is available or
// select a new one.
object select_opponent()
{
	int which;

	if( !sizeof(enemy) ) return 0;

	which = random(MAX_OPPONENT);

	return which < sizeof(enemy) ? enemy[which] : enemy[0];
}

// Stop fighting ob.
int remove_enemy(object ob)
{
	if( is_killing(ob->query("id")) ) return 0;

	enemy -= ({ ob });
	return 1;
}

// Stop killing ob.
int remove_killer(object ob)
{
	if( is_killing(ob->query("id")) ) {
		killer -= ({ ob->query("id") });
		remove_enemy(ob);
		return 1;
	}

	return remove_enemy(ob);
}

// Stop all fighting, but killer remains.
void remove_all_enemy()
{
	for(int i=0; i<sizeof(enemy); i++) {
		// We ask our enemy to stop fight, but not nessessary to confirm
		// if the fight is succeffully stopped, bcz the fight will start
		// again if our enemy keeping call COMBAT_D->fight() on us.
		if( objectp(enemy[i]) ) enemy[i]->remove_enemy(this_object());
		enemy[i] = 0;;
	}

	enemy = ({});
}

// Stop all fighting and killing.
void remove_all_killer()
{
	killer = ({});
	enemy -= ({ 0 });

	for(int i=0; i<sizeof(enemy); i++)
		if( enemy[i]->remove_killer(this_object()) )
			enemy[i] = 0;;

	enemy -= ({ 0 });
}

// reset_action()
//
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
//
void reset_action()
{
	object ob;
	string type, skill;

	if( ob = query_temp("weapon") )
		type = ob->query("skill_type");
	else 
		type = "unarmed";

	if( stringp(skill = query_skill_mapped(type)) ) {
		// If using a mapped skill, call the skill daemon.
		set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
	} else {
		// Else, let weapon handle it.
		if( ob ) set("actions", ob->query("actions",1) );
		else set("actions", query("default_actions",1) );
	}
}

// This is called in heart_beat() to perform attack action.
int attack()
{
	object opponent;

	clean_up_enemy();

	opponent = select_opponent();
	if( objectp(opponent) ) {
		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
}

//
// init() - called by MudOS when another object is moved to us.
//
void init()
{
	object ob;
	string vendetta_mark;

	// We check these conditions here prior to handle auto fights. Although
	// most of these conditions are checked again in COMBAT_D's auto_fight()
	// function, these check reduces lots of possible failure in the call_out
	// launched by auto_fight() and saves some overhead.
	if(	is_fighting()
	||	!living(this_object())
	||	!(ob = this_player()) 
	||	environment(ob)!=environment()
	||	!living(ob)
	||	ob->query("linkdead") )
		return;

	// Now start check the auto fight cases.
	if( userp(ob) && is_killing(ob->query("id")) ) {
		COMBAT_D->auto_fight(this_object(), ob, "hatred");
		return;
	} else if( stringp(vendetta_mark = query("vendetta_mark"))
	&& ob->query("vendetta/" + vendetta_mark) ) {
		COMBAT_D->auto_fight(this_object(), ob, "vendetta");
		return;
	} else if( userp(ob) && (string)query("attitude")=="aggressive" ) {
		COMBAT_D->auto_fight(this_object(), ob, "aggressive");
		return;
	} else if( random((int)query("bellicosity") / 40) > (int)query("cps") ) {
		COMBAT_D->auto_fight(this_object(), ob, "berserk");
		return;
	} 
}
