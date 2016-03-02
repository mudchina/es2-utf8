// Room: /d/village/road4.c

inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
青石小路两旁没有树木，几根杂草随风摇摆，路上的石头被行人踩磨得
很光亮，但奇怪的是平时这里的行人却非常稀少！小路向西延伸开去，南面
是一片大大的瓜地，北面是一家农舍。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"farmhouse1",
  "west" : __DIR__"road5",
  "southdown" : __DIR__"melonfarm",
  "east" : __DIR__"road3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
