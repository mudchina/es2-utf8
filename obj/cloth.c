// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("布衣", ({ "cloth" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一件普通的粗布衣服，不值什么钱。\n");
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 1);
  }
  setup();
}
