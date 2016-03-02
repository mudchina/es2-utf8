
#include <ansi.h>
inherit ROOM;

void create()
{
     set("short","傍厅");
	set("long", @LONG
这里是晚月庄接待宾客的傍厅，厅中摆了一张桌几，上面摆著
一块大红镶金桌巾，靠东壁面西设著半旧青缎靠背引枕，两张太师
椅座。桌几上有一精致的茶壶，旁有盛好的上等茗茶。
LONG
	);
    set("resource/water", 1);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"latemoon1",
]));

    set("objects", ([
         __DIR__"npc/yumay" : 1  ]) );
	setup();
}
int valid_leave(object me, string dir)
{
        string item;
        object obj;

        item = "tea cup";
        if( !objectp(obj = present(item, me)) )  {
                tell_object(me, "你起身往南离开!\n" NOR );
        }  else  {
        if ( me->query_temp("latemoon/茶") ) {
                tell_object(me, HIC "你将瓷杯交回给雨梅。\n" NOR);
                me->set_temp("latemoon/茶", 0);
        destruct(obj);
           }
        }
        return 1;
}
