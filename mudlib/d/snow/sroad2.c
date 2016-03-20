// Room: /d/snow/sroad2.c

inherit ROOM;

void create()
{
	set("short", "雪亭镇街道");
	set("long", @LONG
这里是雪亭镇的街道，你的北边有一家客栈，从这里就可以听到客
栈里人们饮酒谈笑的声音，街道往东不远处有个转角往北，如果你往东
直走就是上山的小径了，往西则可以走到车马来往络绎不绝的官道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"sroad3",
  "south" : __DIR__"school",
  "east" : __DIR__"sroad1",
  ]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/farmer" : 2,
  ]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
