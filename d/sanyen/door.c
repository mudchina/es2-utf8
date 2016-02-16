// Room: /d/sanyen/door.c

inherit ROOM;

void create()
{
	set("short", "山烟寺寺门");
	set("long", @LONG
出现在眼前的是一座宏伟壮丽的寺门, 上方覆著镶金的瓦片, 瓦
片的下方挂著一方翡翠匾额, 上面写著『山烟寺』三个烫金大字。正
中的大门正紧紧关闭著, 只有在迎接大人物时才会开启。现在只开著
两旁的偏门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/sanyen/road1",
  "south" : "/d/sanyen/front_yard",
]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
