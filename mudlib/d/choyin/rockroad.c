inherit ROOM;

void create()
{
        set("short", "砾石路");
        set("long", @LONG
    这是一条铺著砾石的上路，险峻难行。南面一座高山，云雾
缭绕险峻异常。山前断碑字迹依稀可辨--「姑射山』。传说中有
位仙人曾居于此地，不知如今还在不在......
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/choyin/spath",
  "southup" : "/d/choyin/guyehill",
]));
        set("outdoors", "choyin");
        replace_program(ROOM);
        setup();
}

