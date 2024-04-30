#include QMK_KEYBOARD_H
#include "version.h"

typedef enum layer_t {
  L_GAME, // core: gaming base
  L_G_KB, // core: gaming rts base
  L_G_HB, // core: gaming hitbox base
  L_OH,   // core: one-handed
  L_OHA,  // core: one-handed alt
  L_DV,   // core: dvorak
  L_QT,   // core: qwerty
  L_SHV,  // core: shavian
  L_ST,   // core: stenotype
  L_MS,   // core: mouse
  L_SYM,  // utils: symbols
  L_NUM,  // utils: numpad
  L_NAV,  // utils: navigation
  L_FUNC, // utils: function keys
  L_SHRT, // utils: shortcuts
  // layers above this point must be in the 0-15 range, as they are used in LM/LT
  L_G_NU, // core: gaming numpad
  L_G_K1, // core: gaming letters 1
  L_G_K2, // core: gaming letters 2
  L_O_GA, // overlay: gaming overlay
  L_O_ST, // overlay: stenotype overlay
  L_O_SY, // overlay: symbols overlay
  L_O_NU, // overlay: numpad overlay
  L_O_MS, // overlay: mouse overlay
  L_SYS,  // utils: system
  L_WEB,  // utils: web
  L_LED,  // utils: leds
  L_HUB,  // utils: hub
  L_MAX,
} layer_t;

typedef enum custom_keycode_t { // {{{
  RGB_SLD = SAFE_RANGE,         // pause LED animation
  TO_ST2,                       // go directly to steno with overlay
  DF_ST2,                       // go directly to steno with overlay
} custom_keycode_t;             // }}}

// {{{ unicode defs
typedef enum unicode_names {
  SHV_PEEP,    // 𐑐
  SHV_BIB,     // 𐑚
  SHV_TOT,     // 𐑑
  SHV_DEAD,    // 𐑛
  SHV_KICK,    // 𐑒
  SHV_GAG,     // 𐑜
  SHV_FEE,     // 𐑓
  SHV_VOW,     // 𐑝
  SHV_THIGH,   // 𐑔
  SHV_THEY,    // 𐑞
  SHV_SO,      // 𐑕
  SHV_ZOO,     // 𐑟
  SHV_SURE,    // 𐑖
  SHV_MEASURE, // 𐑠
  SHV_CHURCH,  // 𐑗
  SHV_JUDGE,   // 𐑡
  SHV_YEA,     // 𐑘
  SHV_WOE,     // 𐑢
  SHV_HUNG,    // 𐑙
  SHV_HAHA,    // 𐑣
  SHV_LOLL,    // 𐑤
  SHV_ROAR,    // 𐑮
  SHV_MINE,    // 𐑥
  SHV_NUN,     // 𐑯
  SHV_IF,      // 𐑦
  SHV_EAT,     // 𐑰
  SHV_EGG,     // 𐑧
  SHV_AGE,     // 𐑱
  SHV_ASH,     // 𐑨
  SHV_ICE,     // 𐑲
  SHV_ADO,     // 𐑩
  SHV_UP,      // 𐑳
  SHV_ON,      // 𐑪
  SHV_OAK,     // 𐑴
  SHV_WOOL,    // 𐑫
  SHV_OOZE,    // 𐑵
  SHV_OUT,     // 𐑬
  SHV_OIL,     // 𐑶
  SHV_AH,      // 𐑭
  SHV_AWE,     // 𐑷
  SHV_ARE,     // 𐑸
  SHV_OR,      // 𐑹
  SHV_AIR,     // 𐑺
  SHV_ERR,     // 𐑻
  SHV_ARRAY,   // 𐑼
  SHV_EAR,     // 𐑽
  SHV_IAN,     // 𐑾
  SHV_YEW,     // 𐑿
  SHV_NAME,    // ·
  SHV_ABBRV,   // ⸰

  UM_SPACE,
} unicode_names;

const uint32_t PROGMEM unicode_map[] = {
  [SHV_PEEP]    = 0x10450,
  [SHV_TOT]     = 0x10451,
  [SHV_KICK]    = 0x10452,
  [SHV_FEE]     = 0x10453,
  [SHV_THIGH]   = 0x10454,
  [SHV_SO]      = 0x10455,
  [SHV_SURE]    = 0x10456,
  [SHV_CHURCH]  = 0x10457,
  [SHV_YEA]     = 0x10458,
  [SHV_HUNG]    = 0x10459,

  [SHV_BIB]     = 0x1045a,
  [SHV_DEAD]    = 0x1045b,
  [SHV_GAG]     = 0x1045c,
  [SHV_VOW]     = 0x1045d,
  [SHV_THEY]    = 0x1045e,
  [SHV_ZOO]     = 0x1045f,
  [SHV_MEASURE] = 0x10460,
  [SHV_JUDGE]   = 0x10461,
  [SHV_WOE]     = 0x10462,
  [SHV_HAHA]    = 0x10463,

  [SHV_LOLL]    = 0x10464,
  [SHV_MINE]    = 0x10465,
  [SHV_IF]      = 0x10466,
  [SHV_EGG]     = 0x10467,
  [SHV_ASH]     = 0x10468,
  [SHV_ADO]     = 0x10469,
  [SHV_ON]      = 0x1046a,
  [SHV_WOOL]    = 0x1046b,
  [SHV_OUT]     = 0x1046c,
  [SHV_AH]      = 0x1046d,

  [SHV_ROAR]    = 0x1046e,
  [SHV_NUN]     = 0x1046f,
  [SHV_EAT]     = 0x10470,
  [SHV_AGE]     = 0x10471,
  [SHV_ICE]     = 0x10472,
  [SHV_UP]      = 0x10473,
  [SHV_OAK]     = 0x10474,
  [SHV_OOZE]    = 0x10475,
  [SHV_OIL]     = 0x10476,
  [SHV_AWE]     = 0x10477,

  [SHV_ARE]     = 0x10478,
  [SHV_OR]      = 0x10479,
  [SHV_AIR]     = 0x1047a,
  [SHV_ERR]     = 0x1047b,
  [SHV_ARRAY]   = 0x1047c,
  [SHV_EAR]     = 0x1047d,
  [SHV_IAN]     = 0x1047e,
  [SHV_YEW]     = 0x1047f,

  [SHV_NAME]    = 0x00b7,
  [SHV_ABBRV]   = 0x2e30,

  [UM_SPACE]   = 0x20,
};
// }}}

// {{{ layout key meta-def
// we assume that name(kc) is a macro that creates a mod-tap key
#define META_KEY(name, mod, default_kc)                                                                                                    \
  const uint16_t KA_##name = name(default_kc);                                                                                             \
  const uint16_t MA_##name = mod;

#define META_PLAINKEY(name, mod, mod_kc)                                                                                                   \
  const uint16_t KA_##name = mod_kc;                                                                                                       \
  const uint16_t MA_##name = mod;
// }}}

// {{{ layout key defs
// moonlander keys
#define RGB_TLC TOGGLE_LAYER_COLOR

// layer keys
#define MO_NAV MO(L_NAV)
#define MO_LED MO(L_LED)
#define MO_WEB MO(L_WEB)
#define MO_SYS MO(L_SYS)

#define TG_HUB TG(L_HUB)
#define TG_DV TG(L_DV)
#define TG_OH TG(L_OH)

#define TO_GAME TO(L_GAME)
#define TO_G_KB TO(L_G_KB)
#define TO_G_HB TO(L_G_HB)
#define TO_SHV  TO(L_SHV)

#define DF_GAME DF(L_GAME)
#define DF_G_KB DF(L_G_KB)
#define DF_G_HB DF(L_G_HB)
#define DF_SHV  DF(L_SHV)

// shortcut keys
#define KA_UNDO LCTL(KC_Z)
#define KA_REDO LCTL(KC_Y)

