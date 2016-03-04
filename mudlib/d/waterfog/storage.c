// Room: /d/waterfog/storage.c

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
这里是一间柴房，一捆一捆劈好的柴薪都整齐地堆放在柴房北侧，
留下一条通道通往东边仆役的卧室。往南可以回到水烟阁的西侧厅。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"weststair",
		"east" : __DIR__"servroom",
	]) );

    set("objects", ([
		__DIR__"npc/servant" : 2
	]) );

	setup();
	replace_program(ROOM);
}
