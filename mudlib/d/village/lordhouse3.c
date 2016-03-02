// Room: /d/village/lordhouse3.c

inherit ROOM;
string look_shield();

void create()
{
	set("short", "财主家南房");
	set("long", @LONG
南房布置得象个书房，在屋子的中间有一张大书桌，靠西侧的墙上立
着一个书架(shield)，上面很摆了几本书。向南和向西开了两面大窗户，
向南望去，能模模糊糊地望见京城林立的楼阁；向西可以看到在田间忙碌
的田农。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lordhouse1",
]));
	set("item_desc",([
	//	"shield": "这书架上好象摆着八本书，你可以将它们中的某一本抽(take)出来，\n或将抽出来的书放回去(putback)。\n",
		"shield": look_shield(),
	]) );
	
	set("no_clean_up", 0);

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_takeout","take_out");
	add_action("do_push","push");
}

int do_takeout(string arg)
{
	object room;
	string num;
	
	if( !arg || arg=="" )
		return notify_fail("你要拿什么？\n");
	if( arg=="book" ) {
	write("你想拿第几本石书？\n");
	return 1;
	}
	
	if( sscanf(arg, "book %s", num)==1 ) {
	    if( num <"0" || num >"12" ){
	    	return notify_fail("有多少本书，你仔细点清楚了！\n");
	    }
	    switch( num ){
	    	case "9":
		    if( (int)query("key")==0 )
		    	add("key",1);
		    else
		    	add("key",6);
		    break;
	    	case "3":
		    if( (int)query("key")==1 )
			add("key",1);
		    else
			add("key",6);
		    break;
		case "11":
		    if( (int)query("key")==2 )
			add("key",1);
		    else
			add("key",6);
		    break;
		case "6":
		    break;
//		    if( (int)query("key")==3 ){
//		    	if( room = find_object("/d/village/lordhouse2") )
		   
		    }
	    }
	}

	return 1;
}

string look_shield()
{
//	string book[16];
	int iCount;
	return "are this true?\n";
}
