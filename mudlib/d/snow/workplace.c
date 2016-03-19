#include <dbase.h>
#include <room.h>

inherit ROOM;
 
string look_sign ();

void create ()
{
	set ("short","谷物加工厂");
	set ("long", @LONG
这是一间谷物加工厂，这里是谷子脱壳成米的地方。米厂老板是一个一
看就知道是十分精明的干瘦的中年人，老是带着一脸奸笑。你可以看到
许多人正在忙忙碌碌的工作着，门口挂著一块牌子(sign)，往西是通往
雪亭镇大街的大门。
LONG
	);
	
	set ("no_fight", 1);
	set ("item_desc", ([
		"sign": (:look_sign :),
	]) );

	set ("exits", ([
		"west"		: "/d/snow/mstreet2" ]));

	setup ();
}

void init ()
{
	add_action ("do_work", "work");
}

int do_work ()
{
	object me;
        object silver;

	me = this_player ();
	
        if((int)me->query("gin")<30 || (int)me->query("sen")<30)
                return notify_fail ("你的精神太差了,现在不能工作.\n");
	
	printf("
你辛苦的工作终于结束了，可人也累的要死。
老板对你说：这是你的工钱。
");

	me->receive_damage( "sen", 30 );
	me->receive_damage( "gin", 30 );
 	silver=new(SILVER_OB);
	silver->set_amount(1);
	silver->move(me);
//	destruct(silver);
	return 1;
}
		
string look_sign ()
{
	return "告示
现在正紧缺人手，急需雇佣一批短工来干活。
工作(work)一次，给工钱纹银一两。
";
}
