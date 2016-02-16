// /d/city/biaoju

inherit ROOM;

void create()
{
        set("short", "振远总局");
        set("long",@LONG
你来到了振远总局里。镖局虽然不大，但在京师这块土地上，已无人
不知其名。尤其是其总镖头，俨然是以京城武林领袖自居。
LONG
        );

        set("exits", ([
		"south":	__DIR__"street1",
                ]));

	set("objects", ([
		__DIR__"npc/chen":	1,
		]) );

        setup();
        set("valid_startroom", 1);
        replace_program(ROOM);
}

