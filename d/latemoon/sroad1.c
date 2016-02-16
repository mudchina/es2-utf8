inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
你走在一条蜿蜒的小径, 小径的两旁是半个人高的杂草, 你可以感受
到清凉的微风从两侧吹来。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
         "southeast" :__DIR__"sroad2",
         "north" : "/d/sanyen/gate",
]));
        set("outdoors", "latemoon");

        setup();
        replace_program(ROOM);
}
