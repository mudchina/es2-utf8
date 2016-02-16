// Room: /d/city/street1.c

inherit ROOM;

void create()
{
        set("short", "京师东街");
        set("long", @LONG
这里是京师东街的北段。往北走有一个大院子，院里立着根老高
老高的旗杆，上书一个斗大的「镖」字，隔很远就可以看见。镖局的
生意似乎很好，人络绎不绝。西向是庄严的神武门。向南则去向尚书
府和午门。
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"biaoju",
		"south":	__DIR__"street2",
		"west":		__DIR__"shenwumen",
		]));

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

