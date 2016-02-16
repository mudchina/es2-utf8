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
    __DIR__"npc/worker2" : 3,
	]) );
    set("resource/water",1);
    set("outdoors", "snow");
	setup();
	replace_program(ROOM);
}

void init()
{
        add_action("do_fillwater", "fillwater");
}

int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "清水",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("你从井里装满了清水! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？");
        }
        return 1;
}

