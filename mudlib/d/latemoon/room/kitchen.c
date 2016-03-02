
inherit ROOM;

void create()
{
   set("short", "厨房");
	set("long", @LONG
你走进厨房，看到有好多的烹饪用品与设备，小蒸笼、大锅、平  
炊灶、烧饭炉等，五花八门，式样齐全。旁边的大仓储中，更放满各
式各样山珍美味，各种材料，调味物品应有尽有。里头的掌厨师姐们
忙里忙外，在为准备一道道佳肴辛苦著! 闻到那阵阵美味的菜香，你
的肚子咕噜咕噜叫了起来!
LONG
	);
    set("exits", ([ 
    "west" :__DIR__"eat2",
    ]));
    set("objects", ([
        __DIR__"npc/obj/fire" : 1,
        __DIR__"npc/fochin" : 1,
    ]) );

	setup();
	replace_program(ROOM);
}
