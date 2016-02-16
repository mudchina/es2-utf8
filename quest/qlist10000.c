inherit SKILL;

mapping *quest = ({
        ([      "quest":                "卧龙岗强盗",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               10 
        ]),
        ([      "quest":                "郑屠夫",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               6 
        ]),
        ([      "quest":                "彩衣少女",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               4
        ]),
        ([      "quest":                "飞贼",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               5
        ]),
        ([      "quest":                "兵器贩子",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               8
        ]),
        ([      "quest":                "刘安禄",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            15,
                "score" :               8 
        ]),
        ([      "quest":                "旅客",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               8
        ]),
       ([      "quest":                "土匪爪牙",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
       ([      "quest":                "巨岩蛭",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15 
        ]),
       ([      "quest":                "袭人",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            10,
                "pot_bonus":            10,
                "score" :               9
        ]),
       ([      "quest":                "圆春",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            10,
                "pot_bonus":            10,
                "score" :               8
        ]),
/*       ([      "quest":                "柳绘心",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
       ([      "quest":                "老兵",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               8 
        ]),
        ([      "quest":                "趟子手",
                "quest_type":           "杀",
                "time":                 540,
                "exp_bonus":            40,
                "pot_bonus":            30,
                "score" :               8
        ]),
        ([      "quest":                "后备兵",
                "quest_type":           "杀",
                "time":                 480,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "旅客",
                "quest_type":           "杀",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "书生",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            30,
                "score" :               10 
        ]),
        ([      "quest":                "彩衣少女",
                "quest_type":           "杀",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "船夫",
                "quest_type":           "杀",
                "time":                 150,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5 
        ]),
        ([      "quest":                "明心",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               8 
        ]),
        ([      "quest":                "跛僧人",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               8 
        ]),
        ([      "quest":                "仆役",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               3
        ]),
*/
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

