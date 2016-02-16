// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "工作站");
	set("long", @LONG
这里是采石场在村口的工作站，一栋小小的木屋立在东边，旁边是一
条上山的斜坡。路旁有一口井。空地上停著几辆载满石料的车。往西是一
条铺著大石板的路，一路往山下延伸过去。
 
LONG
	);
    set("exits", ([
    "northeast" : __DIR__"station1",
    "west" : __DIR__"path5",
]));
	set("objects", ([
    __DIR__"npc/worker2" : 1,
	]) );
    set("resource/water",1);

	setup();
	replace_program(ROOM);
}

