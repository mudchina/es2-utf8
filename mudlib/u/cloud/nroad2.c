// Room: /u/cloud/nroad2.c

inherit ROOM;

void create()
{
        set("short", "南市场");
        set("long", @LONG
这里是绮云镇的南市场，西面是杂货铺，向东可看到 怡红院 的二楼。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/zaihuoy",
  "north" : "/u/cloud/nroad1",
  "south" : "/u/cloud/cross",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

