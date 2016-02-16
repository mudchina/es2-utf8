
// old.c

inherit NPC;

void create()
{
	set_name("无名老妇", ({ "old" }) );
      set("title", "看管人" );
	set("long", "这个老妇人不知姓甚名谁, 她在晚月很久了, 一直看管\n书房, 连庄主都对她很尊敬。\n");
      set("gender", "女性" );
	set("age", 62);
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 26);
	set("cps", 26);
	set("per", 29);
	set("inquiry", ([
		"here": "这里是书房，有些鞭法教材存放在这儿。",
		"trouble":
			"实不相瞒，这杀手是我的私生女，但已误入歧途 ...\n我一直舍不得亲手杀了她，你若能帮忙我会非常感谢。 \n只是要以令牌为证，唉 ...",
		"令牌" : "就在我儿身上 ...你拿到了就给我。",
	]) );
      set("class", "dancer");
      set("combat_exp", 500000);
      set("score", 1000);
      set_skill("dodge", 70);
      set_skill("stormdance", 70);
      set_skill("tenderzhi", 70);
      set_skill("snowwhip", 60); 
      map_skill("dodge","stormdance");
      map_skill("whip","snowwhip"); 
      map_skill("unarmed","tenderzhi");
      set("force", 1000);
      set("max_force", 800);
      set("force_factor", 10);
      create_family("晚月庄", 1, "前辈");

      setup();
      carry_object("/d/latemoon/obj/deer_boot")->wear();
      carry_object("/d/latemoon/obj/blue_dress")->wear();
	carry_object("/u/cloud/obj/npc/lm_guard/whip")->wield();
}

int accept_object(object me, object ob)
{
        object book;	
        int iNeiLiTrans;
	if( !ob->id("###token###") ) return 0;
	command("sigh");
      if( (int)me->query( "max_force" ) < 160 
               && ((string)me->query("family/family_name")=="晚月庄") )
      {
         command("say 作为感谢，我传你一些内力。");
         message_vision( "无名老妇手抵在$N的后心，头上冒出丝丝白气。 \n", me );
         message( "vision", "你感觉到一股热气传了过来。 \n", me );
         iNeiLiTrans = 160-(int)me->query( "max_force" );
         if( iNeiLiTrans>50 ) 
             iNeiLiTrans = random( 50 );
         else
             iNeiLiTrans = random( iNeiLiTrans ); 
	 if( iNeiLiTrans > 20 ) iNeiLiTrans = 20;
	 iNeiLiTrans = iNeiLiTrans*(int)me->query_kar()/30; 
         me->set("max_force", (int)me->query("max_force")+iNeiLiTrans );
         me->set("force", 0);
      }
      else
      {
         command("say 作为感谢，我给你一本寒雪鞭法密笈。");
         book = new(__DIR__"obj/whip_book");
         book->move(me);	
        //delete("inquiry/trouble");
	//delete("inquiry/令牌");
      }
	return 1;	
}
