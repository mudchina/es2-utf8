// wizard_j.c

inherit "/std/jboard";

void create()
{
	set_name("巫师工作进度报告", ({ "job board", "board" }) );
	set("location", "/d/wiz/jobroom");
	set("board_id", "wizard_j");
	set("long",	"这是一个特殊的留言板供巫师报告自己的工作进度。\n" );
	setup();
	replace_program("/std/jboard");
}
