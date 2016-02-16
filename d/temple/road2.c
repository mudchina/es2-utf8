// Room: /d/temple/road2.c
#include <room.h>

inherit ROOM;

void create()
{
    seteuid(getuid());
	set("short", "青石小径");
	set("long", @LONG
绕过了后殿, 出现在眼前的是一栋木造两层高的屋子。屋子四周
的门窗都紧紧的关著, 门口上方挂著一方蓝色琉璃匾额, 上书『藏经
楼』三个金字。门旁立著一个石碑(slab)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "southeast" : "/d/temple/road1",
            "enter" : "/d/temple/book_room1",
]));

        set("item_desc", ([
            "slab" : "石碑上写著 : \n\n"
                     "    非\n"
                     "    茅  不\n"
                     "    山  得\n"
                     "    弟  进\n"
                     "    子  入\n\n"
           ]) );

    setup();

    reset();
}

void reset()
{
        ::reset();
        set("objects", ([ /* sizeof() == 2 */
            __DIR__"npc/guard_taoist" + (random(3)+1) : 1,
            __DIR__"npc/taoist_guard" + (random(3)+1) : 1,
           ]) );
}

int valid_leave(object me, string dir)
{
     if ( dir=="enter" && (string)this_player()->query("family/family_name") != "茅山派")      
          return notify_fail("\n一道无形的墙挡住了门口, 差点把你的鼻子给撞扁了。\n\n");
     if ( dir=="enter" && (string)this_player()->query("family/family_name") == "茅山派") 
         {
          message_vision("\n$N推开门走了进去, 顺手把门关了起来。\n\n", this_player());
          tell_room(__DIR__"book_room1", "你看到门被推了开来, 有人走了进来并随手把门带上。\n\n");
          ::valid_leave(me, dir);
         }
     return 1;
}
