// /d/city/shangshu/road4

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long",@LONG
你走在尚书府的一条僻静的小路上。这条小路连接着花园和一间
废弃的杂货屋，平常很少有人来此。东面的花园渐渐地远了，西面的
门都已经脱落的废屋已历历在目。北面是高耸的院墙。
LONG
        );

        set("exits", ([
		"west":		__DIR__"feiwu",
		"east":		__DIR__"huayuan",
                ]));

	set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

