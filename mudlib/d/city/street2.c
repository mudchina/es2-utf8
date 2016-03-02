// Room: /d/city/street2.c

inherit ROOM;

void create()
{
        set("short", "京师东街");
        set("long", @LONG
你走在京师东街的中段。这里夹在紫禁城城墙与尚书府院墙之间
，南向的道路通向午门和尚书府的大门，而北方不远处振远总局的旗
杆依稀可见，令人隐隐约约地感到一种杀气。
LONG
        );

	set("objects", ([
		__DIR__"npc/walker":	2,
		]) );

        set("exits", ([ 
		"north":	__DIR__"street1",
		"south":	__DIR__"street3",
		]));

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

