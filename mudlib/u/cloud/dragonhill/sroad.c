// Room: /u/cloud/dragonhill/sroad.c

inherit ROOM;

void create()
{
        set("short", "黄土路");
        set("long", @LONG
这里是雪亭镇通往绮云镇的必经之路。南面就是绮云镇，北面通往
卧龙岗。早先官府想在此修条大路连接两镇，无奈地势所限，加上卧龙
岗上常有强人出没，只得做罢。虽说是土路，可过往的人很多，路面已
被踩得很平了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"shillfoot",
  "southeast" : "/u/cloud/entrance"
]));
        set("outdoors", "dragonhill");

        setup();
        replace_program(ROOM);
}
