inherit NPC;

void create()
{
     set_name("进香客", ({"guest"}) );
     set("gender", "男性");
     set("age", 31);
     set("long", 
         "一个福福泰泰的中年人, 他正气喘嘘嘘地走著石梯道\n");
     set("combat_exp", 600);
     set("attitude", "friendly");
     setup();
     add_money("silver", 5);
}
