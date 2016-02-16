// Mon  08-21-95

inherit ROOM;
 
void create()
{
        set("short", "洞口");
        set("long", @LONG
这里是山洞的入口, 往南看去是一条小小的碎石路, 两旁长满
杂草, 看来很不明显. 往北是一道厚厚的木门, 上面用一条手臂粗
的铁链拴著. 虽然如此, 你仍可以感到一股寒气从里面透出来.
 
LONG
        );
       set("exits", ([
       "south" : __DIR__"path0",
]));
 
        set("objects", ([
        __DIR__"npc/kid4" : 2,
		]) );
        setup();
        replace_program(ROOM);
}
 
