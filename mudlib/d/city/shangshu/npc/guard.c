// guard.c
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("门房", ({ "guard" }) );
        set("id", "guard");
	set("long",
		"尚书府的门房虽然没什么官衔，但所有想晋见\n"
		"尚书的白衣无不对他毕恭毕敬的n"
		);

        set("attitude", "peaceful");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

	set("combat_exp", 1000);

        set("chat_chance", 5);
	set("chat_msg", ({
        	"门房慢吞吞地说：是。。想见尚书大人的吗？。。\n",
		"门房嘿嘿地笑了笑，手里比划着一个数字.\n"
		}) );

        set_skill("unarmed", 90);
        set_skill("parry", 60);
	set_skill("dodge", 90);

        setup();
        carry_object("/obj/cloth")->wear();
}

int accept_object(object who, object ob)
{
        if ( !who->query("marks/尚书") ) {
                if( ob->value() >=30000 ) {
                        say("门房说道:这位大人，里面请！\n"); 
                        who->set("marks/尚书",1);
                        return 1;
			}  
	           else {
       		         say ("鼻子里哼了一声，头掉了过去。\n"); 
			 return 1;
       			 }
		}

	else {
		say ("大人太客气了\n");
        	return 1;
		}
}

