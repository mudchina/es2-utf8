// Room: /d/chuenyu/high_b_mtn2.c

inherit ROOM;

void create()
{
        set("short", "花岗石街");
        set("long", @LONG
这是通往城堡的石街，整条石街全是用巨大的花岗岩砌成的。
单这条石路就足已表明城堡主人的富有和气势。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "up" : __DIR__"gate_castle",
          "east" : __DIR__"rope_bridge",
          ]));
          
          set("outdoors", "chuenyu");
          
          setup();
}
                  