#define KA_CUT LCTL(KC_X)
#define KA_COPY LCTL(KC_C)
#define KA_PSTE LCTL(KC_V)

#define KA_QUIT LCTL(KC_Q)
#define KA_CLOS LCTL(KC_W)

// {{{ shavian
#define SHV_1_0 UP(SHV_NAME,   SHV_ABBRV)
#define SHV_1_1 UP(SHV_OIL,    UM_SPACE)
#define SHV_1_2 UP(SHV_OUT,    UM_SPACE)
#define SHV_1_3 UP(SHV_WOOL,   UM_SPACE)
#define SHV_1_4 UP(SHV_GAG,    UM_SPACE)
#define SHV_1_5 UP(SHV_SURE,   UM_SPACE)
#define SHV_1_6 UP(SHV_CHURCH, UM_SPACE)
#define SHV_1_7 UP(SHV_HUNG,   UM_SPACE)
#define SHV_1_8 UP(SHV_YEA,    UM_SPACE)
#define SHV_1_9 UP(SHV_JUDGE,  UM_SPACE)
#define SHV_1_A UP(SHV_THIGH,  UM_SPACE)

#define SHV_2_1 UP(SHV_AH,      SHV_ARE)
#define SHV_2_2 UP(SHV_AWE,     SHV_OR)
#define SHV_2_3 UP(SHV_WOOL,    SHV_YEW)
#define SHV_2_4 UP(SHV_AGE,     SHV_AIR)
#define SHV_2_5 UP(SHV_UP,      SHV_ERR)
#define SHV_2_6 UP(SHV_FEE,     UM_SPACE)
#define SHV_2_7 UP(SHV_THEY,    UM_SPACE)
#define SHV_2_8 UP(SHV_LOLL,    UM_SPACE)
#define SHV_2_9 UP(SHV_MINE,    UM_SPACE)
#define SHV_2_A UP(SHV_KICK,    UM_SPACE)
#define SHV_2_B UP(SHV_WOE,     UM_SPACE)
#define SHV_2_C UP(SHV_HAHA,    UM_SPACE)
#define SHV_2_D UP(SHV_MEASURE, UM_SPACE)

#define SHV_3_1 UP(SHV_ON,   UM_SPACE)
#define SHV_3_2 UP(SHV_ASH,  UM_SPACE)
#define SHV_3_3 UP(SHV_IF,   UM_SPACE)
#define SHV_3_4 UP(SHV_ADO,  SHV_ARRAY)
#define SHV_3_5 UP(SHV_EGG,  UM_SPACE)
#define SHV_3_6 UP(SHV_PEEP, UM_SPACE)
#define SHV_3_7 UP(SHV_NUN,  UM_SPACE)
#define SHV_3_8 UP(SHV_TOT,  UM_SPACE)
#define SHV_3_9 UP(SHV_ROAR, UM_SPACE)
#define SHV_3_A UP(SHV_SO,   UM_SPACE)
#define SHV_3_B UP(SHV_DEAD, UM_SPACE)

#define SHV_4_1 UP(SHV_IAN,  SHV_EAR)
#define SHV_4_2 UP(SHV_ICE,  UM_SPACE)
#define SHV_4_3 UP(SHV_OAK,  UM_SPACE)
#define SHV_4_4 UP(SHV_EAT,  UM_SPACE)
#define SHV_4_5 UP(SHV_BIB,  UM_SPACE)
#define SHV_4_6 UP(SHV_VOW,  UM_SPACE)
#define SHV_4_7 UP(SHV_ZOO,  UM_SPACE)
#define SHV_4_8 UP(SHV_TOT,  UM_SPACE)
#define SHV_4_9 UP(SHV_ROAR, UM_SPACE)
#define SHV_4_A UP(SHV_SO,   UM_SPACE)
#define SHV_4_B UP(SHV_DEAD, UM_SPACE)
// }}}

// normal left modifiers
#define L1(kc) (LALT_T(kc))
META_KEY(L1, KC_LALT, KC_GRV);
#define L2(kc) (LGUI_T(kc))
META_KEY(L2, KC_LGUI, KC_ESC);
#define L3(kc) (LCTL_T(kc))
META_KEY(L3, KC_LCTL, KC_BSPC);
#define L4(kc) (LSFT_T(kc))
META_PLAINKEY(L4, KC_LSFT, SC_LSPO);
#define L5(kc) (RALT_T(kc))
META_KEY(L5, KC_RALT, KC_DEL);
#define L6(kc) (LGUI_T(kc))
META_KEY(L6, KC_LGUI, KC_LBRC);
#define L7(kc) (LCTL_T(kc))
META_KEY(L7, KC_LCTL, KC_RBRC);
#define L8(kc) (LSFT_T(kc))
META_KEY(L8, KC_LSFT, KC_LEFT);
#define L9(kc) (LALT_T(kc))
META_KEY(L9, KC_LALT, KC_RIGHT);
#define L10(kc) (LALT_T(kc))
META_KEY(L10, KC_LALT, KC_LBRC);
#define L11(kc) (LSFT_T(kc))
META_KEY(L11, KC_LSFT, KC_MINS);
#define L12(kc) (LCTL_T(kc))
META_KEY(L12, KC_LCTL, KC_BSLS);

// normal right modifiers
#define R1(kc) (LALT_T(kc))
META_KEY(R1, KC_LALT, KC_EQL);
#define R2(kc) (RGUI_T(kc))
META_KEY(R2, KC_RGUI, KC_SLSH);
#define R3(kc) (RCTL_T(kc))
META_KEY(R3, KC_RCTL, KC_MINS);
#define R4(kc) (RSFT_T(kc))
META_PLAINKEY(R4, KC_RSFT, SC_RSPC);
#define R5(kc) (RALT_T(kc))
META_KEY(R5, KC_RALT, KC_EQL);
#define R6(kc) (RGUI_T(kc))
META_KEY(R6, KC_RGUI, KC_SLSH);
#define R7(kc) (RCTL_T(kc))
META_KEY(R7, KC_RCTL, KC_BSLS);
#define R8(kc) (RSFT_T(kc))
META_KEY(R8, KC_RSFT, KC_UP);
#define R9(kc) (LALT_T(kc))
META_KEY(R9, KC_LALT, KC_DOWN);
#define R10(kc) (LALT_T(kc))
META_KEY(R10, KC_LALT, KC_RBRC);
#define R11(kc) (RSFT_T(kc))
META_KEY(R11, KC_RSFT, KC_BSLS);
#define R12(kc) (RCTL_T(kc))
META_KEY(R12, KC_RCTL, KC_GRV);

// thumb keys
#define KA_APP MO(L_HUB)

#define KA_LT1 LT(L_SYM, KC_SPC)
#define KA_LT2 LT(L_NAV, KC_TAB)
#define KA_LT3 LT(L_SHRT, KC_ENT)

#define KA_RT1 LT(L_NUM, KC_SPC)
#define KA_RT2 LT(L_FUNC, KC_ENT)
#define KA_RT3 LT(L_MS, KC_TAB)

#define KA_OHT1 LT(L_OHA, KC_SPC)
#define KA_OHT2 LT(L_NAV, KC_TAB)
#define KA_OHT3 LT(L_SYM, KC_ENT)

// TODO needs access to: symbols, all letters, function keys, thumbless modifiers
#define KA_G_K1 MO(L_G_K1)
#define KA_G_K2 MO(L_G_K2)
// }}}

// {{{ layout convenience defs
// clang-format off
#define LAYOUT_moonlander_mirrored(                                       \
  k00, k01, k02, k03, k04, k05, k06,                                      \
  k10, k11, k12, k13, k14, k15, k16,                                      \
  k20, k21, k22, k23, k24, k25, k26,                                      \
  k30, k31, k32, k33, k34, k35,                                           \
  k40, k41, k42, k43, k44,      k53,                                      \
                      k50, k51, k52)                                      \
