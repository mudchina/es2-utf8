inherit ROOM;
#include <ansi.h>

string look_sign(object me);

void create()
{
   set("short", "□香榭");
	set("long", @LONG
转过翠嫣桥，隐隐露出一带黄泥筑就矮墙，墙头用稻茎掩护，
有几百株杏花，如喷火蒸霞一般，里面数楹茅屋，外面却是桑、
榆、槿、杉各色树木新条，随其曲折编就两溜青篱，篱外有一土  
井，旁有一石牌(sign)。旁边有一些佳蔬菜花。
LONG
	);
    set("item_desc", ([
        "sign": (: look_sign :)
    ]) );
	set("exits", ([ /* sizeof() == 2 */
       "east" :__DIR__"bridge2",
       "northwest" :__DIR__"moon3",

]));

    set("objects", ([
        __DIR__"npc/rabbit" : 2 ]) );
	setup();
}

string look_sign(object me)
{
    if( wizardp(me) )
        return "这是一个任务提示。暂时未开放。\n";
    else
        return "\n 「六神」、「四鬼」、「三灵」 \n\n" +
            HIM "         旋芒震日月\n" +
                "         宝剑护河山\n\n" NOR ;
}
