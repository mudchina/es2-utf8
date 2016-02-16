inherit ROOM;

void create()
{
        set("short", "刑房");
        set("long", @LONG
整间刑房已被乾曷的血迹然成暗红色。散发着扑鼻的腥臭。墙上挂满了
各式各样的邢具。刑房的地上散落着生锈的铁链和破碎的骷髅。偶尔之间，
你还可以听到老鼠“吱吱”的尖叫声。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"tunnel6",
        "east" : __DIR__"tunnel4",
        ]));
        set("objects", ([
         __DIR__"npc/highrat": 2, 
         __DIR__"npc/guard2" : 2
         ]) );
         
         setup();
}
                 