// Room: /d/sanyen/sroad1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条铺著生满青苔大石的山路，但是路面大概常有人行走，因
此倒也并不湿滑，往南是一段石阶缓缓下山，往北则是通往山中的山路
，东面的山壁上刻著「山烟寺」几个大字，看起来岁月已经颇久了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
//  "north" : "/d/sanyen/sroad2",
  "west" : "/d/sanyen/sroad2",
"northdown" : "/u/cloud/sunhill/road4",
//  "southdown" : "/d/snow/eroad3",
]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
