// Room: /d/choyin/n_gate.c

inherit ROOM;

void create()
{
	set("short", "乔阴县城北门");
	set("long", @LONG
这里乔阴县城的北门，一座高大的石牌楼上面刻著「北门」两个大
字，一条黄土路往北穿过一片松树林，青郁郁地通往北边的山上，石牌
楼旁蹲著两只石狮，由于乔阴县城最热闹的火龙将军庙远在城南，因此
北门这一带反而显得比较冷清，和附近的乡村一般的宁静纯朴。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		// "north" : "/d/oldpine/spath4",
		"west"  : "/u/cloud/sunhill/road1",
		"south" : __DIR__"n_street1",
	"east" : "/d/social_guild/gee/gee_room",
	]));
	set("objects", ([
		__DIR__"npc/cityguard": 2,
		__DIR__"npc/ghost": 1,
		"/obj/npc/garrison": 2,
	]) );
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
