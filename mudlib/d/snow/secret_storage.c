// Room: /d/snow/secret_storage.c

inherit ROOM;

void create()
{
	set("short", "地下密室");
	set("long", @LONG
这里是一间窄小的密室，你的面前只有一个破旧的小床(bed)跟一
些乾草。
LONG
	);
	set("objects", ([
		__DIR__"obj/shield": 1
	]) );

	setup();
	replace_program(ROOM);
}
