// Room: /u/cloud/entrance.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "绮云镇");
        set("long", @LONG
这里是绮云镇的入口。绮云镇是坐落在泓水北岸的一个大镇, 以其商业
发达和盛产茶叶而为来往客商们所青睐。北边过了卧龙岗就是著名的
封山剑派北宗所在的雪亭镇; 镇南有个渡口, 过了江就是少林的支脉 
-- 山烟寺。镇上很是热闹, 在这里就能听到南边集市上传来的叫卖声。
入口处有个官府的公告(sign), 不知是写了些什么。 
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :)
        ]) );

        set("exits", ([ /* sizeof() == 2 */
		  "northwest" : __DIR__"dragonhill/sroad",
		  "south" : __DIR__"nwroad1",
	]));

 //       set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}

string look_sign(object me)
{
        return "公告上写着:[启事] 由此入镇收取黄金一两\n";
}

