// Room: /d/choyin/w_street1.c

inherit ROOM;

int do_lift (string arg);
int do_check ();

void create()
{
        set("short", "西大街");
        set("long", @LONG
这里是乔阴县城的西大街，西边就是县城的西门，一座巨大的牌楼
上刻著「西门」二字，往北有一条小巷，南边则是一间书肆，街道中央
立著一尊石狮(statue)，而且是站著的，将来往行人分为左右两道。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "statue" : 
"这尊石狮跟一般寻常人家放在门口镇宅避邪的石狮颇有不同，姿势是立
著的，而且大小要大得多，只怕有几万斤重，从来没见过谁能举起它。
你注意到石狮的额头上刻著一个「□」字，不知是何用意？
",
]));
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"w_street2",
]));
        set("no_clean_up", 0);
        set("outdoors", "choyin");

        setup();
}

void init()
{
        add_action ("do_lift", "lift");
	add_action ("do_check", "check");
}

void do_check()
{
	printf("%s\n", query("liftid"));
}

void check_trigger()
{
	object me ;
	me = this_player();

        if  ((int) query("lift_trigger") + me->query("str")/5 >= 10) {
                message("vision", "石狮子竟然向左移动了尺许，漏出向下的洞穴。\n"+
"$N从洞口掉了下去。\n",environment(me),({ me }) );
		me->move(__DIR__"lionroom");
                message_vision ("$N石狮子又缓缓地向右移动了尺许，正好盖住洞口。\n", me);
		set("liftid", me->query("id"));
                }
}

int do_lift (string arg)
{
	string id ;
	object ob;

        if (arg != "statue")
                return notify_fail("你要推什么？\n");

        message_vision ("$N努力地抬着石狮子，试图抬起一点点。\n", this_player())
;
	id = (string) query("liftid");
/*	if ( id && ( id != (string)this_player()->query("id")) ) 
		return 1 ;
*/
	if ( id ) {
		ob = find_player(id);
		if ( ob && (environment(ob)->query("short") == "神秘洞穴"))
		return 1;
		}

 	if ( !id ) set("liftid",(string)this_player()->query("id"));

        add("lift_trigger", 1);
        check_trigger();
        return 1;
}

/*int valid_leave(object me,string dir)
{
	if ( ::valid_leave(me,dir) ) {
		delete("liftid");
		delete("lift_trigger");
	}
	return 1;
}
*/
void reset()
{
        delete("lift_trigger");
	delete("liftid");
        ::reset();
}

