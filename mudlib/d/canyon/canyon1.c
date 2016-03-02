// ROOM:__DIR__"canyon1"

inherit ROOM;
void create()
{
        set("short","黄石隘口尾");
	set("long",@LONG
脚下为碎石黄土路，两侧是高耸入云的荒山，向上仰望乃似无边无际
穹空，北缘为一山壁，壁上有一长达十七、八丈的铁索(chain) ，上面大
概就是人家所谓的「关外绿洲－雪亭镇」。
LONG
	); // eof(long)

	set("item_desc", ([
        	"chain" : @TEXT
    一长条铁索缘山壁而上，若无绝佳的体力就好不要轻意攀爬(climb)。
TEXT
	]) );
	
	set("exits",([ /* sizeof()==1 */
		"southwest" : __DIR__"canyon2",
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

        message_vision("$N手脚并用，努力地沿著铁索向上攀缘上去了\n",me);
                       
	me->receive_damage("gin", 30);
	me->receive_damage("kee", 40);
	me->receive_damage("sen", 20);
	
	if ( ((int)me->query("gin") < 0) ||
	     ((int)me->query("kee") < 0) ||
	     ((int)me->query("sen") < 0) ) {   //判别式
           	tell_room(__DIR__"road",me->name()+"体力不支了。\n");
            	me->move(__DIR__"road");
	        return 1;
	}
        
        tell_room(__DIR__"road",me->name()+"平安的从下面爬了上来。\n");
	me->move(__DIR__"road");
        return 1;
}

