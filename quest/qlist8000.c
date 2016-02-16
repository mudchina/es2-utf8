inherit SKILL;

mapping *quest = ({
        ([      "quest":                "郑屠夫",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "卧龙岗强盗",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            35,
                "pot_bonus":            35,
                "score" :               10
        ]),
        ([      "quest":                "彩衣少女",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "护寺武僧",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               15
        ]),
        ([      "quest":                "飞贼",
                "quest_type":           "杀",
                "time":                 600,
                "exp_bonus":            40,
                "pot_bonus":            35,
                "score" :               10
        ]),
        ([      "quest":                "农夫",
                "quest_type":           "杀",
                "time":                 120,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               12
        ]),
        ([      "quest":                "旅客",
                "quest_type":           "杀",
                "time":                 200,
                "exp_bonus":            25,
                "pot_bonus":            25,
                "score" :               10
        ]),
        ([      "quest":                "樵夫",
                "quest_type":           "杀",
                "time":                 120,
                "exp_bonus":            15,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "肥岩蛭",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "大岩蛭",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            25,
                "score" :               10
        ]),
        ([      "quest":                "巨岩蛭",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            50,
                "pot_bonus":            35,
                "score" :               10
        ]),
        ([      "quest":                "土匪爪牙",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            45,
                "pot_bonus":            35,
                "score" :               10
        ]),
        ([      "quest":                "昭仪",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "圆春",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "惜春",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "跛僧人",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "僵尸侍者",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            35,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "明心",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "清虚",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            35,
                "pot_bonus":            20,
                "score" :               10
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

