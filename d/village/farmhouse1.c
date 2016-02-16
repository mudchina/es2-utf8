// Room: /d/village/farmhouse1.c

inherit ROOM;

void create()
{
	set("short", "农舍");
	set("long", @LONG
这间农舍内的摆设非常朴素，但十分井井有条。阳光顺着窗缝撒在屋
角落里的纺车上，桌上摆着泥作的玩具，特别是那泥老虎捏的形态生动活
泼，色彩逼真，旁边还摆着一把木刀，可能都是父亲作给小孩的玩具。一
张大床的旁边还有一张小床。这屋的北面是农舍的后院，南边出了屋就是
村里的青石小路。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fmhousback.c",
  "south" : __DIR__"road4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
