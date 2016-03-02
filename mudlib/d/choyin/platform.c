inherit ROOM;

void create()
{
        set("short", "云台");
        set("long", @LONG
姑射之巅，祥云朵朵，瑞彩千条。藐姑射之山，有神人居焉，肌肤若冰雪，绰约如处子..
仙踪难觅，只觉风声飒然，云开之出，凸现一座云台(platform)
LONG
        );
        set("item_desc", ([
                "platform":
                    "一座精雕细琢的玉台,放有一矮几;几上立有玉瓶,几株寒谷幽兰
绽放其中.台旁置一云幡(flag),可是仙家宝物.\n",
                "flag":"此幡可翻云覆雨,最好不要碰(touch)它.\n",
          ]) );      
        set("objects", ([
                __DIR__"npc/lboy" :2,
        ]) );

        setup();
        
} 


void init()
{     
        add_action("do_touch", "touch");
}


int thounder(object ob)

{
        int i;
        int damage;
        if( environment(ob) == this_object())
        {
        message_vision("刹那间彤云密布,山川改色.无数雷霆霹向$N...\n", ob);
        message_vision("$N顿时周身起火,七窍冒烟...\n", ob);
        tell_room("/d/choyin/platform","你闻到一股烧焦的味道.\n");                                                                         
        i = (int)ob->query("eff_kee");
        damage = random(10)+35  ;
        ob->set("eff_kee",(int) i - damage );
        i =  (int)ob->query("kee");
        ob->set("kee",(int) i - damage);
        if( environment(ob) == this_object())
        call_out("thounder",5, ob);
        }
        else

        return 1;
}


void close_passage()
{
        if( !query("exits/down") ) return;
 message("vision", "一道蓝光过后,云台合拢了.\n",
                        this_object() );                      
        delete("exits/down");
}


int do_touch(string arg) 
{
       string dir;
       object ob;
       if( !arg || arg=="" ) return 0;

       if( arg=="flag" ) {
                write("你碰了云幡,云幡动了一下.....\n");
        if( interactive(( ob = this_player())) )
        remove_call_out("thounder");
        call_out("thounder", 15, ob);            
        message("vision", "白光一闪,云台忽地裂开\n",
                        this_object() );                       
        set("exits/down", __DIR__"stove");
        call_out("close_passage", 1);  
        return 1;
        }
}


