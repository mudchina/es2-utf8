// iron-cloth.c

inherit SKILL;

string *absorb_msg = ({
        "$n已有准备，不慌不忙的运起铁布衫。\n",
        "$n闭目凝神，气走全身，护体硬功达到巅峰状态。\n",
        "$n「嘿」的一声，不躲不闪，运起铁布衫迎向$N！\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int learn_bonus()
{
        return 10;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 0;
}
