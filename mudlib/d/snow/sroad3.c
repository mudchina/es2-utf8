// Room: /d/snow/sroad3.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条宽敞坚实的青石板铺成的大道，路上车马的痕迹已经在路
面上留下一条条明显的凹痕，往东是一条较小的街道通往雪亭镇，大路
从这里往北可达水烟阁，往西南穿过黄石隘口则通往戍守京畿重地的天
驼关。
LONG
	);
    set("exits", ([ /* sizeof() == 3 */
  "southwest" : "/d/canyon/road",
  "north" : "/d/snow/sroad4",
  "east" : "/d/snow/sroad2",
]));
	set("outdoors", "snow");
	set("objects", ([
		__DIR__"npc/crazy_dog": 1 ]) );

	setup();
	replace_program(ROOM);
}
