// Room: /d/village/fmhousback.c

inherit ROOM;

void create()
{
	set("short", "农舍后院");
	set("long", @LONG
在后院的左侧有个猪圈，几只小白猪在里面胡吃海塞，右面是一排鸡
笼，两个红皮鸡蛋落在鸡笼后边的槽里。这村子的妇女经常把自家产的鸡
蛋拿到京城去卖，去扯些花布或作件衣服。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"farmhouse1",
]));
	//set("no_clean_up", 0);
	set("objects", ([
		"/d/village/npc/woman1":1,	
		]) );
	setup();
	//replace_program(ROOM);
}
