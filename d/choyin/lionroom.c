// This is a room made by roommaker.

inherit ROOM;

int do_smell(string arg);

void create()
{
	set("short", "神秘洞穴");
	set("long", @LONG
洞内黑漆漆的，几乎什么都看不见，只是在一个角落里
有两点红光闪烁，凭你多年的经验，那一定是一双野兽的眼
睛。这个地方最好不要久留。
LONG
);
	set("objects", ([
		__DIR__"npc/lion":1,
	]) ) ;

	set("no_magic", 1);
	setup();
}

void init()
{
	add_action ("do_smell", "smell");
}

int do_smell (string arg)
{
	object* list;
	int i;

	if (arg != "grass")
		return notify_fail ("你要用什么？\n");

	list = all_inventory(this_player());  
	i = sizeof(list);
	while (i--) {
		if (((string)list[i]->query("id")) == "grass")
			message_vision("一阵怪风骤然刮起，$N仿佛腾云驾雾般。\n", this_player());
			this_player()->move ("/u/cloud/biaoju");
			return 1;
		}

	return notify_fail ("你身上没有忘忧草啊。\n");
}
