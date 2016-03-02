// Mon  08-21-95

inherit ITEM;

void create()
{
	set_name("绳子", ({"rope"}) );
	if (clonep())
		set_default_object(__FILE__);
	else {
	set("unit","捆");
	set("long", @LONG
这是一捆粗麻绳. 你可以用它来上吊(hang).

LONG
	);
	set("material","linen");
	set("value",5);
	set_weight(3000);
	}
}

void init()
{
    add_action("hang_self", "hang");
}

int hang_self(string str)
{
    // do we pass any argument?
    if (!str)
        return notify_fail("嗯... 想上吊啊? hang <name> 罗... \n");
    // check if we are doing this indoor
    if (environment(this_player())->query("outdoors"))
        return notify_fail("你四处看看, 实在找不到地方挂绳子说...\n");
    // are we hanging ourselves? :-)
    if (((string)this_player()->query("id") != str) && (str != "self"))
        return notify_fail("ㄟ... 上吊是自己的事, 请不要鸡婆...\n");
    // if we get to here, we are ready..
    tell_room(environment(this_player()), (string)this_player()->name()+
    "叹了一口气, 很肯定地把绳子套在脖子上.....\n",
    ({this_object(), this_player()}) );
    tell_object(this_player(), "你把绳子一端挂好, 另一端往脖子上一套.....\n");
    this_player()->die();
    return 1;
}

