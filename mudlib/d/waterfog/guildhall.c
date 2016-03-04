// guildhall.c

inherit CLASS_GUILD;

void create()
{
        set("short", "水烟阁正厅");
        set("long", @LONG
这里是水烟阁的正厅，简单的陈设中透出一股尊贵不凡的气派，一
张黝黑的太师椅端坐在大厅中央，这里同时也是「武者」们议事的所在
，每年的正月十七都要在水烟阁外的「虹台」推选武林盟主，然後在这
里举行登位大典。你可以看到北边的墙上挂著一樟木匾(sign)，似乎写
著一些有关成为一名武者的事项。
LONG
        );
        set("exits", ([
                "south" : __DIR__"entrance",
        ]));
        set("item_desc", ([
                "sign": @TEXT
要成为一名武者并不难，水烟阁随时欢迎任何身家清白之人成为我们的
一份子，只要你加入(join)武者同盟，就可以向同盟中的各大门派拜师
学艺。
TEXT
        ]) );

        set("objects", ([
                CLASS_D("fighter") + "champion":1,
                CLASS_D("fighter") + "master":1,
                CLASS_D("fighter") + "executioner":1
        ]) );
        set("valid_startroom", 1);
        setup();
        call_other("/obj/board/fighter_b", "???");
}
