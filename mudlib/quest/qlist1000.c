inherit SKILL;

mapping *quest = ({
        ([      "quest":                "乞丐",
                "quest_type":           "杀",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               6
        ]),
        ([      "quest":                "李师师",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "宝官",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            30,
                "score" :               4
        ]),
        ([      "quest":                "知客僧",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "裁缝",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            40,
                "score" :               8
        ]),
        ([      "quest":                "茶工",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            28,
                "pot_bonus":            18,
                "score" :               12
        ]),
        ([      "quest":                "疯狗",
                "quest_type":           "杀",
                "time":                 40,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "野狗",
                "quest_type":           "杀",
                "time":                 40,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "杜宽",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               8
        ]),
        ([      "quest":                "收破烂的",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            15,
                "score" :               12
        ]),
       ([      "quest":                "王铁匠",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               8
        ]),
        ([      "quest":                "扫地僧",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            35,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "进香客",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            25,
                "score" :               10
        ]),
       ([      "quest":                "魏无极",
                "quest_type":           "杀",
                "time":                 40,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               10
        ]),
       ([      "quest":                "武馆弟子",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               20
        ]),
        ([      "quest":                "卖饼大叔",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            25,
                "score" :               8
        ]),
        ([      "quest":                "卖糖葫芦的",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            25,
                "score" :               10
        ]),
        ([      "quest":                "卖包子的",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            25,
                "score" :               8
        ]),
        ([      "quest":                "家丁",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "岩蛭",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            50,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "蜘蛛",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "金丝雀",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "药僧",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

