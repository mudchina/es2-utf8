inherit ROOM;

void create()
{
        set("short", "黑松阁正厅");
        set("long", @LONG
黑松阁正厅完全是用檀香木打造的。一阵阵的檀香飘过来，
使你心旷神夷。厅口悬着一幅字画，写道：“是非成败转头空，
青山依旧在，几度夕阳红。”整幅字画是用一条很粗的绳子挂起
来的。
LONG
        );
        set("exits", ([
        "west" : __DIR__"west_blackge",
        ]));
        set("item_desc", ([
        "rope": "这根绳子顺着墙垂下来，你似乎可以拉(pull)它，但是你有一种不祥的感觉。\n",
        "绳子": "这根绳子顺着墙垂下来，你似乎可以拉(pull)它，但是你有一种不祥的感觉。\n",
        ]) );
        
        
        setup();
}

void init()
{
        add_action("roping", "pull");
}

int roping(string arg)
{
        int i;
        int damage;
        object obj;
        object ob;
        object me;
        ob = this_player();
        if(!arg || arg=="")
        {
                write("你要拉什么？\n");
                return 1;
        }
        if( arg == "rope" || arg == "绳子" )
        {
        me = this_player();
        message_vision("$N试着拉了一下绳子，触动了翻板，整个人“轰隆”一声掉了下去！\n", me);
        me->move(__DIR__"tunnel1");
        message_vision("$N“轰隆”一声，从上面掉了下来！摔得你好痛！\n", me);
        i = (int)ob->query("eff_kee");
        damage = random(10)+5  ;
        ob->set("eff_kee",(int) i - damage );
        i =  (int)ob->query("kee");
        ob->set("kee",(int) i - damage);
        
        return 1;
        }
        else
        {
                write("你不可以拉"+arg+"\n");
                return 1;
        }
}
                                                