LAYOUT_moonlander(                                                        \
  k00, k01, k02, k03, k04, k05, k06,   k06, k05, k04, k03, k02, k01, k00, \
  k10, k11, k12, k13, k14, k15, k16,   k16, k15, k14, k13, k12, k11, k10, \
  k20, k21, k22, k23, k24, k25, k26,   k26, k25, k24, k23, k22, k21, k20, \
  k30, k31, k32, k33, k34, k35,             k35, k34, k33, k32, k31, k30, \
  k40, k41, k42, k43, k44,      k53,   k53,      k44, k43, k42, k41, k40, \
                      k50, k51, k52,   k52, k51, k50)

// mirrored layout, save for the 3x3 'inner' area centred on the middle finger
// we flip row 0 too, because of the mouse buttons in L_MS
#define LAYOUT_moonlander_mirrored_outer(                                 \
  k00, k01, k02, k03, k04, k05, k06,                                      \
  k10, k11, k12, k13, k14, k15, k16,                                      \
  k20, k21, k22, k23, k24, k25, k26,                                      \
  k30, k31, k32, k33, k34, k35,                                           \
  k40, k41, k42, k43, k44,      k53,                                      \
                      k50, k51, k52                                       \
)                                                                         \
LAYOUT_moonlander(                                                        \
  k00, k01, k02, k03, k04, k05, k06,   k06, k05, k02, k03, k04, k01, k00, \
  k10, k11, k12, k13, k14, k15, k16,   k16, k15, k12, k13, k14, k11, k10, \
  k20, k21, k22, k23, k24, k25, k26,   k26, k25, k22, k23, k24, k21, k20, \
  k30, k31, k32, k33, k34, k35,             k35, k32, k33, k34, k31, k30, \
  k40, k41, k42, k43, k44,      k53,   k53,      k44, k43, k42, k41, k40, \
                      k50, k51, k52,   k52, k51, k50)
// clang-format on
// }}}

