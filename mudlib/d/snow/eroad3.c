// Room: /d/snow/eroad3.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条说宽不宽，说窄倒也不窄的山路，路面用几块生满青苔的
大石铺成，西面是一段坡地，从这里可以望见西边有几间房屋错落在林
木间，东面则是山壁，山路往西南衔接一条黄土小径，往北则是通往山
上的石阶。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : "/d/oldpine/npath1",
  "west" : "/d/temple/sroad",
  "southwest" : __DIR__"eroad2",
]));
	set("no_clean_up", 0);
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
