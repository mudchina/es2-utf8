inherit SKILL;

mapping *quest = ({
        ([      "quest":                "船夫",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            40,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "潘若秋",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "弈者",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            24,
                "score" :               10
        ]),
        ([      "quest":                "宝官",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            24,
                "pot_bonus":            16,
                "score" :               10
        ]),
        ([      "quest":                "化缘和尚",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            38,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "知客僧",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               15
        ]),
        ([      "quest":                "鸨母",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "杂货贩",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "裁缝",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               18
        ]),
        ([      "quest":                "农夫",
                "quest_type":           "杀",
                "time":                 600,
                "exp_bonus":            50,
                "pot_bonus":            30,
                "score" :               12
        ]),
        ([      "quest":                "李火狮",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            28,
                "pot_bonus":            26,
                "score" :               10
        ]),
        ([      "quest":                "杜宽",
                "quest_type":           "杀",
                "time":                 50,
                "exp_bonus":            24,
                "pot_bonus":            20,
                "score" :               12
        ]),
        ([      "quest":                "旅客",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            40,
                "score" :               10
        ]),
        ([      "quest":                "樵夫",
                "quest_type":           "杀",
                "time":                 600,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "贵公子",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "岩蛭",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "玄真",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            25,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "蜘蛛",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            16,
                "score" :               10
        ]),
        ([      "quest":                "蝴蝶",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            36,
                "pot_bonus":            25,
                "score" :               10
        ]),
        ([      "quest":                "芳绫",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "金丝雀",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "药僧",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            18,
                "score" :               10
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

