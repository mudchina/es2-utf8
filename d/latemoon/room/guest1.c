
inherit ROOM;

void create()
{
     set("short", "客房");
	set("long", @LONG
这是一间客房，两边摆了一对小茶几。上面的彩绘瓶中插了一束
琼花，茶几旁两张雕漆椅。整个房间简朴幽静，为晚月庄供外客留宿
的一间厢房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" :__DIR__"two1",

]));

    set("objects", ([
        __DIR__"npc/guest" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
