// Room: /daemon/class/scholar/taolin

inherit ROOM;
/*
#define dir_east	0
#define dir_south	1
#define dir_west	2
#define dir_north	3
#define dir_southeast	4
#define dir_southwest	5
#define dir_northeast	6
#define dir_northwest	7
*/
string Get_Dir(string arg);
int do_read(string arg);
int do_go (string arg);

mapping Note_Msg = ([
        "欲将愁心附明月,随君直到夜郎--":"dir_west",
        "问君能有几多愁,恰似一江春水向--流":"dir_east",
        "自笑堂堂汉使,得似洋洋河水,依旧只流--":"dir_east",
        "--朝四百八十寺,多少楼台烟雨中":"dir_south",
        "孔雀--飞,五里一徘徊":"dir_southeast",
        "帘卷--风,人比黄花叟":"dir_west",
        "醉别--楼醒不记,春梦秋云,聚散真容易":"dir_west",
        "春草绿色,春水碧波,送君--埔,伤之如何":"dir_south",
        "--望，射天狼":"dir_northwest",
        "--风卷地白草折，胡天八月即飞雪":"dir_north",
        "青山横--郭，白水绕东城":"dir_north",
        ]);


string	*notemsg;
int 	msg_no;
// int tl_steps;
 
void create()
{
        set("short", "桃林");
        set("long", @LONG
这是很大的一片桃林。每年花开的季节，这里一片桃花灿烂，总引得
邻近的镇集的游客来观看，甚至京城的游客也不乏其人。桃林中阡陌纵横
，不熟悉此地的游客经常迷路。当然啦，一些先行者在桃树枝上挂了些字
条以指示道路。看。。字条（note）在那儿。。
LONG
        );

        set("item_desc", ([
                "note": (: "这是一张指示路径的字条.似乎可以读(read)它.\n" :),
        ]) );

        set("exits", ([ 
                "south" : 	__DIR__"taolin",
                "north" : 	__DIR__"taolin",
                "west" : 	__DIR__"taolin",
                "east" : 	__DIR__"taolin",
		"northwest":	__DIR__"taolin",
//		"northeast":	__DIR__"taolin",
		"southeast":	__DIR__"taolin",
//		"southwest":	__DIR__"taolin",
        ]));

	notemsg = keys(Note_Msg);
	msg_no = random(sizeof(Note_Msg));	
//        tl_steps = this_player()->query("taolin_steps");

	setup();
}

void init()
{
	add_action("do_read", "read");
	add_action("do_go", "go");
}

int do_read(string arg)
{
	if (arg != "note") 
		return notify_fail("你要读什么?\n");
	    else {
		message_vision("$N看见:"+notemsg[msg_no]+"\n", this_player()); 
		return (1);
		}
}

int do_go(string dir)
{
	int steps;
	object me;

	me = this_player();
	steps = me->query("taolin_steps");
	if (dir == Get_Dir(Note_Msg[notemsg[msg_no]])) {
		if (steps  <= 1) {
			me->delete("taolin_steps");
			message_vision("$N走出了桃林\n",me);
			me->set("marks/桃林", 1);
                        msg_no = random(sizeof(Note_Msg));
			me->move(__DIR__"entrance");
			message("vision",me->name()+"从桃林走了出来。\n",environment(me),({me}));
			return 1;
			}
		    else {
			steps -= 1;  
			me->set("taolin_steps", steps);
			}
		}
	    else {
		steps += 3;
		me->set("taolin_steps", steps);
		}
	
	msg_no = random(sizeof(Note_Msg));
	return 0;
}

string Get_Dir(string arg)
{
	switch (arg) {
		case "dir_east":	return ("east");
		case "dir_south":	return ("south");
		case "dir_west":	return ("west");
		case "dir_north":	return ("north");
		case "dir_southeast":	return ("southeast");
		case "dir_southwest":	return ("southwest");
		case "dir_northeast":	return ("northeast");
		case "dir_northwest":	return ("northwest");
		default:	return ("NULL");
	}

}
