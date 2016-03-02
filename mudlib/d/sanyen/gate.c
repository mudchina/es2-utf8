// Room: /d/sanyen/gate.c

inherit ROOM;

void create()
{
	set("short", "山烟寺山门");
	set("long", @LONG
这里是往山烟寺的山门，西边是一条穿过山腰的隧道，山烟寺在你
的东北方不远，由于寺中的老方丈玄智和尚医术通神，不少受过恩惠的
各地富豪将山烟寺修整得金碧辉煌，庄严雄伟，因此山烟寺规模虽然不
及京城的白象禅院，但是名气却是大得多了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : "/d/sanyen/sroad2",
		"east" : "/d/sanyen/front_yard",
	//	"south" : "/d/latemoon/sroad1"
	]));
	set("objects", ([ /* sizeof() == 1 */
		"/d/sanyen/npc/greeting" : 2,
	]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
