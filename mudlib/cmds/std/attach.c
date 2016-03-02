// attach.c 

int main()
{
	object* list;
	object me, ob;
	int i;
	int tag_havesheet = 0;
	string func_path, func_name, func_arg;

	me = this_player();

	list = all_inventory(me);
	i = sizeof(list); 
	while (i--) {
		ob = list[i];
		if (((string)ob->query("id")) == "sheet") {
			tag_havesheet = 1;
			break;
			}
		};

	if ( !tag_havesheet )
		return notify_fail("有没有搞错？你没有sheet啊。\n");

	func_path = (string) ob->query("func_path");
	func_name = (string) ob->query("func_name");
	func_arg = (string) ob->query("func_arg");


	if (wizardp(this_player()))
		tell_object(this_player(), sprintf("%s, %s, %s\n", func_path, func_name, func_arg));

	ob->move("/obj/void");
	switch (func_name) {
		case "do_scribe_haunt":
			func_path->do_scribe_haunt(func_arg);
			break;
		default:
			return notify_fail ("你不会这种符啊！\n");
		}

	return 1;
}

