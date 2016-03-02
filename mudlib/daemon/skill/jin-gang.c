inherit FORCE;

int valid_enable(string usage) { return usage=="iron-cloth"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("金刚不坏功只能用学的。\n");
}

 
int effective_level() { return 20;}

string *absorb_msg = ({
        "$n双臂一震，金刚不坏功力决堤似的澎湃而出。\n",
        "$n施展出金刚不坏功中的「弹」字诀，一股弹力传入$N的体内。\n",
        "$n使出一招「苦海无涯」，凝虚为实，浑身硬如金刚。\n",
        "$n施展出金刚不坏功，对抗$N的一击之力。\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
        return 10;
}

int learn_bonus()
{
        return -10;
}
int practice_bonus()
{
        return -5;
}
int black_white_ness()
{
        return 20;
}
