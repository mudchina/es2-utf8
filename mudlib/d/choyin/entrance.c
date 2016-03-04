// Room: /daemon/class/scholar/entrance.c

inherit ROOM;

void create()
{
	set("short", "曼雩台");
	set("long", @LONG
这里是雨桥庄西边的曼雩台，也是乔阴县城的文人墨客时常聚集谈
论诗文的地方，台宽约十丈，西边是连接乔阴县城的翠柳曲桥，从翠柳
湖中的片片睡莲中弯弯曲曲地通往西边的广场，北边和南边各有数十根
梁柱，常有许多落拓的士人将他们的作品贴在这里希望得到贵人赏识，
往东是一片桃树林，春天时和翠柳湖畔的柳树相辉映，蔚为乔阴县的第
一盛景。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"west" :	"/d/choyin/bridge5",
		"east" :	__DIR__"taolin",
]));

        set("objects", ([
                CLASS_D("scholar") + "/master":1,
		 ]) );

        set("valid_startroom", 1);

	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me,string dir)
{
        if ( dir=="east" && !(string)me->query("marks/书生") )
		return notify_fail("东行的道路被骆云舟挡住了.\n");
	if (dir=="east")
        	me->set("taolin_steps", 3);
	return ::valid_leave(me,dir);
}

