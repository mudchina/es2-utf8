// Room: /d/choyin/club.c
# include <room.h>
# include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "草堂");
	set("long", @LONG
一间由白茅草搭成的草堂，室内仅有一竹榻，一矮几，四把竹椅．堂前一幅拓片装裱精
致，上书:
                              书有未曾经我读
                              事无不可对人言
矮几上摊有书卷(books)放着一支朱砂笔，一房歙砚竟题有岳武穆藏，另几张上好生宣． 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yard.c",
  "east" : __DIR__"fence.c",
]));
        set("no_fight", "1");
        set("no_magic", "1");
        set("item_desc", ([
                "books" : @TEXT
几上的书信手而放，装帧古朴，竟是宋版书，还有几卷汉碑原拓。你按捺不住好奇心想拿
起来(scratch)仔细研究一番。
TEXT
]));     

        create_door("west", "柴门", "west" , DOOR_CLOSED);    
	set("no_clean_up", 0);

	setup();
}

void init()
{
   add_action("do_pray","pray");
   add_action("do_dance","dancing");
   add_action("do_scratch","scratch");
}

int do_dance(string arg)
{
     message_vision("也不知道隐士怎么弄的，$N无法跳出专注的舞步。\n",
                this_player());   
      return 1;
}               

int do_pray(string arg)
{
     message_vision("也不知道隐士怎么弄的，$N的玛瑙手镯不灵验了。\n",
                this_player());       
    return 1;
}               

int do_scratch(string arg)
{ 
  int ddt=0; 
  object book;
  object ob;

  ob = this_player();

  if( !arg || arg!="books" ) 
  return 0;
  else { ddt = ddt + 1; 
  message_vision("$N乘人不备，抓起一本书藏入怀中。\n\n",
                this_player()); 

  switch( random(3) ) {
                case 0: book = new("/d/choyin/npc/obj/book1");
                        book ->move(ob);
                        ob->set_temp("choyin/书", ddt); 
                        break;
                case 1: book = new("/d/choyin/npc/obj/book1");
                        book ->move(ob);
                        ob->set_temp("choyin/书", ddt); 
                        break;
                case 2: book =new("/d/choyin/npc/obj/book2");
                        book ->move(ob);
                        ob->set_temp("choyin/书", ddt); 
                        break; 
                      }
}
  return 1;
}


int valid_leave(object me, string dir)
{       string item;
        object obj;

        item = "book";
        if( !objectp(obj = present(item, me)) )  {
                tell_object(me, "你离开草堂!\n" NOR );
        }  else  {
            while(objectp(obj = present(item, me)) ) 
              { if ( me->query_temp("choyin/书") ) {
                tell_object(me, HIC "你将书放回到矮几。\n" NOR);
                obj = present(item, me); 
                destruct(obj);
                                                         }
           me->set_temp("choyin/\112\151", 0);   
              }        
                 }
        return 1;
} 
