// Room: /u/cloud/eroad1.c

inherit ROOM;

void create()
{
        set("short", "绮云镇街道");
        set("long", @LONG
这里是十字路口的东侧，两边房子里都颇为吵闹。北面似乎是家春
楼，不时可听到风尘女子的卖笑声。南面却是些三教九流的人物在吆三
喝五，象是家赌场。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/cross",
  "north" : "/u/cloud/jiyuan",
  "south" : "/u/cloud/duchang",
  "east" : "/u/cloud/eroad2",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

