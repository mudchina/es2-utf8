
inherit ROOM;

void create()
{
      set("short","后院书房");
	set("long", @LONG
这是一间小小的书房，窗明几静，朴素典雅，一张古意盎然的红木书桌，
吸引了你的目光，上面摆著一座小小的香炉，几本善本书整齐的堆放在桌上
，可见主人相当的爱惜书本。一幅「沧海龙吟」的舞曲图画挂在墙上，似乎
有一些秘密在里头。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"latemoon7",

        ]) );
        set("item_desc", ([
                "sea-dragon" : @TEXT
这是一幅湘绣的彩图，上有几名貌美的女子，以不同的姿态
舞著，其漫妙之处让你著迷。图旁另绣有一曲名『西出阳关』
(dancing out)与『有凤来仪 』(dancing yu-girl)
TEXT
]));

      set("objects", ([
          __DIR__"npc/girl" : 1 ]) );
	setup();
	replace_program(ROOM);
}
