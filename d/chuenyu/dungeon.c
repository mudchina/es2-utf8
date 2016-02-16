// Room: /d/chuenyu/dungeon.c

inherit ROOM;

void create()
{
        set("short", "刑房");
        set("long", @LONG
你处在一个阴湿的地牢里。地牢的角落里堆着一些干草，干草上沾满了
暗红色的血迹。许多骷髅被生锈的铁链绑在墙上。偶尔之间，你还可以听到
老鼠“吱吱”的尖叫声。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"tunnel3",
          "north"   : __DIR__"tunnel4",
]));

        set("objects", ([
                __DIR__"npc/chuenyu" : 1,
                __DIR__"xiaojuan2" : 1,
        ]) );
                
                
        setup();
}
 
                                  