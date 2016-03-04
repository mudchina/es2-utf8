// duchang2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "赌场");
	set("long", @LONG
这里是赌场的二楼，很多人在围着几张桌子高声叫嚷，煞是热闹。
靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
      set("exits", ([
        "down" : __DIR__"duchang",
      ]) );

        set("item_desc", ([
            "sign": "招牌写著：赌(bet)：押注一两纹银，赢了得二两。\n",
        ]) );

        setup();

}

void init()
{
  add_action("do_bet", "bet");
}

int do_bet(string arg)
{
  // TODO: 
  if(random(10) < 8) {
  }

  return 1;
}
