// ROOM:__DIR__"canyon4"

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short","隘口中道");
	set("long",@LONG                                   
来到这□，风势比其他地方大了许多，或许是因为东边为军营入口通
风较为良好的原因，南方一十里路的地方就是京城关口－天驼关的入口，
在西边的山壁似乎过于平滑，不太自然，或许这□有什么秘密也说不定。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==3 */
        	"north" : __DIR__"canyon3",
        	"south" : __DIR__"canyon5",
        	"east" : __DIR__"camp1",
	]) ); //eof(exits)
	
	setup();
	
} //EOF

void init()
{
	add_action("do_swear","swear");
} //eof(init)

int do_swear(string arg)
{
	object me;

	me=this_player();
	
	if (!this_player()->query_temp("军营/swear") ) return 0;
	
	if (!arg) return notify_fail("天空突然一声轰响:不要吵～～～\n");
	
	if (arg != "我爱安尼席洛特尔" && arg != "我爱东方故事II")
		return notify_fail("天空突然一声轰响:不要吵～～～\n");
		
	this_player()->set_temp("军营/swear", 0);
	
    	message_vision(HIB"突然间一阵强光将"HIW"$N"HIB"给罩住了\n"NOR,me);
    	message_vision(HIW"轰隆～～～～～～～～～～～～～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～轰隆～～～～～轰隆～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～～～轰隆～～～～～～～～轰隆～\n"NOR,me);
    	message_vision(HIC"$N"HIW"惨叫了一声:哇，好痛啊～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～～～～～～～～～～～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～～～～～～～～～～～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～～～～～～～～～～～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～～～～～～～～～～～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～～～～～～～～～～～～～～～～\n"NOR,me);
    
    	tell_room(__DIR__"blackmarket",me->name()+"被传送过来了。\n");
    	tell_room(environment(me),me->name()+"突然间消失了\n",me);
    	this_player()->move(__DIR__"blackmarket");
    	return 1;

} // EOF

