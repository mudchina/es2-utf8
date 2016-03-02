// Room: /d/canyon/bamboo/train.c

inherit ROOM;

void create()
{
	set("short", "洞内石室");
	set("long", @LONG
飕飕的风不停地向你身上袭卷而来，石室的四周竟有四个大洞各
分布东南西北四方，向洞外望去亦是一遍遍的竹林，和之前的竹林只
差在于风势的大小，强风无情的猛击挺立的竹子，竹子左右摇晃的抵
抗著，正是一幅柔以破刚之图，壁上有一石制书柜(bookcase)，正散
出阵阵的蓝光，和之前所遇之正气一脉相连，匣中似有一物，看来才
是正气的来源。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"bamboo3",
]));

        set("item_desc", ([
        "bookcase" : "看起来是个普普通通的柜子，或许\你可以search看看。\n",
	]) );

	setup();
}

void init()
{
	add_action("search_case","search");
}

int search_case(string arg)
{
	object me,obj;
	
	if ( !arg || (arg!="bookcase") ) return 0;
	
	me=this_player();
	if ( query_temp("got") ) {
		message_vision("$N在书柜找了找但没找到些什么\n",me); 
		return 1;
	}
	
	message_vision("$N在书柜中找了到一个书匣\n",me);
	obj=new(__DIR__"obj/slipcase");
	obj->move(me);
	set_temp("got", 1);
	return 1;
}	
	
