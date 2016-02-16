// Room: /d/chuenyu/rope_bridge.c

inherit ROOM;

void create()
{
// this place can check on player's dodge, if toolow, drop them!
        set("short", "铁索桥");
        set("long", @LONG
山顶强劲的风吹得铁索桥左右晃动，脚下的万丈深渊使你头晕目旋。
你竭尽全力的维持身体平衡。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"high_b_mtn",
          "east" : __DIR__"high_b_mtn2",
          ]));
          set("objects", ([
          __DIR__"npc/jiading3" : 2,
          ]) );
          
          
          set("outdoors", "chuenyu");
          
          setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        if( !arg || arg!="chain" ) 
	{
	     write("这里只有一条铁链（chain）。\n");
             return 1;
	}

        message_vision("$N抓紧铁链，顺着铁索桥走了下去。\n",
                this_player() );
        this_player()->move(__DIR__"base_b_m");

        return 1;
}
                  
