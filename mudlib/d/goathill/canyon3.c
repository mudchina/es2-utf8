// Room: /d/goathill/canyon3.c

inherit ROOM;

void create()
{
	set("short", "峡谷");
	set("long", @LONG
你现在正走在一条峡谷的谷底，这里的峭壁斜度之大让你胆颤心惊
，只消有人在这里一声大喝将上面的土石震了下来，只怕立刻就得被活
埋，东边的峭壁上有一个黑漆漆的洞穴，里面似乎有什么东西蠕蠕而动
，峡谷往西南和西北两边各有狭窄的出口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"cavern1",
		"southwest" : __DIR__"canyon2",
]));

	setup();
	replace_program(ROOM);
}
