// tearoom.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
        set("short", "香茗坊");
        set("long", @LONG
你来到绮云镇西边的一家茶坊里, 它的历史已不下百年, 绮云镇本 
就是以盛产茶叶而闻名于世, 因此茶楼的生意出奇的好。
    高高悬起的金匾(sign)让你的有一种眩晕的感觉, 幸好阵阵茶香使
你清醒了许多。
    站在门口, 你可以看到北首有一扇不太起眼的木雕门(door)。
    东侧的楼梯通往楼上的雅座, 不时能听到上面传来丝竹之声和阵阵
笑声... 
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :),
                "door": (: look_door, "north" :),
        ]) );

        set("exits", ([
                "south"          : "/u/cloud/nwroad3",
                "west"           : "/u/cloud/nwroad1",
                "north"          : "/u/cloud/tea_corridor",
                "up"             : "/u/cloud/tearoom2" ]) );

        set("objects", ([
                "/u/cloud/npc/tea_waiter" : 1,
 ]) );

        create_door("north", "木雕门", "south", DOOR_CLOSED);
       set("valid_startroom", 1);

        setup();

        "/u/cloud/board/common_b"->foo();
}

string look_sign()
{
        return "匾上写着: 香茗坊 ， 旁边一排小字: 御赐亲笔。 \n";
}


