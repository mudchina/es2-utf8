// Room: /d/oldpine/epath2.c

inherit ROOM;

void create()
{
	set("short", "小石桥");
	set("long", @LONG
你现在正站在一座长满青苔的古桥上，桥下是一条山涧，几股清泉
在乱石之中向山下奔流，桥北边不远处有一个瀑布(waterfall) ，从山
壁上犹如一条白练般垂了下来，瀑布两旁的石壁十分陡峭，高度和山涧
旁的松林相差了近三、四十丈。
LONG
	);
	set("item_desc", ([
		"waterfall":
			"这个瀑布从数百丈高的山壁上冲激而下，流入一个山涧底的小水潭\n"
			"，水潭两边的石壁垂下许\多的藤蔓(vine)，你注意到瀑布后面似乎\n"
			"有什么东西在发著光。\n",
		"vine":
			"其中有一根藤蔓距离你比较近，你可以试著抓住(hold)藤蔓，看看\n"
			"能不能像泰山一样荡过去，看看瀑布后面有什么？\n"
			"对了，提醒你一点，这座石桥下面是高约百丈的山涧深谷....。\n"
	]) );
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/oldpine/epath1",
  "east" : "/d/oldpine/epath3",
]));
	set("outdoors", "oldpine");

	setup();
}

void init()
{
	add_action("do_hold_vine", ({ "hold", "grab" }) );
}

int do_hold_vine(string arg)
{
	if( !arg || arg!= "vine" )
		return notify_fail("你要抓住什么？\n");
	message_vision("$N爬上石桥的护栏，伸手往不远处的一根藤蔓抓去....\n",
		this_player());
	if( random((int)this_player()->query_skill("dodge")) < 5 ) {
		message_vision("\n只听见一声杀猪般的惨叫，$N已经往山涧中坠了下去。\n\n", this_player());
		tell_room(__DIR__"waterfall",
			"你听到有人高声惊叫，一条人影从上方掉了下来，「扑通」一声跌进潭中。\n");
		this_player()->move(__DIR__"waterfall");
	} else {
		message_vision("$N手脚俐落地攀附著藤蔓，慢慢地爬下山涧....。\n",
			this_player() );
		tell_room(__DIR__"passage",
			"忽然一条人影从南边的帘幕穿了出来。\n");
		this_player()->move(__DIR__"passage");
	}
	return 1;
}

