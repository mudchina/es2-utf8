// Room: /d/snow/herbshop1.c

inherit ROOM;

void create()
{
	set("short", "药铺密室");
	set("long", @LONG
这是一间光线阴暗的密室，从地上厚厚的灰尘看得出来这里很少有
人出入，靠西边的地上放著一副脚镣，连著一条铁链镶在墙上，不知道
是用来锁什么人，南面的墙(wall)是用红杉木做的，跟另外三面的灰土
墙比起来显得有些不寻常。
LONG
	);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
