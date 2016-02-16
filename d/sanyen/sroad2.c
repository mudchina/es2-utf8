// Room: /d/sanyen/sroad2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这条山路到这里转了个弯，往东穿过一个山壁上凿出来的隧道，往
南则顺著山势缓缓下山。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
//  "south" : "/d/sanyen/sroad1",
 "northdown": "/u/cloud/sunhill/road4",
 "east" : "/d/sanyen/gate",
]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
