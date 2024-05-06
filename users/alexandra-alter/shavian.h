
// {{{ shavian entry for unicode_names
#define SHAVIAN_UNICODE_NAMES() \
  SHV_PEEP,    /* 𐑐 */          \
  SHV_BIB,     /* 𐑚 */          \
  SHV_TOT,     /* 𐑑 */          \
  SHV_DEAD,    /* 𐑛 */          \
  SHV_KICK,    /* 𐑒 */          \
  SHV_GAG,     /* 𐑜 */          \
  SHV_FEE,     /* 𐑓 */          \
  SHV_VOW,     /* 𐑝 */          \
  SHV_THIGH,   /* 𐑔 */          \
  SHV_THEY,    /* 𐑞 */          \
  SHV_SO,      /* 𐑕 */          \
  SHV_ZOO,     /* 𐑟 */          \
  SHV_SURE,    /* 𐑖 */          \
  SHV_MEASURE, /* 𐑠 */          \
  SHV_CHURCH,  /* 𐑗 */          \
  SHV_JUDGE,   /* 𐑡 */          \
  SHV_YEA,     /* 𐑘 */          \
  SHV_WOE,     /* 𐑢 */          \
  SHV_HUNG,    /* 𐑙 */          \
  SHV_HAHA,    /* 𐑣 */          \
                                \
  SHV_LOLL,    /* 𐑤 */          \
  SHV_ROAR,    /* 𐑮 */          \
  SHV_MINE,    /* 𐑥 */          \
  SHV_NUN,     /* 𐑯 */          \
                                \
  SHV_IF,      /* 𐑦 */          \
  SHV_EAT,     /* 𐑰 */          \
  SHV_EGG,     /* 𐑧 */          \
  SHV_AGE,     /* 𐑱 */          \
  SHV_ASH,     /* 𐑨 */          \
  SHV_ICE,     /* 𐑲 */          \
  SHV_ADO,     /* 𐑩 */          \
  SHV_UP,      /* 𐑳 */          \
  SHV_ON,      /* 𐑪 */          \
  SHV_OAK,     /* 𐑴 */          \
  SHV_WOOL,    /* 𐑫 */          \
  SHV_OOZE,    /* 𐑵 */          \
  SHV_OUT,     /* 𐑬 */          \
  SHV_OIL,     /* 𐑶 */          \
  SHV_AH,      /* 𐑭 */          \
  SHV_AWE,     /* 𐑷 */          \
                                \
  SHV_ARE,     /* 𐑸 */          \
  SHV_OR,      /* 𐑹 */          \
  SHV_AIR,     /* 𐑺 */          \
  SHV_ERR,     /* 𐑻 */          \
  SHV_ARRAY,   /* 𐑼 */          \
  SHV_EAR,     /* 𐑽 */          \
  SHV_IAN,     /* 𐑾 */          \
  SHV_YEW,     /* 𐑿 */          \
                                \
  SHV_NAME,    /* · */          \
  SHV_ABBRV    /* ⸰ */
// }}}

