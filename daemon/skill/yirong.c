// buddhism.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

string perform_action_file (string action )
{
	return "/daemon/class/nomad/yirong/yirong";
}

int valid_enable(string usage)
{
        return  (usage=="move");
}

