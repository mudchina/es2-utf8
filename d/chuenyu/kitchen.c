#include <room.h>
inherit ROOM;

void create()
{
        set("short", "膳房");
        set("long", @LONG
这是淳于堡主的用膳房。整个房间飘荡着上等竹叶青的酒香和
令人垂滟欲滴的烤山猪的香气。你似乎听到你的肚子在“咕咕咕”
的叫了起来。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"bedroom",
        ]));
        set("objects", ([
        __DIR__"obj/pigmeat" : 3,
        __DIR__"obj/qiwine" : 3,
        __DIR__"npc/cook" : 1,
        ]) );
        
        
        create_door("north", "玉帘门", "south", DOOR_CLOSED);
        
        setup();
}

                