const uint16_t PROGMEM keymaps[L_MAX][MATRIX_ROWS][MATRIX_COLS] = {
  /* {{{ templates
  [L_] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______,            _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,    _______, _______, _______
  ), */ // }}}

  [L_DV] = LAYOUT_moonlander( // {{{ dvorak
    KA_L1,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KA_L12,     KA_R12,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KA_R1,
    KA_L2,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KA_L11,     KA_R11,  KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KA_R2,
    KA_L3,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KA_L10,     KA_R10,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KA_R3,
    KA_L4,   KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KA_R4,
    KA_L5,   KA_L6,   KA_L7,   KA_L8,   KA_L9,        KA_APP,             KA_APP,       KA_R9,   KA_R8,   KA_R7,   KA_R6,   KA_R5,
                                        KA_LT1,  KA_LT2,  KA_LT3,     KA_RT3,  KA_RT2,  KA_RT1
  ), // }}}

  [L_QT] = LAYOUT_moonlander( // {{{ qwerty
    KA_L1,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KA_L12,     KA_R12,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KA_R1,
    KA_L2,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KA_L11,     KA_R11,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KA_R2,
    KA_L3,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KA_L10,     KA_R10,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KA_R3,
    KA_L4,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KA_R4,
    KA_L5,   KA_L6,   KA_L7,   KA_L8,   KA_L9,        KA_APP,             KA_APP,       KA_R9,   KA_R8,   KA_R7,   KA_R6,   KA_R5,
                                        KA_LT1,  KA_LT2,  KA_LT3,     KA_RT3,  KA_RT2,  KA_RT1
  ), // }}}

  [L_SHV] = LAYOUT_moonlander( // {{{ shavian
    SHV_1_0, SHV_1_1, SHV_1_2, SHV_1_3, SHV_1_4, SHV_1_5, KA_L12,     KA_R12,  SHV_1_6, SHV_1_7, SHV_1_8, SHV_1_9, SHV_1_A, SHV_2_C,
    KA_L2,   SHV_2_1, SHV_2_2, SHV_2_3, SHV_2_4, SHV_2_5, KA_L11,     KA_R11,  SHV_2_6, SHV_2_7, SHV_2_8, SHV_2_9, SHV_2_A, SHV_2_B,
    KA_L3,   SHV_3_1, SHV_3_2, SHV_3_3, SHV_3_4, SHV_3_5, KA_L10,     KA_R10,  SHV_3_6, SHV_3_7, SHV_3_8, SHV_3_9, SHV_3_A, SHV_3_B,
    KA_L4,   SHV_4_1, SHV_4_2, SHV_4_3, SHV_4_4, SHV_4_5,                      SHV_4_6, SHV_4_7, KC_COMM, KC_DOT,  KC_SLSH, SHV_2_D,
    KA_L5,   KA_L6,   KA_L7,   KA_L8,   KA_L9,        KA_APP,             KA_APP,       KA_R9,   KA_R8,   KA_R7,   KA_R6,   KA_R5,
                                        KA_LT1,  KA_LT2,  KA_LT3,     KA_RT3,  KA_RT2,  KA_RT1
  ), // }}}

  [L_ST] = LAYOUT_moonlander( // {{{ stenotype
    STN_PWR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_HUB,     TG_HUB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, STN_PWR,
    STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  XXXXXXX,    XXXXXXX, STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
    STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, XXXXXXX,    XXXXXXX, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    STN_FN,  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,                      STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    MO_NAV,  STN_N1,  STN_N1,  STN_N2,  STN_N2,       _______,            _______,      STN_NB,  STN_NB,  STN_NC,  STN_NC,  MO_NAV,
                                        STN_A,   STN_O,   STN_RE1,    STN_RE2, STN_E,   STN_U
  ), // }}}

  [L_O_ST] = LAYOUT_moonlander( // {{{ stenotype overlay
    _______, _______, _______, _______, _______, _______, TG_HUB,     TG_HUB,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      STN_RE1,            STN_RE2,      _______, _______, _______, _______, _______,
                                        _______, _______, STN_N1,     STN_NC,  _______, _______
  ), // }}}

  [L_OH] = LAYOUT_moonlander_mirrored( // {{{ one-handed
    KA_L1,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KA_L12,
    KA_L2,   KC_L,    KC_R,    KC_C,    KC_G,    KC_F,    KA_L11,
    KA_L3,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KA_L10,
    KA_L4,   KC_S,    KC_N,    KC_T,    KC_H,    KC_D,
    KA_L5,   KA_L6,   KA_L7,   KA_L8,   KA_L9,        _______,
                                        KA_OHT1, KA_OHT2,  KA_OHT3
  ), // }}}

  [L_OHA] = LAYOUT_moonlander_mirrored_outer( // {{{ one-handed alt
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______,
    _______, KC_Z,    KC_V,    KC_W,    KC_M,    KC_B,    _______,
    _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,
    _______, _______, _______, _______, _______,      _______,
                                        _______, _______, _______
  ), // }}}

  [L_GAME] = LAYOUT_moonlander( // {{{ gaming base
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,    XXXXXXX, _______, _______, _______, _______, _______, _______,
    KC_ESC,  KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_6,       _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_7,       _______, _______, _______, _______, _______, _______, _______,
    KC_LSFT, KC_ENT,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,                      _______, _______, _______, _______, _______, _______,
    KC_LGUI, KC_DEL,  KC_0,    KC_9,    KC_8,         _______,            _______,      _______, _______, _______, _______, _______,
                                        KC_SPC,  KC_LALT, KC_LCTL,    _______, _______, _______
  ), // }}}

  [L_G_KB] = LAYOUT_moonlander( // {{{ gaming rts base
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,    XXXXXXX, _______, _______, _______, _______, _______, _______,
    KC_ESC,  KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_6,       _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_7,       _______, _______, _______, _______, _______, _______, _______,
    KC_LSFT, KC_ENT,  KC_BSPC, KC_INS,  XXXXXXX, KC_PAUS,                      _______, _______, _______, _______, _______, _______,
    KC_LGUI, KC_DEL,  KC_0,    KC_9,    KC_8,         _______,            _______,      _______, _______, _______, _______, _______,
                                        KC_SPC,  KA_G_K1, KA_G_K2,    _______, _______, _______
  ), // }}}

  [L_G_HB] = LAYOUT_moonlander( // {{{ gaming hitbox base
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,    XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_ESC,  KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_6,       KC_F5,   KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_F12,
    KC_LCTL, KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_7,       KC_F4,   KC_PSLS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_RCTL,
    KC_LSFT, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,                       KC_PDOT, KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_RSFT,
    KC_LGUI, XXXXXXX, KC_0,    KC_9,    KC_8,         _______,            _______,      KC_F3,   KC_F2,   KC_F1,   KC_RALT, KC_RGUI,
                                        KC_HOME, KC_UP,   KC_END,     KC_PGDN, KC_UP,   KC_PGUP
  ), // }}}

  [L_G_K1] = LAYOUT_moonlander_mirrored( // {{{ gaming letters 1
    MA_L1,   KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    MA_L2,   KC_L,    KC_R,    KC_C,    KC_G,    KC_F,    L11(KC_SLSH),
    MA_L3,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    L10(KC_BSLS),
    MA_L4,   KC_S,    KC_N,    KC_T,    KC_H,    KC_D,
    MA_L5,   MA_L6,   MA_L7,   MA_L8,   MA_L9,        _______,
                                        _______,  _______,  _______
  ), // }}}

  [L_G_K2] = LAYOUT_moonlander_mirrored( // {{{ gaming letters 2
    MA_L1,      KC_F1,      KC_F2,      KC_F3,     KC_F4,     KC_F5, _______,
    MA_L2,      KC_QUOT,    KC_COMM,    KC_DOT,    KC_P,      KC_Y,  L11(KC_F6),
    MA_L3,      KC_Z,       KC_V,       KC_W,      KC_M,      KC_B,  L10(KC_F7),
    MA_L4,      KC_SCLN,    KC_Q,       KC_J,      KC_K,      KC_X,
    L5(KC_F12), L6(KC_F11), L7(KC_F10), L8(KC_F9), L9(KC_F8),      _______,
                                        _______,   _______,   _______
  ), // }}}

  [L_G_NU] = LAYOUT_moonlander( // {{{ gaming numpad
    _______, _______, _______, _______, _______, _______, XXXXXXX,    XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______, _______,    KC_F5,   KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_F12,
    _______, _______, _______, _______, _______, _______, _______,    KC_F4,   KC_PSLS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_RCTL,
    _______, _______, _______, _______, _______, _______,                      XXXXXXX, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, KC_RSFT,
    _______, _______, _______, _______, _______,      _______,            _______,      KC_F3,   KC_F2,   KC_F1,   KC_RALT, KC_RGUI,
                                        _______, _______, _______,    KC_PENT, KC_PDOT, KC_P0
  ), // }}}

  [L_O_GA] = LAYOUT_moonlander( // {{{ gaming overlay
    _______, _______, _______, _______, _______, _______, TG_OH,      TG_DV,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______,            _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,    _______, _______, _______
  ), // }}}

  [L_MS] = LAYOUT_moonlander_mirrored_outer( // {{{ mouse
    _______, XXXXXXX, KC_BTN6, KC_BTN7, KC_BTN8, XXXXXXX, _______,
    _______, KC_ACL0, KC_BTN4, KC_MS_U, KC_BTN5, KC_WH_U, _______,
    _______, KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,
    _______, KC_ACL2, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX,
    _______, _______, _______, _______, _______,      _______,
                                        KC_BTN1, KC_BTN2, KC_BTN3
  ), // }}}

  [L_O_MS] = LAYOUT_moonlander( // {{{ mouse overlay
    _______, _______, _______, _______, _______, _______, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______,      _______,            _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,    KC_ACL0, KC_ACL1, KC_ACL2
  ), // }}}

  [L_SYM] = LAYOUT_moonlander( // {{{ symbols
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_QUOT, KC_COMM, KC_DOT,  XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, KC_DOT,  KC_COMM, KC_QUOT, _______,
    _______, KC_GRV,  KC_MINS, KC_EQL,  KC_SLSH, XXXXXXX, _______,    _______, XXXXXXX, KC_SLSH, KC_EQL,  KC_MINS, KC_GRV,  _______,
    _______, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX,                      XXXXXXX, KC_BSLS, KC_LBRC, KC_RBRC, KC_SCLN, _______,
    _______, _______, _______, _______, _______,      _______,            _______,      _______, _______, _______, _______, _______,
                                           _______, _______, _______,    _______, _______, _______
  ), // }}}

  [L_O_SY] = LAYOUT_moonlander( // {{{ symbols overlay
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______, _______,    _______, XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, XXXXXXX, KC_F12,
    _______, _______, _______, _______, _______, _______, _______,    _______, XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______,                      XXXXXXX, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, _______, _______, _______, _______,      _______,            _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,    _______, _______, _______
  ), // }}}

  [L_NUM] = LAYOUT_moonlander( // {{{ numpad
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______,    _______, KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______,
    _______, KC_PSLS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,    _______, KC_PSLS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
    _______, KC_PEQL, KC_P7,   KC_P8,   KC_P9,   KC_P0,                        KC_PEQL, KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______,
    _______, KC_LPRN, KC_RPRN, KC_PDOT, KC_PCMM,      _______,            _______,      KC_PDOT, KC_PCMM, KC_LPRN, KC_RPRN, _______,
                                        _______, _______, _______,    _______, _______, _______
  ), // }}}

  [L_O_NU] = LAYOUT_moonlander( // {{{ numpad overlay
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, XXXXXXX, KC_COMM, KC_DOT,  XXXXXXX, XXXXXXX, _______,    _______, _______, _______, _______, _______, _______, KC_F12,
    _______, KC_COLN, KC_A,    KC_B,    KC_C,    XXXXXXX, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_SCLN, KC_D,    KC_E,    KC_F,    KC_X,                         _______, _______, _______, _______, _______, _______,
    _______, KA_L6,   KA_L7,   KA_L8,   KA_L9,        _______,            _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,    _______, _______, _______
  ), // }}}

  [L_NAV] = LAYOUT_moonlander_mirrored_outer( // {{{ navigation
    _______, KC_INS,  XXXXXXX, KC_PSCR, XXXXXXX, KC_PAUS, _______,
    _______, KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
    _______, KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
    _______, KC_ENT,  KC_BSPC, XXXXXXX, KC_DEL,  KC_APP,
    _______, _______, _______, _______, _______,      _______,
                                        _______, _______, _______
  ), // }}}

  [L_FUNC] = LAYOUT_moonlander( // {{{ function keys
    MA_L1,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MA_R1,
    MA_L2,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, MA_L11,     MA_R11,  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   MA_R2,
    MA_L3,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, MA_L10,     MA_R10,  XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   MA_R3,
    MA_L4,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                      XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  MA_R4,
    MA_L5,   MA_L6,   MA_L7,   MA_L8,   MA_L9,        _______,            _______,      MA_R9,   MA_R8,   MA_R7,   MA_R6,   MA_R5,
                                        _______, _______, _______,    _______, _______, _______
  ), // }}}

  [L_SHRT] = LAYOUT_moonlander_mirrored( // {{{ shortcuts
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MRWD, KC_MFFD, XXXXXXX,
    XXXXXXX, KA_QUIT, KA_CLOS, KC_VOLU, KC_MPRV, KC_MNXT, XXXXXXX,
    MO_SYS,  KA_REDO, XXXXXXX, KC_VOLD, KC_MSTP, KC_MPLY, MO_LED,
    MO_WEB,  KA_UNDO, KA_CUT,  KA_COPY, KA_PSTE, KC_APP,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX
  ), // }}}

  [L_SYS] = LAYOUT_moonlander_mirrored( // {{{ system
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PWR,  XXXXXXX,
    XXXXXXX, KC_MYCM, KC_CALC, KC_MAIL, KC_MSEL, KC_SLEP, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EJCT, KC_WAKE,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX
  ), // }}}

  [L_WEB] = LAYOUT_moonlander_mirrored( // {{{ web
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_WHOM, KC_WFAV, KC_WSCH, KC_WBAK, KC_WFWD, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WSTP, KC_WREF,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX
  ), // }}}

  [L_LED] = LAYOUT_moonlander_mirrored( // {{{ leds
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, RGB_HUI, RGB_SAI, RGB_TOG, RGB_TLC, XXXXXXX, XXXXXXX,
    XXXXXXX, RGB_VAI, RGB_SPI, RGB_MOD, RGB_SLD, XXXXXXX, XXXXXXX,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX
  ), // }}}

  [L_HUB] = LAYOUT_moonlander_mirrored( // {{{ hub
    QK_BOOT,  XXXXXXX,  KC_CAPS,  KC_NUM,   KC_SCRL,  XXXXXXX,  TG_HUB,
    XXXXXXX,  XXXXXXX,  DF_SHV,   DF_ST2,   DF_G_HB,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  DF(L_OH), DF(L_DV), DF(L_ST), DF_GAME,  DF(L_MS), XXXXXXX,
    XXXXXXX,  XXXXXXX,  DF(L_QT), XXXXXXX,  DF_G_KB,  XXXXXXX,
    AU_TOGG,  UC_NEXT,  XXXXXXX,  XXXXXXX,  XXXXXXX,       _______,
                                            XXXXXXX,  XXXXXXX,  XXXXXXX
  ), // }}}
};

