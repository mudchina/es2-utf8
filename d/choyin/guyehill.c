#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","绝壁");
        set("long",@LONG
    采药人言曰：有仙人乘鹤飞升，径入此山，不知所终.....
此地林木(tree)繁茂，藤蔓(vine)错杂。南耸绝壁，下临深谷.
半山腰处，隐隐可见一洞，流云出岫。
LONG
       );
        set("item_desc", ([
                "vine":
                    "其中有一根藤蔓距离你比较近，你可以试著抓住(hold)藤蔓\n",

                "tree":
                    "这是一株万年古树，寻常人等休想爬得上去.\n"

                          ]) );
        set("exits", ([ /* sizeof() == 1 */
                "northdown" : __DIR__"rockroad",
                      ]));
        set("outdoors", "choyin");
        setup();
}

void init()
{
        add_action("do_climb", "climb");
        add_action("do_hold", "hold");  
}
int do_climb(string arg)
{
        if( !arg || arg!="tree" ) return 0;
        message_vision("$N七手八脚地爬上了古树。\n",
                this_player());
        tell_room(__DIR__"craneroom",this_player()->query("name") + "树下爬了上来。\n");
        this_player()->move(__DIR__"craneroom");
        return 1;
}

int do_hold(string arg)
{
        if( !arg || arg!= "vine" )
                return notify_fail("你要抓住什么？\n");
        message_vision("$N伸手往不远处的一根藤蔓抓去....\n\n",
                this_player());
        if( random((int)this_player()->query_skill("dodge")) < 30 ) {
                message_vision("\n只听见一声杀猪般的惨叫，$N已坠落深谷。。\n\n
", this_player());  
        this_player()->move(__DIR__"hollow");        
      } else {
                message_vision("$N手脚俐落地攀附著藤蔓，慢慢地爬近山洞。\n\n",
                      this_player() );
        this_player()->move(__DIR__"halfhole");  
        }
        return 1;
}

