// Room: /d/sanyen/gate.c

inherit ROOM;

void create()
{
	set("short", "山烟寺山门");
	set("long", @LONG
这里是往山烟寺的山门，山烟寺在你的西面不远，由于寺中的老方丈
玄智和尚医术通神，不少受过恩惠的各地富豪将山烟寺修整得金碧辉煌，
庄严雄伟，因此山烟寺规模虽然不及京城的白象禅院，但是名气却是
大得多了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"sroad2",
		"north" : __DIR__"front_yard",
        "west" : __DIR__"tunnele",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/greeting" : 2,
	]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
