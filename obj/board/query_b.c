// query_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("意见反应留言板", ({ "board" }) );
	set("location", "/d/wiz/entrance");
	set("board_id", "query_b");
	set("long",	"这是一个供人留言记事的留言板。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
