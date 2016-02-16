inherit ROOM;

void create()
{
   set("short", "长廊曲洞");
	set("long", @LONG
你走入一长廊曲洞，里头略略的有几点山石，种著芭蕉，你可以
听到潺潺的流水声，这里是园内假山开凿的通道，蜿蜒盘□，从洞口
向外望去，是一碧清的水池。顺著曲径走去，转了两个弯子，看见一
座石板桥。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "west" :__DIR__"moonc",
       "southeast" :__DIR__"bridge3",

]));

	setup();
	replace_program(ROOM);
}