typedef enum color_t { // {{{
  C_NONE,
  C_____ = C_NONE,
  C__ = C_NONE,

  // sunset
  C_SU_1, // orange
  C_SU_2, // red
  C_SU_3, // purple
  C_SU_4, // violet
  C_SU_5, // blue

  // tomorrow
  C_TO_1, // l. lime
  C_TO_2, // l. orange
  C_TO_3, // l. blue
  C_TO_4, // l. red
  C_TO_5, // l. purple

  // rubik's cube
  C_RU_1, // green
  C_RU_2, // red
  C_RU_3, // yellow
  C_RU_4, // blue
  C_RU_5, // orange

  // desert sun
  C_DS_1, // orange
  C_DS_2, // yellow
  C_DS_3, // l. yellow
  C_DS_4, // white
  C_DS_5, // blue

  // cosmic chocolate
  C_CC_1, // brown
  C_CC_2, // d. red
  C_CC_3, // red
  C_CC_4, // white
  C_CC_5, // yellow

  // material
  C_MA_1, // yellow
  C_MA_2, // orange
  C_MA_3, // d. pink
  C_MA_4, // green
  C_MA_5, // blue

  // solarized
  C_SO_1, // yellow
  C_SO_2, // orange
  C_SO_3, // red
  C_SO_4, // blue
  C_SO_5, // l. blue

  // raspberry
  C_RA_1, // red
  C_RA_2, // l. red
  C_RA_3, // l. yellow
  C_RA_4, // l. brown
  C_RA_5, // brown

  C_MAX,
} color_t; // }}}

const uint8_t PROGMEM color_map[C_MAX][3] = {
    // {{{
    [C_NONE] = {0, 0, 0},

    // sunset
    [C_SU_1] = {14, 222, 242},
    [C_SU_2] = {255, 220, 201},
    [C_SU_3] = {233, 218, 217},
    [C_SU_4] = {205, 255, 255},
    [C_SU_5] = {180, 255, 233},

    // tomorrow
    [C_TO_1] = {50, 153, 244},
    [C_TO_2] = {20, 177, 225},
    [C_TO_3] = {154, 86, 255},
    [C_TO_4] = {252, 119, 255},
    [C_TO_5] = {195, 61, 255},

    // rubik's cube
    [C_RU_1] = {105, 255, 255},
    [C_RU_2] = {249, 228, 255},
    [C_RU_3] = {35, 255, 255},
    [C_RU_4] = {154, 255, 255},
    [C_RU_5] = {14, 255, 255},

    // desert sun
    [C_DS_1] = {14, 255, 255},
    [C_DS_2] = {33, 255, 255},
    [C_DS_3] = {30, 96, 255},
    [C_DS_4] = {0, 0, 255},
    [C_DS_5] = {141, 255, 233},

    // cosmic chocolate
    [C_CC_1] = {15, 166, 195},
    [C_CC_2] = {0, 205, 155},
    [C_CC_3] = {0, 183, 238},
    [C_CC_4] = {0, 0, 255},
    [C_CC_5] = {31, 255, 255},

    // material
    [C_MA_1] = {32, 176, 255},
    [C_MA_2] = {10, 225, 255},
    [C_MA_3] = {243, 222, 234},
    [C_MA_4] = {85, 203, 158},
    [C_MA_5] = {134, 255, 213},

    // solarized
    [C_SO_1] = {32, 255, 234},
    [C_SO_2] = {12, 225, 241},
    [C_SO_3] = {1, 204, 255},
    [C_SO_4] = {168, 120, 255},
    [C_SO_5] = {145, 224, 255},

    // raspberry
    [C_RA_1] = {252, 199, 190},
    [C_RA_2] = {248, 159, 255},
    [C_RA_3] = {28, 126, 255},
    [C_RA_4] = {16, 97, 236},
    [C_RA_5] = {16, 177, 169},
}; // }}}

typedef enum led_mode_t {
  LM_NONE,
  LM_BOTH,
  LM_LEFT,
  LM_RIGHT,
} led_mode_t;

typedef struct layer_led_config_t {
  led_mode_t mode;
  const uint8_t leds; // last three LED indicators of the board
  const color_t colors[RGB_MATRIX_LED_COUNT];
} layer_led_config_t;

// {{{ led convenience defs
// clang-format off
#define LEDS_moonlander_both( \
  l00, l05, l10, l15, l20, l25, l29, l65, l61, l56, l51, l46, l41, l36, \
  l01, l06, l11, l16, l21, l26, l30, l66, l62, l57, l52, l47, l42, l37, \
  l02, l07, l12, l17, l22, l27, l31, l67, l63, l58, l53, l48, l43, l38, \
  l03, l08, l13, l18, l23, l28,           l64, l59, l54, l49, l44, l39, \
  l04, l09, l14, l19, l24,   l35,       l71,   l60, l55, l50, l45, l40, \
                      l32, l33, l34, l70, l69, l68 \
) { \
  l00, l01, l02, l03, l04, l05, l06, l07, l08, l09, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, \
  l20, l21, l22, l23, l24, l25, l26, l27, l28, l29, l30, l31, l32, l33, l34, l35, \
  l36, l37, l38, l39, l40, l41, l42, l43, l44, l45, l46, l47, l48, l49, l50, l51, l52, l53, l54, l55, \
  l56, l57, l58, l59, l60, l61, l62, l63, l64, l65, l66, l67, l68, l69, l70, l71 }

#define LEDS_moonlander_left( \
  l00, l05, l10, l15, l20, l25, l29, \
  l01, l06, l11, l16, l21, l26, l30, \
  l02, l07, l12, l17, l22, l27, l31, \
  l03, l08, l13, l18, l23, l28,      \
  l04, l09, l14, l19, l24,   l35,    \
                      l32, l33, l34  \
) { \
  l00, l01, l02, l03, l04, l05, l06, l07, l08, l09, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, \
  l20, l21, l22, l23, l24, l25, l26, l27, l28, l29, l30, l31, l32, l33, l34, l35, \
  C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, \
  C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__ }

