// Room: /u/sunhill/midriver.c

inherit ROOM;

void create()
{
        set("short", "江心");
        set("long", @LONG
这里虽说是泓水最窄的地方，可泓水在这里转了个弯，所以常有暗
流出现。常有过往船只在这里沉入江底，连水性了得的船夫们也不敢在
风大浪急时过江。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"northriver",
  "south" : __DIR__"southriver",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

