// Room: /u/cloud/wroad0.c

inherit ROOM;

void create()
{
        set("short", "绮云镇街道");
        set("long", @LONG
东边青板石铺的路与向西的碎石小径在这里汇合。西面仿佛是座庄
院，似可听到曲乐声，却又分辨不清; 北面是红娘庄，常常有一对对
男女来往。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/latemoon/entrance",
  "east" : __DIR__"wroad1",
  "north" : __DIR__"marry_room",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

