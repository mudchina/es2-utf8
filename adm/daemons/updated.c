// updated.c

void create() { seteuid(getuid()); }

void check_user(object ob)
{
	int v1, v2;
	string m;
	mapping my;

	ob->delete_skill("antielem");

	ob->delete_skill("octigua-magic");
	if( (string)ob->query_skill_mapped("spells")=="octigua-magic" )
		ob->map_skill("spells");
	if( (string)ob->query_skill_mapped("magic")=="octigua-magic" )
		ob->map_skill("magic");

	if( (v1=ob->query_skill("evolution", 1)) > 0 ) {
		if( (v2=ob->query_skill("magic", 1)) > 0 ) {
			ob->set_skill("spells", v2);
			if( stringp(m=ob->query_skill_mapped("magic")) ) {
				ob->map_skill("magic");
				ob->map_skill("spells", m);
			}
		}
		ob->set_skill("magic", v1);
		ob->delete_skill("evolution");
		ob->map_skill("evolution");
	}

	if( (v1=ob->query_skill("essence", 1)) > 0 ) {
		ob->set_skill("force", v1);
		ob->delete_skill("essence");
		if( stringp(m=ob->query_skill_mapped("essence")) ) {
			ob->map_skill("essence");
			ob->map_skill("force", m);
		}
	}

	my = ob->query_entire_dbase();
	if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
	if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
	if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];
	if( my["eff_gin"] > my["max_gin"] ) my["eff_gin"] = my["max_gin"];
	if( my["eff_kee"] > my["max_kee"] ) my["eff_kee"] = my["max_kee"];
	if( my["eff_sen"] > my["max_sen"] ) my["eff_sen"] = my["max_sen"];
	if( my["gin"] > my["eff_gin"] ) my["gin"] = my["eff_gin"];
	if( my["kee"] > my["eff_kee"] ) my["kee"] = my["eff_kee"];
	if( my["sen"] > my["eff_sen"] ) my["sen"] = my["eff_sen"];
}
