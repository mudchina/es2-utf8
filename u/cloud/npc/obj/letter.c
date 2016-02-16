inherit ITEM;

void create()
{
    set_name("信件", ({ "letter" }) );
    set_weight(50);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	    set("unit", "封");
	    set("long",@LONG
师叔：
    小徒在我这里学满，欲求教于您老，敬请收纳他为徒。
                                侄：剑秋 敬上
LONG
);
            set("material", "paper");
            set("value", 100);
        }
        setup();
}


