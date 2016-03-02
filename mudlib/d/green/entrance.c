#include <room.h>

inherit ROOM;

void create()
{
        set("short","山路尽头");
        set("long",@LONG
你走到了山路的尽头，发现三面都是石壁，东面石壁上有一个洞口，洞内隐隐
发出风雷之声，洞口上方似乎刻着一副图(painting)，北面是一扇大石门，
门上苔迹斑斑，显然已经很久没人打开过了。
LONG
);
        set("exits",([ /* sizeof() == 3 */
                "north": __DIR__"outdoor",
                "east" : __DIR__"eight0",
                "south": __DIR__"mpath2",
        ])
	);
        create_door("north","大石门","south", DOOR_CLOSED);
        set("item_desc",([ 
        "painting":"这是一副八卦阵图,图下面有一行模糊的小字：八卦古阵\n"
        ]) 
        );

        set("no_clean_up",0);
        setup();
}

int valid_leave(object me,string dir)
{
        if ( dir == "east" && me->query("combat_exp") < 100000 ) 
                return notify_fail("你向石洞走去，忽然一阵狂风涌至，你抵受不住，只好退了回来\n");
        if ( dir == "east" ) {
		tell_room(environment(me),(string)me->query("name")+
        "向石洞走去，接着便消失在迷雾之中......\n",
        ({this_object(), me}));
	return 1 ;
	}
         else   return ::valid_leave(me,dir);
}

