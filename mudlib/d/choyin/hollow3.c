inherit ROOM;

void create()
{
        set("short", "寒谷尽头");
        set("long", @LONG
两面皆为峭壁，光滑无物。一株寒谷幽兰,暗香浮动，沁人心脾。山壁天然行成
一空穴(vase),积满寒露.
LONG
        );
        set("item_desc", ([
                "vase":
                    "石穴呈瓶状,想是用来插(interject)什么东东的.\n",
                          ]) );
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"hollow1",
]));
        set("objects", ([ /* sizeof() == 1 */
                  __DIR__"obj/orchid" : 1,
]));
        set("no_magic", 1);

        setup();

}

void init()
{
        add_action("do_interject", "interject");
}
int do_interject(string arg)
{
        if( !arg || arg!="orchid" ) return notify_fail ("你要用什么？\n");
        message_vision("寒谷幽兰忽地绽放,幻出七色光华.$N轻轻地飘起...\n",
                this_player());
        tell_room("/d/latemoon/bamboo",this_player()->query("name") + "轻轻飘落.\n");
        this_player()->move("/d/latemoon/bamboo");
        return 1;
}
