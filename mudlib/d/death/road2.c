// Room: /d/death/road2.c
 
inherit ROOM;
 
void create()
{
        set("short", "鬼门大道");
        set("long", @LONG
你走在一条阴森森的路上, 浓浓的雾环绕在你的四周, 好像永
远都不会散去似的. 整条路前后只看到零星的几盏灯笼........
 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/death/road3",
  "south" : "/d/death/road1",
]));
 
        setup();
}
int valid_leave(object me, string dir)
{
        int i;
        if (dir == "north") {
                i = (int)me->query_temp("long_road");
                i = i + 1;
                if (i == 5) {
                me->delete_temp("long_road");
                return 1;
                }
                else {
                        me->set_temp("long_road",i);
                        return notify_fail("你走著走著..... 发现四周景色居然都没有变....\n");
                }
        }
        else {
        if (dir == "south") {
                me->delete_temp("long_road");
                return 1;
                }
        return 1;
        }
}
