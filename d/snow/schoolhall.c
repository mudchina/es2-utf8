// Room: /d/snow/schoolhall.c

inherit ROOM;

void create()
{
	set("short", "淳风武馆大厅");
	set("long", @LONG
这里是淳风武馆的正厅，五张太师椅一字排开面对著门口，这是武
馆中四位大师傅与馆主柳淳风的座位，和一般武馆不同的是，墙上竟然
挂著几幅风骨颇为不俗的书画，显示这里的主人并非大字不识的粗汉，
而是文武双全的高人。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"school2",
  "east" : __DIR__"inneryard",
]));
	set("objects", ([
		CLASS_D("swordsman") + "/master":1 ]) );
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
	"obj/board/swordsman_b"->foo();
}
