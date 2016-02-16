#include <ansi.h>

inherit NPC;

string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈",
        "刘","林" });
string *name_words = ({ "顺","昌","振","发","财","俊","彦","良","志","忠",
        "孝","雄","益","添","金","辉","长","盛","胜","进","安","福","同",
        "满","富","万","龙","隆","祥","栋","国","亿","寿" });

string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

string *rnd_say = ({
        "我是新手，请告诉我如何玩这个游戏。",
        "为什麽我的精气神都不会恢复？",
        "有谁可以给我一些钱？",
        "这里的人都不理我！",
        "可不可以告诉我哪里可以练功\？",
        "hi",
        "hello",
        "hello",
        "hmm",
        "wa...",
        "waley",
        "wait...",
        "hohoho",
        "hehe",
        "ah..",
});

varargs void drool(string msg, string who);

void create()
{
        string name, id;

        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];

        id = rnd_id[random(sizeof(rnd_id))];
        if( random(10) > 4 ) id += rnd_id[random(sizeof(rnd_id))];
        id += rnd_id_tail[random(sizeof(rnd_id_tail))];

        set_name(name, ({ id, "drooler" }) );
        set("title", "普通百姓");
        set("gender", "男性");
        set("age", 14);
        set("attitude", "friendly");
        set("attitude", "friendly");
        set("combat_exp", 100);
        set("env/wimpy", 100);
        set("chat_chance", 30);
        set("chat_msg", ({
                (: command, "get all" :),
                (: command, "wear all" :),
                (: command, "wield all" :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
           }) );
        setup();
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "！", "");
        msg = replace_string(msg, "啊", "");
        msg = replace_string(msg, "吗", "");
        msg = replace_string(msg, "耶", "");
        msg = replace_string(msg, "吧", "");
        msg = replace_string(msg, "吧", "");

        if( msg!="" ) {
                add("memory/" + who, ({ msg }));
                return 1;
        } else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
        string who, phrase;

        if( !userp(ob) || (channel != "chat") ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
        string who, phrase;
        string who, phrase;

        if( !userp(ob) ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
                if( random(10)<5 ) {
                        command("chat 为什麽踢我？会痛耶！");
                        break;
                }
        default:
                if( random(10)<5 )
                        command(verb + " " + ob->query("id"));
                else
                        drool();
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;

        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }

        if( (strsrch(msg, "为什麽") >= 0) ) {
                if( sscanf(msg, "%*s为什麽%s", msg)==2 ) msg = "为什麽" + msg;
                switch(random(8)) {
                case 0: command("chat " + who + "，你是在问我吗？"); 
			break;
                case 1: command("chat 关於" + msg + " ... "); 
			break;
                case 2: command("chat 呃 ... "); drool(); 
			break;
                case 3: command("chat 这个问题嘛 ...."); 
			break;
                case 4: command("chat " + who + "，知道这个问题的答案对你那麽重要吗？"); 
			break;
                case 5: command("chat " + msg + "？"); 
			break;
                case 6: command("chat " + who + "你能不能说清楚一点？"); 
			break;
                case 7: command("chat " + who + "，我不懂你问的问题"); 
			break;
                	}
        }
        else if( (strsrch(msg, "你") >= 0)
        ||      (strsrch(msg, "□") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
                msg = replace_string(msg, "你", "我");
                msg = replace_string(msg, "□", "我");
                switch(random(10)) {
                case 0: command("chat " + who + "，你是说" + msg + "吗？");      
			break;
                case 1: command("chat 你确定" + msg + "？");     
			break;
                case 2: command("chat " + msg + "跟你有什麽关系？");     
			break;
                case 3: command("chat 嗯 ... " + who + "说得好"); 
			break;
                case 4: command("chat " + who + "你为什麽对" + msg + "这麽有兴趣？"); 
			break;
                case 5: command("chat 为什麽你认为" + msg + "？"); 
			break;
                case 6: command("chat 换个话题吧"); drool(); 
			break;
                case 7: command("chat 才怪"); 
			break;
                case 8: command("chat 不一定吧？"); 
			break;
                case 9: command("chat 有这个可能 ...."); 
			break;
                }
        }
        else if( (strsrch(msg, "我") >= 0)) {
                if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
                msg = replace_string(msg, "我", "你");
                msg = replace_string(msg, "?", "");
                switch(random(8)) {
                case 0: command("chat 你是说" + msg + "吗？"); break;
                case 1: command("chat 真的？" + msg + "？");     break;
                case 2: command("chat 如果" + msg + "，我能帮你什麽忙吗？");     
			break;
                case 3: command("hmm"); break;
                case 4: command("chat 你认为" + msg + "？"); break;
                case 5: command("chat 我有同感"); break;
                case 6: command("chat 你说的「" + msg + "」我不能苟同"); 
			break;
                case 7: command("chat 有关「" + msg + "」的话题到此为止好吗？"); 
			break;
                }
        } else {
                switch(random(20)) {
                        case 0: command("chat 为什麽说" + msg + "?"); 
				break;
                        case 1: command("chat 「" + msg + "」是什麽意思？"); 
				break;
                        case 2: command("chat " + msg + "？"); break;
                        case 3: command("grin"); break;
                        case 4: command("smile"); break;
                        case 5: command("?"); break;
                        case 6: command("chat ...."); break;
                        case 7: command("hmm"); break;
                        case 8: command("chat " + rnd_say[random(sizeof(rnd_say))]); break
;
                        case 9: command("chat 你怎麽知道" + msg + "?"); break;
                        case 10: command("chat 刚刚" + who + "不是说了，" + msg); 
				break;
                        case 11: command("chat 我当然知道，" + msg); break;
                        case 12: command("chat 然後呢？"); break;
                        case 13: command("chat 真的吗？"); break;
                        case 14: command("chat 我不这麽认为。"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}

int accept_object()
{
        return 1;
}