#define LEDS_moonlander_mirrored( \
  l00, l05, l10, l15, l20, l25, l29, \
  l01, l06, l11, l16, l21, l26, l30, \
  l02, l07, l12, l17, l22, l27, l31, \
  l03, l08, l13, l18, l23, l28,      \
  l04, l09, l14, l19, l24,   l35,    \
                      l32, l33, l34  \
) { \
  l00, l01, l02, l03, l04, l05, l06, l07, l08, l09, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, \
  l20, l21, l22, l23, l24, l25, l26, l27, l28, l29, l30, l31, l32, l33, l34, l35, \
  l00, l01, l02, l03, l04, l05, l06, l07, l08, l09, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, \
  l20, l21, l22, l23, l24, l25, l26, l27, l28, l29, l30, l31, l32, l33, l34, l35 }

#define LEDS_moonlander_right( \
  l65, l61, l56, l51, l46, l41, l36, \
  l66, l62, l57, l52, l47, l42, l37, \
  l67, l63, l58, l53, l48, l43, l38, \
       l64, l59, l54, l49, l44, l39, \
     l71,   l60, l55, l50, l45, l40, \
  l70, l69, l68 \
) { \
  C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, \
  C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, C__, \
  l36, l37, l38, l39, l40, l41, l42, l43, l44, l45, l46, l47, l48, l49, l50, l51, l52, l53, l54, l55, \
  l56, l57, l58, l59, l60, l61, l62, l63, l64, l65, l66, l67, l68, l69, l70, l71 }
// clang-format on
// }}}

