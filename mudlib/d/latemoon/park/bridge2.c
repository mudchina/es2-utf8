inherit ROOM;

void create()
{
    set("short", "翠嫣桥");
	set("long", @LONG
这是一座最精美的桥，全长十二米，宽度恰可走两人。石拱
是单孔结构，青石桥面，汉白玉雕石栏杆，栏板上刻有精致美丽
的花纹。二十个望柱头上各有一小孔雀，情态各异，饶有趣味。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "north" :__DIR__"pavilion1",
       "southeast" :__DIR__"paroad1",
       "west" :__DIR__"paroad2",

]));

	setup();
	replace_program(ROOM);
}
