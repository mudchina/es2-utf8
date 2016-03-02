// Room: /d/city/street16.c

inherit ROOM;

void create()
{
	set("short", "大栅栏");
	set("long", @LONG
从这里再往北走就出了京师的北城门，在与异族交战的时期，为
方便盘查行人，官兵在这儿放了一道很大的栅栏。后来尽管战争结束
了，栅栏拿走了，但老人们还是习惯地把这叫做“大栅栏”，用京音
读起来就变成了“大世烂儿”。西面是护国寺的侧门。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
//  "west" : "d/city/siyuan",
  "north" : "d/city/northdoor",
  "south" : "d/city/street7",]));
	set("outdoors", "city");

	setup();
	replace_program(ROOM);
}
