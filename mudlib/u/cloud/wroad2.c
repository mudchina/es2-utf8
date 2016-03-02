// Room: /u/cloud/wroad2.c

inherit ROOM;

void create()
{
        set("short", "绮云镇街道");
        set("long", @LONG
这里是绮云镇西，东边就是十字路口。南面的院子里甚是喧闹，象
是有很多人的样子。北面是杂货铺，不过门不朝这个方向开。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/wroad1",
  "south" : "/u/cloud/monky",
  "east" : "/u/cloud/cross",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

