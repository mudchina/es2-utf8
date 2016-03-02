// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "巫师会客室");
	set("long",
		"这里是巫师和玩家聊天的地方，如果你有什么意见要让巫师们知道，在这里\n"
	"留言是最快的途径，不过如果是对于游戏中的问题，请您先确定我们提供的说明\n"
	"文件里没有说明，再提出疑问，巫师的主要职责并不是教玩家如何玩。\n");
	set("exits", ([
		"west" : "/d/wiz/hall1",
		"southeast": "/d/snow/inn" ]) );
	set("no_fight", 1);
	set("no_magic", 1);
        set("objects", ([
                "/d/wiz/npc/chpn" : 1 ]) );
	create_door("southeast", "木门", "northwest", DOOR_CLOSED);

	setup();
	call_other( "/obj/board/query_b", "???" );
}

int valid_leave(object me, string dir)
{
	if( dir=="west" && !wizardp(me) )
		return notify_fail("那里只有巫师才能进去。\n");
	return ::valid_leave(me, dir);
}

void init()
{
        add_action("re_route_cmd","",1);
}

int re_route_cmd(string str)
{
        string cmd;
        int i;
        string *invalid_cmds;
        cmd = query_verb();
        invalid_cmds = ({"meditate", "practice", "study", "exercise", "learn", 
                         "respirate"
                       });
        i = member_array(cmd, invalid_cmds);
        if (i == -1) return 0;
        else write("这里是巫师会客室, 不是让你拿来练功的地方哦!\n");
        return 1;
}

