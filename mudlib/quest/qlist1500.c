inherit SKILL;

mapping *quest = ({
        ([      "quest":                "乞丐",
                "quest_type":           "杀",
                "time":                 50,
                "exp_bonus":            25,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "船夫",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            45,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "潘若秋",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            35,
                "pot_bonus":            25,
                "score" :               10
        ]),
        ([      "quest":                "宝官",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "知客僧",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15
        ]),
        ([      "quest":                "鸨母",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            35,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "杂货贩",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            35,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "裁缝",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               18
        ]),
        ([      "quest":                "茶工",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            38,
                "pot_bonus":            30,
                "score" :               12
        ]),
        ([      "quest":                "李火狮",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            45,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "杜宽",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               12
        ]),
        ([      "quest":                "收破烂的",
                "quest_type":           "杀",
                "time":                 50,
                "exp_bonus":            25,
                "pot_bonus":            15,
                "score" :               12
        ]),
       ([      "quest":                "王铁匠",
                "quest_type":           "杀",
                "time":                 50,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
       ([      "quest":                "武馆弟子",
                "quest_type":           "杀",
                "time":                 50,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               20
        ]),
        ([      "quest":                "贵公子",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "玄真",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            25,
                "score" :               10
        ]),
       ([      "quest":                "岩蛭",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            40,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "蜘蛛",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "蝴蝶",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            45,
                "pot_bonus":            35,
                "score" :               10
        ]),
        ([      "quest":                "芳绫",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            35,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "金丝雀",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "药僧",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "进香客",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            20,
                "score" :               10
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

