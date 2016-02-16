// Room: /d/sanyen/tower.c

inherit ROOM;

void create()
{
	set("short", "塔林");
	set("long", @LONG
你正站在两座高塔前, 左边这一座名曰: 『明心塔』, 右方名叫
『见性塔』。历来, 当山烟寺中的高僧涅盘后, 遗体火化后所得的舍
利子就存放在这两座塔里。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/sanyen/back_temple",
]));

         set("objects", ([
             __DIR__"npc/work_bonze" : 1 ]) );
	set("no_clean_up", 0);
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
