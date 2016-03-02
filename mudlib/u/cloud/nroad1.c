// Room: /u/cloud/nroad1.c

inherit ROOM;

void create()
{
        set("short", "东市场");
        set("long", @LONG
这里是绮云镇的东市场，北面是药店，东面是兵器店。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/nwroad3",
  "north" : "/u/cloud/drugstore",
  "south" : "/u/cloud/nroad2",
  "east" : "/u/cloud/weapony",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

