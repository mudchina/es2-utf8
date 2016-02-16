inherit ROOM;

void create()
{
    set("short", "沁芳桥");
	set("long", @LONG
你走至大桥前，见水如晶帘一般奔入，扶著藤栏过去，只见水
上落花愈多，其水愈清，溶溶荡荡，曲折萦纡，池边两行垂柳，杂
著桃、杏，遮天蔽日般，真无一些尘土。度过桥去则通往湖心亭。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "north" :__DIR__"moonc",
       "south" :__DIR__"pavilion1",

]));

	setup();
	replace_program(ROOM);
}
