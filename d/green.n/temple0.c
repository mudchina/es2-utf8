// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "土地庙");
	set("long", @LONG
这是一间小小的土地庙, 庙内相当的暗, 一股湿气混上焚烧冥
纸的味道使得屋内的的气味显得很奇特. 供桌上零星地放个一些水
果, 一尊木刻的土地公像孤独地立在前面. 庙外的小空地边有一个
简陋的金纸亭.
 
LONG
	);
    set("exits", ([
    "east" : __DIR__"path2",
]));

	setup();
	replace_program(ROOM);
}
