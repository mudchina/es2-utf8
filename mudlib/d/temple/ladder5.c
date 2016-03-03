// Room: /d/temple/ladder5.c

inherit ROOM;

void create()
{
	set("short", "石英岩石阶");
	set("long", @LONG
你正站在这阶梯的起点, 纯白色宽敞的石英岩阶梯蜿蜒而上, 在青
翠的山色中形成一条纯白色的巨龙。抬头仰望石阶尽头的那座庙宇, 虽
然无情的岁月已经在它身上留下痕迹, 但仍不失其庄严神圣的气息。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"ladder4",
  "westdown" : __DIR__"sroad",
]));
	set("no_clean_up", 0);
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