// clang-format off
const layer_led_config_t PROGMEM ledmap[L_MAX] = {
  /* template
   * usually the colors will be provided by one of the convenience defs
  [L_] = { .mode = LM_BOTH, .leds = 0b111, .colors = {}, },
  */

  [L_DV] = { .mode = LM_BOTH, .leds = 0b000, .colors = LEDS_moonlander_mirrored( // {{{
    C_SU_4, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_4,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_4,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_4,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2,
    C_SU_4, C_SU_4, C_SU_4, C_SU_3, C_SU_3,     C_SU_5,
                                    C_SU_5, C_SU_5, C_SU_5
  ), }, // }}}

  [L_QT] = { .mode = LM_BOTH, .leds = 0b000, .colors = LEDS_moonlander_mirrored( // {{{
    C_DS_4, C_DS_3, C_DS_3, C_DS_3, C_DS_3, C_DS_3, C_DS_4,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_4,
    C_DS_4, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_2, C_DS_4,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2,
    C_DS_4, C_DS_4, C_DS_4, C_DS_3, C_DS_3,     C_DS_5,
                                    C_DS_5, C_DS_5, C_DS_5
  ), }, // }}}

  [L_SHV] = { .mode = LM_BOTH, .leds = 0b010, .colors = LEDS_moonlander_both( // {{{
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_4,   C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_4,   C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2,
    C_DS_4, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_2, C_DS_4,   C_DS_4, C_DS_2, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_2,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2,                   C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2,
    C_DS_4, C_DS_4, C_DS_4, C_DS_3, C_DS_3,     C_DS_5,           C_DS_5,     C_DS_4, C_DS_4, C_DS_4, C_DS_4, C_DS_4,
                                    C_DS_5, C_DS_5, C_DS_5,   C_DS_5, C_DS_5, C_DS_5
  ), }, // }}}

  [L_OH] = { .mode = LM_BOTH, .leds = 0b100, .colors = LEDS_moonlander_mirrored( // {{{
    C_TO_4, C_TO_3, C_TO_3, C_TO_3, C_TO_3, C_TO_3, C_TO_4,
    C_TO_4, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_4,
    C_TO_4, C_TO_1, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_TO_4,
    C_TO_4, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2,
    C_TO_4, C_TO_4, C_TO_4, C_TO_4, C_TO_4,     C_TO_5,
                                    C_TO_5, C_TO_5, C_TO_5
  ), }, // }}}

  [L_OHA] = { .mode = LM_BOTH, .leds = 0b100, .colors = LEDS_moonlander_mirrored( // {{{
    C_TO_4, C_TO_3, C_TO_3, C_TO_3, C_TO_3, C_TO_3, C_TO_4,
    C_TO_4, C_TO_3, C_TO_3, C_TO_3, C_TO_2, C_TO_2, C_TO_4,
    C_TO_4, C_TO_1, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_TO_4,
    C_TO_4, C_TO_3, C_TO_2, C_TO_2, C_TO_2, C_TO_2,
    C_TO_4, C_TO_4, C_TO_4, C_TO_4, C_TO_4,     C_TO_5,
                                    C_TO_5, C_TO_5, C_TO_5
  ), }, // }}}

  [L_ST] = { .mode = LM_BOTH, .leds = 0b010, .colors = LEDS_moonlander_both( // {{{
    C_MA_4, C_____, C_____, C_____, C_____, C_____, C_MA_5,   C_MA_5, C_____, C_____, C_____, C_____, C_____, C_MA_4,
    C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_____,   C_____, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3,
    C_MA_4, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_2, C_____,   C_____, C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_1,
    C_MA_4, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_2,                   C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_1,
    C_MA_5, C_MA_3, C_MA_3, C_MA_3, C_MA_3,     C_MA_5,           C_MA_5,     C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_5,
                                    C_MA_1, C_MA_1, C_MA_4,   C_MA_4, C_MA_1, C_MA_1
  ), }, // }}}

  [L_O_ST] = { .mode = LM_NONE, .leds = 0, .colors = {}, },

  [L_GAME] = { .mode = LM_LEFT, .leds = 0b100, .colors = LEDS_moonlander_left( // {{{
    C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_5,
    C_RU_2, C_RU_2, C_RU_2, C_RU_1, C_RU_2, C_RU_2, C_RU_3,
    C_RU_4, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,
    C_RU_4, C_RU_2, C_RU_2, C_RU_2, C_RU_2, C_RU_2,
    C_RU_4, C_RU_2, C_RU_3, C_RU_3, C_RU_3,     C_RU_5,
                                    C_RU_2, C_RU_4, C_RU_4
  ), }, // }}}

  [L_G_KB] = { .mode = LM_LEFT, .leds = 0b100, .colors = LEDS_moonlander_left( // {{{
    C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_5,
    C_RU_2, C_RU_2, C_RU_2, C_RU_1, C_RU_2, C_RU_2, C_RU_3,
    C_RU_4, C_RU_4, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,
    C_RU_4, C_RU_2, C_RU_2, C_RU_2, C_____, C_RU_1,
    C_RU_4, C_RU_2, C_RU_3, C_RU_3, C_RU_3,     C_RU_5,
                                    C_RU_2, C_RU_5, C_RU_5
  ), }, // }}}

  [L_G_HB] = { .mode = LM_BOTH, .leds = 0b100, .colors = LEDS_moonlander_both( // {{{
    C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_5,   C_RU_5, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3,
    C_RU_2, C_RU_2, C_RU_2, C_RU_1, C_RU_2, C_RU_2, C_RU_3,   C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,
    C_RU_4, C_RU_4, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,   C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_4,
    C_RU_4, C_RU_2, C_____, C_____, C_____, C_RU_2,                   C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_1, C_RU_4,
    C_RU_4, C_____, C_RU_3, C_RU_3, C_RU_3,     C_RU_5,           C_RU_5,     C_RU_3, C_RU_3, C_RU_3, C_RU_4, C_RU_4,
                                    C_RU_2, C_RU_1, C_RU_2,   C_RU_2, C_RU_1, C_RU_2
  ), }, // }}}

  [L_G_K1] = { .mode = LM_LEFT, .leds = 0b100, .colors = LEDS_moonlander_left( // {{{
    C_RU_4, C_RU_2, C_RU_2, C_RU_2, C_RU_2, C_RU_2, C_RU_5,
    C_RU_4, C_RU_1, C_RU_1, C_RU_1, C_RU_1, C_RU_1, C_RU_2,
    C_RU_4, C_RU_1, C_RU_1, C_RU_1, C_RU_1, C_RU_1, C_RU_2,
    C_RU_4, C_RU_1, C_RU_1, C_RU_1, C_RU_1, C_RU_1,
    C_RU_4, C_RU_4, C_RU_4, C_RU_4, C_RU_4,     C_RU_5,
                                    C_____, C_____, C_____
  ), }, // }}}

  [L_G_K2] = { .mode = LM_LEFT, .leds = 0b100, .colors = LEDS_moonlander_left( // {{{
    C_RU_4, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_5,
    C_RU_4, C_RU_2, C_RU_2, C_RU_2, C_RU_1, C_RU_1, C_RU_3,
    C_RU_4, C_RU_1, C_RU_1, C_RU_1, C_RU_1, C_RU_1, C_RU_3,
    C_RU_4, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_1,
    C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3,     C_RU_5,
                                    C_____, C_____, C_____
  ), }, // }}}

  [L_G_NU] = { .mode = LM_RIGHT, .leds = 0, .colors = LEDS_moonlander_right( // {{{
    C_RU_5, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3,
    C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,
    C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_4,
            C_____, C_RU_1, C_RU_1, C_RU_1, C_____, C_RU_4,
        C_RU_5,     C_RU_3, C_RU_3, C_RU_3, C_RU_4, C_RU_4,
    C_RU_1, C_RU_2, C_RU_1
  ), }, // }}}

  [L_O_GA] = { .mode = LM_NONE, .leds = 0, .colors = {}, },

  [L_MS] = { .mode = LM_BOTH, .leds = 0b100, .colors = LEDS_moonlander_mirrored( // {{{
    C_SO_4, C_____, C_SO_2, C_SO_2, C_SO_2, C_____, C_SO_4,
    C_SO_4, C_SO_3, C_SO_2, C_SO_1, C_SO_2, C_SO_2, C_SO_4,
    C_SO_4, C_SO_3, C_SO_1, C_SO_1, C_SO_1, C_SO_2, C_SO_4,
    C_SO_4, C_SO_3, C_SO_2, C_____, C_SO_2, C_____,
    C_SO_4, C_SO_4, C_SO_4, C_SO_3, C_SO_3,     C_SO_5,
                                    C_SO_1, C_SO_1, C_SO_1
  ), }, // }}}

  [L_O_MS] = { .mode = LM_RIGHT, .leds = 0, .colors = LEDS_moonlander_right( // {{{
    C_SO_4, C_____, C_____, C_____, C_____, C_____, C_SO_4,
    C_SO_4, C_____, C_____, C_SO_2, C_____, C_____, C_SO_4,
    C_SO_4, C_____, C_SO_2, C_SO_2, C_SO_2, C_____, C_SO_4,
            C_____, C_____, C_____, C_____, C_____, C_SO_4,
         C_SO_5,    C_SO_3, C_SO_3, C_SO_4, C_SO_4, C_SO_4,
    C_SO_3, C_SO_3, C_SO_3
  ), }, // }}}

  [L_SYM] = { .mode = LM_BOTH, .leds = 0b100, .colors = LEDS_moonlander_mirrored( // {{{
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_____, C_____, C_SU_4,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_4,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_____,
    C_SU_4, C_SU_4, C_SU_4, C_SU_4, C_SU_4,     C_SU_5,
                                    C_____, C_____, C_____
  ), }, // }}}

  [L_O_SY] = { .mode = LM_BOTH, .leds = 0b100, .colors = LEDS_moonlander_both( // {{{
    C_SU_4, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_4,   C_SU_4, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_____, C_____, C_SU_4,   C_SU_4, C_____, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_3,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_4,   C_SU_4, C_____, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_4,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_____,                   C_____, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_4,
    C_SU_4, C_SU_4, C_SU_4, C_SU_4, C_SU_4,     C_SU_5,           C_SU_5,     C_SU_3, C_SU_3, C_SU_4, C_SU_4, C_SU_4,
                                    C_____, C_____, C_____,   C_____, C_____, C_____
  ), }, // }}}

  [L_NUM] = { .mode = LM_BOTH, .leds = 0b100, .colors = LEDS_moonlander_both( // {{{
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_SU_4,   C_SU_4, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_4,   C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_4,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_4,   C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_4,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_1,                   C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_4,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2,     C_SU_5,           C_SU_5,     C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_4,
                                    C_____, C_____, C_____,   C_____, C_____, C_____
  ), }, // }}}

  [L_O_NU] = { .mode = LM_BOTH, .leds = 0b100, .colors = LEDS_moonlander_both( // {{{
    C_SU_4, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_4,   C_SU_4, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3,
    C_SU_4, C_____, C_SU_2, C_SU_2, C_____, C_____, C_SU_4,   C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_3,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_4,   C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_4,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_1,                   C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_4,
    C_SU_4, C_SU_4, C_SU_4, C_SU_4, C_SU_4,     C_SU_5,           C_SU_5,     C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_4,
                                    C_____, C_____, C_____,   C_____, C_____, C_____
  ), }, // }}}

  [L_NAV] = { .mode = LM_BOTH, .leds = 0b100, .colors = LEDS_moonlander_mirrored( // {{{
    C_SU_4, C_RU_1, C_____, C_RU_3, C_____, C_RU_3, C_SU_5,
    C_SU_4, C_SU_2, C_SU_2, C_SU_1, C_SU_2, C_SU_2, C_RU_1,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_RU_1,
    C_SU_4, C_SU_2, C_SU_2, C_____, C_SU_2, C_SU_1,
    C_SU_4, C_SU_4, C_SU_4, C_SU_4, C_SU_4,     C_SU_5,
                                    C_____, C_____, C_____
  ), }, // }}}

  [L_FUNC] = { .mode = LM_BOTH, .leds = 0b101, .colors = LEDS_moonlander_mirrored( // {{{
    C_SU_3, C_____, C_____, C_____, C_____, C_____, C_SU_3,
    C_SU_3, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_3,
    C_SU_3, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_3,
    C_SU_3, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____,
    C_SU_3, C_SU_3, C_MA_3, C_MA_3, C_MA_3,     C_SU_5,
                                    C_____, C_____, C_____
  ), }, // }}}

  [L_SHRT] = { .mode = LM_BOTH, .leds = 0b101, .colors = LEDS_moonlander_mirrored( // {{{
    C_____, C_____, C_____, C_MA_3, C_MA_2, C_MA_2, C_____,
    C_____, C_SU_1, C_SU_2, C_MA_1, C_MA_2, C_MA_2, C_____,
    C_SU_5, C_SU_2, C_____, C_MA_1, C_MA_3, C_MA_3, C_____,
    C_SU_5, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_1,
    C_____, C_____, C_____, C_____, C_____,     C_SU_5,
                                    C_____, C_____, C_____
  ), }, // }}}

  [L_SYS] = { .mode = LM_BOTH, .leds = 0b011, .colors = LEDS_moonlander_mirrored( // {{{
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_SU_1, C_____,
    C_____, C_SU_3, C_SU_4, C_SU_4, C_SU_4, C_SU_2, C_____,
    C_____, C_____, C_____, C_____, C_SU_3, C_SU_2,
    C_____, C_____, C_____, C_____, C_____,     C_SU_5,
                                    C_____, C_____, C_____
  ), }, // }}}

  [L_WEB] = { .mode = LM_BOTH, .leds = 0b101, .colors = LEDS_moonlander_mirrored( // {{{
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_SU_1, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_____,
    C_____, C_____, C_____, C_____, C_SU_2, C_SU_2,
    C_____, C_____, C_____, C_____, C_____,     C_SU_5,
                                    C_____, C_____, C_____
  ), }, // }}}

  [L_LED] = { .mode = LM_BOTH, .leds = 0b101, .colors = LEDS_moonlander_mirrored( // {{{
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_DS_2, C_DS_2, C_DS_1, C_DS_1, C_____, C_____,
    C_____, C_DS_2, C_DS_2, C_DS_1, C_DS_3, C_____, C_____,
    C_SU_4, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____,     C_SU_5,
                                    C_____, C_____, C_____
  ), }, // }}}

  [L_HUB] = { .mode = LM_BOTH, .leds = 0b111, .colors = LEDS_moonlander_mirrored( // {{{
    C_SU_1, C_____, C_SU_3, C_SU_3, C_SU_3, C_____, C_SU_5,
    C_____, C_____, C_SU_2, C_SU_2, C_SU_2, C_____, C_____,
    C_____, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____,
    C_____, C_____, C_SU_2, C_____, C_SU_2, C_____,
    C_SU_4, C_SU_4, C_____, C_____, C_____,     C_SU_5,
                                    C_____, C_____, C_____
  ), }, // }}}
};
// clang-format on

