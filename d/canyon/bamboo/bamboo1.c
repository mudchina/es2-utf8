// Room: /d/canyon/bamboo/bamboo1.c

inherit ROOM;

void create()
{
	set("short", "竹林道入口");
	set("long", @LONG
修长的竹子映满眼廉，穹空无边，风拂无形，芬芳的气味随著清
风而漂流著，真有如如沐春风，生机充满的竹林道，让站立其中的人
皆受其境界而霍然开朗，忘却了江湖的险恶，行止于此，一直气凝字
之迹，显出居此主人之内力雄厚，亦使你想找点看到居此八泰之地的
主人是何等的人物。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"bamboo2",
		"back" : "/d/canyon/fantasy1",
]));

	setup();
	replace_program(ROOM);
}
