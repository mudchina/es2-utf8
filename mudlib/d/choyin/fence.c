// Room: /d/choyin/fence.c
# include <room.h>
inherit ROOM;

void create()
{
  set("short", "竹林");
  set("long", @LONG
诺大的一片竹林，密密匝匝，望不道尽头。游目四顾，没有路了。
微风乍起，竹林深处现出一角竹篱(fence)。
LONG
);
  set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"club", 
    "eastup" : __DIR__"rockyu",
  ]));
  set("item_desc", ([
    "fence":"篱笆依地势而曲折延伸，你注意到柴门里面有一间草堂。\n",
  ]) );
  create_door("west", "柴门", "east", DOOR_CLOSED);
  set("no_clean_up", 0);      
  setup();
  replace_program(ROOM);
}
