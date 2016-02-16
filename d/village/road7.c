// Room: /d/village/road7.c

inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
小路的两边种了一排垂柳，西边玉螺湖上的阵阵雾气透过柳枝飘散过
来。你的东边是一大片绿油油的瓜地，一条大沟横在小路和瓜地之间，你
可以走到东南向的瓜棚。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"melonguard",
  "south" : __DIR__"road8",
  "west" : __DIR__"lakeside",
  "northup" : __DIR__"road5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
