// Room: /d/choyin/court1.c

inherit ROOM;

void create()
{
	set("short", "县府衙门");
	set("long", @LONG
这里是乔阴县府衙门的大门，就像你印象中的衙门一般，高大的大
门、两只巨大的石狮、以及一种令人为之肃然的气氛。门口有一面大皮
鼓(drum)，不用说，这当然是让百姓击鼓申冤用的，乔阴县的知县据说
是槐阳王的侄子，虽然算不上是包青天，不过倒也没有听说过有什么贪
赃枉法的劣迹。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"crossroad",
	]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");
	set("objects", ([
		__DIR__"npc/judge_gu.c" : 4,
                __DIR__"npc/magistra.c" : 2
	]) );

	setup();
	replace_program(ROOM);
}
