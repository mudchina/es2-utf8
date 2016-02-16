// Room: /d/city/bridge.c
inherit ROOM;
void create()
{
        set("short", "天桥");
        set("long", @LONG
你来到京师的天桥。这里热闹非凡，人声鼎沸。杂耍的、卖艺
的、做小买卖的应有尽有。若是仔细寻找，说不定可以买到什么奇
珍异宝呢。柱子和墙壁上贴满着花花绿绿的广告（post）。
    北边是校武场。再往北就到京师中心……紫禁城了。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "south"  :    __DIR__"street17",
             "west"   :    __DIR__"street12",
             "east"   :    __DIR__"street11",
             "north"  :    __DIR__"jiaowu",]));
        set("objects", ([
               __DIR__"npc/vendor" :1,
               __DIR__"npc/caker"  :1,
	       __DIR__"npc/dumpling_seller":1 ]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

