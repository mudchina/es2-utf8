// Room: /d/sanyen/road1.c

inherit ROOM;

void create()
{
	set("short", "石板大道");
	set("long", @LONG
一条铺著青石板的大道, 两旁种植一排芍药。北方就是大雄宝殿
, 一座上覆金瓦的雄伟建筑, 屋檐的四个角落雕就著四只栩栩如的金
龙, 屋檐下还各挂著一串金风铃, 清风吹来, 发出阵阵清脆的铃声。
东边有条小一点的石板路, 阵阵的药香就从东边传来。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
            "north" : "/d/sanyen/temple",
            "south" : "/d/sanyen/door",
            "east" : "/d/sanyen/road2",
	]));

	create_door("north", "金门", "south");

	set("outdoors", "sanyen");
	set("objects", ([
		__DIR__"npc/monk" : 1
	]) );

	setup();
	replace_program(ROOM);
}
