// Room: /d/choyin/tongbhill.c

inherit ROOM;

void create()
{
	set("short", "桐柏山");
	set("long", @LONG
鬼神皆修于桐柏,故而此地人烟稀少,仅山下青石峪的那位隐士结庐在此.东边山
壁天成一洞,据传是姑射山的仙人炼丹之所,终日烈焰雄雄,烤得此地寸草不生.
然而,一株老松仍枝繁叶茂,立于巨石(stone)之上.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northdown" : __DIR__"rockyu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
