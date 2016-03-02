// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "黑店");
        set("long", @LONG
屋里相当冷清, 外面的浓雾还不时地从半开著的门缝飘进来,
地面上散著一些破旧的物品, 不过光从外表已经无法分辨出那是些
什么东西了. 墙上(wall)刻著一些潦草的字体, 墙角的一盏灯笼挣
扎似地发出一阵阵微弱的光芒, 也始得那些字看来格外的诡异.

LONG
	);
	set("exits", ([
	"west" : "/d/death/road1",
	]) );
	set("item_desc", ([
	"wall" : @WALL
几行你勉强分辨得出来的字:
我被困在这里了.... 我要回家啦!!!!!!!!!!!
                      ^^^^
                        靠自己啦...
什么叫靠自己啊?!?!? 这里连个活人都没有...

看到你自己时问一下吧... 自己人都会互相帮忙的说.. 
                                    ^^^^
                                 你... 确... 定?!?!
喔.. 
WALL
	]) );
        setup();
        replace_program(ROOM);
}
