// /d/city/street5

inherit ROOM;

void create()
{
        set("short", "京师西街");
        set("long",@LONG 
你现在正走在京师的街道上，西边是京师最有名的“太白酒楼”，
酒楼里三教九流的人物都有，嘈杂声不绝于耳。东边紧邻着紫禁城的
城墙(wall)。街道向南北方向延伸着。
LONG
        );

        set("exits", ([
		"west" :	__DIR__"jiulou",
		"south" : 	__DIR__"street4",
		"north" :	__DIR__"street6",
		]));
        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

