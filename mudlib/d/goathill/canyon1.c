// Room: /d/goathill/canyon1.c

inherit ROOM;

void create()
{
	set("short", "峡谷");
	set("long", @LONG
你现在正走在一条狭长的峡谷之中，东西两边都是高不可攀的峭壁
，一根五、六丈宽的石梁正横跨在你头顶的谷口，看起来摇摇欲坠，万
一掉下来只怕当场就会被压成一个肉饼，往南就是峡谷的出口，峡谷谷
底的地面看起来像是乾涸的山涧，弯弯曲曲往北通入峡谷深处。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"canyon2",
		"south" : __DIR__"mroad6",
]));

	setup();
	replace_program(ROOM);
}
