// Mon  08-21-95

inherit ROOM;

string look_drawing();

void create()
{
	set("short", "村长的家");
	set("long", @LONG
这是一间看起来有点不一样的民宅，屋子的中央有一个石制的炉子，
上面生著一堆火，熊熊的火光把屋内照得像白天似的光亮。墙上挂著几幅
字画 (drawing)，一边还放了一个木制的书架，上面整齐地排著一些旧得
不能再旧的书。炉子的旁边摆了一张手工精美的石椅，看来像个很重要的
位置。
 
LONG
	);
    set("item_desc", ([
    "drawing" : (: look_drawing :),
    ]) );

    set("exits", ([
    "north" : __DIR__"field0",
]));

    set("objects", ([
    __DIR__"npc/oldman2" : 1,
	]) );

	setup();
}

string look_drawing()
{
    string str;
    str = "几幅看来普普通通的山水画... 没啥特别的.... 除了... 其中一幅怎么看也不像山水说...\n";
    if (this_player()->query_temp("looked_shape")) {
        this_player()->set_temp("looked_drawing",1);
        return str+"你注意到这幅画跟你在山顶上看到的很像. 底下有一行潦草的签名,\n"+
                   "你只能分辨出其中几个像符号的东西.. Nolen...\n";
    }
    else return str+"上面画了一些还算有规律的线条... 可是你一点也看不懂.\n";
}

