// Room: /d/chuenyu/base_b_mtn.c
inherit ROOM;

void create()
{
        set("short", "黑松山脚");
        set("long", @LONG
一座高而险的山峰耸立在你面前。北面是一条上山的羊肠小路，盘旋曲折。
黑湮湮的松林给你不祥的感觉。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"sunnyroad",
          "up" : __DIR__"foot_b_mtn",
]));
        set("outdoors", "chuenyu");
        
        setup();
        replace_program(ROOM);
}
                          