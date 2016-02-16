// /d/city/feiyuan

inherit ROOM;

int do_find ();

void create()
{
        set("short", "废园");
        set("long", @LONG
你来到一所废园里。据说废园的主人原也是位极人臣的，后来却
以「莫须有」的罪名被皇上斩了全族，其他的官员怕晦气，都不敢来
此住，遂形成废园。废园里荒草丛生，往日的辉煌已不再现，仅留下
几个残垣供人凭吊。
LONG
        );

        set("exits", ([
                "south" :       __DIR__"street6",
                ]));

        setup();
}

void init ()
{
	add_action ("do_find", "find");
}

int valid_leave(object me,string dir)
{
        if ( dir=="south" )
		tell_object(me, "突然你眼前似乎有什么东西一闪，然后又消失在草丛\n中。回去在草丛中找找（find）？\n\n\n");

        return ::valid_leave(me,dir);
}

int do_find ()
{
	object *list, me, token;
	int i;

	me = this_player ();

	list = all_inventory(me);
	i = sizeof(list);
        while (i--) {
              if (((string)list[i]->query("id")) == "token")
			return notify_fail("忙活了半天，没有什么新的发现。\n");
		}

	if (random(me->query("kar") + 30) >= 35) {
		token = new(__DIR__"obj/token");
		token->move(me);
		message_vision("$N竟找到了一个出城令。\n", me);
		return 1;
		}

	return notify_fail ("白忙了半天，一无所获。\n");
}


