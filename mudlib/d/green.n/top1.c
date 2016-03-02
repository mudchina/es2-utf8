// Mon  08-21-95

inherit ROOM;

string long_desc();
string look_ring();
string look_drawing();

void create()
{
    seteuid(getuid());
    set("short", "突出的石块");
    set("long", (: long_desc :));
    set("long.desc", @LONG
你站在山壁上一个突出的平台上. 再上去都是光滑的岩壁. 往下
看去你可以看到几间屋子和道路. 岩壁上有一个奇怪的图形(drawing).
LONG
	);
    set("item_desc", ([
    "ring" : (: look_ring :),
    "drawing" : (: look_drawing :),
    ]) );
    set("outdoors", "green");

	setup();
    //replace_program(ROOM);
}

void reset()
{
    ::reset();
    delete_temp("has_rope");
}

void init()
{
    add_action("do_climb","climb");
    add_action("do_jump","jump");
    add_action("do_tie", "tie");
}

string long_desc()
{
    string str;
    str = query("long.desc");
    if (!query_temp("has_rope")) return str+"平台边有一个铁环(ring).\n";
    else return str+"平台边有一个铁环(ring). 上面绑著一条绳子.\n";
}

int do_climb(string str)
{
    if (!str) return notify_fail("往那爬? 爬那里?!?\n");
    if (!query_temp("has_rope"))
        return notify_fail("嗯.... 没有绳子的话跟跳(jump)下去没两样.\n");
    if ((str != "rope") && (str != "down"))
        return notify_fail("嗯.... 你不可能爬得上去的.\n");
    write("你深深地吸了一口气, 看准方位, 拉了绳子慢慢的往下爬...\n");
    tell_room(environment(this_player()),
    (string)this_player()->name()+"深深地吸了一口气, 拉著绳子开始往下爬.\n",
    this_player());
    this_player()->move(__DIR__"field2");
    tell_room(__DIR__"wall1",
    (string)this_player()->name()+"拉著绳子从你旁边经过, 可惜你构不到绳子.\n",
    this_player());
    tell_room(environment(this_player()),
    (string)this_player()->name()+"从上面爬下来.\n",
    this_player());
    return 1;
}

int do_jump(string str)
{
    object ob;
    ob = this_player();
    if (!str) return 0;
    if (str != "down") return 0;
    tell_room(environment(ob), (string)ob->name()+"纵身往下跳.\n", ob);
    write("你深深地吸一口气, 纵身往下跳.\n");
    if ((int)ob->query("force") >= 300) {
    ob->move(__DIR__"field2");
    tell_room(environment(ob), (string)ob->name()+"从上面跳了下来.\n", ob);
    }
    else {
    write("忽然觉得一口气换不过来....\n");
    ob->move(__DIR__"field2");
    write("碰! 地一声, 头先著地.\n");
    ob->unconcious();
    tell_room(environment(ob), "碰! 地一声, 一件重物从上面掉下来.\n", ob);
    }
    tell_room(__DIR__"wall1","一个人影从你身旁飞过.\n");
    return 1;
}

string look_ring()
{
    if (this_player()->query_temp("looked_ring"))
    return "一个生锈的铁环, 大概可以绑(tie)绳子吧.\n";
    else return "一个生锈的铁环.\n";
}

string look_drawing()
{
    this_player()->set_temp("looked_shape",1);
    return (@SHAPE
    □ ││      ││
     —┘└———┘└— <- W
     —┐┌———┐┌—
     —┘└———┘└— <- 57
     —┐┌———┐┌—             □
     —┘└———┘└————————— <- 181
     —┐┌———┐┌—————————
                  ^67
SHAPE
    );
}

int do_tie(string str)
{
    object ob;
    if (!str) return notify_fail("绑啥?\n");
    if (str != "rope") return notify_fail("你还想要绑啥?\n");
    ob = present("rope",this_player());
    if (!ob) return notify_fail("你没有绳子...\n");
    destruct(ob);
    write("你小心地将绳子绑在铁环上.\n");
    tell_room(environment(this_player()),
    (string)this_player()->name()+"将绳子绑在铁环上.\n",
    this_player());
    set_temp("has_rope",1);
    return 1;
}

