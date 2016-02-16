inherit ROOM;

void create()
{
        set("short", "北花园");
        set("long", @LONG
你站在黑松城堡的东花园里。花园里长满了各式各样奇花异草。
再通向北面的路被一块巨石(rock)堵死。再往南则是雄伟的黑松阁。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "south" : __DIR__"west_blackge",
          ]));
          set("objects", ([
          __DIR__"npc/smallgardener" : 2,
          ]) );
          
          set("item_desc", ([
          "rock" : "这是一块千斤巨石，阻住了通向北面的路。\n",
          ]));
          
          
          set("outdoors", "chuenyu");
          
          setup();
}
                  