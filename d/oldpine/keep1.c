// Room: /d/oldpine/keep1.c

inherit ROOM;

void create()
{
	set("short", "老松寨秘密入口");
	set("long", @LONG
这里只见一个木头搭成的大门，门框上挂著四、五的不知道是什么
动物的头骨跟一些铁链，外面再铺上一层乾枯的松枝，在这样一个森林
里还真不容易发觉。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/oldpine/pine2",
  "east" : "/d/oldpine/keep2",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/oldpine/npc/bandit_guard" : 4,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
