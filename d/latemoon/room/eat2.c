
inherit ROOM;

void create()
{
   set("short", "膳房");
	set("long", @LONG
这是一间膳房，中央摆了二张大圆桌。周围三十二张雕饰木藤椅。
平常庄内上下用膳的地方，东边是厨房，西边则是大饭厅，这虽然不
及饭厅华丽，但所有锅盘匙碗，也都是上等珍品。有大户人家的气派
与富贵。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"kitchen",
     "west" :__DIR__"eat1",

]));

    set("objects", ([
        "/d/latemoon/obj/wine" : 1,
        "/d/latemoon/obj/food" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
