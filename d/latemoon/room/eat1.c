
inherit ROOM;

void create()
{
    set("short", "大饭厅");
	set("long", @LONG
你走进一间装饰华丽的大饭厅，有一种说不出的气派，一张杉木  
雕饰的大圆桌子在厅子中央，铺著丝绸彩桌巾，上等南湖紫玉盘，湘
陵的瓷玉碗，银匙金筷。十分奢华。这是晚月庄宴请宾客的地方，平
常也是庄主及庄内辈份高的前辈用膳的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"eat2",
     "west" :__DIR__"twoc",

]));

    set("objects", ([
        "/d/latemoon/obj/food2" : 1,
        "/d/latemoon/obj/food3" : 2,
    ]));
	setup();
	replace_program(ROOM);
}
