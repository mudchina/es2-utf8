// Room: /d/city/jitan.c

inherit ROOM;

void create()
{
	set("short", "祭坛");
	set("long", @LONG
这是一片宽阔的小广场，广场的中间是皇家的祭坛(altar)，每年
朝廷庆祝丰收或祈祷的重大典礼都在这里举行，皇上、皇后和文武百
官能上祭坛，其他人只能从旁边绕过去。除了禁卫军的官兵和宫里的
杂役偶尔出入外，很少有人来往。往南是紫禁城的神武门，北面是一
个非常热闹的十字路口。
LONG
	);
	set("exits", ([
		"south" : "/d/city/shenwumen",
		"north" : "/d/city/street7",
	]));
	set("item_desc", ([
		"altar": 
	"园祭坛的栏杆是用汉白玉作成的，坛面由精细磨过的花岗岩铺成，中\n"
	"间有个台子(platform)。\n",
		"platform": 
	"只有皇帝能站在这个汉白玉台子上面，隐约地你好象看到台子的下面\n"
	"有个凸起(sth)。\n",
		"sth": 
	"这很象一个按钮(button)，上面长着细细的青苔，你突然一阵莫名其\n"
	"妙的紧张，好奇心却驱使你摸摸这个按钮，你发现它可以按(press)，\n"
	"也可以旋转(turn)。\n"
	]) );

	setup();
}

void init()
{
	add_action("do_turn", "turn");
	add_action("do_press", "press");
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision", "地板忽然发出轧轧的声音，一块地面缓缓移动著，将向下的通道盖\住了。\n",
		this_object() );
	if( room = find_object("/d/city/midao1") ) {
		room->delete("exits/up");
		message("vision", "天花板忽然发出轧轧的声音，向上的阶梯又缓缓地收了回去。\n",
			room );
	}
	delete("exits/down");
}

int do_turn(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="button" ) {
		write("你转了转这个按钮，它顺时针和逆时针方向都能转动。\n");
		return 1;
	}
	if( sscanf(arg, "button %s", dir)==1 ) {
		if( dir=="forward" ) {
			message_vision("$N将按钮沿顺时针转了一圈，什么事情也没发生。\n", this_player());
			add("forward", 1);
			return 1;
		} else if( dir=="backward" ) {
			message_vision("$N将按钮沿逆时针转了一圈，什么事情也没发生。\n$N忽然打了个冷颤，可能是心里害怕了。\n", this_player());
			add("backward", 1);
			return 1;
		} else {
			write("你想让它顺时针(forward)转还是逆时针(backward)转？\n");
			return 1;
		}
	}
}


int do_press(string arg)
{
	string dir;
	object room;

	if( !arg || arg=="" ) return 0;

	if( arg=="button" ){ //return 0;

	if( (int)query("forward")==1
	&&	(int)query("backward")==3
	&&	!query("exits/down") ) {
		message("vision", "地板忽然发出轧轧的声音，一块地面缓缓移动著，露出一个向下的阶梯。\n",
			this_object() );
		set("exits/down", "/d/city/midao1");
		if( room = find_object("/d/city/midao1") ) {
			room->set("exits/up", __FILE__);
			message("vision", "天花板忽然发出轧轧的声音，露出一个向上的阶梯。\n",
				room );
		}
		delete("forward");
		delete("backward");
		call_out("close_passage", 3);
	}
	return 1;}
}


void reset()
{
	::reset();
	delete("forward");
	delete("backward");
}
