inherit ROOM;
#include <room.h>
void create()
{
        set("short", "刘家小房");
        set("long", @LONG
这是一所很破旧的木屋。每当山风吹来，都会发出“吱吱呀呀”
的声音。南侧是一个小小的厨房。木屋的后面是一个精巧的花园，花
园里穿来阵阵打闹之声。一个翠绿的小草坪就在西面。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "south" : __DIR__"smallstorage",
          "north" : __DIR__"littlegarden",
            "west" : __DIR__"smallyard",
              "southwest" : __DIR__"dustyroad3",
              ]));
              
              create_door("southwest", "木门", "northeast", DOOR_CLOSED);
              
              
              set("objects", ([
              __DIR__"npc/oldliu" : 1,
                      ]) );
                      
              setup();
}
