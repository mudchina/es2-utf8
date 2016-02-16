#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "夹道");
        set("long", @LONG
你现在处于一个窄窄的夹道里，通向北面的路被一块巨石(rock)堵死。
夹道的两侧是三丈高的石墙(wall)。出乎你的意料，石墙上布满了
碗大的圆孔(hole)。石墙的后面传出“吱吱嘎嘎”的声音(noise)。
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"gate_castle",
        ]));
        set("item_desc", ([
        "wall" : "这是一道三丈高，厚达尺许的石墙。墙上的圆孔很适合用来发暗箭。\n",
        "rock" : "这是一块千斤巨石，阻住了通向北面的路。\n",
        "hole" : "你试着往圆孔里看，可是里面太黑了，什么也看不到。\n",
        "noise": "这显然是拉开强弩的声音。\n"
]));

        set("outdoors", "chuenyu");
        
        create_door("south", "城门", "north", DOOR_CLOSED);
        setup();
}

void init()
{       object ob;
        if( interactive( ob = this_player()))
        remove_call_out("arrowing");
        call_out("arrowing", 15, ob);
}

int arrowing(object ob)

{
        int i;
        int damage;
        if( environment(ob) == this_object())
        {
        message_vision(HIW"刹那间石墙的后面“嘣嘣”声不绝，无数羽箭从圆孔中向$N激射而出！！\n", ob);
        message_vision("$N被乱箭射得头破血流，遍体鳞伤！\n"NOR, ob);
        i = (int)ob->query("eff_kee");
        damage = random(10)+35  ;
        ob->set("eff_kee",(int) i - damage );
        i =  (int)ob->query("kee");
        ob->set("kee",(int) i - damage);
        if( environment(ob) == this_object())
        call_out("arrowing",5, ob);
        }
        else
        
        return 1;
}
                                        