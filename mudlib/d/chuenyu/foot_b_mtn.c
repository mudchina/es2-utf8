// Room: /d/chuenyu/foot_b_mtn.c

inherit ROOM;

void create()
{
        set("short", "黑松山腰");
        set("long", @LONG
你正在艰难的走在唯一通往山顶的小路上。路边堆着很多面目
狰狞的巨石。几棵幼松顽强的从石缝中挤了出来。你在这
里可以看到山顶城堡的大致伦廓。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "down" : __DIR__"base_b_m",
          "up" : __DIR__"high_b_mtn",
          ]));
          set("outdoors", "chuenyu");
          
          setup();
          replace_program(ROOM);
}
                  
