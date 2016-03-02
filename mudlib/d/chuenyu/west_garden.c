inherit ROOM;

void create()
{
        set("short", "西花园");
        set("long", @LONG
你站在黑松城堡的西花园里。花园里长满了各式各样奇花异草。
西侧高耸的城墙上长满了青色的蔓藤。蔓藤从墙顶一直垂到你的脚下。
再往东则是雄伟的黑松阁。
LONG
        );
        set("exits", ([
        "east" : __DIR__"west_blackge",
        ]));
        set("item_desc", ([
        "wall": "城墙虽陡，但长满了蔓藤。你似乎可以试着爬(climb)上去。\n",
        "城墙": "城墙虽陡，但长满了蔓藤。你似乎可以试着爬(climb)上去。\n",
        
        "蔓藤": "蔓藤长满了城墙，你似乎可以试着爬(climb)上去。\n"
         ]) );
         set("objects", ([
          __DIR__"npc/gardener" : 1,
          __DIR__"npc/bee" : 2,
          ]) );
          
          set("outdoors", "chuenyu");
          
          setup();
}

void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
        write("你要爬什么？\n");
        return 1;
        }
        if( arg == "wall" || arg == "蔓藤" || arg == "城墙")
        {
        me = this_player();
        message_vision("$N抓着蔓藤，慢慢的顺着城墙爬了上去。\n", me);
        me->start_busy(3);
         call_out("fliping",3,me);
         me->stop_busy();
         return 1;
         }
         else
         {
         write("你不可以爬"+arg+"\n");
          return 1;
          }
}

int fliping(object me)
{
        me->move(__DIR__"west_castle.c");
        message_vision("$N用手一撑墙头儿，轻巧的跳了过来。\n", me);
        return 1;
        
}
                                            