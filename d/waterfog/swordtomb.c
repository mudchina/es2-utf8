// Room: /d/waterfog/swordtomb.c

inherit ROOM;

void create()
{
	set("short", "葬剑亭");
	set("long", @LONG
你现在来到一个山腰靠近山顶的亭子，亭子前立著一个两丈多高的
石碑(monolith)，从亭子里远眺北方连绵不尽的大山，使你不禁感到胸
臆之间一股英雄情怀油然而生，葬剑亭据说每到夏日夜晚，野风吹过，
会产生一阵阵呜呜的哭泣声，这也是水烟十景中的「孤亭剑泣」。出了
亭子，往南便是直通虹台的石阶，一条黄土小路往西通往另一条下山的
小路。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "monolith" : "石碑上龙飞凤武地刻著几个大字：

    风波剑神黎红药前辈葬剑于此，水烟阁第四代七长老比武
    不胜，以奸计害人而自取其辱，武者皆不齿其小人行径，
    合力击杀于此，甲辰年立此亭书铭其事以为后人殷鉴。

                        第三代水烟阁主 于兰玫音
                        第四代水烟阁主 聂    言   合立
                        第五代水烟阁主 段 柏 山
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/waterfog/wpath5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
