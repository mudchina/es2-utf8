inherit ROOM;

void create()
{
   set("short", "紫翎小轩");
	set("long", @LONG
你一进了小轩内，只觉异香扑鼻，那些奇草仙藤，越冷越苍翠，
都结了实，似珊瑚豆子一般，累垂可爱。房内雪洞一般，清凉舒适  
，案上一个土定瓶，中供著数枝菊花，旁边放了两本书、茶瓯茶杯  
而已，床上只吊著青纱帐幔被褥，也十分朴实。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "east" :__DIR__"moon3",

]));

    set("objects", ([
        __DIR__"npc/girl_yu" : 1,
        __DIR__"npc/dodo1" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
