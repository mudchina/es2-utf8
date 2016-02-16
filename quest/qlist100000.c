inherit SKILL;

mapping *quest = ({
       ([      "quest":                "李信",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            60,
                "pot_bonus":            30,
                "score" :               20
        ]),
       ([      "quest":                "严廷殷",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            100,
                "pot_bonus":            50,
                "score" :               30
        ]),
       ([      "quest":                "赫造基",
                "quest_type":           "杀",
                "time":                 200,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               15
        ]),
       ([      "quest":                "狼狗",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            80,
                "pot_bonus":            40,
                "score" :               20
        ]),
       ([      "quest":                "常老大",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            100,
                "pot_bonus":            50,
                "score" :               30
        ]),
       ([      "quest":                "蓝雨梅",
                "quest_type":           "杀",
                "time":                 50,
                "exp_bonus":            40,
                "pot_bonus":            15,
                "score" :               15
        ]),
       ([      "quest":                "蓝筱薇",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15
        ]),
       ([      "quest":                "土匪首领",
                "quest_type":           "杀",
                "time":                 400,
                "exp_bonus":            60,
                "pot_bonus":            35,
                "score" :               15
        ]),
       ([      "quest":                "疯老头子",
                "quest_type":           "杀",
                "time":                 400,
                "exp_bonus":            70,
                "pot_bonus":            40,
                "score" :               15
        ]),
        ([      "quest":                "守城官兵",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               9 
        ]),
        ([      "quest":                "莫欣芳",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               9 
        ]),
        ([      "quest":                "邢千慧",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5 
        ]),
        ([      "quest":                "芙云",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               5
        ]),
        ([      "quest":                "梦玉楼",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               8
        ]),
       ([      "quest":                "安惜迩",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
       ([      "quest":                "武官",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15
        ]),
       ([      "quest":                "县城官兵",  
               "quest_type":           "杀",
               "time":                  300,
               "exp_bonus":             40,
               "pot_bonus":             20,
               "score" :                8
         ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

