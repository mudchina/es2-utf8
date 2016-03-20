var mapdata = 
{
  "total": 1270,
  "count": 556,
  "domains": {
    "canyon": 27,
    "choyin": 62,
    "chuenyu": 37,
    "city": 55,
    "death": 12,
    "goathill": 16,
    "graveyard": 2,
    "green": 38,
    "latemoon": 74,
    "oldpine": 41,
    "sanyen": 18,
    "snow": 38,
    "temple": 27,
    "village": 26,
    "waterfog": 28,
    "wiz": 4,
    "cloud": 51
  },
  "rooms": {
    "/d/canyon/bamboo/bamboo1": {
      "type": "ROOM",
      "short": "竹林道入口",
      "exits": {
        "north": "/d/canyon/bamboo/bamboo2",
        "back": "/d/canyon/fantasy1"
      }
    },
    "/d/canyon/bamboo/bamboo2": {
      "type": "ROOM",
      "short": "竹林道",
      "exits": {
        "north": "/d/canyon/bamboo/bamboo3",
        "south": "/d/canyon/bamboo/bamboo1"
      }
    },
    "/d/canyon/bamboo/bamboo3": {
      "type": "ROOM",
      "short": "竹林道",
      "exits": {
        "south": "/d/canyon/bamboo/bamboo2"
      }
    },
    "/d/canyon/bamboo/train": {
      "type": "ROOM",
      "short": "洞内石室",
      "exits": {
        "out": "/d/canyon/bamboo/bamboo3"
      }
    },
    "/d/canyon/blackmarket": {
      "type": "ROOM",
      "short": "兵器库",
      "exits": {
        "east": "/d/canyon/canyon4"
      },
      "objects": {
        "/d/canyon/npc/seller": 1
      }
    },
    "/d/canyon/camp1": {
      "type": "ROOM",
      "short": "军营入口",
      "exits": {
        "west": "/d/canyon/canyon4",
        "north": "/d/canyon/camp3",
        "south": "/d/canyon/camp4",
        "east": "/d/canyon/camp2"
      },
      "objects": {
        "/d/canyon/npc/door_guard": 2
      }
    },
    "/d/canyon/camp2": {
      "type": "ROOM",
      "short": "营火区",
      "exits": {
        "north": "/d/canyon/camp5",
        "south": "/d/canyon/camp6",
        "east": "/d/canyon/camp7",
        "west": "/d/canyon/camp1"
      }
    },
    "/d/canyon/camp3": {
      "type": "ROOM",
      "short": "小兵营帐",
      "exits": {
        "south": "/d/canyon/camp1"
      },
      "objects": {
        "/d/canyon/npc/guard1": 2
      }
    },
    "/d/canyon/camp4": {
      "type": "ROOM",
      "short": "小兵营帐",
      "exits": {
        "north": "/d/canyon/camp1"
      },
      "objects": {
        "/d/canyon/npc/guard1": 2,
        "/d/canyon/npc/guard2": 1
      }
    },
    "/d/canyon/camp5": {
      "type": "ROOM",
      "short": "小队长营帐",
      "exits": {
        "south": "/d/canyon/camp2"
      },
      "objects": {
        "/d/canyon/npc/leader1": 2
      }
    },
    "/d/canyon/camp6": {
      "type": "ROOM",
      "short": "小队长营帐",
      "exits": {
        "north": "/d/canyon/camp2"
      },
      "objects": {
        "/d/canyon/npc/captain": 1,
        "/d/canyon/npc/leader2": 1
      }
    },
    "/d/canyon/camp7": {
      "type": "ROOM",
      "short": "副将营帐",
      "exits": {
        "east": "/d/canyon/camp8",
        "west": "/d/canyon/camp2"
      },
      "objects": {
        "/d/canyon/npc/vice_general": 1
      }
    },
    "/d/canyon/camp8": {
      "type": "ROOM",
      "short": "将军营帐",
      "exits": {
        "west": "/d/canyon/camp7"
      },
      "objects": {
        "/d/canyon/npc/general": 1,
        "/d/canyon/npc/adviser": 1
      }
    },
    "/d/canyon/canyon1": {
      "type": "ROOM",
      "short": "黄石隘口尾",
      "exits": {
        "southwest": "/d/canyon/canyon2"
      }
    },
    "/d/canyon/canyon2": {
      "type": "ROOM",
      "short": "隘口小路",
      "exits": {
        "northeast": "/d/canyon/canyon1",
        "south": "/d/canyon/canyon3"
      }
    },
    "/d/canyon/canyon3": {
      "type": "ROOM",
      "short": "隘口小路",
      "exits": {
        "north": "/d/canyon/canyon2",
        "south": "/d/canyon/canyon4"
      }
    },
    "/d/canyon/canyon4": {
      "type": "ROOM",
      "short": "隘口中道",
      "exits": {
        "north": "/d/canyon/canyon3",
        "south": "/d/canyon/canyon5",
        "east": "/d/canyon/camp1"
      }
    },
    "/d/canyon/canyon5": {
      "type": "ROOM",
      "short": "关外小路",
      "exits": {
        "south": "/d/canyon/canyon6",
        "north": "/d/canyon/canyon4"
      }
    },
    "/d/canyon/canyon6": {
      "type": "ROOM",
      "short": "天驼关谷地",
      "exits": {
        "south": "/d/canyon/canyon7",
        "north": "/d/canyon/canyon5"
      }
    },
    "/d/canyon/canyon7": {
      "type": "ROOM",
      "short": "天驼关谷地",
      "exits": {
        "south": "/d/village/road1",
        "north": "/d/canyon/canyon6"
      }
    },
    "/d/canyon/dream/tmp": {
      "type": "ROOM",
      "short": "幻影道入口",
      "exits": {
        "down": "/d/canyon/fantasy1"
      }
    },
    "/d/canyon/evil/tmp": {
      "type": "ROOM",
      "short": "妖魔道入口",
      "exits": {
        "up": "/d/canyon/fantasy1"
      }
    },
    "/d/canyon/fantasy1": {
      "type": "ROOM",
      "short": "梦幻迷境通道",
      "exits": {
        "up": "/d/canyon/dream/tmp",
        "down": "/d/canyon/evil/tmp",
        "back": "/d/canyon/stone_forest3",
        "center": "/d/canyon/bamboo/bamboo1"
      }
    },
    "/d/canyon/road": {
      "type": "ROOM",
      "short": "碎石小路",
      "exits": {
        "northeast": "/d/snow/sroad4"
      }
    },
    "/d/canyon/stone_forest1": {
      "type": "ROOM",
      "short": "黄石穿林路路口",
      "exits": {
        "east": "/d/canyon/canyon2",
        "west": "/d/canyon/stone_forest2"
      }
    },
    "/d/canyon/stone_forest2": {
      "type": "ROOM",
      "short": "黄石穿林路",
      "exits": {
        "west": "/d/canyon/stone_forest3",
        "east": "/d/canyon/stone_forest1"
      }
    },
    "/d/canyon/stone_forest3": {
      "type": "ROOM",
      "short": "梦幻迷境入口",
      "exits": {
        "mirror": "/d/canyon/fantasy1",
        "east": "/d/canyon/stone_forest2"
      }
    },
    "/d/choyin/altar": {
      "type": "ROOM",
      "short": "火龙将军庙",
      "exits": {
        "down": "/d/choyin/dragon_temple"
      },
      "objects": {
        "/d/choyin/obj/denotation": 1,
        "/d/choyin/npc/lady": 1
      }
    },
    "/d/choyin/bridge1": {
      "type": "ROOM",
      "short": "曲桥",
      "exits": {
        "north": "/d/choyin/s_street1",
        "east": "/d/choyin/bridge2"
      },
      "objects": {
        "/d/choyin/npc/visitor": 4
      }
    },
    "/d/choyin/bridge2": {
      "type": "ROOM",
      "short": "曲桥",
      "exits": {
        "west": "/d/choyin/bridge1",
        "north": "/d/choyin/bridge3"
      },
      "objects": {
        "/d/choyin/npc/scholar": 2
      }
    },
    "/d/choyin/bridge3": {
      "type": "ROOM",
      "short": "曲桥",
      "exits": {
        "south": "/d/choyin/bridge2",
        "east": "/d/choyin/bridge4"
      },
      "objects": {
        "/d/choyin/npc/visitor": 4
      }
    },
    "/d/choyin/bridge4": {
      "type": "ROOM",
      "short": "曲桥",
      "exits": {
        "south": "/d/choyin/bridge5",
        "west": "/d/choyin/bridge3"
      },
      "objects": {
        "/d/choyin/npc/girl": 1,
        "/d/choyin/npc/maid": 2
      }
    },
    "/d/choyin/bridge5": {
      "type": "ROOM",
      "short": "曲桥",
      "exits": {
        "north": "/d/choyin/bridge4",
        "east": "/d/choyin/entrance"
      }
    },
    "/d/choyin/cloudpool": {
      "type": "ROOM",
      "short": "云梦大泽",
      "exits": {
        "southwest": "/d/choyin/solidpath2"
      },
      "objects": {
        "/d/choyin/npc/serpent": 4
      }
    },
    "/d/choyin/club": {
      "type": "ROOM",
      "short": "草堂",
      "exits": {
        "west": "/d/choyin/yard",
        "east": "/d/choyin/fence"
      }
    },
    "/d/choyin/court1": {
      "type": "ROOM",
      "short": "县府衙门",
      "exits": {
        "south": "/d/choyin/crossroad"
      },
      "objects": {
        "/d/choyin/npc/judge_gu.c": 4,
        "/d/choyin/npc/magistra.c": 2
      }
    },
    "/d/choyin/craneroom": {
      "type": "ROOM",
      "short": "树冠",
      "exits": {
        "down": "/d/choyin/guyehill"
      },
      "objects": {
        "/d/choyin/npc/crane": 4
      }
    },
    "/d/choyin/crossroad": {
      "type": "ROOM",
      "short": "十字路口",
      "exits": {
        "south": "/d/choyin/s_gate",
        "north": "/d/choyin/court1",
        "east": "/d/choyin/s_street5"
      }
    },
    "/d/choyin/dragon_temple": {
      "type": "ROOM",
      "short": "火龙将军庙",
      "exits": {
        "up": "/d/choyin/altar",
        "west": "/d/choyin/s_gate",
        "east": "/d/choyin/sw_road1"
      },
      "objects": {
        "/d/choyin/npc/crone": 1
      }
    },
    "/d/choyin/e_gate": {
      "type": "ROOM",
      "short": "东城门",
      "exits": {
        "west": "/d/choyin/e_street1",
        "east": "/d/choyin/solidpath1"
      },
      "objects": {
        "/d/choyin/npc/cityguard": 2,
        "/d/choyin/npc/ghost": 1
      }
    },
    "/d/choyin/e_street1": {
      "type": "ROOM",
      "short": "东大街",
      "exits": {
        "west": "/d/choyin/tree_tomb",
        "east": "/d/choyin/e_gate"
      }
    },
    "/d/choyin/entrance": {
      "type": "ROOM",
      "short": "曼雩台",
      "exits": {
        "west": "/d/choyin/bridge5",
        "east": "/d/choyin/taolin"
      },
      "objects": {
        "CLASS_D(scholar)+/master": 1
      }
    },
    "/d/choyin/fence": {
      "type": "ROOM",
      "short": "竹林",
      "exits": {
        "west": "/d/choyin/club",
        "eastup": "/d/choyin/rockyu"
      }
    },
    "/d/choyin/guyehill": {
      "type": "ROOM",
      "short": "绝壁",
      "exits": {
        "northdown": "/d/choyin/rockroad"
      }
    },
    "/d/choyin/halfhole": {
      "type": "ROOM",
      "short": "山洞",
      "exits": {
        "down": "/d/choyin/guyehill"
      },
      "objects": {
        "/d/choyin/obj/goldenrope": 1
      }
    },
    "/d/choyin/hollow": {
      "type": "ROOM",
      "short": "寒谷",
      "exits": {
        "east": "/d/choyin/hollow1"
      }
    },
    "/d/choyin/hollow1": {
      "type": "ROOM",
      "short": "寒谷",
      "exits": {
        "north": "/d/choyin/hollow2",
        "south": "/d/choyin/hollow1",
        "west": "/d/choyin/hollow"
      }
    },
    "/d/choyin/hollow2": {
      "type": "ROOM",
      "short": "寒谷",
      "exits": {
        "west": "/d/choyin/hollow3",
        "south": "/d/choyin/hollow1"
      }
    },
    "/d/choyin/hollow3": {
      "type": "ROOM",
      "short": "寒谷尽头",
      "exits": {
        "east": "/d/choyin/hollow1"
      },
      "objects": {
        "/d/choyin/obj/orchid": 1
      }
    },
    "/d/choyin/hotel1": {
      "type": "ROOM",
      "short": "福林酒楼",
      "exits": {
        "up": "/d/choyin/hotel2",
        "west": "/d/choyin/s_street2"
      },
      "objects": {
        "/d/choyin/npc/boss": 1,
        "/d/choyin/npc/sergeant": 1
      }
    },
    "/d/choyin/hotel2": {
      "type": "ROOM",
      "short": "福林酒楼",
      "exits": {
        "up": "/d/choyin/hotel3",
        "down": "/d/choyin/hotel1"
      },
      "objects": {
        "/d/choyin/npc/youngman": 1,
        "/d/choyin/npc/servant": 3
      }
    },
    "/d/choyin/hotel3": {
      "type": "ROOM",
      "short": "福林酒楼",
      "exits": {
        "down": "/d/choyin/hotel2"
      },
      "objects": {
        "/d/choyin/npc/guard": 3
      }
    },
    "/d/choyin/lionroom": {
      "type": "ROOM",
      "short": "神秘洞穴",
      "objects": {
        "/d/choyin/npc/lion": 1
      }
    },
    "/d/choyin/n_gate": {
      "type": "ROOM",
      "short": "乔阴县城北门",
      "exits": {
        "west": "/u/cloud/sunhill/road1",
        "south": "/d/choyin/n_street1"
      },
      "objects": {
        "/d/choyin/npc/cityguard": 2,
        "/d/choyin/npc/ghost": 1,
        "/obj/npc/garrison": 2
      }
    },
    "/d/choyin/n_street1": {
      "type": "ROOM",
      "short": "福林大街",
      "exits": {
        "south": "/d/choyin/n_street2",
        "north": "/d/choyin/n_gate"
      },
      "objects": {
        "/d/choyin/npc/cake_vendor": 1,
        "CLASS_D(beggar)+/master": 1
      }
    },
    "/d/choyin/n_street2": {
      "type": "ROOM",
      "short": "福林大街",
      "exits": {
        "south": "/d/choyin/n_street3",
        "north": "/d/choyin/n_street1"
      }
    },
    "/d/choyin/n_street3": {
      "type": "ROOM",
      "short": "福林大街",
      "exits": {
        "west": "/d/choyin/nw_street",
        "north": "/d/choyin/n_street2",
        "south": "/d/choyin/tree_tomb"
      },
      "objects": {
        "/d/choyin/npc/dumpling_seller": 1
      }
    },
    "/d/choyin/nw_street": {
      "type": "ROOM",
      "short": "石板空地",
      "exits": {
        "west": "/d/choyin/w_street4",
        "south": "/d/choyin/w_street3",
        "east": "/d/choyin/n_street3"
      }
    },
    "/d/choyin/platform": {
      "type": "ROOM",
      "short": "云台",
      "objects": {
        "/d/choyin/npc/lboy": 2
      }
    },
    "/d/choyin/rockpath1": {
      "type": "ROOM",
      "short": "青石小路",
      "exits": {
        "northdown": "/d/choyin/rockpath2",
        "southup": "/d/choyin/rockyu"
      }
    },
    "/d/choyin/rockpath2": {
      "type": "ROOM",
      "short": "青石小路",
      "exits": {
        "north": "/d/choyin/solidpath1",
        "southup": "/d/choyin/rockpath1"
      }
    },
    "/d/choyin/rockroad": {
      "type": "ROOM",
      "short": "砾石路",
      "exits": {
        "north": "/d/choyin/spath",
        "southup": "/d/choyin/guyehill"
      }
    },
    "/d/choyin/rockyu": {
      "type": "ROOM",
      "short": "青石峪",
      "exits": {
        "northdown": "/d/choyin/rockpath1",
        "westdown": "/d/choyin/fence",
        "southup": "/d/choyin/tongbhill"
      },
      "objects": {
        "/d/choyin/npc/oldman": 1
      }
    },
    "/d/choyin/s_gate": {
      "type": "ROOM",
      "short": "乔阴县城南门",
      "exits": {
        "north": "/d/choyin/crossroad",
        "east": "/d/choyin/dragon_temple",
        "south": "/d/choyin/spath"
      },
      "objects": {
        "/d/choyin/npc/cityguard": 2
      }
    },
    "/d/choyin/s_street1": {
      "type": "ROOM",
      "short": "南门广场",
      "exits": {
        "south": "/d/choyin/bridge1",
        "north": "/d/choyin/s_street2",
        "west": "/d/choyin/s_street4",
        "southwest": "/d/choyin/sw_road1"
      },
      "objects": {
        "/d/choyin/npc/cucurbit_seller": 1,
        "/d/choyin/npc/dumpling_seller": 1
      }
    },
    "/d/choyin/s_street2": {
      "type": "ROOM",
      "short": "福林大街",
      "exits": {
        "north": "/d/choyin/s_street3",
        "south": "/d/choyin/s_street1",
        "east": "/d/choyin/hotel1"
      }
    },
    "/d/choyin/s_street3": {
      "type": "ROOM",
      "short": "福林大街",
      "exits": {
        "south": "/d/choyin/s_street2",
        "north": "/d/choyin/tree_tomb"
      }
    },
    "/d/choyin/s_street4": {
      "type": "ROOM",
      "short": "承安街",
      "exits": {
        "west": "/d/choyin/s_street5",
        "east": "/d/choyin/s_street1"
      }
    },
    "/d/choyin/s_street5": {
      "type": "ROOM",
      "short": "承安街",
      "exits": {
        "west": "/d/choyin/crossroad",
        "east": "/d/choyin/s_street4"
      }
    },
    "/d/choyin/solidpath1": {
      "type": "ROOM",
      "short": "土路",
      "exits": {
        "west": "/d/choyin/e_gate",
        "south": "/d/choyin/rockpath2",
        "north": "/d/choyin/solidpath2"
      }
    },
    "/d/choyin/solidpath2": {
      "type": "ROOM",
      "short": "荒野小径",
      "exits": {
        "northeast": "/d/choyin/cloudpool",
        "south": "/d/choyin/solidpath1"
      }
    },
    "/d/choyin/spath": {
      "type": "ROOM",
      "short": "土路",
      "exits": {
        "north": "/d/choyin/s_gate",
        "south": "/d/choyin/rockroad"
      }
    },
    "/d/choyin/stonehole": {
      "type": "ROOM",
      "short": "石室"
    },
    "/d/choyin/stove": {
      "type": "ROOM",
      "short": "丹炉",
      "exits": {
        "out": "/d/choyin/tongbhill"
      },
      "objects": {
        "/d/choyin/obj/tablet": 5
      }
    },
    "/d/choyin/sw_road1": {
      "type": "ROOM",
      "short": "街道",
      "exits": {
        "northeast": "/d/choyin/s_street1",
        "west": "/d/choyin/dragon_temple"
      }
    },
    "/d/choyin/taolin": {
      "type": "ROOM",
      "short": "桃林",
      "exits": {
        "south": "/d/choyin/taolin",
        "north": "/d/choyin/taolin",
        "west": "/d/choyin/taolin",
        "east": "/d/choyin/taolin",
        "northwest": "/d/choyin/taolin",
        "southeast": "/d/choyin/taolin"
      }
    },
    "/d/choyin/tomb1": {
      "type": "ROOM",
      "short": "树王坟",
      "exits": {
        "north": "/d/choyin/tomb3",
        "west": "/d/choyin/tomb2",
        "up": "/d/choyin/tree_tomb"
      },
      "objects": {
        "/d/choyin/npc/shadow": 3
      }
    },
    "/d/choyin/tomb2": {
      "type": "ROOM",
      "short": "树王坟内部",
      "exits": {
        "east": "/d/choyin/tomb1"
      }
    },
    "/d/choyin/tomb3": {
      "type": "ROOM",
      "short": "树王坟内部",
      "exits": {
        "south": "/d/choyin/tomb1"
      },
      "objects": {
        "/d/choyin/obj/chest": 1
      }
    },
    "/d/choyin/tongbhill": {
      "type": "ROOM",
      "short": "桐柏山",
      "exits": {
        "northdown": "/d/choyin/rockyu"
      }
    },
    "/d/choyin/tree_tomb": {
      "type": "ROOM",
      "short": "树王坟",
      "exits": {
        "north": "/d/choyin/n_street3",
        "west": "/d/choyin/w_street3",
        "south": "/d/choyin/s_street3",
        "east": "/d/choyin/e_street1"
      }
    },
    "/d/choyin/w_street1": {
      "type": "ROOM",
      "short": "西大街",
      "exits": {
        "east": "/d/choyin/w_street2"
      }
    },
    "/d/choyin/w_street2": {
      "type": "ROOM",
      "short": "西大街",
      "exits": {
        "west": "/d/choyin/w_street1",
        "east": "/d/choyin/w_street3"
      }
    },
    "/d/choyin/w_street3": {
      "type": "ROOM",
      "short": "西大街",
      "exits": {
        "north": "/d/choyin/nw_street",
        "west": "/d/choyin/w_street2",
        "east": "/d/choyin/tree_tomb"
      }
    },
    "/d/choyin/w_street4": {
      "type": "ROOM",
      "short": "西大街",
      "exits": {
        "south": "/d/choyin/w_street2",
        "east": "/d/choyin/nw_street"
      }
    },
    "/d/choyin/yamen": {
      "type": "ROOM",
      "short": "大堂",
      "exits": {
        "north": "/d/choyin/yamen_iner",
        "south": "/d/choyin/yamen_yard"
      },
      "objects": {
        "/d/choyin/npc/judgeman": 1,
        "/d/choyin/npc/magistra": 2,
        "/d/choyin/npc/yamen_po": 8
      }
    },
    "/d/choyin/yamen_iner": {
      "type": "ROOM",
      "short": "内厅",
      "exits": {
        "south": "/d/choyin/yamen"
      }
    },
    "/d/choyin/yamen_yard": {
      "type": "ROOM",
      "short": "县衙内院",
      "exits": {
        "south": "/d/choyin/court1",
        "north": "/d/choyin/yamen"
      },
      "objects": {
        "/d/choyin/npc/magistra": 4
      }
    },
    "/d/choyin/yard": {
      "type": "ROOM",
      "short": "庭院",
      "exits": {
        "east": "/d/choyin/club"
      }
    },
    "/d/chuenyu/base_b_m": {
      "type": "ROOM",
      "short": "黑松山脚",
      "exits": {
        "south": "/d/chuenyu/sunnyroad",
        "up": "/d/chuenyu/foot_b_mtn"
      }
    },
    "/d/chuenyu/bedroom": {
      "type": "ROOM",
      "short": "卧室",
      "exits": {
        "north": "/d/chuenyu/yiantai",
        "south": "/d/chuenyu/kitchen",
        "westdown": "/d/chuenyu/west_blackge",
        "eastdown": "/d/chuenyu/east_blackge"
      }
    },
    "/d/chuenyu/center": {
      "type": "ROOM",
      "short": "黑松阁正厅",
      "exits": {
        "west": "/d/chuenyu/west_blackge"
      }
    },
    "/d/chuenyu/croad1": {
      "type": "ROOM",
      "short": "黄土大道",
      "exits": {
        "south": "/d/village/road1",
        "north": "/d/chuenyu/croad2"
      }
    },
    "/d/chuenyu/croad2": {
      "type": "ROOM",
      "short": "路口",
      "exits": {
        "northeast": "/d/chuenyu/sunnyroad",
        "south": "/d/chuenyu/croad1"
      }
    },
    "/d/chuenyu/dungeon": {
      "type": "ROOM",
      "short": "刑房",
      "exits": {
        "west": "/d/chuenyu/tunnel3",
        "north": "/d/chuenyu/tunnel4"
      },
      "objects": {
        "/d/chuenyu/npc/chuenyu": 1,
        "/d/chuenyu/xiaojuan2": 1
      }
    },
    "/d/chuenyu/dustyroad3": {
      "type": "ROOM",
      "short": "青石小路",
      "exits": {
        "southwest": "/d/chuenyu/croad2",
        "northeast": "/d/chuenyu/home",
        "north": "/d/chuenyu/sunnyroad"
      }
    },
    "/d/chuenyu/east_blackge": {
      "type": "ROOM",
      "short": "黑松阁东厅",
      "exits": {
        "east": "/d/chuenyu/east_garden",
        "south": "/d/chuenyu/south_garden",
        "westup": "/d/chuenyu/bedroom"
      },
      "objects": {
        "/d/chuenyu/npc/cleangirl": 1
      }
    },
    "/d/chuenyu/east_castle": {
      "type": "ROOM",
      "short": "黑松城堡的东侧",
      "exits": {
        "west": "/d/chuenyu/gate_castle"
      }
    },
    "/d/chuenyu/east_garden": {
      "type": "ROOM",
      "short": "东花园",
      "exits": {
        "west": "/d/chuenyu/east_blackge"
      },
      "objects": {
        "/d/chuenyu/npc/wolfdog": 3
      }
    },
    "/d/chuenyu/foot_b_mtn": {
      "type": "ROOM",
      "short": "黑松山腰",
      "exits": {
        "down": "/d/chuenyu/base_b_m",
        "up": "/d/chuenyu/high_b_mtn"
      }
    },
    "/d/chuenyu/gate_castle": {
      "type": "ROOM",
      "short": "黑松淳于",
      "exits": {
        "east": "/d/chuenyu/east_castle",
        "west": "/d/chuenyu/west_castle",
        "north": "/d/chuenyu/trap_castle",
        "down": "/d/chuenyu/high_b_mtn2"
      }
    },
    "/d/chuenyu/high_b_mtn": {
      "type": "ROOM",
      "short": "花岗石街",
      "exits": {
        "up": "/d/chuenyu/gate_castle",
        "east": "/d/chuenyu/rope_bridge"
      }
    },
    "/d/chuenyu/high_b_mtn2": {
      "type": "ROOM",
      "short": "花岗石街",
      "exits": {
        "down": "/d/chuenyu/base_b_m",
        "up": "/d/chuenyu/gate_castle",
        "west": "/d/chuenyu/rope_bridge"
      }
    },
    "/d/chuenyu/home": {
      "type": "ROOM",
      "short": "刘家小房",
      "exits": {
        "south": "/d/chuenyu/smallstorage",
        "north": "/d/chuenyu/littlegarden",
        "west": "/d/chuenyu/smallyard",
        "southwest": "/d/chuenyu/dustyroad3"
      },
      "objects": {
        "/d/chuenyu/npc/oldliu": 1
      }
    },
    "/d/chuenyu/kitchen": {
      "type": "ROOM",
      "short": "膳房",
      "exits": {
        "north": "/d/chuenyu/bedroom"
      },
      "objects": {
        "/d/chuenyu/obj/pigmeat": 3,
        "/d/chuenyu/obj/qiwine": 3,
        "/d/chuenyu/npc/cook": 1
      }
    },
    "/d/chuenyu/littlegarden": {
      "type": "ROOM",
      "short": "花园",
      "exits": {
        "south": "/d/chuenyu/home"
      },
      "objects": {
        "/d/chuenyu/npc/flowergirl": 5
      }
    },
    "/d/chuenyu/north_garden": {
      "type": "ROOM",
      "short": "北花园",
      "exits": {
        "south": "/d/chuenyu/west_blackge"
      },
      "objects": {
        "/d/chuenyu/npc/smallgardener": 2
      }
    },
    "/d/chuenyu/rope_bridge": {
      "type": "ROOM",
      "short": "铁索桥",
      "exits": {
        "west": "/d/chuenyu/high_b_mtn",
        "east": "/d/chuenyu/high_b_mtn2"
      },
      "objects": {
        "/d/chuenyu/npc/jiading3": 2
      }
    },
    "/d/chuenyu/smallstorage": {
      "type": "ROOM",
      "short": "厨房",
      "exits": {
        "north": "/d/chuenyu/home"
      },
      "objects": {
        "/d/chuenyu/npc/rat": 6
      }
    },
    "/d/chuenyu/smallyard": {
      "type": "ROOM",
      "short": "翠绿的小草坪",
      "exits": {
        "east": "/d/chuenyu/home",
        "south": "/d/chuenyu/dustyroad3"
      },
      "objects": {
        "/d/chuenyu/npc/frog": 2,
        "/d/chuenyu/npc/ant": 2,
        "/d/chuenyu/npc/fly": 2
      }
    },
    "/d/chuenyu/south_garden": {
      "type": "ROOM",
      "short": "南花园",
      "exits": {
        "north": "/d/chuenyu/east_blackge"
      },
      "objects": {
        "/d/chuenyu/npc/smallgardener": 2
      }
    },
    "/d/chuenyu/storage": {
      "type": "ROOM",
      "short": "储藏室",
      "exits": {
        "north": "/d/chuenyu/west_blackge"
      },
      "objects": {
        "/obj/longsword": 5
      }
    },
    "/d/chuenyu/sunnyroad": {
      "type": "ROOM",
      "short": "山脚乡田",
      "objects": {
        "/d/chuenyu/npc/flower_seller": 1
      },
      "exits": {
        "north": "/d/chuenyu/base_b_m",
        "southwest": "/d/chuenyu/croad2"
      }
    },
    "/d/chuenyu/tortureroom": {
      "type": "ROOM",
      "short": "刑房",
      "exits": {
        "south": "/d/chuenyu/tunnel6",
        "east": "/d/chuenyu/tunnel4"
      },
      "objects": {
        "/d/chuenyu/npc/highrat": 2,
        "/d/chuenyu/npc/guard2": 2
      }
    },
    "/d/chuenyu/tortureroom2": {
      "type": "ROOM",
      "short": "刑房",
      "exits": {
        "south": "/d/chuenyu/tunnel6",
        "east": "/d/chuenyu/tunnel4"
      },
      "objects": {
        "/d/chuenyu/npc/highrat": 2,
        "/d/chuenyu/npc/guard2": 2
      }
    },
    "/d/chuenyu/trap_castle": {
      "type": "ROOM",
      "short": "夹道",
      "exits": {
        "south": "/d/chuenyu/gate_castle"
      }
    },
    "/d/chuenyu/tunnel1": {
      "type": "ROOM",
      "short": "地牢",
      "exits": {
        "south": "/d/chuenyu/tunnel5",
        "north": "/d/chuenyu/tunnel2"
      },
      "objects": {
        "/d/chuenyu/npc/highrat": 1
      }
    },
    "/d/chuenyu/tunnel2": {
      "type": "ROOM",
      "short": "地牢",
      "exits": {
        "east": "/d/chuenyu/tunnel6",
        "north": "/d/chuenyu/tunnel3",
        "south": "/d/chuenyu/tunnel1"
      }
    },
    "/d/chuenyu/tunnel3": {
      "type": "ROOM",
      "short": "地牢",
      "exits": {
        "east": "/d/chuenyu/dungeon",
        "north": "/d/chuenyu/tunnel5",
        "south": "/d/chuenyu/tunnel2"
      }
    },
    "/d/chuenyu/tunnel4": {
      "type": "ROOM",
      "short": "地牢",
      "exits": {
        "north": "/d/chuenyu/tunnel5",
        "east": "/d/chuenyu/tortureroom",
        "west": "/d/chuenyu/tortureroom2",
        "south": "/d/chuenyu/dungeon"
      }
    },
    "/d/chuenyu/tunnel5": {
      "type": "ROOM",
      "short": "地牢",
      "exits": {
        "north": "/d/chuenyu/tunnel1",
        "west": "/d/chuenyu/tunnel6",
        "east": "/d/chuenyu/tortureroom"
      }
    },
    "/d/chuenyu/tunnel6": {
      "type": "ROOM",
      "short": "地牢",
      "exits": {
        "north": "/d/chuenyu/tortureroom2",
        "east": "/d/chuenyu/tunnel5"
      }
    },
    "/d/chuenyu/west_blackge": {
      "type": "ROOM",
      "short": "黑松阁西厅",
      "exits": {
        "eastup": "/d/chuenyu/bedroom",
        "east": "/d/chuenyu/center",
        "west": "/d/chuenyu/west_garden",
        "south": "/d/chuenyu/storage",
        "north": "/d/chuenyu/north_garden"
      },
      "objects": {
        "/d/chuenyu/npc/guard": 2
      }
    },
    "/d/chuenyu/west_castle": {
      "type": "ROOM",
      "short": "黑松城堡的西侧",
      "exits": {
        "east": "/d/chuenyu/gate_castle"
      }
    },
    "/d/chuenyu/west_garden": {
      "type": "ROOM",
      "short": "西花园",
      "exits": {
        "east": "/d/chuenyu/west_blackge"
      },
      "objects": {
        "/d/chuenyu/npc/gardener": 1,
        "/d/chuenyu/npc/bee": 2
      }
    },
    "/d/chuenyu/yiantai": {
      "type": "ROOM",
      "short": "阳台",
      "exits": {
        "south": "/d/chuenyu/bedroom"
      },
      "objects": {
        "/d/chuenyu/npc/pigeon": 2
      }
    },
    "/d/city/bank": {
      "type": "BANK",
      "short": "旺金钱庄",
      "exits": {
        "south": "/d/city/street8"
      },
      "objects": {
        "/d/city/npc/microsof": 1
      }
    },
    "/d/city/biaoju": {
      "type": "ROOM",
      "short": "振远总局",
      "exits": {
        "south": "/d/city/street1"
      },
      "objects": {
        "/d/city/npc/chen": 1
      }
    },
    "/d/city/boots": {
      "type": "ROOM",
      "short": "李记鞋店",
      "exits": {
        "south": "/d/city/street11"
      },
      "objects": {
        "/d/city/npc/shoer.c": 1
      }
    },
    "/d/city/bridge": {
      "type": "ROOM",
      "short": "天桥",
      "exits": {
        "south": "/d/city/street17",
        "west": "/d/city/street12",
        "east": "/d/city/street11",
        "north": "/d/city/jiaowu"
      },
      "objects": {
        "/d/city/npc/vendor": 1,
        "/d/city/npc/caker": 1,
        "/d/city/npc/dumpling_seller": 1
      }
    },
    "/d/city/cloth": {
      "type": "ROOM",
      "short": "四喜绸缎庄",
      "exits": {
        "east": "/d/city/street6"
      },
      "objects": {
        "/d/city/npc/clother.c": 1
      }
    },
    "/d/city/eastdoor1": {
      "type": "ROOM",
      "short": "京师东一门",
      "exits": {
        "west": "/d/city/street9"
      },
      "objects": {
        "/d/city/npc/guard": 3
      }
    },
    "/d/city/eastdoor2": {
      "type": "ROOM",
      "short": "京师东二门",
      "exits": {
        "west": "/d/city/street10"
      },
      "objects": {
        "/d/city/npc/guard": 3
      }
    },
    "/d/city/feiyuan": {
      "type": "ROOM",
      "short": "废园",
      "exits": {
        "south": "/d/city/street6"
      }
    },
    "/d/city/house1": {
      "type": "ROOM",
      "short": "空房间",
      "exits": {
        "north": "/d/city/street11"
      }
    },
    "/d/city/jiaowu": {
      "type": "ROOM",
      "short": "校武场",
      "exits": {
        "south": "/d/city/bridge",
        "north": "/d/city/wumen"
      }
    },
    "/d/city/jitan": {
      "type": "ROOM",
      "short": "祭坛",
      "exits": {
        "south": "/d/city/shenwumen",
        "north": "/d/city/street7"
      }
    },
    "/d/city/jiulou": {
      "type": "ROOM",
      "short": "太白酒楼",
      "exits": {
        "east": "/d/city/street5",
        "up": "/d/city/jiulou_2"
      },
      "objects": {
        "/d/city/npc/waiter": 1,
        "/d/city/npc/boss": 1
      }
    },
    "/d/city/jiulou_2": {
      "type": "ROOM",
      "short": "太白酒楼二楼",
      "exits": {
        "down": "/d/city/jiulou"
      }
    },
    "/d/city/midao1": {
      "type": "ROOM",
      "short": "地下密室"
    },
    "/d/city/northdoor": {
      "type": "ROOM",
      "short": "京师北门",
      "exits": {
        "north": "/d/city/nroad1",
        "south": "/d/city/street16"
      },
      "objects": {
        "/d/city/npc/guard": 3
      }
    },
    "/d/city/nroad1": {
      "type": "ROOM",
      "short": "北驿道",
      "exits": {
        "north": "/d/city/nroad2",
        "south": "/d/city/northdoor"
      }
    },
    "/d/city/nroad2": {
      "type": "ROOM",
      "short": "北驿道",
      "exits": {
        "south": "/d/city/nroad1",
        "north": "/d/village/road2"
      },
      "objects": {
        "/u/cp/chater2": 1
      }
    },
    "/d/city/shangshu/chufang": {
      "type": "ROOM",
      "short": "厨房",
      "exits": {
        "west": "/d/city/shangshu/road3"
      },
      "objects": {
        "/d/city/shangshu/npc/maid": 1
      }
    },
    "/d/city/shangshu/feiwu": {
      "type": "ROOM",
      "short": "废屋",
      "exits": {
        "east": "/d/city/shangshu/road4"
      }
    },
    "/d/city/shangshu/gate": {
      "type": "ROOM",
      "short": "尚书府大门",
      "exits": {
        "west": "/d/city/street3",
        "east": "/d/city/shangshu/yuan"
      },
      "objects": {
        "/d/city/shangshu/npc/guard": 1
      }
    },
    "/d/city/shangshu/huayuan": {
      "type": "ROOM",
      "short": "花园",
      "exits": {
        "north": "/d/city/shangshu/road3",
        "east": "/d/city/shangshu/neizhai",
        "west": "/d/city/shangshu/road4"
      },
      "objects": {
        "/d/city/shangshu/npc/gardener": 1
      }
    },
    "/d/city/shangshu/kefang": {
      "type": "ROOM",
      "short": "客房",
      "exits": {
        "west": "/d/city/shangshu/road2"
      }
    },
    "/d/city/shangshu/keting": {
      "type": "ROOM",
      "short": "尚书府客厅",
      "exits": {
        "west": "/d/city/shangshu/yuan"
      },
      "objects": {
        "/d/city/shangshu/npc/shangshu": 1
      }
    },
    "/d/city/shangshu/neizhai": {
      "type": "ROOM",
      "short": "内宅",
      "exits": {
        "west": "/d/city/shangshu/huayuan"
      },
      "objects": {
        "/d/city/shangshu/npc/qing_chen": 1
      }
    },
    "/d/city/shangshu/road1": {
      "type": "ROOM",
      "short": "小径",
      "exits": {
        "east": "/d/city/shangshu/xiaowu",
        "south": "/d/city/shangshu/road2"
      },
      "objects": {
        "/d/city/shangshu/npc/huyuan": 1
      }
    },
    "/d/city/shangshu/road2": {
      "type": "ROOM",
      "short": "小径",
      "exits": {
        "north": "/d/city/shangshu/road1",
        "east": "/d/city/shangshu/kefang",
        "south": "/d/city/shangshu/yuan"
      },
      "objects": {
        "/d/city/shangshu/npc/huyuan": 1,
        "/d/city/shangshu/npc/huyuan1": 1
      }
    },
    "/d/city/shangshu/road3": {
      "type": "ROOM",
      "short": "花园小径",
      "exits": {
        "north": "/d/city/shangshu/yuan",
        "south": "/d/city/shangshu/huayuan",
        "east": "/d/city/shangshu/chufang"
      }
    },
    "/d/city/shangshu/road4": {
      "type": "ROOM",
      "short": "小路",
      "exits": {
        "west": "/d/city/shangshu/feiwu",
        "east": "/d/city/shangshu/huayuan"
      }
    },
    "/d/city/shangshu/xiaowu": {
      "type": "ROOM",
      "short": "小屋",
      "exits": {
        "west": "/d/city/shangshu/road1"
      }
    },
    "/d/city/shangshu/yuan": {
      "type": "ROOM",
      "short": "尚书府庭院",
      "exits": {
        "west": "/d/city/shangshu/gate",
        "east": "/d/city/shangshu/keting",
        "south": "/d/city/shangshu/road3",
        "north": "/d/city/shangshu/road2"
      }
    },
    "/d/city/shenwumen": {
      "type": "ROOM",
      "short": "神武门",
      "exits": {
        "north": "/d/city/jitan",
        "east": "/d/city/street1",
        "west": "/d/city/street6"
      }
    },
    "/d/city/southdoor": {
      "type": "ROOM",
      "short": "京师南门",
      "exits": {
        "north": "/d/city/street17"
      },
      "objects": {
        "/d/city/npc/guard": 3
      }
    },
    "/d/city/street1": {
      "type": "ROOM",
      "short": "京师东街",
      "exits": {
        "north": "/d/city/biaoju",
        "south": "/d/city/street2",
        "west": "/d/city/shenwumen"
      }
    },
    "/d/city/street10": {
      "type": "ROOM",
      "short": "京师街道",
      "exits": {
        "east": "/d/city/eastdoor2",
        "west": "/d/city/street11"
      }
    },
    "/d/city/street11": {
      "type": "ROOM",
      "short": "京师街道",
      "exits": {
        "west": "/d/city/bridge",
        "north": "/d/city/boots",
        "east": "/d/city/street10",
        "south": "/d/city/house1"
      }
    },
    "/d/city/street12": {
      "type": "ROOM",
      "short": "京师街道",
      "exits": {
        "east": "/d/city/bridge",
        "west": "/d/city/street13"
      }
    },
    "/d/city/street13": {
      "type": "ROOM",
      "short": "京师街道",
      "exits": {
        "west": "/d/city/westdoor2",
        "east": "/d/city/street12"
      },
      "objects": {
        "d/snow/npc/scavenger": 1
      }
    },
    "/d/city/street14": {
      "type": "ROOM",
      "short": "京师街道",
      "exits": {
        "west": "/d/city/westdoor1",
        "east": "/d/city/street15"
      }
    },
    "/d/city/street15": {
      "type": "ROOM",
      "short": "京师街道",
      "exits": {
        "west": "/d/city/street14",
        "east": "/d/city/street7"
      }
    },
    "/d/city/street16": {
      "type": "ROOM",
      "short": "大栅栏",
      "exits": {
        "north": "/d/city/northdoor",
        "south": "/d/city/street7"
      }
    },
    "/d/city/street17": {
      "type": "ROOM",
      "short": "京师街道",
      "exits": {
        "north": "/d/city/bridge",
        "south": "/d/city/southdoor"
      },
      "objects": {
        "d/snow/npc/scavenger": 1
      }
    },
    "/d/city/street2": {
      "type": "ROOM",
      "short": "京师东街",
      "objects": {
        "/d/city/npc/walker": 2
      },
      "exits": {
        "north": "/d/city/street1",
        "south": "/d/city/street3"
      }
    },
    "/d/city/street3": {
      "type": "ROOM",
      "short": "京师东街",
      "exits": {
        "east": "/d/city/shangshu/gate",
        "west": "/d/city/wumen",
        "north": "/d/city/street2"
      }
    },
    "/d/city/street4": {
      "type": "ROOM",
      "short": "京师西街",
      "exits": {
        "east": "/d/city/wumen",
        "west": "/d/city/xiangguo/gate",
        "north": "/d/city/street5"
      },
      "objects": {
        "/d/city/npc/walker": 1,
        "/d/city/npc/trader": 1
      }
    },
    "/d/city/street5": {
      "type": "ROOM",
      "short": "京师西街",
      "exits": {
        "west": "/d/city/jiulou",
        "south": "/d/city/street4",
        "north": "/d/city/street6"
      }
    },
    "/d/city/street6": {
      "type": "ROOM",
      "short": "京师西街",
      "exits": {
        "east": "/d/city/shenwumen",
        "south": "/d/city/street5",
        "west": "/d/city/cloth",
        "north": "/d/city/feiyuan"
      }
    },
    "/d/city/street7": {
      "type": "ROOM",
      "short": "十字路口",
      "exits": {
        "east": "/d/city/street8",
        "west": "/d/city/street15",
        "north": "/d/city/street16",
        "south": "/d/city/jitan"
      }
    },
    "/d/city/street8": {
      "type": "ROOM",
      "short": "京师街道",
      "exits": {
        "east": "/d/city/street9",
        "north": "/d/city/bank",
        "west": "/d/city/street7"
      },
      "objects": {
        "d/snow/npc/scavenger": 1
      }
    },
    "/d/city/street9": {
      "type": "ROOM",
      "short": "京师街道",
      "exits": {
        "east": "/d/city/eastdoor1",
        "north": "/d/city/weapon",
        "west": "/d/city/street8"
      },
      "objects": {
        "d/snow/npc/scavenger": 1
      }
    },
    "/d/city/wall": {
      "type": "ROOM",
      "short": "院墙",
      "exits": {},
      "objects": {}
    },
    "/d/city/weapon": {
      "type": "ROOM",
      "short": "京师武器店",
      "exits": {
        "south": "/d/city/street9"
      },
      "objects": {
        "/d/city/npc/weaponor": 1
      }
    },
    "/d/city/westdoor1": {
      "type": "ROOM",
      "short": "京师西一门",
      "exits": {
        "east": "/d/city/street14"
      },
      "objects": {
        "/d/city/npc/guard": 3
      }
    },
    "/d/city/westdoor2": {
      "type": "ROOM",
      "short": "京师西二门",
      "exits": {
        "east": "/d/city/street13"
      },
      "objects": {
        "/d/city/npc/guard": 3
      }
    },
    "/d/city/wumen": {
      "type": "ROOM",
      "short": "午门",
      "exits": {
        "east": "/d/city/street3",
        "west": "/d/city/street4",
        "south": "/d/city/jiaowu"
      }
    },
    "/d/city/xiangguo/gate": {
      "type": "ROOM",
      "short": "相国府大门",
      "exits": {
        "east": "/d/city/street4"
      }
    },
    "/d/death/block": {
      "type": "ROOM",
      "short": "空房间"
    },
    "/d/death/bridge": {
      "type": "ROOM",
      "short": "奈何桥",
      "exits": {
        "north": "/d/death/gate",
        "south": "/d/death/bridge1"
      },
      "objects": {
        "/d/death/npc/hell_guard": 4
      }
    },
    "/d/death/bridge1": {
      "type": "ROOM",
      "short": "奈何桥",
      "exits": {
        "north": "/d/death/bridge"
      }
    },
    "/d/death/gate": {
      "type": "ROOM",
      "exits": {
        "south": "/d/death/bridge",
        "north": "/d/death/gateway"
      },
      "objects": {
        "/d/death/npc/wgargoyle": 1
      }
    },
    "/d/death/gateway": {
      "type": "ROOM",
      "short": "酆都城门",
      "exits": {
        "north": "/d/death/road1",
        "south": "/d/death/gate"
      },
      "objects": {
        "/d/death/npc/bgargoyle": 1
      }
    },
    "/d/death/inn1": {
      "type": "ROOM",
      "short": "小店",
      "exits": {
        "east": "/d/death/road1"
      }
    },
    "/d/death/inn2": {
      "type": "ROOM",
      "short": "黑店",
      "exits": {
        "west": "/d/death/road1"
      }
    },
    "/d/death/jail": {
      "type": "ROOM",
      "short": "绿岛"
    },
    "/d/death/road1": {
      "type": "ROOM",
      "short": "鬼门大道",
      "exits": {
        "north": "/d/death/road2",
        "south": "/d/death/gateway",
        "west": "/d/death/inn1",
        "east": "/d/death/inn2"
      }
    },
    "/d/death/road2": {
      "type": "ROOM",
      "short": "鬼门大道",
      "exits": {
        "north": "/d/death/road3",
        "south": "/d/death/road1"
      }
    },
    "/d/death/road3": {
      "type": "ROOM",
      "short": "路的尽头",
      "exits": {
        "south": "/d/death/road2"
      }
    },
    "/d/death/spath1": {
      "type": "ROOM",
      "short": "墙边小路",
      "exits": {
        "east": "/d/death/gateway"
      }
    },
    "/d/goathill/canyon1": {
      "type": "ROOM",
      "short": "峡谷",
      "exits": {
        "northdown": "/d/goathill/canyon2",
        "south": "/d/goathill/mroad6"
      }
    },
    "/d/goathill/canyon2": {
      "type": "ROOM",
      "short": "峡谷",
      "exits": {
        "northeast": "/d/goathill/canyon3",
        "southup": "/d/goathill/canyon1"
      }
    },
    "/d/goathill/canyon3": {
      "type": "ROOM",
      "short": "峡谷",
      "exits": {
        "east": "/d/goathill/cavern1",
        "southwest": "/d/goathill/canyon2"
      }
    },
    "/d/goathill/cavern1": {
      "type": "ROOM",
      "short": "岩洞",
      "objects": {
        "/d/goathill/npc/worm": 2
      },
      "exits": {
        "southeast": "/d/goathill/cavern4",
        "northeast": "/d/goathill/cavern2",
        "west": "/d/goathill/canyon3"
      }
    },
    "/d/goathill/cavern1.c": {
      "type": "ROOM",
      "short": "空房间"
    },
    "/d/goathill/cavern2": {
      "type": "ROOM",
      "short": "岩洞",
      "exits": {
        "east": "/d/goathill/cavern3",
        "southwest": "/d/goathill/cavern1"
      },
      "objects": {
        "/d/goathill/npc/fat_worm": 1,
        "/d/goathill/npc/worm": 3
      }
    },
    "/d/goathill/cavern3": {
      "type": "ROOM",
      "short": "岩穴",
      "exits": {
        "west": "/d/goathill/cavern2"
      },
      "objects": {
        "/d/goathill/npc/big_worm": 2,
        "/d/goathill/npc/huge_worm": 2
      }
    },
    "/d/goathill/cavern4": {
      "type": "ROOM",
      "short": "岩洞",
      "exits": {
        "northwest": "/d/goathill/cavern1"
      },
      "objects": {
        "/d/goathill/npc/worm": 2,
        "/d/goathill/npc/big_worm": 1
      }
    },
    "/d/goathill/mroad1": {
      "type": "ROOM",
      "short": "山路",
      "exits": {
        "north": "/d/goathill/mroad2",
        "south": "/d/snow/crossroad"
      }
    },
    "/d/goathill/mroad2": {
      "type": "ROOM",
      "short": "山路",
      "exits": {
        "northeast": "/d/goathill/mroad3",
        "south": "/d/goathill/mroad1"
      }
    },
    "/d/goathill/mroad3": {
      "type": "ROOM",
      "short": "山路",
      "exits": {
        "northup": "/d/goathill/mroad4",
        "east": "/d/goathill/temple1",
        "southwest": "/d/goathill/mroad2"
      }
    },
    "/d/goathill/mroad4": {
      "type": "ROOM",
      "short": "山路转角",
      "exits": {
        "east": "/d/goathill/mroad5",
        "southdown": "/d/goathill/mroad3"
      },
      "objects": {
        "/d/goathill/npc/bandit": 3,
        "/d/goathill/npc/bandit_leader": 1
      }
    },
    "/d/goathill/mroad5": {
      "type": "ROOM",
      "short": "山路",
      "exits": {
        "northeast": "/d/goathill/mroad6",
        "east": "/d/goathill/slope1",
        "west": "/d/goathill/mroad4"
      }
    },
    "/d/goathill/mroad6": {
      "type": "ROOM",
      "short": "山路",
      "exits": {
        "north": "/d/goathill/canyon1",
        "southwest": "/d/goathill/mroad5",
        "south": "/d/goathill/slope1"
      }
    },
    "/d/goathill/slope1": {
      "type": "ROOM",
      "short": "岩石坡",
      "exits": {
        "north": "/d/goathill/mroad6",
        "west": "/d/goathill/mroad5"
      }
    },
    "/d/goathill/temple1": {
      "type": "ROOM",
      "short": "小土地庙",
      "exits": {
        "west": "/d/goathill/mroad3"
      },
      "objects": {
        "/d/goathill/npc/bandit_hwang": 1
      }
    },
    "/d/graveyard/grave1": {
      "type": "ROOM",
      "short": "乱葬岗",
      "exits": {
        "southeast": "/d/graveyard/road1"
      }
    },
    "/d/graveyard/road1": {
      "type": "ROOM",
      "short": "黄土小径",
      "exits": {
        "northwest": "/d/graveyard/grave1"
      }
    },
    "/d/green/cave0": {
      "type": "ROOM",
      "short": "洞口",
      "exits": {
        "south": "/d/green/path0",
        "north": "/d/green/cave1"
      },
      "objects": {
        "/d/green/npc/kid4": 2
      }
    },
    "/d/green/cave1": {
      "type": "ROOM",
      "short": "黑暗山洞",
      "exits": {
        "south": "/d/green/cave0",
        "north": "/d/green/cave2"
      }
    },
    "/d/green/cave2": {
      "type": "ROOM",
      "short": "黑暗山洞",
      "exits": {
        "south": "/d/green/cave1",
        "north": "/d/green/mpath0"
      }
    },
    "/d/green/cavehall": {
      "type": "ROOM",
      "short": "石室大厅",
      "exits": {
        "south": "/d/green/outdoor"
      },
      "objects": {
        "CLASS_D(juechen)+/master": 1
      }
    },
    "/d/green/eight0": {
      "type": "ROOM",
      "short": "迷阵",
      "exits": {
        "south": "/d/green/entrance",
        "north": "/d/green/closed",
        "west": "/d/green/eight0",
        "east": "/d/green/eight1"
      }
    },
    "/d/green/eight1": {
      "type": "ROOM",
      "short": "迷阵",
      "exits": {
        "south": "/d/green/eight1",
        "north": "/d/green/eight2",
        "west": "/d/green/closed",
        "east": "/d/green/eight0"
      }
    },
    "/d/green/eight2": {
      "type": "ROOM",
      "short": "迷阵",
      "exits": {
        "south": "/d/green/eight2",
        "north": "/d/green/eight1",
        "west": "/d/green/eight3",
        "east": "/d/green/closed"
      }
    },
    "/d/green/eight3": {
      "type": "ROOM",
      "short": "迷阵",
      "exits": {
        "south": "/d/green/eight3",
        "north": "/d/green/closed",
        "west": "/d/green/eight2",
        "east": "/d/green/eight4"
      }
    },
    "/d/green/eight4": {
      "type": "ROOM",
      "short": "迷阵",
      "exits": {
        "south": "/d/green/closed",
        "north": "/d/green/eight5",
        "west": "/d/green/eight4",
        "east": "/d/green/eight3"
      }
    },
    "/d/green/eight5": {
      "type": "ROOM",
      "short": "迷阵",
      "exits": {
        "south": "/d/green/eight5",
        "north": "/d/green/eight4",
        "west": "/d/green/eight6",
        "east": "/d/green/closed"
      }
    },
    "/d/green/eight6": {
      "type": "ROOM",
      "short": "迷阵",
      "exits": {
        "south": "/d/green/eight5",
        "north": "/d/green/eight7",
        "west": "/d/green/closed",
        "east": "/d/green/eight6"
      }
    },
    "/d/green/eight7": {
      "type": "ROOM",
      "short": "迷阵",
      "exits": {
        "south": "/d/green/stoneroom",
        "north": "/d/green/eight7",
        "west": "/d/green/eight6",
        "east": "/d/green/closed"
      }
    },
    "/d/green/entrance": {
      "type": "ROOM",
      "short": "山路尽头",
      "exits": {
        "north": "/d/green/outdoor",
        "east": "/d/green/eight0",
        "south": "/d/green/mpath2"
      }
    },
    "/d/green/field0": {
      "type": "ROOM",
      "short": "小广场",
      "exits": {
        "west": "/d/green/path8",
        "south": "/d/green/house4",
        "north": "/d/green/house2",
        "east": "/d/green/field1"
      }
    },
    "/d/green/field1": {
      "type": "ROOM",
      "short": "采石场的空地",
      "exits": {
        "west": "/d/green/field0",
        "south": "/d/green/station1",
        "north": "/d/green/house3"
      },
      "objects": {
        "/d/green/npc/kid1": 1
      }
    },
    "/d/green/house0": {
      "type": "ROOM",
      "short": "民宅",
      "exits": {
        "east": "/d/green/path3"
      },
      "objects": {
        "/d/green/npc/woman1": 1,
        "/d/green/npc/woman2": 1
      }
    },
    "/d/green/house1": {
      "type": "ROOM",
      "short": "工匠的家",
      "exits": {
        "south": "/d/green/path8"
      },
      "objects": {
        "/d/green/npc/worker1": 1
      }
    },
    "/d/green/house2": {
      "type": "ROOM",
      "short": "民宅",
      "exits": {
        "south": "/d/green/field0"
      },
      "objects": {
        "/d/green/npc/oldman": 1,
        "/d/green/npc/oldwoman": 1
      }
    },
    "/d/green/house3": {
      "type": "ROOM",
      "short": "民宅",
      "exits": {
        "south": "/d/green/field1"
      }
    },
    "/d/green/house4": {
      "type": "ROOM",
      "short": "村长的家",
      "exits": {
        "north": "/d/green/field0"
      },
      "objects": {
        "/d/green/npc/oldman2": 1
      }
    },
    "/d/green/mpath0": {
      "type": "ROOM",
      "short": "山路",
      "exits": {
        "south": "/d/green/cave2",
        "north": "/d/green/mpath1"
      }
    },
    "/d/green/mpath1": {
      "type": "ROOM",
      "short": "山路",
      "exits": {
        "south": "/d/green/mpath0",
        "north": "/d/green/mpath2"
      }
    },
    "/d/green/mpath2": {
      "type": "ROOM",
      "short": "山路",
      "exits": {
        "south": "/d/green/mpath1",
        "north": "/d/green/entrance"
      }
    },
    "/d/green/outdoor": {
      "type": "ROOM",
      "short": "石室",
      "exits": {
        "enter": "/d/green/cavehall",
        "south": "/d/green/entrance"
      }
    },
    "/d/green/path0": {
      "type": "ROOM",
      "short": "小路的尽头",
      "exits": {
        "north": "/d/green/cave0",
        "south": "/d/green/path1"
      }
    },
    "/d/green/path1": {
      "type": "ROOM",
      "short": "小路",
      "exits": {
        "north": "/d/green/path0",
        "south": "/d/green/path2"
      }
    },
    "/d/green/path2": {
      "type": "ROOM",
      "short": "三叉路口",
      "exits": {
        "south": "/d/green/path3",
        "north": "/d/green/path1",
        "west": "/d/green/temple0"
      },
      "objects": {
        "/d/green/npc/kid2": 2
      }
    },
    "/d/green/path3": {
      "type": "ROOM",
      "short": "三叉路口",
      "exits": {
        "north": "/d/green/path2",
        "south": "/d/green/path4",
        "west": "/d/green/house0",
        "east": "/d/green/path8"
      }
    },
    "/d/green/path4": {
      "type": "ROOM",
      "short": "小路",
      "exits": {
        "south": "/d/green/path5",
        "north": "/d/green/path3",
        "east": "/d/green/shop0"
      }
    },
    "/d/green/path5": {
      "type": "ROOM",
      "short": "石板路",
      "exits": {
        "west": "/d/green/path6",
        "north": "/d/green/path4",
        "east": "/d/green/station0"
      }
    },
    "/d/green/path6": {
      "type": "ROOM",
      "short": "石板路",
      "exits": {
        "west": "/d/snow/crossroad",
        "east": "/d/green/path5"
      }
    },
    "/d/green/path8": {
      "type": "ROOM",
      "short": "小巷子",
      "exits": {
        "west": "/d/green/path3",
        "north": "/d/green/house1",
        "east": "/d/green/field0"
      },
      "objects": {
        "/d/green/npc/kid3": 2
      }
    },
    "/d/green/shop0": {
      "type": "ROOM",
      "short": "沈记商行",
      "exits": {
        "west": "/d/green/path4"
      },
      "objects": {
        "/d/green/npc/shen": 1,
        "/d/green/npc/woman1": 1
      }
    },
    "/d/green/station0": {
      "type": "ROOM",
      "short": "工作站",
      "exits": {
        "northeast": "/d/green/station1",
        "west": "/d/green/path5"
      },
      "objects": {
        "/d/green/npc/worker2": 3
      }
    },
    "/d/green/station1": {
      "type": "ROOM",
      "short": "工作站",
      "exits": {
        "north": "/d/green/field1",
        "southwest": "/d/green/station0"
      },
      "objects": {
        "/d/green/npc/worker2": 2
      }
    },
    "/d/green/stoneroom": {
      "type": "ROOM",
      "short": "石室",
      "exits": {
        "west": "/d/green/cavehall",
        "south": "/d/green/water"
      }
    },
    "/d/green/temple0": {
      "type": "ROOM",
      "short": "土地庙",
      "exits": {
        "east": "/d/green/path2"
      }
    },
    "/d/green/water": {
      "type": "ROOM",
      "short": "溪水边",
      "exits": {
        "west": "/d/green/outdoor",
        "north": "/d/green/stoneroom"
      }
    },
    "/d/latemoon/bamboo": {
      "type": "ROOM",
      "short": "竹林",
      "exits": {
        "east": "/d/latemoon/bamboo1",
        "west": "/d/latemoon/bamboo2",
        "north": "/d/latemoon/bamboo3",
        "south": "/d/latemoon/bamboo4"
      }
    },
    "/d/latemoon/bamboo1": {
      "type": "ROOM",
      "short": "竹林",
      "exits": {
        "east": "/d/latemoon/bamboo",
        "west": "/d/latemoon/bamboo1",
        "north": "/d/latemoon/bamboo2",
        "south": "/d/latemoon/bamboo4"
      }
    },
    "/d/latemoon/bamboo2": {
      "type": "ROOM",
      "short": "竹林",
      "exits": {
        "east": "/d/latemoon/bamboo4",
        "west": "/d/latemoon/bamboo3",
        "north": "/d/latemoon/bamboo3",
        "south": "/d/latemoon/bamboo1"
      }
    },
    "/d/latemoon/bamboo3": {
      "type": "ROOM",
      "short": "竹林",
      "exits": {
        "north": "/d/latemoon/sroad5",
        "east": "/d/latemoon/bamboo",
        "west": "/d/latemoon/bamboo2",
        "south": "/d/latemoon/bamboo"
      }
    },
    "/d/latemoon/bamboo4": {
      "type": "ROOM",
      "short": "竹林",
      "exits": {
        "west": "/d/latemoon/bamboo3",
        "east": "/d/latemoon/bamboo",
        "north": "/d/latemoon/bamboo1",
        "south": "/d/latemoon/bamboo2"
      },
      "objects": {
        "/d/latemoon/obj/bamboo": 1
      }
    },
    "/d/latemoon/entrance": {
      "type": "ROOM",
      "short": "碎石小径",
      "exits": {
        "west": "/d/latemoon/gate",
        "east": "/u/cloud/wroad0"
      },
      "objects": {
        "/u/cloud/npc/lm_guard": 2
      }
    },
    "/d/latemoon/front_yard": {
      "type": "ROOM",
      "short": "晚月庄前庭",
      "exits": {
        "east": "/d/latemoon/gate",
        "west": "/d/latemoon/latemoon1",
        "south": "/d/latemoon/park/yard1"
      }
    },
    "/d/latemoon/gate": {
      "type": "ROOM",
      "short": "晚月庄大门",
      "exits": {
        "east": "/d/latemoon/entrance",
        "west": "/d/latemoon/front_yard"
      }
    },
    "/d/latemoon/latebook": {
      "type": "ROOM",
      "short": "后院书房",
      "exits": {
        "east": "/d/latemoon/latemoon7"
      },
      "objects": {
        "/d/latemoon/npc/girl": 1
      }
    },
    "/d/latemoon/latemoon1": {
      "type": "ROOM",
      "short": "晚月庄大厅",
      "exits": {
        "east": "/d/latemoon/front_yard",
        "north": "/d/latemoon/latemoon3",
        "west": "/d/latemoon/latemoonc"
      },
      "objects": {
        "/d/latemoon/npc/servant": 2,
        "CLASS_D(dancer)+/master": 1
      }
    },
    "/d/latemoon/latemoon2": {
      "type": "ROOM",
      "short": "内厅",
      "exits": {
        "west": "/d/latemoon/latemoon4"
      },
      "objects": {
        "/d/latemoon/npc/zauron": 1
      }
    },
    "/d/latemoon/latemoon3": {
      "type": "ROOM",
      "short": "傍厅",
      "exits": {
        "south": "/d/latemoon/latemoon1"
      },
      "objects": {
        "/d/latemoon/npc/yumay": 1
      }
    },
    "/d/latemoon/latemoon4": {
      "type": "ROOM",
      "short": "内厅穿堂",
      "exits": {
        "north": "/d/latemoon/latemoonc",
        "south": "/d/latemoon/room/twoc",
        "east": "/d/latemoon/latemoon2"
      }
    },
    "/d/latemoon/latemoon5": {
      "type": "ROOM",
      "short": "后院走道",
      "exits": {
        "west": "/d/latemoon/latemoon6",
        "south": "/d/latemoon/latemoonc"
      }
    },
    "/d/latemoon/latemoon6": {
      "type": "ROOM",
      "short": "禁闭房",
      "exits": {
        "east": "/d/latemoon/latemoon5"
      },
      "objects": {
        "/d/latemoon/npc/funlin": 1
      }
    },
    "/d/latemoon/latemoon7": {
      "type": "ROOM",
      "short": "后院走道",
      "exits": {
        "south": "/d/latemoon/latemoon8",
        "east": "/d/latemoon/latemoonc",
        "west": "/d/latemoon/latebook"
      }
    },
    "/d/latemoon/latemoon8": {
      "type": "ROOM",
      "short": "密室",
      "exits": {
        "north": "/d/latemoon/latemoon7"
      }
    },
    "/d/latemoon/latemoonc": {
      "type": "ROOM",
      "short": "大厅后院",
      "exits": {
        "north": "/d/latemoon/latemoon5",
        "west": "/d/latemoon/latemoon7",
        "east": "/d/latemoon/latemoon1",
        "south": "/d/latemoon/latemoon4"
      }
    },
    "/d/latemoon/miroom": {
      "type": "ROOM",
      "short": "set(,HIY \"密室\" NOR);",
      "exits": {
        "north": "/d/latemoon/miroom2"
      },
      "objects": {
        "/d/latemoon/obj/hankie": 1
      }
    },
    "/d/latemoon/miroom2": {
      "type": "ROOM",
      "short": "内厅",
      "exits": {
        "south": "/d/latemoon/miroom"
      },
      "objects": {
        "/d/latemoon/npc/shaowei": 1
      }
    },
    "/d/latemoon/park/bridge1": {
      "type": "ROOM",
      "short": "沁芳桥",
      "exits": {
        "north": "/d/latemoon/park/moonc",
        "south": "/d/latemoon/park/pavilion1"
      }
    },
    "/d/latemoon/park/bridge2": {
      "type": "ROOM",
      "short": "翠嫣桥",
      "exits": {
        "north": "/d/latemoon/park/pavilion1",
        "southeast": "/d/latemoon/park/paroad1",
        "west": "/d/latemoon/park/paroad2"
      }
    },
    "/d/latemoon/park/bridge3": {
      "type": "ROOM",
      "short": "朱栏板桥",
      "exits": {
        "south": "/d/latemoon/park/moon4",
        "northwest": "/d/latemoon/park/moon1"
      }
    },
    "/d/latemoon/park/flower2": {
      "type": "ROOM",
      "short": "月洞门",
      "exits": {
        "north": "/d/latemoon/park/yard1",
        "south": "/d/latemoon/park/moonc"
      }
    },
    "/d/latemoon/park/moon1": {
      "type": "ROOM",
      "short": "长廊曲洞",
      "exits": {
        "west": "/d/latemoon/park/moonc",
        "southeast": "/d/latemoon/park/bridge3"
      }
    },
    "/d/latemoon/park/moon2": {
      "type": "ROOM",
      "short": "湘园小径",
      "exits": {
        "south": "/d/latemoon/park/moon5",
        "east": "/d/latemoon/park/moonc"
      }
    },
    "/d/latemoon/park/moon3": {
      "type": "ROOM",
      "short": "甬路",
      "exits": {
        "southeast": "/d/latemoon/park/paroad2",
        "north": "/d/latemoon/park/moon5",
        "west": "/d/latemoon/park/moroom"
      }
    },
    "/d/latemoon/park/moon4": {
      "type": "ROOM",
      "short": "暖香榭",
      "exits": {
        "southwest": "/d/latemoon/park/paroad1",
        "north": "/d/latemoon/park/bridge3"
      },
      "objects": {
        "/d/latemoon/park/npc/bird": 2,
        "/d/latemoon/park/npc/maysan": 1
      }
    },
    "/d/latemoon/park/moon5": {
      "type": "ROOM",
      "short": "桂花园",
      "exits": {
        "south": "/d/latemoon/park/moon3",
        "north": "/d/latemoon/park/moon2"
      },
      "objects": {
        "/d/latemoon/park/npc/flwgirl": 4
      }
    },
    "/d/latemoon/park/moonc": {
      "type": "ROOM",
      "short": "翠嶂",
      "exits": {
        "north": "/d/latemoon/park/flower2",
        "south": "/d/latemoon/park/bridge1",
        "west": "/d/latemoon/park/moon2",
        "east": "/d/latemoon/park/moon1"
      },
      "objects": {}
    },
    "/d/latemoon/park/moondoor": {
      "type": "ROOM",
      "short": "晚月庄后门",
      "exits": {
        "north": "/d/latemoon/park/paroad1",
        "south": "/d/latemoon/sroad1"
      }
    },
    "/d/latemoon/park/moroom": {
      "type": "ROOM",
      "short": "紫翎小轩",
      "exits": {
        "east": "/d/latemoon/park/moon3"
      },
      "objects": {
        "/d/latemoon/park/npc/girl_yu": 1,
        "/d/latemoon/park/npc/dodo1": 1
      }
    },
    "/d/latemoon/park/paroad1": {
      "type": "ROOM",
      "short": "甬路",
      "exits": {
        "northwest": "/d/latemoon/park/bridge2",
        "northeast": "/d/latemoon/park/moon4",
        "south": "/d/latemoon/park/moondoor"
      }
    },
    "/d/latemoon/park/paroad2": {
      "type": "ROOM",
      "short": "□香榭",
      "exits": {
        "east": "/d/latemoon/park/bridge2",
        "northwest": "/d/latemoon/park/moon3"
      },
      "objects": {
        "/d/latemoon/park/npc/rabbit": 2
      }
    },
    "/d/latemoon/park/pavilion1": {
      "type": "ROOM",
      "short": "沁芳亭",
      "exits": {
        "north": "/d/latemoon/park/bridge1",
        "south": "/d/latemoon/park/bridge2"
      },
      "objects": {
        "/d/latemoon/park/npc/shiren": 1
      }
    },
    "/d/latemoon/park/yard1": {
      "type": "ROOM",
      "short": "前院",
      "exits": {
        "north": "/d/latemoon/front_yard",
        "south": "/d/latemoon/park/flower2"
      }
    },
    "/d/latemoon/room/bathroom": {
      "type": "ROOM",
      "short": "小花池",
      "objects": {
        "/d/latemoon/room/npc/fireangel": 1,
        "/d/latemoon/room/npc/eton": 1
      },
      "exits": {
        "west": "/d/latemoon/room/bathroom1"
      }
    },
    "/d/latemoon/room/bathroom1": {
      "type": "ROOM",
      "short": "沐浴更衣室",
      "objects": {
        "/d/latemoon/room/npc/shinyu": 1
      },
      "exits": {
        "west": "/d/latemoon/room/flower1",
        "east": "/d/latemoon/room/bathroom"
      }
    },
    "/d/latemoon/room/corridor7": {
      "type": "ROOM",
      "short": "内厅",
      "exits": {
        "south": "/d/latemoon/room/flower1",
        "east": "/d/latemoon/room/eroad1",
        "west": "/d/latemoon/room/wroad2"
      },
      "objects": {
        "/d/latemoon/room/npc/yuchoun": 1
      }
    },
    "/d/latemoon/room/eastroom": {
      "type": "ROOM",
      "short": "东厢房",
      "exits": {
        "west": "/d/latemoon/room/eroad1"
      },
      "objects": {
        "/d/latemoon/room/npc/servant": 1,
        "/d/latemoon/room/npc/elon": 1
      }
    },
    "/d/latemoon/room/eat1": {
      "type": "ROOM",
      "short": "大饭厅",
      "exits": {
        "east": "/d/latemoon/room/eat2",
        "west": "/d/latemoon/room/twoc"
      },
      "objects": {
        "/d/latemoon/obj/food2": 1,
        "/d/latemoon/obj/food3": 2
      }
    },
    "/d/latemoon/room/eat2": {
      "type": "ROOM",
      "short": "膳房",
      "exits": {
        "east": "/d/latemoon/room/kitchen",
        "west": "/d/latemoon/room/eat1"
      },
      "objects": {
        "/d/latemoon/obj/wine": 1,
        "/d/latemoon/obj/food": 1
      }
    },
    "/d/latemoon/room/eroad1": {
      "type": "ROOM",
      "short": "东厢房走道",
      "exits": {
        "east": "/d/latemoon/room/eastroom",
        "west": "/d/latemoon/room/corridor7",
        "north": "/d/latemoon/room/eroad2"
      }
    },
    "/d/latemoon/room/eroad2": {
      "type": "ROOM",
      "short": "东厢房走道",
      "exits": {
        "north": "/d/latemoon/room/lroad1",
        "south": "/d/latemoon/room/eroad1"
      }
    },
    "/d/latemoon/room/flower1": {
      "type": "ROOM",
      "short": "内厅穿堂",
      "exits": {
        "north": "/d/latemoon/room/corridor7",
        "east": "/d/latemoon/room/bathroom1",
        "south": "/d/latemoon/miroom2"
      },
      "objects": {
        "/d/latemoon/room/npc/shaoin": 1
      }
    },
    "/d/latemoon/room/guest1": {
      "type": "ROOM",
      "short": "客房",
      "exits": {
        "north": "/d/latemoon/room/two1"
      },
      "objects": {
        "/d/latemoon/room/npc/guest": 1
      }
    },
    "/d/latemoon/room/guest2": {
      "type": "ROOM",
      "short": "上等厢房",
      "exits": {
        "north": "/d/latemoon/room/two2"
      },
      "objects": {
        "/d/latemoon/room/npc/tguest": 1
      }
    },
    "/d/latemoon/room/kitchen": {
      "type": "ROOM",
      "short": "厨房",
      "exits": {
        "west": "/d/latemoon/room/eat2"
      },
      "objects": {
        "/d/latemoon/room/npc/obj/fire": 1,
        "/d/latemoon/room/npc/fochin": 1
      }
    },
    "/d/latemoon/room/lcenter": {
      "type": "ROOM",
      "short": "后厅",
      "exits": {
        "east": "/d/latemoon/room/lroad1",
        "north": "/d/latemoon/room/twoc",
        "west": "/d/latemoon/room/lroad3",
        "south": "/d/latemoon/room/lstudio"
      },
      "objects": {
        "/d/latemoon/room/npc/spring2": 1,
        "/d/latemoon/room/npc/yushou": 1
      }
    },
    "/d/latemoon/room/lroad1": {
      "type": "ROOM",
      "short": "后厅走道",
      "exits": {
        "south": "/d/latemoon/room/eroad2",
        "west": "/d/latemoon/room/lcenter"
      }
    },
    "/d/latemoon/room/lroad3": {
      "type": "ROOM",
      "short": "后厅走道",
      "exits": {
        "east": "/d/latemoon/room/lcenter",
        "west": "/d/latemoon/room/room4",
        "south": "/d/latemoon/room/wroad1",
        "northup": "/d/latemoon/upstar/upstar1"
      }
    },
    "/d/latemoon/room/lstudio": {
      "type": "ROOM",
      "short": "内书房",
      "exits": {
        "north": "/d/latemoon/room/lcenter"
      },
      "objects": {
        "/d/latemoon/room/npc/old": 1,
        "/d/latemoon/room/npc/killer": 1
      }
    },
    "/d/latemoon/room/room4": {
      "type": "ROOM",
      "short": "内书房",
      "exits": {
        "east": "/d/latemoon/room/lroad3"
      },
      "objects": {
        "/d/latemoon/npc/servant2": 1,
        "/d/latemoon/room/npc/spring1": 1
      }
    },
    "/d/latemoon/room/two1": {
      "type": "ROOM",
      "short": "夹道",
      "exits": {
        "south": "/d/latemoon/room/guest1",
        "east": "/d/latemoon/room/twoc",
        "west": "/d/latemoon/room/two2"
      }
    },
    "/d/latemoon/room/two2": {
      "type": "ROOM",
      "short": "夹道",
      "exits": {
        "south": "/d/latemoon/room/guest2",
        "east": "/d/latemoon/room/two1"
      }
    },
    "/d/latemoon/room/twoc": {
      "type": "ROOM",
      "short": "仪门",
      "exits": {
        "north": "/d/latemoon/latemoon4",
        "south": "/d/latemoon/room/lcenter",
        "east": "/d/latemoon/room/eat1",
        "west": "/d/latemoon/room/two1"
      }
    },
    "/d/latemoon/room/westroom": {
      "type": "ROOM",
      "short": "西厢房",
      "exits": {
        "east": "/d/latemoon/room/wroad2"
      },
      "objects": {
        "/d/latemoon/room/npc/servant": 1,
        "/d/latemoon/room/npc/annihi": 1
      }
    },
    "/d/latemoon/room/wroad1": {
      "type": "ROOM",
      "short": "西厢房走道",
      "exits": {
        "north": "/d/latemoon/room/lroad3",
        "south": "/d/latemoon/room/wroad2"
      }
    },
    "/d/latemoon/room/wroad2": {
      "type": "ROOM",
      "short": "西厢房走道",
      "exits": {
        "north": "/d/latemoon/room/wroad1",
        "east": "/d/latemoon/room/corridor7",
        "west": "/d/latemoon/room/westroom",
        "southup": "/d/latemoon/upstar/upstar2"
      }
    },
    "/d/latemoon/sroad1": {
      "type": "ROOM",
      "short": "山路",
      "exits": {
        "north": "/d/latemoon/park/moondoor",
        "southeast": "/d/latemoon/sroad2"
      }
    },
    "/d/latemoon/sroad2": {
      "type": "ROOM",
      "short": "蜿蜒小径",
      "exits": {
        "northwest": "/d/latemoon/sroad1",
        "east": "/d/latemoon/sroad3"
      }
    },
    "/d/latemoon/sroad3": {
      "type": "ROOM",
      "short": "小径",
      "exits": {
        "northwest": "/d/latemoon/sroad2",
        "east": "/d/latemoon/sroad4"
      }
    },
    "/d/latemoon/sroad4": {
      "type": "ROOM",
      "short": "蜿蜒小径",
      "exits": {
        "west": "/d/latemoon/sroad3",
        "south": "/d/latemoon/sroad5"
      },
      "objects": {
        "/d/latemoon/npc/butterfly": 1
      }
    },
    "/d/latemoon/sroad5": {
      "type": "ROOM",
      "short": "小径",
      "exits": {
        "north": "/d/latemoon/sroad4",
        "south": "/d/latemoon/bamboo3",
        "east": "/d/sanyen/tunnel"
      },
      "objects": {
        "/d/latemoon/npc/butterfly": 1
      }
    },
    "/d/latemoon/upstar/upcenter": {
      "type": "ROOM",
      "short": "佛堂门前",
      "exits": {
        "west": "/d/latemoon/upstar/uproom",
        "north": "/d/latemoon/upstar/upstar1",
        "south": "/d/latemoon/upstar/upstar2"
      }
    },
    "/d/latemoon/upstar/uplook": {
      "type": "ROOM",
      "short": "观景台",
      "exits": {
        "west": "/d/latemoon/upstar/upstarc",
        "jump": "/d/latemoon/park/yard1"
      },
      "objects": {
        "/d/latemoon/upstar/npc/bird": 2
      }
    },
    "/d/latemoon/upstar/uproom": {
      "type": "ROOM",
      "short": "佛堂",
      "exits": {
        "east": "/d/latemoon/upstar/upcenter"
      },
      "objects": {
        "/d/latemoon/upstar/npc/statue": 1
      }
    },
    "/d/latemoon/upstar/uproom2": {
      "type": "ROOM",
      "short": "翠湘阁",
      "exits": {
        "south": "/d/latemoon/upstar/upstar4"
      },
      "objects": {
        "/d/latemoon/upstar/npc/shinfun": 1
      }
    },
    "/d/latemoon/upstar/uproom3": {
      "type": "ROOM",
      "short": "缀芳阁",
      "exits": {
        "north": "/d/latemoon/upstar/upstar3"
      },
      "objects": {
        "/d/latemoon/upstar/npc/huei": 1,
        "/d/latemoon/obj/cake": 1
      }
    },
    "/d/latemoon/upstar/upstar1": {
      "type": "ROOM",
      "short": "二楼走廊",
      "exits": {
        "east": "/d/latemoon/upstar/upstar4",
        "south": "/d/latemoon/upstar/upcenter",
        "northdown": "/d/latemoon/room/lroad3"
      }
    },
    "/d/latemoon/upstar/upstar2": {
      "type": "ROOM",
      "short": "二楼走廊",
      "exits": {
        "east": "/d/latemoon/upstar/upstar3",
        "north": "/d/latemoon/upstar/upcenter",
        "southdown": "/d/latemoon/room/wroad2"
      }
    },
    "/d/latemoon/upstar/upstar3": {
      "type": "ROOM",
      "short": "二楼走廊",
      "exits": {
        "west": "/d/latemoon/upstar/upstar2",
        "north": "/d/latemoon/upstar/upstarc",
        "south": "/d/latemoon/upstar/uproom3"
      }
    },
    "/d/latemoon/upstar/upstar4": {
      "type": "ROOM",
      "short": "二楼走廊",
      "exits": {
        "west": "/d/latemoon/upstar/upstar1",
        "south": "/d/latemoon/upstar/upstarc",
        "north": "/d/latemoon/upstar/uproom2"
      }
    },
    "/d/latemoon/upstar/upstarc": {
      "type": "ROOM",
      "short": "前堂楼",
      "exits": {
        "east": "/d/latemoon/upstar/uplook",
        "north": "/d/latemoon/upstar/upstar4",
        "south": "/d/latemoon/upstar/upstar3"
      }
    },
    "/d/oldpine/cave1": {
      "type": "ROOM",
      "short": "山洞",
      "exits": {
        "south": "/d/oldpine/cave+(random(4)+1)",
        "north": "/d/oldpine/cave2",
        "west": "/d/oldpine/cave+(random(3)+1)",
        "east": "/d/oldpine/cave+(random(4)+1)"
      }
    },
    "/d/oldpine/cave2": {
      "type": "ROOM",
      "short": "山洞",
      "exits": {
        "south": "/d/oldpine/cave+(random(4)+1)",
        "north": "/d/oldpine/cave+(random(4)+1)",
        "west": "/d/oldpine/cave+(random(3)+1)",
        "east": "/d/oldpine/cave4"
      }
    },
    "/d/oldpine/cave3": {
      "type": "ROOM",
      "short": "山洞",
      "exits": {
        "south": "/d/oldpine/cave+(random(4)+1)",
        "north": "/d/oldpine/cave+(random(4)+1)",
        "west": "/d/oldpine/cave+(random(4)+1)",
        "east": "/d/oldpine/cave+(random(4)+1)"
      }
    },
    "/d/oldpine/cave4": {
      "type": "ROOM",
      "short": "山洞",
      "exits": {
        "south": "/d/oldpine/cave+(random(4)+1)",
        "north": "/d/oldpine/cave+(random(4)+1)",
        "west": "/d/oldpine/cave5",
        "east": "/d/oldpine/cave+(random(4)+1)"
      }
    },
    "/d/oldpine/cave5": {
      "type": "ROOM",
      "short": "山洞",
      "exits": {
        "eastdown": "/d/oldpine/waterfall"
      },
      "objects": {
        "/d/oldpine/npc/skeleton": 1
      }
    },
    "/d/oldpine/clearing": {
      "type": "ROOM",
      "short": "林间空地",
      "exits": {
        "west": "/d/oldpine/npath3",
        "north": "/d/oldpine/spath1",
        "east": "/d/oldpine/epath1"
      }
    },
    "/d/oldpine/cliff1": {
      "type": "ROOM",
      "short": "山壁上的窄穴"
    },
    "/d/oldpine/cliff2": {
      "type": "ROOM",
      "short": "山壁上的窄穴"
    },
    "/d/oldpine/cliffdown": {
      "type": "ROOM",
      "short": "林间....不....悬崖边",
      "exits": {
        "south": "/d/oldpine/pine+(random(6)+1)",
        "north": "/d/oldpine/pine+(random(6)+1)",
        "east": "/d/oldpine/pine+(random(6)+1)",
        "west": "/d/oldpine/pine+(random(6)+1)",
        "northeast": "/d/oldpine/pine7"
      }
    },
    "/d/oldpine/cliffside": {
      "type": "ROOM",
      "short": "林间....不....悬崖边",
      "exits": {
        "north": "/d/oldpine/pine1"
      }
    },
    "/d/oldpine/epath1": {
      "type": "ROOM",
      "short": "林间小路",
      "exits": {
        "west": "/d/oldpine/clearing",
        "east": "/d/oldpine/epath2"
      }
    },
    "/d/oldpine/epath2": {
      "type": "ROOM",
      "short": "小石桥",
      "exits": {
        "west": "/d/oldpine/epath1",
        "east": "/d/oldpine/epath3"
      }
    },
    "/d/oldpine/epath3": {
      "type": "ROOM",
      "short": "林间小路",
      "exits": {
        "west": "/d/oldpine/epath2"
      },
      "objects": {
        "/d/oldpine/npc/maniac": 1
      }
    },
    "/d/oldpine/keep1": {
      "type": "ROOM",
      "short": "老松寨秘密入口",
      "exits": {
        "west": "/d/oldpine/pine2",
        "east": "/d/oldpine/keep2"
      },
      "objects": {
        "/d/oldpine/npc/bandit_guard": 4
      }
    },
    "/d/oldpine/keep2": {
      "type": "ROOM",
      "short": "老松寨",
      "exits": {
        "west": "/d/oldpine/keep1",
        "east": "/d/oldpine/keep3"
      },
      "objects": {
        "/d/oldpine/npc/bandit_guard": 2,
        "/d/oldpine/npc/bandit_leader": 1
      }
    },
    "/d/oldpine/keep3": {
      "type": "ROOM",
      "short": "老松寨",
      "exits": {
        "west": "/d/oldpine/keep2"
      },
      "objects": {
        "/d/oldpine/npc/bandit_leader": 3,
        "/d/oldpine/npc/bandit_commander": 1
      }
    },
    "/d/oldpine/lake": {
      "type": "ROOM",
      "short": "水潭",
      "exits": {
        "north": "/d/oldpine/riverbank1"
      },
      "objects": {
        "/d/oldpine/npc/serpent": 5
      }
    },
    "/d/oldpine/npath1": {
      "type": "ROOM",
      "short": "林间小路",
      "exits": {
        "south": "/d/oldpine/npath2",
        "north": "/d/snow/eroad3"
      }
    },
    "/d/oldpine/npath2": {
      "type": "ROOM",
      "short": "林间小路",
      "exits": {
        "southeast": "/d/oldpine/npath3",
        "north": "/d/oldpine/npath1"
      }
    },
    "/d/oldpine/npath3": {
      "type": "ROOM",
      "short": "林间小路",
      "exits": {
        "east": "/d/oldpine/clearing",
        "northwest": "/d/oldpine/npath2"
      }
    },
    "/d/oldpine/passage": {
      "type": "ROOM",
      "short": "秘密通道入口",
      "exits": {
        "north": "/d/oldpine/secrectpath1",
        "south": "/d/oldpine/waterfall"
      }
    },
    "/d/oldpine/path3": {
      "type": "ROOM",
      "short": "秘密通道",
      "exits": {
        "south": "/d/oldpine/secrectpath1"
      }
    },
    "/d/oldpine/pine1": {
      "type": "ROOM",
      "short": "松树林",
      "objects": {
        "/d/oldpine/npc/tall_bandit": 1,
        "/d/oldpine/npc/fat_bandit": 1
      },
      "exits": {
        "south": "/d/oldpine/pine+(random(5)+2)",
        "north": "/d/oldpine/pine+(random(5)+2)",
        "west": "/d/oldpine/pine4",
        "east": "/d/oldpine/pine+(random(5)+2)"
      }
    },
    "/d/oldpine/pine2": {
      "type": "ROOM",
      "short": "松树林",
      "exits": {
        "south": "/d/oldpine/pine+(random(5)+2)",
        "north": "/d/oldpine/pine+(random(5)+2)",
        "west": "/d/oldpine/pine+(random(5)+2)",
        "east": "/d/oldpine/keep1"
      }
    },
    "/d/oldpine/pine3": {
      "type": "ROOM",
      "short": "松树林",
      "exits": {
        "south": "/d/oldpine/pine+(random(5)+2)",
        "north": "/d/oldpine/pine+(random(5)+2)",
        "west": "/d/oldpine/pine+(random(5)+2)",
        "east": "/d/oldpine/pine+(random(5)+2)"
      }
    },
    "/d/oldpine/pine4": {
      "type": "ROOM",
      "short": "松树林",
      "exits": {
        "south": "/d/oldpine/pine+(random(5)+2)",
        "north": "/d/oldpine/pine5",
        "west": "/d/oldpine/pine+(random(5)+2)",
        "east": "/d/oldpine/pine+(random(5)+2)"
      }
    },
    "/d/oldpine/pine5": {
      "type": "ROOM",
      "short": "松树林",
      "exits": {
        "south": "/d/oldpine/pine+(random(5)+2)",
        "north": "/d/oldpine/pine6",
        "west": "/d/oldpine/pine+(random(5)+2)",
        "east": "/d/oldpine/pine+(random(5)+2)"
      }
    },
    "/d/oldpine/pine6": {
      "type": "ROOM",
      "short": "松树林",
      "exits": {
        "south": "/d/oldpine/pine+(random(5)+2)",
        "north": "/d/oldpine/pine+(random(5)+2)",
        "west": "/d/oldpine/pine7",
        "east": "/d/oldpine/pine+(random(5)+2)"
      }
    },
    "/d/oldpine/pine7": {
      "type": "ROOM",
      "short": "松树林",
      "objects": {
        "/d/oldpine/npc/wolf_dog": 1
      },
      "exits": {
        "south": "/d/oldpine/pine+(random(5)+2)",
        "north": "/d/oldpine/pine+(random(5)+2)",
        "west": "/d/oldpine/pine+(random(5)+2)",
        "east": "/d/oldpine/pine+(random(5)+2)",
        "southwest": "/d/oldpine/cliffdown"
      }
    },
    "/d/oldpine/riverbank1": {
      "type": "ROOM",
      "short": "山涧之中",
      "exits": {
        "north": "/d/oldpine/riverbank2",
        "south": "/d/oldpine/lake"
      }
    },
    "/d/oldpine/riverbank2": {
      "type": "ROOM",
      "short": "山涧之中",
      "exits": {
        "north": "/d/oldpine/waterfall",
        "south": "/d/oldpine/riverbank1"
      }
    },
    "/d/oldpine/secrectpath1": {
      "type": "ROOM",
      "short": "秘密通道",
      "exits": {
        "north": "/d/oldpine/path3",
        "south": "/d/oldpine/passage"
      }
    },
    "/d/oldpine/spath1": {
      "type": "ROOM",
      "short": "林间小路",
      "objects": {
        "/d/oldpine/npc/bandit": 3
      },
      "exits": {
        "south": "/d/oldpine/clearing",
        "north": "/d/oldpine/spath2"
      }
    },
    "/d/oldpine/spath2": {
      "type": "ROOM",
      "short": "下坡道",
      "exits": {
        "south": "/d/oldpine/spath1",
        "north": "/d/oldpine/spath3"
      }
    },
    "/d/oldpine/spath3": {
      "type": "ROOM",
      "short": "下坡道",
      "exits": {
        "north": "/d/oldpine/spath4",
        "south": "/d/oldpine/spath2"
      }
    },
    "/d/oldpine/spath4": {
      "type": "ROOM",
      "short": "下坡道",
      "exits": {
        "south": "/d/oldpine/spath3"
      }
    },
    "/d/oldpine/stone": {
      "type": "ROOM",
      "short": "大青石上",
      "objects": {
        "/d/oldpine/npc/venomsnake": 1
      }
    },
    "/d/oldpine/tree1": {
      "type": "ROOM",
      "short": "大松树上",
      "objects": {
        "/d/oldpine/npc/spy": 1
      },
      "exits": {
        "up": "/d/oldpine/tree2",
        "down": "/d/oldpine/clearing"
      }
    },
    "/d/oldpine/tree2": {
      "type": "ROOM",
      "short": "大松树上",
      "exits": {
        "up": "/d/oldpine/tree3",
        "down": "/d/oldpine/tree1"
      },
      "objects": {
        "/d/oldpine/npc/butterfly": 6
      }
    },
    "/d/oldpine/tree3": {
      "type": "ROOM",
      "short": "大松树顶",
      "exits": {
        "down": "/d/oldpine/tree2"
      }
    },
    "/d/oldpine/waterfall": {
      "type": "ROOM",
      "short": "瀑布前",
      "exits": {
        "south": "/d/oldpine/riverbank2"
      }
    },
    "/d/sanyen/back_temple": {
      "type": "ROOM",
      "short": "后殿",
      "exits": {
        "south": "/d/sanyen/corridor",
        "east": "/d/sanyen/tower"
      },
      "objects": {
        "/d/sanyen/npc/little_bonze": 1
      }
    },
    "/d/sanyen/corridor": {
      "type": "ROOM",
      "short": "走廊",
      "exits": {
        "west": "/d/sanyen/corridor1",
        "north": "/d/sanyen/back_temple",
        "south": "/d/sanyen/temple"
      }
    },
    "/d/sanyen/corridor1": {
      "type": "ROOM",
      "short": "走廊",
      "exits": {
        "west": "/d/sanyen/kitchen",
        "east": "/d/sanyen/corridor"
      }
    },
    "/d/sanyen/door": {
      "type": "ROOM",
      "short": "山烟寺寺门",
      "exits": {
        "north": "/d/sanyen/road1",
        "south": "/d/sanyen/front_yard"
      }
    },
    "/d/sanyen/drug_field": {
      "type": "ROOM",
      "short": "药圃",
      "exits": {
        "south": "/d/sanyen/road2"
      }
    },
    "/d/sanyen/front_yard": {
      "type": "ROOM",
      "short": "山烟寺前广场",
      "exits": {
        "north": "/d/sanyen/door",
        "south": "/d/sanyen/gate"
      },
      "objects": {
        "/d/sanyen/npc/monk_guard": 2
      }
    },
    "/d/sanyen/gate": {
      "type": "ROOM",
      "short": "山烟寺山门",
      "exits": {
        "south": "/d/sanyen/sroad2",
        "north": "/d/sanyen/front_yard",
        "west": "/d/sanyen/tunnele"
      },
      "objects": {
        "/d/sanyen/npc/greeting": 2
      }
    },
    "/d/sanyen/heal_room": {
      "type": "ROOM",
      "short": "流云轩",
      "exits": {
        "south": "/d/sanyen/inner_yard"
      },
      "objects": {
        "/d/sanyen/npc/drug_bonze": 1
      }
    },
    "/d/sanyen/inner_yard": {
      "type": "ROOM",
      "short": "庭园",
      "exits": {
        "north": "/d/sanyen/heal_room",
        "east": "/d/sanyen/temple"
      },
      "objects": {
        "/d/sanyen/npc/cripple": 1
      }
    },
    "/d/sanyen/kitchen": {
      "type": "ROOM",
      "short": "香积厨",
      "exits": {
        "east": "/d/sanyen/corridor1"
      },
      "objects": {
        "/d/sanyen/npc/cook_bonze": 1
      }
    },
    "/d/sanyen/road1": {
      "type": "ROOM",
      "short": "石板大道",
      "exits": {
        "north": "/d/sanyen/temple",
        "south": "/d/sanyen/door",
        "east": "/d/sanyen/road2"
      },
      "objects": {
        "/d/sanyen/npc/monk": 1
      }
    },
    "/d/sanyen/road2": {
      "type": "ROOM",
      "short": "石板小径",
      "exits": {
        "west": "/d/sanyen/road1",
        "north": "/d/sanyen/drug_field"
      },
      "objects": {
        "/d/sanyen/npc/bonze": 1
      }
    },
    "/d/sanyen/sroad1": {
      "type": "ROOM",
      "short": "山路",
      "exits": {
        "west": "/d/sanyen/sroad2",
        "northeast": "/u/cloud/sunhill/road4"
      }
    },
    "/d/sanyen/sroad2": {
      "type": "ROOM",
      "short": "山路",
      "exits": {
        "east": "/d/sanyen/sroad1",
        "north": "/d/sanyen/gate"
      }
    },
    "/d/sanyen/temple": {
      "type": "ROOM",
      "short": "大雄宝殿",
      "exits": {
        "south": "/d/sanyen/road1",
        "west": "/d/sanyen/inner_yard",
        "north": "/d/sanyen/corridor"
      },
      "objects": {
        "CLASS_D(bonze)+/master": 1
      }
    },
    "/d/sanyen/tower": {
      "type": "ROOM",
      "short": "塔林",
      "exits": {
        "west": "/d/sanyen/back_temple"
      },
      "objects": {
        "/d/sanyen/npc/work_bonze": 1
      }
    },
    "/d/sanyen/tunnel": {
      "type": "ROOM",
      "short": "隧道",
      "exits": {
        "west": "/d/latemoon/sroad5",
        "east": "/d/sanyen/tunnele"
      }
    },
    "/d/sanyen/tunnele": {
      "type": "ROOM",
      "short": "隧道口",
      "exits": {
        "west": "/d/sanyen/tunnel",
        "east": "/d/sanyen/gate"
      }
    },
    "/d/snow/bank": {
      "type": "BANK",
      "short": "安记钱庄",
      "exits": {
        "east": "/d/snow/mstreet1"
      },
      "objects": {
        "/d/snow/npc/annihir": 1
      }
    },
    "/d/snow/crossroad": {
      "type": "ROOM",
      "short": "山坳",
      "exits": {
        "north": "/d/goathill/mroad1",
        "east": "/d/green/path6",
        "south": "/d/snow/mstreet4"
      }
    },
    "/d/snow/e_room": {
      "type": "ROOM",
      "short": "客房",
      "exits": {
        "west": "/d/snow/inn_2f"
      }
    },
    "/d/snow/eroad1": {
      "type": "ROOM",
      "short": "黄土小径",
      "exits": {
        "east": "/d/snow/eroad2",
        "north": "/d/snow/temple",
        "west": "/d/snow/sroad1"
      }
    },
    "/d/snow/eroad2": {
      "type": "ROOM",
      "short": "黄土小径",
      "exits": {
        "east": "/d/snow/eroad3",
        "west": "/d/snow/eroad1"
      },
      "objects": {
        "/d/snow/npc/dog": 2
      }
    },
    "/d/snow/eroad3": {
      "type": "ROOM",
      "short": "山路",
      "exits": {
        "south": "/d/oldpine/npath1",
        "east": "/d/temple/sroad",
        "west": "/d/snow/eroad2"
      }
    },
    "/d/snow/guestroom": {
      "type": "ROOM",
      "short": "客房",
      "exits": {
        "north": "/d/snow/inneryard"
      }
    },
    "/d/snow/herbshop": {
      "type": "ROOM",
      "short": "桑邻药铺",
      "exits": {
        "east": "/d/snow/mstreet3"
      },
      "objects": {
        "/d/snow/npc/herbalist": 1,
        "/d/snow/npc/woodcutter": 1
      }
    },
    "/d/snow/herbshop1": {
      "type": "ROOM",
      "short": "药铺密室"
    },
    "/d/snow/hockshop": {
      "type": "HOCKSHOP",
      "short": "丰登当铺",
      "exits": {
        "west": "/d/snow/mstreet3",
        "east": "/d/snow/hockshop2"
      }
    },
    "/d/snow/hockshop2": {
      "type": "ROOM",
      "short": "储藏室",
      "exits": {
        "west": "/d/snow/hockshop"
      }
    },
    "/d/snow/inn": {
      "type": "ROOM",
      "short": "饮风客栈",
      "exits": {
        "east": "/d/snow/square",
        "up": "/d/snow/inn_2f",
        "northwest": "/d/wiz/entrance"
      },
      "objects": {
        "/d/snow/npc/traveller": 2,
        "/d/snow/npc/waiter": 1
      }
    },
    "/d/snow/inn_2f": {
      "type": "ROOM",
      "short": "饮风客栈二楼",
      "exits": {
        "west": "/d/snow/w_room",
        "north": "/d/snow/n_room",
        "down": "/d/snow/inn",
        "east": "/d/snow/e_room"
      },
      "objects": {
        "/d/snow/npc/rat": 6
      }
    },
    "/d/snow/innerhall": {
      "type": "ROOM",
      "short": "武馆内院",
      "exits": {
        "west": "/d/snow/inneryard"
      }
    },
    "/d/snow/inneryard": {
      "type": "ROOM",
      "short": "天井",
      "exits": {
        "south": "/d/snow/guestroom",
        "north": "/d/snow/nyard",
        "west": "/d/snow/schoolhall",
        "east": "/d/snow/innerhall"
      }
    },
    "/d/snow/mstreet1": {
      "type": "ROOM",
      "short": "雪亭镇街道",
      "exits": {
        "west": "/d/snow/bank",
        "south": "/d/snow/square",
        "north": "/d/snow/mstreet2",
        "east": "/d/snow/school1"
      }
    },
    "/d/snow/mstreet2": {
      "type": "ROOM",
      "short": "雪亭镇街道",
      "exits": {
        "north": "/d/snow/mstreet3",
        "south": "/d/snow/mstreet1",
        "west": "/d/snow/smithy",
        "east": "/d/snow/workplace"
      },
      "objects": {
        "/d/snow/npc/drunk": 1,
        "/d/snow/npc/scavenger": 1
      }
    },
    "/d/snow/mstreet3": {
      "type": "ROOM",
      "short": "雪亭镇街道",
      "exits": {
        "south": "/d/snow/mstreet2",
        "north": "/d/snow/mstreet4",
        "east": "/d/snow/hockshop",
        "west": "/d/snow/herbshop"
      }
    },
    "/d/snow/mstreet4": {
      "type": "ROOM",
      "short": "雪亭镇街道",
      "exits": {
        "north": "/d/snow/crossroad",
        "south": "/d/snow/mstreet3",
        "west": "/d/snow/postoffice"
      }
    },
    "/d/snow/n_room": {
      "type": "ROOM",
      "short": "客房",
      "exits": {
        "south": "/d/snow/inn_2f"
      }
    },
    "/d/snow/nyard": {
      "type": "ROOM",
      "short": "书房",
      "exits": {
        "south": "/d/snow/inneryard"
      },
      "objects": {
        "/d/snow/npc/girl": 1
      }
    },
    "/d/snow/postoffice": {
      "type": "ROOM",
      "short": "雪亭驿",
      "exits": {
        "east": "/d/snow/mstreet4"
      },
      "objects": {
        "/d/snow/npc/post_officer": 1
      }
    },
    "/d/snow/school": {
      "type": "ROOM",
      "short": "书院",
      "exits": {
        "north": "/d/snow/sroad2"
      },
      "objects": {
        "/d/snow/npc/teacher": 1
      }
    },
    "/d/snow/school1": {
      "type": "ROOM",
      "short": "淳风武馆大门",
      "exits": {
        "west": "/d/snow/mstreet1",
        "east": "/d/snow/school2"
      },
      "objects": {
        "/d/snow/npc/guard": 1
      }
    },
    "/d/snow/school2": {
      "type": "ROOM",
      "short": "淳风武馆教练场",
      "exits": {
        "north": "/d/snow/weapon_storage",
        "west": "/d/snow/school1",
        "east": "/d/snow/schoolhall"
      },
      "objects": {
        "/d/snow/npc/trainee": 6,
        "/d/snow/npc/fist_trainer": 1
      }
    },
    "/d/snow/schoolhall": {
      "type": "ROOM",
      "short": "淳风武馆大厅",
      "exits": {
        "west": "/d/snow/school2",
        "east": "/d/snow/inneryard"
      },
      "objects": {
        "CLASS_D(swordsman)+/master": 1
      }
    },
    "/d/snow/secret_storage": {
      "type": "ROOM",
      "short": "地下密室",
      "objects": {
        "/d/snow/obj/shield": 1
      }
    },
    "/d/snow/smithy": {
      "type": "ROOM",
      "short": "打铁铺子",
      "exits": {
        "east": "/d/snow/mstreet2"
      },
      "objects": {
        "/d/snow/npc/smith": 1
      }
    },
    "/d/snow/square": {
      "type": "ROOM",
      "short": "广场",
      "exits": {
        "north": "/d/snow/mstreet1",
        "west": "/d/snow/inn",
        "south": "/d/snow/sroad1",
        "east": "/d/snow/temple"
      },
      "objects": {
        "/d/snow/npc/trav_blade": 3
      }
    },
    "/d/snow/sroad1": {
      "type": "ROOM",
      "short": "雪亭镇街道",
      "exits": {
        "west": "/d/snow/sroad2",
        "north": "/d/snow/square",
        "south": "/u/cloud/dragonhill/nroad",
        "east": "/d/snow/eroad1"
      }
    },
    "/d/snow/sroad2": {
      "type": "ROOM",
      "short": "雪亭镇街道",
      "exits": {
        "west": "/d/snow/sroad3",
        "south": "/d/snow/school",
        "east": "/d/snow/sroad1"
      },
      "objects": {
        "/d/snow/npc/farmer": 2
      }
    },
    "/d/snow/sroad3": {
      "type": "ROOM",
      "short": "青石官道",
      "exits": {
        "west": "/d/snow/sroad4",
        "east": "/d/snow/sroad2"
      }
    },
    "/d/snow/sroad4": {
      "type": "ROOM",
      "short": "青石官道",
      "exits": {
        "north": "/d/snow/sroad5",
        "east": "/d/snow/sroad3",
        "southwest": "/d/canyon/road"
      },
      "objects": {
        "/d/snow/npc/crazy_dog": 1
      }
    },
    "/d/snow/sroad5": {
      "type": "ROOM",
      "short": "青石官道",
      "exits": {
        "west": "/d/waterfog/sroad1",
        "south": "/d/snow/sroad4"
      }
    },
    "/d/snow/temple": {
      "type": "ROOM",
      "short": "城隍庙",
      "exits": {
        "south": "/d/snow/eroad1",
        "west": "/d/snow/square"
      },
      "objects": {
        "/obj/paper_seal": 2,
        "/d/snow/npc/keeper": 1,
        "/d/snow/obj/denotation": 1
      }
    },
    "/d/snow/w_room": {
      "type": "ROOM",
      "short": "客房",
      "exits": {
        "east": "/d/snow/inn_2f"
      }
    },
    "/d/snow/weapon_storage": {
      "type": "ROOM",
      "short": "兵器储藏室",
      "exits": {
        "south": "/d/snow/school2"
      },
      "objects": {
        "/d/snow/npc/obj/bamboo_sword": 1
      }
    },
    "/d/snow/workplace": {
      "type": "ROOM",
      "short": "谷物加工厂",
      "exits": {
        "west": "/d/snow/mstreet2"
      }
    },
    "/d/temple/book_room1": {
      "type": "ROOM",
      "short": "经楼",
      "exits": {
        "up": "/d/temple/book_room2",
        "out": "/d/temple/road2"
      }
    },
    "/d/temple/book_room2": {
      "type": "ROOM",
      "short": "经楼",
      "exits": {
        "down": "/d/temple/book_room1"
      }
    },
    "/d/temple/broom1": {
      "type": "ROOM",
      "short": "经楼",
      "exits": {
        "up": "/d/temple/broom2",
        "out": "/d/temple/road2"
      }
    },
    "/d/temple/broom2": {
      "type": "ROOM",
      "short": "书库",
      "exits": {
        "down": "/d/temple/broom1"
      }
    },
    "/d/temple/corridor1": {
      "type": "ROOM",
      "short": "回廊",
      "exits": {
        "west": "/d/temple/temple1",
        "north": "/d/temple/corridor7"
      }
    },
    "/d/temple/corridor2": {
      "type": "ROOM",
      "short": "回廊",
      "exits": {
        "north": "/d/temple/corridor6",
        "east": "/d/temple/temple1"
      }
    },
    "/d/temple/corridor3": {
      "type": "ROOM",
      "short": "回廊",
      "exits": {
        "north": "/d/temple/road1",
        "south": "/d/temple/corridor7",
        "west": "/d/temple/corridor5",
        "east": "/d/temple/restroom2"
      }
    },
    "/d/temple/corridor4": {
      "type": "ROOM",
      "short": "回廊",
      "exits": {
        "north": "/d/temple/trainroom",
        "south": "/d/temple/corridor6",
        "east": "/d/temple/corridor5"
      }
    },
    "/d/temple/corridor5": {
      "type": "ROOM",
      "short": "回廊",
      "exits": {
        "west": "/d/temple/corridor4",
        "east": "/d/temple/corridor3",
        "south": "/d/temple/inneryard",
        "north": "/d/temple/temple2"
      }
    },
    "/d/temple/corridor6": {
      "type": "ROOM",
      "short": "回廊",
      "exits": {
        "south": "/d/temple/corridor2",
        "north": "/d/temple/corridor4",
        "east": "/d/temple/inneryard"
      }
    },
    "/d/temple/corridor7": {
      "type": "ROOM",
      "short": "回廊",
      "exits": {
        "north": "/d/temple/corridor3",
        "south": "/d/temple/corridor1",
        "west": "/d/temple/inneryard",
        "east": "/d/temple/restroom1"
      }
    },
    "/d/temple/entrance": {
      "type": "ROOM",
      "short": "灵心观前",
      "exits": {
        "north": "/d/temple/square",
        "south": "/d/temple/ladder1"
      }
    },
    "/d/temple/inneryard": {
      "type": "ROOM",
      "short": "天井",
      "exits": {
        "north": "/d/temple/corridor5",
        "west": "/d/temple/corridor6",
        "east": "/d/temple/corridor7"
      },
      "objects": {
        "/d/temple/npc/little_taoist2": 1
      }
    },
    "/d/temple/ladder1": {
      "type": "ROOM",
      "short": "石英岩石阶",
      "objects": {
        "/d/temple/npc/little_taoist1": 1
      },
      "exits": {
        "north": "/d/temple/entrance",
        "west": "/d/temple/ladder2"
      }
    },
    "/d/temple/ladder2": {
      "type": "ROOM",
      "short": "石英岩石阶",
      "objects": {
        "/d/temple/npc/guest": 1
      },
      "exits": {
        "east": "/d/temple/ladder1",
        "southdown": "/d/temple/ladder3"
      }
    },
    "/d/temple/ladder3": {
      "type": "ROOM",
      "short": "石英岩石阶",
      "exits": {
        "northup": "/d/temple/ladder2",
        "westdown": "/d/temple/ladder4"
      }
    },
    "/d/temple/ladder4": {
      "type": "ROOM",
      "short": "石英岩石阶",
      "exits": {
        "eastup": "/d/temple/ladder3",
        "southdown": "/d/temple/ladder5"
      }
    },
    "/d/temple/ladder5": {
      "type": "ROOM",
      "short": "石英岩石阶",
      "exits": {
        "northup": "/d/temple/ladder4",
        "westdown": "/d/temple/sroad"
      }
    },
    "/d/temple/restroom1": {
      "type": "ROOM",
      "short": "厢房",
      "exits": {
        "west": "/d/temple/corridor7"
      },
      "objects": {
        "/d/temple/npc/old_taoist": 1
      }
    },
    "/d/temple/restroom2": {
      "type": "ROOM",
      "short": "厢房",
      "exits": {
        "west": "/d/temple/corridor3"
      }
    },
    "/d/temple/road1": {
      "type": "ROOM",
      "short": "青石小径",
      "exits": {
        "south": "/d/temple/corridor3",
        "northwest": "/d/temple/road2"
      }
    },
    "/d/temple/road2": {
      "type": "ROOM",
      "short": "青石小径",
      "exits": {
        "southeast": "/d/temple/road1",
        "enter": "/d/temple/book_room1"
      },
      "objects": {
        "/d/temple/npc/guard_taoist+(random(3)+1)": 1,
        "/d/temple/npc/taoist_guard+(random(3)+1)": 1
      }
    },
    "/d/temple/square": {
      "type": "ROOM",
      "short": "灵心观广场",
      "exits": {
        "north": "/d/temple/temple1",
        "south": "/d/temple/entrance"
      }
    },
    "/d/temple/sroad": {
      "type": "ROOM",
      "short": "青石官道",
      "exits": {
        "eastup": "/d/temple/ladder5",
        "west": "/d/snow/eroad3"
      }
    },
    "/d/temple/temple1": {
      "type": "ROOM",
      "short": "灵心观大殿",
      "exits": {
        "west": "/d/temple/corridor2",
        "south": "/d/temple/square",
        "east": "/d/temple/corridor1"
      },
      "objects": {
        "CLASS_D(taoist)+/taolord": 1,
        "/d/temple/npc/trainer": 1,
        "/d/temple/npc/tfighter": 1
      }
    },
    "/d/temple/temple2": {
      "type": "ROOM",
      "short": "后殿",
      "exits": {
        "south": "/d/temple/corridor5"
      }
    },
    "/d/temple/trainroom": {
      "type": "ROOM",
      "short": "练功\\房",
      "exits": {
        "south": "/d/temple/corridor4"
      },
      "objects": {
        "/d/temple/npc/taoist": 1,
        "/d/temple/npc/taoist2": 1
      }
    },
    "/d/village/farmhouse1": {
      "type": "ROOM",
      "short": "农舍",
      "exits": {
        "north": "/d/village/fmhousback",
        "south": "/d/village/road4"
      }
    },
    "/d/village/field": {
      "type": "ROOM",
      "short": "稻田",
      "exits": {
        "east": "/d/village/road9"
      }
    },
    "/d/village/fmhousback": {
      "type": "ROOM",
      "short": "农舍后院",
      "exits": {
        "south": "/d/village/farmhouse1"
      },
      "objects": {
        "/d/village/npc/woman1": 1
      }
    },
    "/d/village/home": {
      "type": "ROOM",
      "short": "刘家小房",
      "exits": {
        "northwest": "/d/village/smallstorage",
        "south": "/d/village/littlegarden"
      },
      "objects": {
        "/d/village/npc/oldliu": 1
      }
    },
    "/d/village/lake": {
      "type": "ROOM",
      "short": "玉螺湖",
      "exits": {
        "east": "/d/village/lakeside"
      }
    },
    "/d/village/lakebottom1": {
      "type": "ROOM",
      "short": "水下岩洞",
      "exits": {
        "westup": "/d/village/lakebottom2"
      }
    },
    "/d/village/lakebottom2": {
      "type": "ROOM",
      "short": "水下岩洞",
      "exits": {
        "westup": "/d/village/valley1",
        "eastdown": "/d/village/lakebottom1"
      },
      "objects": {
        "/d/village/npc/dragon": 6
      }
    },
    "/d/village/lakeside": {
      "type": "ROOM",
      "short": "玉螺湖畔",
      "exits": {
        "west": "/d/village/lake",
        "east": "/d/village/road7"
      },
      "objects": {
        "/d/village/npc/fisher": 3
      }
    },
    "/d/village/littlegarden": {
      "type": "ROOM",
      "short": "花园",
      "exits": {
        "south": "/d/village/road5",
        "north": "/d/village/home"
      },
      "objects": {
        "/d/village/npc/flowergirl": 5
      }
    },
    "/d/village/lordhouse1": {
      "type": "ROOM",
      "short": "财主家前院",
      "exits": {
        "south": "/d/village/lordhouse3",
        "west": "/d/village/road9",
        "east": "/d/village/lordhouse2"
      }
    },
    "/d/village/lordhouse2": {
      "type": "ROOM",
      "short": "财主家东房",
      "exits": {
        "west": "/d/village/lordhouse1"
      }
    },
    "/d/village/lordhouse3": {
      "type": "ROOM",
      "short": "财主家南房",
      "exits": {
        "north": "/d/village/lordhouse1"
      }
    },
    "/d/village/melonfarm": {
      "type": "ROOM",
      "short": "瓜地",
      "exits": {
        "south": "/d/village/melonguard",
        "northup": "/d/village/road4"
      }
    },
    "/d/village/melonguard": {
      "type": "ROOM",
      "short": "瓜棚",
      "exits": {
        "north": "/d/village/melonfarm",
        "northwest": "/d/village/road7"
      },
      "objects": {
        "/d/village/npc/meloner": 3
      }
    },
    "/d/village/road1": {
      "type": "ROOM",
      "short": "黄土大道",
      "exits": {
        "south": "/d/village/road2",
        "north": "/d/canyon/canyon7"
      }
    },
    "/d/village/road2": {
      "type": "ROOM",
      "short": "三叉路口",
      "exits": {
        "south": "/d/city/nroad2",
        "north": "/d/village/road1",
        "west": "/d/village/road3"
      },
      "objects": {
        "/d/village/npc/trader1": 2
      }
    },
    "/d/village/road3": {
      "type": "ROOM",
      "short": "青石小路",
      "exits": {
        "west": "/d/village/road4",
        "east": "/d/village/road2"
      }
    },
    "/d/village/road4": {
      "type": "ROOM",
      "short": "青石小路",
      "exits": {
        "north": "/d/village/farmhouse1",
        "west": "/d/village/road5",
        "southdown": "/d/village/melonfarm",
        "east": "/d/village/road3"
      }
    },
    "/d/village/road5": {
      "type": "ROOM",
      "short": "青石小路",
      "exits": {
        "west": "/d/village/road6",
        "north": "/d/village/littlegarden",
        "southdown": "/d/village/road7",
        "east": "/d/village/road4"
      }
    },
    "/d/village/road6": {
      "type": "ROOM",
      "short": "青石小路",
      "exits": {
        "east": "/d/village/road5"
      }
    },
    "/d/village/road7": {
      "type": "ROOM",
      "short": "青石小路",
      "exits": {
        "southeast": "/d/village/melonguard",
        "south": "/d/village/road8",
        "west": "/d/village/lakeside",
        "northup": "/d/village/road5"
      }
    },
    "/d/village/road8": {
      "type": "ROOM",
      "short": "青石小路",
      "exits": {
        "south": "/d/village/road9",
        "north": "/d/village/road7"
      }
    },
    "/d/village/road9": {
      "type": "ROOM",
      "short": "青石小路",
      "exits": {
        "north": "/d/village/road8",
        "west": "/d/village/field",
        "east": "/d/village/lordhouse1"
      }
    },
    "/d/village/smallstorage": {
      "type": "ROOM",
      "short": "厨房",
      "exits": {
        "southeast": "/d/village/home"
      },
      "objects": {
        "/d/village/npc/rat": 6
      }
    },
    "/d/village/valley1": {
      "type": "ROOM",
      "short": "忘情谷外",
      "exits": {
        "north": "/d/village/valley2",
        "eastdown": "/d/village/lakebottom2"
      }
    },
    "/d/village/valley2": {
      "type": "ROOM",
      "short": "忘情谷外",
      "exits": {
        "south": "/d/village/valley1",
        "east": "/d/village/road6"
      }
    },
    "/d/waterfog/clifftop": {
      "type": "ROOM",
      "short": "水烟阁半山亭",
      "exits": {
        "westup": "/d/waterfog/stair5",
        "southdown": "/d/waterfog/stair4"
      },
      "objects": {
        "/d/waterfog/npc/watcher": 1,
        "/d/waterfog/npc/celes_tiger": 1
      }
    },
    "/d/waterfog/east_2f": {
      "type": "ROOM",
      "short": "东侧厅",
      "exits": {
        "west": "/d/waterfog/forehall",
        "down": "/d/waterfog/eaststair"
      },
      "objects": {
        "/d/waterfog/npc/elite_guard": 2
      }
    },
    "/d/waterfog/easthall": {
      "type": "ROOM",
      "short": "水烟阁东侧花厅",
      "exits": {
        "north": "/d/waterfog/eaststair",
        "west": "/d/waterfog/entrance"
      }
    },
    "/d/waterfog/eaststair": {
      "type": "ROOM",
      "short": "东侧厅",
      "exits": {
        "up": "/d/waterfog/east_2f",
        "south": "/d/waterfog/easthall",
        "north": "/d/waterfog/kitchen"
      }
    },
    "/d/waterfog/entrance": {
      "type": "ROOM",
      "short": "水烟阁正门",
      "exits": {
        "south": "/d/waterfog/frontyard",
        "west": "/d/waterfog/westhall",
        "east": "/d/waterfog/easthall",
        "north": "/d/waterfog/guildhall"
      },
      "objects": {
        "/d/waterfog/npc/guard": 2
      }
    },
    "/d/waterfog/forehall": {
      "type": "ROOM",
      "short": "聆啸厅",
      "exits": {
        "west": "/d/waterfog/west_2f",
        "east": "/d/waterfog/east_2f"
      },
      "objects": {
        "/d/waterfog/npc/elder5": 1,
        "/d/waterfog/npc/elder6": 1,
        "/d/waterfog/npc/elder7": 1
      }
    },
    "/d/waterfog/frontyard": {
      "type": "ROOM",
      "short": "水烟阁前",
      "exits": {
        "west": "/d/waterfog/wpath1",
        "north": "/d/waterfog/entrance",
        "southdown": "/d/waterfog/stair5"
      }
    },
    "/d/waterfog/guildhall": {
      "type": "CLASS_GUILD",
      "short": "水烟阁正厅",
      "exits": {
        "south": "/d/waterfog/entrance"
      },
      "objects": {
        "CLASS_D(fighter)+champion": 1,
        "CLASS_D(fighter)+master": 1,
        "CLASS_D(fighter)+executioner": 1
      }
    },
    "/d/waterfog/kitchen": {
      "type": "ROOM",
      "short": "厨房",
      "exits": {
        "south": "/d/waterfog/eaststair"
      }
    },
    "/d/waterfog/servroom": {
      "type": "ROOM",
      "short": "仆役卧室",
      "exits": {
        "west": "/d/waterfog/storage"
      }
    },
    "/d/waterfog/sroad1": {
      "type": "ROOM",
      "short": "青石官道",
      "exits": {
        "east": "/d/snow/sroad5",
        "northwest": "/d/waterfog/sroad2"
      }
    },
    "/d/waterfog/sroad2": {
      "type": "ROOM",
      "short": "青石官道",
      "exits": {
        "southeast": "/d/waterfog/sroad1",
        "west": "/d/waterfog/sroad3"
      }
    },
    "/d/waterfog/sroad3": {
      "type": "ROOM",
      "short": "青石官道",
      "exits": {
        "northup": "/d/waterfog/stair1",
        "east": "/d/waterfog/sroad2"
      },
      "objects": {
        "/d/waterfog/npc/guard": 2
      }
    },
    "/d/waterfog/stair1": {
      "type": "ROOM",
      "short": "白石阶梯",
      "exits": {
        "northup": "/d/waterfog/stair2",
        "southdown": "/d/waterfog/sroad3"
      }
    },
    "/d/waterfog/stair2": {
      "type": "ROOM",
      "short": "白石阶梯",
      "exits": {
        "southdown": "/d/waterfog/stair1",
        "eastup": "/d/waterfog/stair3"
      }
    },
    "/d/waterfog/stair3": {
      "type": "ROOM",
      "short": "白石阶梯",
      "exits": {
        "northup": "/d/waterfog/stair4",
        "westdown": "/d/waterfog/stair2"
      }
    },
    "/d/waterfog/stair4": {
      "type": "ROOM",
      "short": "白石阶梯",
      "exits": {
        "northup": "/d/waterfog/clifftop",
        "southdown": "/d/waterfog/stair3"
      }
    },
    "/d/waterfog/stair5": {
      "type": "ROOM",
      "short": "白石阶梯",
      "exits": {
        "northup": "/d/waterfog/frontyard",
        "eastdown": "/d/waterfog/clifftop"
      }
    },
    "/d/waterfog/storage": {
      "type": "ROOM",
      "short": "柴房",
      "exits": {
        "south": "/d/waterfog/weststair",
        "east": "/d/waterfog/servroom"
      },
      "objects": {
        "/d/waterfog/npc/servant": 2
      }
    },
    "/d/waterfog/swordtomb": {
      "type": "ROOM",
      "short": "葬剑亭",
      "exits": {
        "east": "/d/waterfog/wpath5"
      }
    },
    "/d/waterfog/west_2f": {
      "type": "ROOM",
      "short": "西侧厅",
      "exits": {
        "down": "/d/waterfog/weststair",
        "east": "/d/waterfog/forehall"
      },
      "objects": {
        "/d/waterfog/npc/elite_guard": 2
      }
    },
    "/d/waterfog/westhall": {
      "type": "ROOM",
      "short": "水烟阁西侧花厅",
      "exits": {
        "north": "/d/waterfog/weststair",
        "east": "/d/waterfog/entrance"
      }
    },
    "/d/waterfog/weststair": {
      "type": "ROOM",
      "short": "西侧厅",
      "exits": {
        "up": "/d/waterfog/west_2f",
        "north": "/d/waterfog/storage",
        "south": "/d/waterfog/westhall"
      }
    },
    "/d/waterfog/wpath1": {
      "type": "ROOM",
      "short": "山坡小径",
      "exits": {
        "west": "/d/waterfog/wpath2",
        "east": "/d/waterfog/frontyard"
      }
    },
    "/d/waterfog/wpath2": {
      "type": "ROOM",
      "short": "山坡小径",
      "exits": {
        "north": "/d/waterfog/wpath3",
        "east": "/d/waterfog/wpath1"
      }
    },
    "/d/waterfog/wpath3": {
      "type": "ROOM",
      "short": "白石阶梯",
      "exits": {
        "north": "/d/waterfog/wpath4",
        "south": "/d/waterfog/wpath2"
      }
    },
    "/d/waterfog/wpath4": {
      "type": "ROOM",
      "short": "白石阶梯",
      "exits": {
        "south": "/d/waterfog/wpath3",
        "north": "/d/waterfog/wpath5"
      }
    },
    "/d/waterfog/wpath5": {
      "type": "ROOM",
      "short": "白石阶梯",
      "exits": {
        "south": "/d/waterfog/wpath4",
        "west": "/d/waterfog/swordtomb"
      }
    },
    "/d/wiz/courthouse": {
      "type": "ROOM",
      "short": "法院",
      "objects": {
        "/d/wiz/npc/judge": 1
      }
    },
    "/d/wiz/entrance": {
      "type": "ROOM",
      "short": "巫师会客室",
      "exits": {
        "west": "/d/wiz/hall1",
        "southeast": "/d/snow/inn"
      },
      "objects": {
        "/d/wiz/npc/chpn": 1
      }
    },
    "/d/wiz/hall1": {
      "type": "ROOM",
      "short": "巫师交谊厅",
      "exits": {
        "north": "/d/wiz/jobroom",
        "east": "/d/wiz/entrance"
      }
    },
    "/d/wiz/jobroom": {
      "type": "ROOM",
      "short": "工作进度简报室",
      "exits": {
        "south": "/d/wiz/hall1"
      }
    },
    "/u/cloud/biaoju": {
      "type": "ROOM",
      "short": "镖局",
      "exits": {
        "north": "/u/cloud/eroad2"
      },
      "objects": {
        "/u/cloud/npc/b_header": 1,
        "/u/cloud/npc/bfighter": 1
      }
    },
    "/u/cloud/bookstore": {
      "type": "ROOM",
      "short": "书局",
      "exits": {
        "north": "/u/cloud/wroad1"
      },
      "objects": {
        "/u/cloud/npc/book_seller": 1
      }
    },
    "/u/cloud/butchery": {
      "type": "ROOM",
      "short": "镇北肉铺",
      "exits": {
        "east": "/u/cloud/nwroad1"
      },
      "objects": {
        "/u/cloud/npc/butcher": 1,
        "/u/cloud/npc/fly.c": 6
      }
    },
    "/u/cloud/cross": {
      "type": "ROOM",
      "short": "十字路口",
      "exits": {
        "west": "/u/cloud/wroad2",
        "north": "/u/cloud/nroad2",
        "south": "/u/cloud/sroad1",
        "east": "/u/cloud/eroad1"
      }
    },
    "/u/cloud/dragonhill/hummock": {
      "type": "ROOM",
      "short": "卧龙岗",
      "exits": {
        "northdown": "/u/cloud/dragonhill/nhillfoot",
        "southdown": "/u/cloud/dragonhill/shillfoot"
      },
      "objects": {
        "/u/cloud/npc/gangster": 2
      }
    },
    "/u/cloud/dragonhill/nhillfoot": {
      "type": "ROOM",
      "short": "卧龙岗北坡",
      "exits": {
        "northwest": "/u/cloud/dragonhill/nroad",
        "southup": "/u/cloud/dragonhill/hummock"
      }
    },
    "/u/cloud/dragonhill/nroad": {
      "type": "ROOM",
      "short": "黄土路",
      "exits": {
        "north": "/d/snow/sroad1",
        "southeast": "/u/cloud/dragonhill/nhillfoot"
      }
    },
    "/u/cloud/dragonhill/shillfoot": {
      "type": "ROOM",
      "short": "卧龙岗南坡",
      "exits": {
        "northup": "/u/cloud/dragonhill/hummock",
        "southeast": "/u/cloud/entrance"
      }
    },
    "/u/cloud/dragonhill/sroad": {
      "type": "ROOM",
      "short": "黄土路",
      "exits": {
        "northwest": "/u/cloud/dragonhill/shillfoot",
        "southeast": "/u/cloud/entrance"
      }
    },
    "/u/cloud/drugstore": {
      "type": "ROOM",
      "short": "药店",
      "exits": {
        "south": "/u/cloud/nroad1"
      },
      "objects": {
        "/u/cloud/npc/doctor": 1
      }
    },
    "/u/cloud/duchang": {
      "type": "ROOM",
      "short": "赌场",
      "exits": {
        "north": "/u/cloud/eroad1",
        "up": "/u/cloud/duchang2"
      },
      "objects": {
        "/u/cloud/npc/judge": 1
      }
    },
    "/u/cloud/duchang2": {
      "type": "ROOM",
      "short": "赌场",
      "exits": {
        "down": "/u/cloud/duchang"
      }
    },
    "/u/cloud/dukou": {
      "type": "ROOM",
      "short": "江北渡口",
      "exits": {
        "north": "/u/cloud/sroad1",
        "south": "/u/cloud/sunhill/northriver"
      },
      "objects": {
        "/u/cloud/npc/boater": 1
      }
    },
    "/u/cloud/entrance": {
      "type": "ROOM",
      "short": "绮云镇",
      "exits": {
        "northwest": "/u/cloud/dragonhill/sroad",
        "south": "/u/cloud/nwroad1"
      }
    },
    "/u/cloud/eroad1": {
      "type": "ROOM",
      "short": "绮云镇街道",
      "exits": {
        "west": "/u/cloud/cross",
        "north": "/u/cloud/jiyuan",
        "south": "/u/cloud/duchang",
        "east": "/u/cloud/eroad2"
      }
    },
    "/u/cloud/eroad2": {
      "type": "ROOM",
      "short": "绮云镇街道",
      "exits": {
        "west": "/u/cloud/eroad1",
        "north": "/u/cloud/park",
        "south": "/u/cloud/biaoju",
        "northeast": "/u/cloud/eroad3"
      }
    },
    "/u/cloud/eroad3": {
      "type": "ROOM",
      "short": "绮云镇街道",
      "exits": {
        "north": "/u/cloud/rich",
        "southwest": "/u/cloud/eroad2",
        "southeast": "/u/cloud/eroad4"
      }
    },
    "/u/cloud/eroad4": {
      "type": "ROOM",
      "short": "茶场",
      "exits": {
        "northwest": "/u/cloud/eroad3"
      },
      "objects": {
        "/u/cloud/npc/worker": 6
      }
    },
    "/u/cloud/god1": {
      "type": "ROOM",
      "short": "场院",
      "exits": {
        "east": "/u/cloud/woodboxy",
        "west": "/u/cloud/god2"
      }
    },
    "/u/cloud/god2": {
      "type": "ROOM",
      "short": "场院前厅",
      "exits": {
        "east": "/u/cloud/god1"
      },
      "objects": {
        "/u/cloud/npc/god": 1
      }
    },
    "/u/cloud/jiyuan": {
      "type": "ROOM",
      "short": "怡红院",
      "exits": {
        "south": "/u/cloud/eroad1",
        "up": "/u/cloud/jiyuan2"
      },
      "objects": {
        "/u/cloud/npc/mother": 1
      }
    },
    "/u/cloud/jiyuan2": {
      "type": "ROOM",
      "short": "怡红院二楼",
      "exits": {
        "down": "/u/cloud/jiyuan"
      },
      "objects": {
        "/u/cloud/npc/girl": 1
      }
    },
    "/u/cloud/m_house": {
      "type": "ROOM",
      "short": "张百万家",
      "exits": {
        "south": "/u/cloud/rich"
      },
      "objects": {
        "/u/cloud/npc/millinare": 1,
        "/u/cloud/npc/jiading": 2
      }
    },
    "/u/cloud/marry_room": {
      "type": "ROOM",
      "short": "红娘庄",
      "exits": {
        "south": "/u/cloud/wroad0"
      },
      "objects": {
        "/u/cloud/npc/mei_po": 1
      }
    },
    "/u/cloud/monky": {
      "type": "ROOM",
      "short": "斋院",
      "exits": {
        "north": "/u/cloud/wroad2"
      },
      "objects": {
        "/u/cloud/npc/monk": 1,
        "/d/snow/npc/beggar": 2,
        "/obj/example/dumpling": 3
      }
    },
    "/u/cloud/nroad1": {
      "type": "ROOM",
      "short": "东市场",
      "exits": {
        "west": "/u/cloud/nwroad3",
        "north": "/u/cloud/drugstore",
        "south": "/u/cloud/nroad2",
        "east": "/u/cloud/weapony"
      }
    },
    "/u/cloud/nroad2": {
      "type": "ROOM",
      "short": "南市场",
      "exits": {
        "west": "/u/cloud/zaihuoy",
        "north": "/u/cloud/nroad1",
        "south": "/u/cloud/cross"
      }
    },
    "/u/cloud/nwroad1": {
      "type": "ROOM",
      "short": "北市场",
      "exits": {
        "west": "/u/cloud/butchery",
        "north": "/u/cloud/entrance",
        "south": "/u/cloud/nwroad2",
        "east": "/u/cloud/tearoom"
      }
    },
    "/u/cloud/nwroad2": {
      "type": "ROOM",
      "short": "西市场",
      "exits": {
        "west": "/u/cloud/woodboxy",
        "north": "/u/cloud/nwroad1",
        "south": "/u/cloud/tailory",
        "east": "/u/cloud/nwroad3"
      }
    },
    "/u/cloud/nwroad3": {
      "type": "ROOM",
      "short": "中市场",
      "exits": {
        "west": "/u/cloud/nwroad2",
        "north": "/u/cloud/tearoom",
        "south": "/u/cloud/zaihuoy",
        "east": "/u/cloud/nroad1"
      },
      "objects": {
        "/obj/npc/garrison": 2
      }
    },
    "/u/cloud/park": {
      "type": "ROOM",
      "short": "张家花园",
      "exits": {
        "south": "/u/cloud/eroad2"
      },
      "objects": {
        "/u/cloud/npc/thief": 1
      }
    },
    "/u/cloud/rich": {
      "type": "ROOM",
      "short": "张百万家",
      "exits": {
        "north": "/u/cloud/m_house",
        "south": "/u/cloud/eroad3"
      },
      "objects": {
        "/u/cloud/npc/room_gua": 5
      }
    },
    "/u/cloud/sroad1": {
      "type": "ROOM",
      "short": "绮云镇街道",
      "exits": {
        "north": "/u/cloud/cross",
        "south": "/u/cloud/dukou"
      }
    },
    "/u/cloud/sunhill/dukou": {
      "type": "ROOM",
      "short": "江南渡口",
      "exits": {
        "north": "/u/cloud/sunhill/southriver",
        "south": "/u/cloud/sunhill/road1"
      }
    },
    "/u/cloud/sunhill/midriver": {
      "type": "ROOM",
      "short": "江心",
      "exits": {
        "north": "/u/cloud/sunhill/northriver",
        "south": "/u/cloud/sunhill/southriver"
      }
    },
    "/u/cloud/sunhill/northriver": {
      "type": "ROOM",
      "short": "泓水北侧",
      "exits": {
        "north": "/u/cloud/dukou",
        "south": "/u/cloud/sunhill/midriver"
      }
    },
    "/u/cloud/sunhill/road1": {
      "type": "ROOM",
      "short": "山脚小路",
      "exits": {
        "north": "/u/cloud/sunhill/dukou",
        "southup": "/u/cloud/sunhill/road2",
        "east": "/d/choyin/n_gate"
      }
    },
    "/u/cloud/sunhill/road2": {
      "type": "ROOM",
      "short": "盘山小径",
      "exits": {
        "north": "/u/cloud/sunhill/road1",
        "west": "/u/cloud/sunhill/road3"
      }
    },
    "/u/cloud/sunhill/road3": {
      "type": "ROOM",
      "short": "盘山小径",
      "exits": {
        "east": "/u/cloud/sunhill/road2",
        "south": "/u/cloud/sunhill/road4"
      }
    },
    "/u/cloud/sunhill/road4": {
      "type": "ROOM",
      "short": "盘山小径",
      "exits": {
        "north": "/u/cloud/sunhill/road3",
        "southwest": "/d/sanyen/sroad1"
      }
    },
    "/u/cloud/sunhill/southriver": {
      "type": "ROOM",
      "short": "泓水南侧",
      "exits": {
        "north": "/u/cloud/sunhill/midriver",
        "south": "/u/cloud/sunhill/dukou"
      }
    },
    "/u/cloud/tailory": {
      "type": "ROOM",
      "short": "布庄",
      "exits": {
        "north": "/u/cloud/nwroad2"
      },
      "objects": {
        "/u/cloud/npc/tailor": 1
      }
    },
    "/u/cloud/tea_corridor": {
      "type": "ROOM",
      "short": "香茗坊茶窖",
      "exits": {
        "south": "/u/cloud/tearoom"
      }
    },
    "/u/cloud/tearoom": {
      "type": "ROOM",
      "short": "香茗坊",
      "exits": {
        "south": "/u/cloud/nwroad3",
        "west": "/u/cloud/nwroad1",
        "north": "/u/cloud/tea_corridor",
        "up": "/u/cloud/tearoom2"
      },
      "objects": {
        "/u/cloud/npc/tea_waiter": 1
      }
    },
    "/u/cloud/tearoom2": {
      "type": "ROOM",
      "short": "香茗坊二楼",
      "exits": {
        "down": "/u/cloud/tearoom"
      },
      "objects": {
        "/u/cloud/npc/chess_player": 1
      }
    },
    "/u/cloud/weapony": {
      "type": "ROOM",
      "short": "兵器屋",
      "exits": {
        "west": "/u/cloud/nroad1"
      },
      "objects": {
        "/u/cloud/npc/weaponor": 1
      }
    },
    "/u/cloud/woodboxy": {
      "type": "ROOM",
      "short": "棺材铺",
      "exits": {
        "east": "/u/cloud/nwroad2",
        "west": "/u/cloud/god1"
      },
      "objects": {
        "/u/cloud/npc/box_boss": 1,
        "/u/cloud/npc/box_waiter": 8
      }
    },
    "/u/cloud/wroad0": {
      "type": "ROOM",
      "short": "绮云镇街道",
      "exits": {
        "west": "/d/latemoon/entrance",
        "east": "/u/cloud/wroad1",
        "north": "/u/cloud/marry_room"
      }
    },
    "/u/cloud/wroad1": {
      "type": "ROOM",
      "short": "绮云镇街道",
      "exits": {
        "south": "/u/cloud/bookstore",
        "west": "/u/cloud/wroad0",
        "east": "/u/cloud/wroad2"
      }
    },
    "/u/cloud/wroad2": {
      "type": "ROOM",
      "short": "绮云镇街道",
      "exits": {
        "west": "/u/cloud/wroad1",
        "south": "/u/cloud/monky",
        "east": "/u/cloud/cross"
      }
    },
    "/u/cloud/zaihuoy": {
      "type": "ROOM",
      "short": "杂货铺",
      "exits": {
        "north": "/u/cloud/nwroad3",
        "east": "/u/cloud/nroad2"
      },
      "objects": {
        "/u/cloud/npc/seller": 1
      }
    }
  }
};