// {{{ shavian entry for unicode_map
#define SHAVIAN_UNICODE_MAP() \
  [SHV_PEEP]    = 0x10450, \
  [SHV_TOT]     = 0x10451, \
  [SHV_KICK]    = 0x10452, \
  [SHV_FEE]     = 0x10453, \
  [SHV_THIGH]   = 0x10454, \
  [SHV_SO]      = 0x10455, \
  [SHV_SURE]    = 0x10456, \
  [SHV_CHURCH]  = 0x10457, \
  [SHV_YEA]     = 0x10458, \
  [SHV_HUNG]    = 0x10459, \
                           \
  [SHV_BIB]     = 0x1045a, \
  [SHV_DEAD]    = 0x1045b, \
  [SHV_GAG]     = 0x1045c, \
  [SHV_VOW]     = 0x1045d, \
  [SHV_THEY]    = 0x1045e, \
  [SHV_ZOO]     = 0x1045f, \
  [SHV_MEASURE] = 0x10460, \
  [SHV_JUDGE]   = 0x10461, \
  [SHV_WOE]     = 0x10462, \
  [SHV_HAHA]    = 0x10463, \
                           \
  [SHV_LOLL]    = 0x10464, \
  [SHV_MINE]    = 0x10465, \
  [SHV_IF]      = 0x10466, \
  [SHV_EGG]     = 0x10467, \
  [SHV_ASH]     = 0x10468, \
  [SHV_ADO]     = 0x10469, \
  [SHV_ON]      = 0x1046a, \
  [SHV_WOOL]    = 0x1046b, \
  [SHV_OUT]     = 0x1046c, \
  [SHV_AH]      = 0x1046d, \
                           \
  [SHV_ROAR]    = 0x1046e, \
  [SHV_NUN]     = 0x1046f, \
  [SHV_EAT]     = 0x10470, \
  [SHV_AGE]     = 0x10471, \
  [SHV_ICE]     = 0x10472, \
  [SHV_UP]      = 0x10473, \
  [SHV_OAK]     = 0x10474, \
  [SHV_OOZE]    = 0x10475, \
  [SHV_OIL]     = 0x10476, \
  [SHV_AWE]     = 0x10477, \
                           \
  [SHV_ARE]     = 0x10478, \
  [SHV_OR]      = 0x10479, \
  [SHV_AIR]     = 0x1047a, \
  [SHV_ERR]     = 0x1047b, \
  [SHV_ARRAY]   = 0x1047c, \
  [SHV_EAR]     = 0x1047d, \
  [SHV_IAN]     = 0x1047e, \
  [SHV_YEW]     = 0x1047f, \
                           \
  [SHV_NAME]    = 0x00b7,  \
  [SHV_ABBRV]   = 0x2e30
// }}}

// {{{ shavian keys
#define SHV_1_0 UP(SHV_AH,   SHV_ARE)
#define SHV_1_1 UP(SHV_AWE,  SHV_OR)
#define SHV_1_2 UP(SHV_OOZE, SHV_YEW)
#define SHV_1_3 UM(SHV_AGE)
#define SHV_1_4 UM(SHV_UP)
#define SHV_1_5 UM(SHV_FEE)
#define SHV_1_6 UP(SHV_THEY, SHV_THIGH)
#define SHV_1_7 UM(SHV_LOLL)
#define SHV_1_8 UM(SHV_MINE)
#define SHV_1_9 UP(SHV_HAHA, SHV_HUNG)

#define SHV_2_0 UP(SHV_ON,   SHV_OIL)
#define SHV_2_1 UP(SHV_ASH,  SHV_OUT)
#define SHV_2_2 UP(SHV_IF,   SHV_WOOL)
#define SHV_2_3 UP(SHV_ADO,  SHV_ARRAY)
#define SHV_2_4 UP(SHV_EGG,  SHV_ERR)
#define SHV_2_5 UP(SHV_PEEP, SHV_ABBRV)
#define SHV_2_6 UP(SHV_NUN,  SHV_NAME)
#define SHV_2_7 UP(SHV_TOT,  SHV_CHURCH)
#define SHV_2_8 UM(SHV_ROAR)
#define SHV_2_9 UP(SHV_SO,   SHV_SURE)

#define SHV_3_0 UP(SHV_IAN,  SHV_EAR)
#define SHV_3_1 UM(SHV_ICE)
#define SHV_3_2 UM(SHV_OAK)
#define SHV_3_3 UM(SHV_EAT)
#define SHV_3_4 UP(SHV_BIB,  SHV_AIR)
#define SHV_3_5 UM(SHV_VOW)
#define SHV_3_6 UP(SHV_ZOO,  SHV_MEASURE)
#define SHV_3_7 UP(SHV_KICK, SHV_GAG)
#define SHV_3_8 UP(SHV_WOE,  SHV_YEA)
#define SHV_3_9 UP(SHV_DEAD, SHV_JUDGE)
// }}}

/* vim: set foldmethod=marker shiftwidth=2 : */
