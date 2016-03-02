// /d/city/shangshu/feiwu

inherit ROOM;

void create()
{
        set("short", "废屋");
        set("long",@LONG
这是一间已被废弃的小屋。小屋很阴暗，也很潮湿。就着微弱的光线
，隐约看见小屋里胡乱地堆放着一些杂物。小屋里到处挂着蜘蛛网，显然
很久没有人来过了。
LONG
        );

        set("exits", ([
		"east":		__DIR__"road4",
                ]));

        setup();
        replace_program(ROOM);
}

