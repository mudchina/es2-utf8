inherit ROOM;

void create()
{
        set("short", "南花园");
        set("long", @LONG
你站在黑松城堡的南花园里。花园里长满了各式各样奇花异草。
再往北则是雄伟的黑松阁。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"east_blackge",
        ]));
        set("objects", ([
        __DIR__"npc/smallgardener" : 2,
        ]) );
        
        setup();
}
                