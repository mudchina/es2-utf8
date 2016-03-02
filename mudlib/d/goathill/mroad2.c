// Room: /d/goathill/mroad2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你现在正走在一条崎岖的山路上，路面到处生满了及膝的杂草丛，
显示这里已经有一段时间没有车马经过了，从这里往北就是野羊山的地
界，野羊山有一座山寨，住著许多凶恶的盗匪，你最好绕道而行。
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"mroad3",
		"south" : __DIR__"mroad1",
]));

	setup();
	replace_program(ROOM);
}
