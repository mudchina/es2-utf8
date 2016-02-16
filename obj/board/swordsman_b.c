// swordsman_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("剑士留言板", ({ "board" }) );
	set("location", "/d/snow/schoolhall");
	set("board_id", "swordsman_b");
	set("long",	"这是供剑士们留言记事的留言板。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
