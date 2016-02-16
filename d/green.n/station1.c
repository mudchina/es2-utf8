// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "工作站");
	set("long", @LONG
这里是采石场的工作站，几间矮小的房舍延著山壁建造。靠南的山边
有一间马房，旁边还堆著山一般的乾草饲料，几辆运输用的车子停在旁边
。往北看去是采石场的空地往南是一条由石板铺成的小斜坡，通往村前的
工作站。西边不远处有一栋看来相当特别的房舍。
 
LONG
	);
    set("exits", ([
    "north" : __DIR__"field1",
    "southwest" : __DIR__"station0",
]));
	set("outdoors", "green");
	set("objects", ([
    __DIR__"npc/worker2" :2,
	]) );

	setup();
	replace_program(ROOM);
}
