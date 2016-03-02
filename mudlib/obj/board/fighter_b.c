// fighter_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("武者留言板", ({ "board" }) );
	set("location", CLASS_D("fighter") + "/guildhall");
	set("board_id", "fighter_b");
	set("long",	"这是供武林中人留言记事的留言板。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
