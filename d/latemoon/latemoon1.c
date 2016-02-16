#include <room.h>

inherit ROOM;

void create()
{
	set("short","晚月庄大厅");
	set("long", @LONG
走进大厅，抬头迎面看见的是一面紫红绣金挂幔，一面屏风将宽敞的
大厅隔成两半，东西两面各设著七张紫檀雕案，案上一色白玉羊脂花瓶，
瓶中插著粉红的处子牡丹，紫檀雕案中间又都挂著七尺来长的画轴，各式
鸟兽虫鱼，翎毛丹青，栩栩如生，宛如要从画纸上飞出，嬉戏于大厅之中
，这大厅中的富贵气派之中透著一股秀气，但是却也无一般富豪人家或酒
店的庸脂俗粉之气。
    屏风两旁的白石嵌云柱上工整地刻著一幅对联写道：

    「座上珠玑照日月，却掩珠帘，难为芳心;
      堂前飘香焕云霞，不知岁月，但晓清音。」

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" :__DIR__"front_yard",
		"north" :__DIR__"latemoon3",
		"west" :__DIR__"latemoonc",
	]));

	set("objects",([
        __DIR__"npc/servant" : 2,
		CLASS_D("dancer") + "/master" : 1 ]) );
	set("valid_startroom", 1);
	setup();
	call_other("/obj/board/dancer_b", "???");
	replace_program(ROOM);
}
