inherit ROOM;

void create()
{
        set("short", "树冠");
        set("long",@LONG
古树果非寻常之物，树冠白雾升腾，上接霄汉，如仙境一般，让人流连忘返...
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "down" : __DIR__"guyehill",
        ]));
        set("objects", ([
                __DIR__"npc/crane" : 4,
                      ]) );

        setup();
        replace_program(ROOM);
} 
