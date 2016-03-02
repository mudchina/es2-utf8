inherit ROOM;

void create()
{
    set("short", "翠嶂");
	set("long", @LONG
穿过一层竹篱、花嶂编的月洞门，在你眼前出现的是那由粉墙环
护，绿柳周垂的翠嶂。两边分别是游廊相接通往桃花林与长廊曲洞。
在这儿一棵西府海棠(flower)吸引你的注意，只见其势若伞，丝垂翠
缕，葩吐丹砂，十分漂亮。
LONG
	);
    set("item_desc", ([
        "flower" : @TEXT
    你仔细看这是一棵形状有些奇特的西府海棠，有一淡淡
的奇异香气。原来在旁边还有一朵不太起眼，但是略成金黄
色的小花蕊，你的直觉告诉你它似乎是一种珍贵药材。你想
把它摘下(pick)。
TEXT
    ]) );
	set("exits", ([ /* sizeof() == 2 */
      "north" :__DIR__"flower2",
      "south" :__DIR__"bridge1",
      "west" :__DIR__"moon2",
      "east" :__DIR__"moon1",

]));

    set("objects", ([
    ]) );
	setup();

}
void init()
{
            add_action("do_pick","pick");
}
void reset()
{
        ::reset();
        set("pick_available" , 2);
}
int do_pick(string arg)
{
       object me,obj;

       me = this_player();
       if( !arg || arg!="flower" )
              return notify_fail("你要摘取什么? \n");
       if ( query("pick_available") )  {
       message_vision("$N从西府海棠中摘下一朵小花蕊。\n",this_player() );
       obj = new ("/d/latemoon/park/npc/obj/flower");
       obj->move(me);
       add("pick_available", -1);
       }
       return 1;
}
