// ROOM:__DIR__"road"

inherit ROOM;
void create()
{
        set("short","碎石小路");
	set("long",@LONG
你正走在碎石小路上，荒凉的景色，不难想像，这□人烟稀少，很少
人会走到这□来，在路尾是一半圆形的土堆，其下有一铁索，爬下铁索(
chain)就可以通达黄石隘口，而东北方是衔接至雪亭镇的青石官道。
LONG
	); // eof(long)

	set("item_desc", ([
        	"chain" : @TEXT
    一长条铁索缘山壁而下，或许你可以试著攀爬(climb)。
TEXT
	]) );
	
	set("exits",([ /* sizeof()==1 */
		"northeast" : "/d/snow/sroad3",
	]) ); //eof(exits)
	
	setup();
	
} 

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{ 
        object me;
        
        me=this_player();
        
	if ( arg != "chain" ) return 0;

        message_vision("$N手脚并用，努力地沿著铁索向下攀爬而去。\n",me);
                       
	me->receive_damage("gin", 20);
	me->receive_damage("kee", 30);
	me->receive_damage("sen", 10);
	
	if ( ((int)me->query("gin") < 0) ||
	     ((int)me->query("kee") < 0) ||
	     ((int)me->query("sen") < 0) ) {   //判别式
           	tell_room(__DIR__"canyon1",me->name()+"体力不支了。\n");
            	me->move(__DIR__"canyon1");
	        return 1;
	}
        
        tell_room(__DIR__"canyon1",me->name()+"平安的从上面爬了下来。\n");
	me->move(__DIR__"canyon1");
        return 1;
}

