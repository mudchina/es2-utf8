// Room: /d/wiz/jobroom.c

inherit ROOM;

void create()
{
	set("short", "工作进度简报室");
	set("long", @LONG
这里是巫师们报告自己工作进度的简报室，同时也是大巫师抓公差
的根据，如果你有工作做，最好常常到这里更新你的工作进度，如果太
久没有看到你的工作进度报告，大巫师们会以为以没事做而指派工作给
，要是你仍然不理，也有可能会被假设成已经放弃巫师的工作而降回玩
家身分。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/wiz/hall1",
]));
	set("no_clean_up", 0);

	setup();
	call_other("/obj/board/wizard_j", "???");
	replace_program(ROOM);
}
