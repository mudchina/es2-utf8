// Room: /u/cloud/nwroad3.c

inherit ROOM;

void create()
{
        set("short", "中市场");
        set("long", @LONG
这里是绮云镇的中市场，北面是茶楼，南面是杂货铺。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/nwroad2",
  "north" : "/u/cloud/tearoom",
  "south" : "/u/cloud/zaihuoy",
  "east" : "/u/cloud/nroad1",
]));
        set("outdoors", "cloud");

        set("objects", ([
                "/obj/npc/garrison" : 2,
        ]) );

        setup();
        replace_program(ROOM);
}

