// Mon  08-21-95

inherit ROOM;

string long_desc();

void create()
{
    set("short", "屋后空地");
    set("long", (: long_desc :) );
    set("long.desc", @LONG
你来到屋后一处空地, 地面长满了杂草. 东面是垂直的山壁, 往上看
似乎可以看到一块突出来的岩石. 岩壁上可看到不少坑洞 (hole).
LONG
	);
    set("item_desc", ([
    "hole" : @HOLE
仔细地观察这些坑洞后, 你发现这里原来可能有一座通往上面的梯子.
试了试那些洞, 你想你「可能」爬得上去....

HOLE
    ]) );
    set("exits", ([
    "southwest" : __DIR__"field1",
]));
    set("outdoors", "green");

	setup();
    //replace_program(ROOM);
}

void init()
{
    add_action("do_climb","climb");
}

string long_desc()
{
    string str;
    object ob;
    str = query("long.desc");
    ob = first_inventory(__DIR__"wall1");
    if (!ob) return str+"\n";
    else
    return sprintf("%s\n可怜的%s正在上面挣扎。\n",
        str,(string)ob->name());
}

int do_climb(string str)
{
    object ob;
    if (!str) return notify_fail("往那爬? 爬那里?!?\n");
    if ((str != "wall") && (str != "up"))
        return notify_fail("嗯.... 你不可能爬得上去的.\n");
    ob = first_inventory(__DIR__"wall1");
    if (!ob) { // can climb
        write("你深深地吸了一口气, 看准方位, 慢慢的往上爬...\n");
        tell_room(environment(this_player()),
        (string)this_player()->name()+"深深地吸了一口气, 开始往上爬.\n",
        ({this_object(), this_player()}) );
        this_player()->move(__DIR__"wall1");
        return 1;
    }
    else {
        return notify_fail(sprintf("你抬头看去, %s正在很努力的往上爬... 不要吓他...\n",
                                    (string)ob->name()));
    }
}

