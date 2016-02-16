// /d/city/shangshu/yuan

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "尚书府庭院");
        set("long",@LONG
你走到了尚书府的庭院。院子很大，地面规规整整地用清一色的
大青石铺就，显示出主人的气派。东边的府门时常关着，不是高官可
甭想进来。西向是主人会客的客厅。北行的石路通向客房，而向南则
是去往内院。
LONG
        );

        set("exits", ([
                "west" :        __DIR__"gate",
                "east" :        __DIR__"keting",
		"south":	__DIR__"road3",
		"north":	__DIR__"road2",
                ]));
       
	set("outdoors", "city");

        create_door ("west", "大铁门", "east", DOOR_CLOSED);

        setup();
}

int valid_leave(object me,string dir)
{
        if ( (dir=="east" || dir == "west" )&&  !userp(this_player()))
        return 0;
        
	return ::valid_leave(me,dir);
}

