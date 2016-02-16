inherit SKILL;

mapping *quest = ({
        ([      "quest":                "船夫",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "潘若秋",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            16,
                "score" :               10
        ]),
        ([      "quest":                "弈者",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            35,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "宝官",
                "quest_type":           "杀",
                "time":                 50,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "化缘和尚",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "护寺武僧",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            50,
                "pot_bonus":            40,
                "score" :               15
        ]),
        ([      "quest":                "鸨母",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "杂货贩",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "农夫",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               12
        ]),
        ([      "quest":                "李火狮",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "旅客",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "樵夫",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            25,
                "pot_bonus":            25,
                "score" :               10
        ]),
        ([      "quest":                "贵公子",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "肥岩蛭",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            45,
                "pot_bonus":            35,
                "score" :               10
        ]),
        ([      "quest":                "大岩蛭",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            45,
                "pot_bonus":            35,
                "score" :               10
        ]),
        ([      "quest":                "蝴蝶",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "芳绫",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "昭仪",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            35,
                "pot_bonus":            25,
                "score" :               10
        ]),
        ([      "quest":                "圆春",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            35,
                "pot_bonus":            25,
                "score" :               10
        ]),
        ([      "quest":                "惜春",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "跛僧人",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "玄真",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "明心",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            35,
                "pot_bonus":            35,
                "score" :               10
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

