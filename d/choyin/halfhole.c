inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
这里就是半山腰处的山洞。四壁空无一物，极为荒凉......
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "down" : __DIR__"guyehill",
                   ]));
        set("objects", ([
                __DIR__"obj/goldenrope" : 1,
               ]) );

        setup();
        replace_program(ROOM);
}

