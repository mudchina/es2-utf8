// Room: /d/waterfog/kitchen.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是水烟阁的厨房，东首一座大灶，灶边堆著许多瓦瓮，北边是
一张方桌，桌上锅碗瓢盆一应俱全，西边则是一个橱柜，往南可以回到
厅中。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"eaststair",
]));

	setup();
	replace_program(ROOM);
}
