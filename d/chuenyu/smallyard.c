inherit ROOM;

void create()
{
        set("short", "翠绿的小草坪");
        set("long", @LONG
小草坪修剪的很整齐。上面还留着小童玩耍过的痕迹。各种
昆虫都在这里建立了它们的乐园。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "east" : __DIR__"home",
          "south" : __DIR__"dustyroad3",
          ]));
          set("objects", ([
           __DIR__"npc/frog" : 2,
           __DIR__"npc/ant"  : 2,
           __DIR__"npc/fly"  : 2,
           ]) );
           set("outdoors", "chuenyu");
           setup();
}
                   