// Room: /d/choyin/stove.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "丹炉");
	set("long", @LONG
雷霆不断击向一粒粒仙丹,仙丹慢慢由黑转为红色.你注意到炉门好象开着.
LONG
	);
         
        tell_room("d/choyin/tongbhill","山洞中喷出一股烈焰, 烤得你觉得自己象个夏威夷烤乳猪......\n"); 
        set("exits",(["out":__DIR__"tongbhill",])); 
        set("no-magic",1);
        set("objects", ([
                __DIR__"obj/tablet" :5,  
                       ]) );     
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
