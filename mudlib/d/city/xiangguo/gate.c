// /d/city/xiangguo/gate

inherit ROOM;

void create()
{
        set("short", "相国府大门");
        set("long", @LONG
你来到相国府的大门处。虽然相国在朝中也是地位显赫，但与对
面尚书府比起来，相国的府第显的寒酸得多。一切都十分简单，只有
牌匾上的「相国府」还提醒着人们主人的地位。
LONG
        );

        set("exits", ([
                "east":         "/d/city/street4",
                ]));
        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

