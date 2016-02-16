// inn.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "饮风客栈");
	set("long", @LONG
你现在正站在雪亭镇南边的一家小客栈里，这家客栈虽小，却是方圆
五百里内最负盛名的一家，客栈的主人据说是一位云游四海的仙人，如果
你的福缘深厚的话，也许可以在这里遇到他。除此之外，来自各地的旅人
都喜欢聚集在这里交换旅途上的见闻，你也可以在这里打听到许多有趣的
消息。靠近门口的地方有一块乌木雕成的招牌(sign)。
    西北边有一个红木门(door)，门上泛著一层白色的光晕，一种令人感
觉很有力量，又很柔和的光芒。
LONG
	);

	// This enables players to save this room as their startroom.
	set("valid_startroom", 1);

	set("item_desc", ([
		"sign": (: look_sign :),
		"door": (: look_door, "northwest" :),
	]) );
	
	set("exits", ([
		"east"    	: "/d/snow/square",
		"up"		: "/d/snow/inn_2f",
		"northwest"	: "/d/wiz/entrance" ]) );

	set("objects", ([
		"/d/npc/sungoku" : 1,
		"/d/snow/npc/traveller" : 3,
//		"/d/snow/npc/trav_blade" : 3,
                "/d/snow/npc/waiter" : 1 ,]) );

	create_door("northwest", "木门", "southeast", DOOR_CLOSED);

	setup();

	// To "load" the board, don't ever "clone" a bulletin board.
	call_other( "/obj/board/common_b", "???" );
}

string look_sign(object me)
{
	if( wizardp(me) )
		return "招牌写著：饮风客栈。旁边一排小字：庄思哑题。\n";
	else
		return "招牌写著：饮风客栈。\n";
}
