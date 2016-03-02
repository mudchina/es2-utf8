// Room: /d/goathill/canyon2.c

inherit ROOM;

void create()
{
	set("short", "峡谷");
	set("long", @LONG
你现在正走在一条狭长的深谷之中，东西两面都是高不可攀的峭壁
，往南沿著谷底一条乾涸的山涧可以通往峡谷的出口，北边的峭壁从这
里斜斜向上宛如从天上掉下来倒插进地面，形势更是危峻，连天空都被
北边的峭壁遮去了七、八分。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"canyon3",
		"southup" : __DIR__"canyon1",
]));

	setup();
	replace_program(ROOM);
}
