// Room: /d/sanyen/drag_field.c

inherit ROOM;

void create()
{
	set("short", "药圃");
	set("long", @LONG
一片广阔的药圃, 药香就是从这里散发出来的。这里似乎经过详
细的规划, 一块一块的, 哪边种当归, 哪边种枸杞, 绝不会混在一起
。只是看来看去都只是些寻常的药材, 看不到比较珍贵特殊的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "west" : "/d/sanyen/road2",
]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
