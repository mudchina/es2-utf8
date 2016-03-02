// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("店小二", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n"
	);

        set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("vendor_goods", ([
                "cake":	__DIR__"obj/cake",
                "fish":	__DIR__"obj/fish",
                "wine":	__DIR__"obj/wine",
        ]) );
        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
        add_action("go_up", "go");
}

int go_up (string arg)
{
        object me;

        me = this_player();

        if ( !me || environment(me) != environment() ) return 0;

        if( arg == "up" ) {
		if (!(me->query("rank")) && !(me->query("marks/酒楼"))) { 
			message_vision("店小二对$N一白眼:你是谁呀，闯什么闯！\n",me);
			write("上楼的路被店小二挡住了 。\n");
			return 1;
			}
		    else {
			message_vision ("店小二高声喊道:$N楼上请\n", me);
			me->move("/d/city/jiulou_2");
			return 1;
			}
	        }

        return 0;
}

int accept_object(object who, object ob)
{
        if ( ob->value() < 1000 ) {
                command("say 这点钱，还不够买酒喝。");
                command("drop all");
                return 1;
	        }

        if ( !who->query("marks/酒楼") )  {
                if( ob->value() >= 1000 ) {
                        command("say 谢谢这位客官了。");   
                        who->set("marks/酒楼",1);
                        return 1;
                	}
                }
            else
                command("say 真是谢谢你了。\n");

        return 1;
}