void set_led_color(int led, color_t col) { // {{{
  HSV hsv = {
      .h = pgm_read_byte(&color_map[col][0]),
      .s = pgm_read_byte(&color_map[col][1]),
      .v = pgm_read_byte(&color_map[col][2]),
  };
  if (!hsv.h && !hsv.s && !hsv.v) {
    rgb_matrix_set_color(led, 0, 0, 0);
  } else {
    RGB rgb = hsv_to_rgb(hsv);
    float f = (float)rgb_matrix_get_val() / UINT8_MAX;
    rgb_matrix_set_color(led, f * rgb.r, f * rgb.g, f * rgb.b);
  }
} // }}}

void set_led_colors(int first_led, int last_led, const color_t *colors) { // {{{
  for (int led_ind = first_led, color_ind = 0; led_ind <= last_led; led_ind++, color_ind++) {
    set_led_color(led_ind, colors[color_ind]);
  }
} // }}}

bool rgb_matrix_indicators_user(void) { // {{{
  if (rgb_matrix_get_suspend_state() || keyboard_config.disable_layer_led)
    return false;

  int first_l_led = 0;
  int total_leds = RGB_MATRIX_LED_COUNT;
  int last_l_led = (total_leds / 2) - 1;
  int first_r_led = total_leds / 2;
  int last_r_led = total_leds - 1;

  bool left_leds_set = false, right_leds_set = false;
  layer_state_t layers = layer_state | default_layer_state;

  for (int8_t layer = MAX_LAYER - 1; layer >= 0; layer--) {
    if (layers & (1UL << layer)) {
      const layer_led_config_t *led_config = &ledmap[layer];
      led_mode_t mode = led_config->mode;

      if (mode == LM_NONE)
        continue;

      if (!left_leds_set && (mode == LM_BOTH || mode == LM_LEFT)) {
        set_led_colors(first_l_led, last_l_led, led_config->colors);
        left_leds_set = true;
      }

      if (!right_leds_set && (mode == LM_BOTH || mode == LM_RIGHT)) {
        set_led_colors(first_r_led, last_r_led, led_config->colors + first_r_led);
        right_leds_set = true;
      }

      if (right_leds_set && left_leds_set)
        return false;
    }
  }

  if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
    rgb_matrix_set_color_all(0, 0, 0);
  }

  return false;
} // }}}

void keyboard_post_init_user(void) {
  rgb_matrix_enable_noeeprom();
  steno_set_mode(STENO_MODE_GEMINI);
  default_layer_set(1 << L_DV);
  layer_move(L_DV);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) { // {{{
  switch (keycode) {
  case RGB_TOG:
    if (record->event.pressed) {
      switch (rgb_matrix_get_flags()) {
      case LED_FLAG_ALL:
        rgb_matrix_set_flags(LED_FLAG_NONE);
        keyboard_config.rgb_matrix_enable = false;
        rgb_matrix_set_color_all(0, 0, 0);
        break;
      default:
        rgb_matrix_set_flags(LED_FLAG_ALL);
        keyboard_config.rgb_matrix_enable = true;
        break;
      }
      eeconfig_update_kb(keyboard_config.raw);
    }
    return false;

  case RGB_TLC:
    if (record->event.pressed) {
      keyboard_config.disable_layer_led ^= 1;
      if (keyboard_config.disable_layer_led)
        rgb_matrix_set_color_all(0, 0, 0);
      eeconfig_update_kb(keyboard_config.raw);
    }
    break;

  case RGB_SLD:
    if (record->event.pressed) {
      rgblight_mode(1);
    }
    return false;

  case TO_ST2:
    if (record->event.pressed) {
      layer_move(L_ST);
      layer_on(L_O_ST);
    }
    return false;

  case DF_ST2:
    if (record->event.pressed) {
      default_layer_set(1 << L_ST);
      layer_on(L_O_ST);
    }
    return false;
  }

  return true;
} // }}}

layer_state_t update_bi_layer_state(layer_state_t state, uint8_t source, uint8_t dest) {
  layer_state_t s_mask = (layer_state_t)1 << source;
  layer_state_t d_mask = (layer_state_t)1 << dest;
  bool s_active = (state & s_mask) == s_mask;
  return s_active ? (state | d_mask) : (state & ~d_mask);
}

// when we're detecting whether OH mode is on, we only care about layers in this mask
// this is because, if DV or QT are on, we're not in OH mode
static layer_state_t oh_detection_mask = (1 << L_DV) | (1 << L_QT) | (1 << L_OH);
static layer_state_t oh_mask = (1 << L_OH);

// when we're detecting whether GAME mode is on, we check both layers
static layer_state_t game_detection_mask = (1 << L_GAME) | (1 << L_G_KB) | (1 << L_G_HB);
static layer_state_t game_overlay_mask = (1 << L_O_GA);
static layer_state_t gnum_detection_mask = (1 << L_GAME) | (1 << L_G_KB);
static layer_state_t gnum_anti_detection_mask = (1 << L_DV);
static layer_state_t gnum_mask = (1 << L_G_NU);

layer_state_t layer_state_set_user(layer_state_t state) { // {{{
  if ((state & oh_detection_mask) == oh_mask) {
    // if we're in one-handed mode, we can use tri layer states
    state = update_tri_layer_state(state, L_OHA, L_NAV, L_NUM);  // number keys
    state = update_tri_layer_state(state, L_NAV, L_SYM, L_FUNC); // function keys
  } else {
    // if we're not in one-handed mode, we can add overlays to some modes
    state = update_bi_layer_state(state, L_SYM, L_O_SY);
    state = update_bi_layer_state(state, L_NUM, L_O_NU);
    state = update_bi_layer_state(state, L_MS, L_O_MS);
  }

  // always activate the gaming overlay if needed
  if ((state & game_detection_mask) != 0) {
    state = state | game_overlay_mask;
  } else {
    state = state & ~game_overlay_mask;
  }

  // always activate the gaming numpad if needed
  if ((state & gnum_detection_mask) != 0 && (state & gnum_anti_detection_mask) == 0) {
    state = state | gnum_mask;
  } else {
    state = state & ~gnum_mask;
  }

  for (int8_t layer = MAX_LAYER - 1; layer >= 0; layer--) {
    if (!((state | default_layer_state) & (1UL << layer)))
      continue;
    if (ledmap[layer].mode == LM_NONE || ledmap[layer].mode == LM_RIGHT)
      continue;
    uint8_t leds = ledmap[layer].leds;
    ML_LED_4((leds & 0b100) != 0);
    ML_LED_5((leds & 0b010) != 0);
    ML_LED_6((leds & 0b001) != 0);
    break;
  }

  return state;
} // }}}

bool led_update_user(led_t led_state) { // {{{
  ML_LED_1(led_state.caps_lock);
  ML_LED_2(!led_state.num_lock);
  ML_LED_3(led_state.scroll_lock);
  if (led_state.compose) {
    ML_LED_1(true);
    ML_LED_3(true);
  }
  if (led_state.kana) {
    ML_LED_2(true);
    ML_LED_3(true);
  }
  return true;
} // }}}

/* vim: set foldmethod=marker shiftwidth=2 : */
