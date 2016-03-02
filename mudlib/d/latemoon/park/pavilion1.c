inherit ROOM;

void create()
{
    set("short", "沁芳亭");
	set("long", @LONG
亭子座落在园内小水池上，亭柱周围以弧形座凳式栏板，内外
雕刻各种不同样式的梅枝，钻尖式紫琉璃瓦顶，天花板也有雕刻非
常精细的百花图案。上下担额枋彩画题材是海墁式点金加彩琼花。
体形别致，色彩丰富。亭边石桥飞架，通萃赏楼，轻灵精巧，为园
中一大奇景。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "north" :__DIR__"bridge1",
       "south" :__DIR__"bridge2",

]));

    set("objects", ([
        __DIR__"npc/shiren" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
