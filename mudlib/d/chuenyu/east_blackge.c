inherit ROOM;

void create()
{
        set("short", "黑松阁东厅");
        set("long", @LONG
这是黑松堡主淳于怀太迎宾的东厅。整个大厅布置的雍荣典雅。
向东和向西都是精心修剪过的花园。楼上则是淳于巨大的睡房。
偶尔有几声狗叫从东花园里传来。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
        "east" : __DIR__"east_garden",
          "south" : __DIR__"south_garden",
            "westup" : __DIR__"bedroom",
]));
                set("objects", ([
                __DIR__"npc/cleangirl" : 1,
                ]) );
                
                setup();
}

                                    