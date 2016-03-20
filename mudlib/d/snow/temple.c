#include <obj.h>

inherit ROOM;

void create()
{
	set("short", "城隍庙");
	set("long", @LONG
这是一间十分老旧的城隍庙，在你面前的神桌上供奉著一尊红脸的城
隍，庙虽老旧，但是神案四周已被香火薰成乌黑的颜色，显示这里必定相
当受到信徒的敬仰。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"eroad1",
		"west" : __DIR__"square",
	]));
	set("no_fight", "1");
	set("objects", ([ /* sizeof() == 2 */
		"/obj/paper_seal" : 2,
		__DIR__"npc/keeper" : 1,
		__DIR__"obj/denotation" : 1
	]));

	setup();
	replace_program(ROOM);
}
