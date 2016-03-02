// Room: /d/sanyen/temple.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "大雄宝殿");
	set("long", @LONG
一阵耀眼的金光向你袭来, 你定神一看原来是座一丈八尺的如来
佛祖金身, 坐在一座三尺高的莲台上, 前方的香炉里香烟缓缓飘上天
。这整座山烟寺都是由上好的桧木搭建而成, 南方则是两扇敞开的金
门, 价值不菲, 气势不凡, 在佛像的右侧有道黄布幔, 布幔后似乎是
条通道。西边则传来阵阵的流水声。
LONG
	);
	set("valid_startroom", 1);
    set("exits", ([ /* sizeof() == 3 */
		"south" : "/d/sanyen/road1",
		"west" : "/d/sanyen/inner_yard",
        "north" : "/d/sanyen/corridor",
	]));

	set("objects", ([
		CLASS_D("bonze") + "/master": 1
	]) );

	create_door("south", "金门", "north", DOOR_CLOSED);

	setup();
	call_other("/obj/board/bonze_b", "???");

	replace_program(ROOM);
}
