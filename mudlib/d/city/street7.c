// Room: /d/city/street7.c

inherit ROOM;

void create()
{
	set("short", "十字路口");
	set("long", @LONG
京师的中轴线和北面的主要街道护国道在这里交叉，东西向的护
国道上人来人往，热闹非凡，南面的皇家祭坛反倒冷冷清清，往北可
以望到大红颜色的北城门。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"street8",
  "west" : __DIR__"street15",
  "north" : __DIR__"street16",
  "south" : __DIR__"jitan",]));

	set("outdoors", "city");

	setup();
	replace_program(ROOM);
}
