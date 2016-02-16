// Room: /u/cloud/eroad4.c

inherit ROOM;

void create()
{
        set("short", "茶场");
        set("long", @LONG
这里是绮云镇的茶场，绮云盛产茶叶，因此这里有不少茶工在忙着
采茶。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : "/u/cloud/eroad3",
]));

        set("objects", ([
                "/u/cloud/npc/worker" : 6,
        ]) );

        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

