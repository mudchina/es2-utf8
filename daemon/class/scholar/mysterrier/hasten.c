// hasten.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int count;

        if( !me->is_fighting() )
                return notify_fail("「玄羽乱舞」只能在战斗中使用。\n");

        if( (int)me->query("kee") < 70 ) return notify_fail("你的气不够！\n");
        if( (int)me->query("force") - (int)me->query("max_force") < 70 )
                return notify_fail("你的真气不够！\n");

        msg = HIY "$N使出步玄七诀第一式「玄羽乱舞」，身法陡然加快！\n" NOR;

        message_vision(msg, me);
        count = (int)me->query_skill("mysterrier") / 20 + 2;
        if( count > 7 ) count = 7;
        while( count-- ) {
                object ob;

                me->clean_up_enemy();
                ob = me->select_opponent();
                if( !ob || (environment(ob) != environment(me))) {
                        message_vision(CYN "$N的身形转了几转，倏地停住了脚步。\n" NOR, me);
                        break;
                } else
                        message_vision(CYN "$N迅捷无伦地在$n身旁绕了一圈 ...\n" NOR, me, ob);

                if( !COMBAT_D->fight(me, ob) )
                        message_vision(CYN "但是$N找不到机会出手！\n" NOR, me);
                me->receive_damage("kee", 10);
                me->add("force", -10);
        }

        me->start_busy(3);
        return 1;
}
