inherit SKILL;

mapping *quest = ({
        ([      "quest":                "守城官兵",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               9 
        ]),
        ([      "quest":                "赫造基",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               9 
        ]),
        ([      "quest":                "独眼头陀",
                "quest_type":           "杀",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5 
        ]),
        ([      "quest":                "芙云",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               5
        ]),
        ([      "quest":                "梦玉楼",
                "quest_type":           "杀",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               8
        ]),
       ([      "quest":                "安惜迩",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
       ([      "quest":                "武官",
                "quest_type":           "杀",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15
        ]),
       ([      "quest":                "县城官兵",  
               "quest_type":           "杀",
               "time":                  500,
               "exp_bonus":             40,
               "pot_bonus":             20,
               "score" :                8
         ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

