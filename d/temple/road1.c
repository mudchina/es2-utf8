// Room: /d/temple/road1.c

inherit ROOM;

void create()
{
	set("short", "青石小径");
	set("long", @LONG
一条铺著青石板的小径, 两侧高大的松树, 偶有松针缓缓飘落。
树干上布满了青苔, 甚至还有些蔓延到石板上。南边通往回廊, 西侧
则是后殿。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/temple/corridor3",
  "northwest" : "/d/temple/road2",
]));

	setup();
}

int valid_leave(object me, string dir)
{
     if (!wizardp(this_player()) && (dir=="south" || dir=="northwest"))
          {
           if( random((int)this_player()->query("kar")) < 3 )
              {
               message_vision("$N一脚踩在青苔上, 不小心滑了一跤, 四脚朝天地摔在地上起不来。\n\n\n", this_player());
               this_player()->unconcious();
               return 0;
              }
           else return ::valid_leave(me, dir);
          }
     else return ::valid_leave(me ,dir);
} 
         
