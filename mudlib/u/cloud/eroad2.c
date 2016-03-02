// Room: /u/cloud/eroad2.c

inherit ROOM;

void create()
{
        set("short", "绮云镇街道");
        set("long", @LONG
这里是绮云镇东，通往茶场的路。南边是一家有名的大镖局 -- 振
远镖局。北面是绮云张家的宅院。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/eroad1",
  "north" : "/u/cloud/park",
  "south" : "/u/cloud/biaoju",
  "northeast" : "/u/cloud/eroad3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

