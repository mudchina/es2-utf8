// Room: /u/cloud/dukou.c

inherit ROOM;

void create()
{
        set("short", "江北渡口");
        set("long", @LONG
这是个虽说不大却过客甚多的渡口。往北去是通往绮云镇里的青石
道，南面就是无风亦起浪的泓水了。向南望去，隐约可见对岸日照山的
轮廓，山顶有袅袅炊烟升起。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sroad1",
  "south" : __DIR__"sunhill/northriver",
]));

	set("objects", ([
                "/u/cloud/npc/boater" : 1,
	]) );

        set("outdoors", "cloud");

        setup();
}
