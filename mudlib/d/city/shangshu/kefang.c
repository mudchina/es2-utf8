// /d/city/shangshu/kefang

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "客房");
        set("long",@LONG
你走进了尚书府的客房。客房不大，但布置得比较整洁。靠窗的
小桌上摞放着几本书(book)，另一侧的墙上则挂了把宝剑，似乎告诉
来人此地主人竞是文武双全。
LONG
        );

        set("exits", ([
		"west":		__DIR__"road2"
                ]));

	set("item_desc", ([
		"book":	(: "一本诗词集，上面圈圈点点了一些句子.\n" :),
		]) );

	create_door ("west", "木门", "east", DOOR_CLOSED);

        setup();
}

