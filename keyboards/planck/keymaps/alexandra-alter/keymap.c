#include QMK_KEYBOARD_H
#include "version.h"
#include "shavian.h"

extern keyboard_config_t keyboard_config;

typedef enum layer_t {
  L_BASE, // base
  L_GA,   // gaming
  L_DV,   // dvorak
  L_QT,   // qwerty
  L_SHV,  // shavian
  L_OH,   // one-handed
  L_OHA,  // one-handed alt
  L_ST,   // stenotype
  L_STC,  // stenotype comfort
  L_MS,   // mouse
  L_NP,   // number pad
  L_NAV,  // navigation
  L_LWR,  // lower
  L_RAI,  // raise
  L_ADJ,  // adjust
  L_GLWR, // gaming lower
  L_GRAI, // gaming raise
  L_GADJ, // gaming adjust
  L_HUB,  // hub
  L_MAX,
} layer_t;

typedef enum custom_keycode_t { // {{{
  LED_CYC = SAFE_RANGE,         // cycle led level
  RGB_SLD,                      // pause LED animation
  G_SPC,                        // gaming space bar
  G_S_CY,                       // gaming space bar cycle
} custom_keycode_t;             // }}}

// {{{ unicode defs
typedef enum unicode_names {
  SHAVIAN_UNICODE_NAMES()
} unicode_names;

const uint32_t PROGMEM unicode_map[] = {
  SHAVIAN_UNICODE_MAP()
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
#define RGB_TLC TOGGLE_LAYER_COLOR

#define L1(kc) (LGUI_T(kc))
META_KEY(L1, KC_LGUI, KC_ESC);
#define L2(kc) (LCTL_T(kc))
META_KEY(L2, KC_LCTL, KC_BSPC);
#define L3(kc) (LSFT_T(kc))
META_KEY(L3, KC_LSFT, KC_TAB);
#define MA_L4 (MO(L_HUB))
#define MA_L5 (KC_LGUI)
#define MA_L6 (KC_LCTL)
#define MA_L7 (KC_LALT)

#define SPC(kc) (LT(L_NAV, kc))
META_KEY(SPC, MO(L_NAV), KC_SPC);
#define SPC_SFT (KC_LSFT)
#define LWR(kc) (LT(L_LWR, kc))
META_KEY(LWR, MO(L_LWR), KC_LBRC);
#define RAI(kc) (LT(L_RAI, kc))
META_KEY(RAI, MO(L_RAI), KC_RBRC);

#define R1(kc) (RGUI_T(kc))
META_KEY(R1, KC_RGUI, KC_TAB);
#define R2(kc) (RCTL_T(kc))
META_KEY(R2, KC_RCTL, KC_DEL);
#define R3(kc) (RSFT_T(kc))
META_KEY(R3, KC_RSFT, KC_ENT);
#define R4(kc) (RALT_T(kc))
META_KEY(R4, KC_RALT, KC_RIGHT);
#define R5(kc) (RGUI_T(kc))
META_KEY(R5, KC_RGUI, KC_UP);
#define R6(kc) (RCTL_T(kc))
META_KEY(R6, KC_RCTL, KC_DOWN);
#define R7(kc) (LALT_T(kc))
META_KEY(R7, KC_LALT, KC_LEFT);

#define KA_R4A (R4(KC_END))
#define KA_R5A (R5(KC_PGUP))
#define KA_R6A (R6(KC_PGDN))
#define KA_R7A (R7(KC_HOME))

#define KA_OSPC (LT(L_OHA, KC_SPC))
#define KA_OLWR (LT(L_LWR, KC_TAB))
#define KA_ORAI (LT(L_NAV, KC_ENT))

#define KA_GLWR (MO(L_GLWR))
#define KA_GRAI (MO(L_GRAI))

#define MO_MS (MO(L_MS))
// }}}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_planck_grid( // {{{ base
    KA_L1,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KA_R1,
    KA_L2,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KA_R2,
    KA_L3,   KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KA_R3,
    MA_L4,   MA_L5,   MA_L6,   MA_L7,   KA_LWR,  KA_SPC,  KA_SPC,  KA_RAI,  KA_R7,   KA_R6,   KA_R5,   KA_R4
  ), // }}}

  [L_DV] = LAYOUT_planck_grid( // {{{ dvorak
    KA_L1,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KA_R1,
    KA_L2,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KA_R2,
    KA_L3,   KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KA_R3,
    MA_L4,   MA_L5,   MA_L6,   MA_L7,   KA_LWR,  KA_SPC,  KA_SPC,  KA_RAI,  KA_R7,   KA_R6,   KA_R5,   KA_R4
  ), // }}}

  [L_QT] = LAYOUT_planck_grid( // {{{ qwerty
    KA_L1,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KA_R1,
    KA_L2,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KA_R2,
    KA_L3,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KA_R3,
    MA_L4,   MA_L5,   MA_L6,   MA_L7,   KA_LWR,  KA_SPC,  KA_SPC,  KA_RAI,  KA_R7,   KA_R6,   KA_R5,   KA_R4
  ), // }}}

  [L_SHV] = LAYOUT_planck_grid( // {{{ shavian
    KA_L1,   SHV_1_0, SHV_1_1, SHV_1_2, SHV_1_3, SHV_1_4, SHV_1_5, SHV_1_6, SHV_1_7, SHV_1_8, SHV_1_9, KA_R1,
    KA_L2,   SHV_2_0, SHV_2_1, SHV_2_2, SHV_2_3, SHV_2_4, SHV_2_5, SHV_2_6, SHV_2_7, SHV_2_8, SHV_2_9, KA_R2,
    KA_L3,   SHV_3_0, SHV_3_1, SHV_3_2, SHV_3_3, SHV_3_4, SHV_3_5, SHV_3_6, SHV_3_7, SHV_3_8, SHV_3_9, KA_R3,
    MA_L4,   MA_L5,   MA_L6,   MA_L7,   KA_LWR,  KA_SPC,  KA_SPC,  KA_RAI,  KA_R7,   KA_R6,   KA_R5,   KA_R4
  ), // }}}

  [L_OH] = LAYOUT_planck_grid( // {{{ one-handed
    KA_L1,   KC_L,    KC_R,    KC_C,    KC_G,    KC_F,    MA_R5,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R1,
    KA_L2,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    MA_R6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R2,
    KA_L3,   KC_S,    KC_N,    KC_T,    KC_H,    KC_D,    MA_R7,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R3,
    MA_L4,   MA_L5,   MA_L6,   MA_L7,   KA_OLWR, KA_OSPC, KA_OSPC, KA_ORAI, KA_R7,   KA_R6,   KA_R5,   KA_R4
  ), // }}}

  [L_OHA] = LAYOUT_planck_grid( // {{{ one-handed alt
    _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_Z,    KC_V,    KC_W,    KC_M,    KC_B,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KA_R7A,  KA_R6A,  KA_R5A,  KA_R4A
  ), // }}}

  [L_ST] = LAYOUT_planck_grid( // {{{ stenotype
    STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
    STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    STN_FN,  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    _______, STN_PWR, STN_RE1, STN_A,   STN_O,   MO_MS,   MO_MS,   STN_E,   STN_U,   STN_RE2, STN_PWR, MO_MS
  ), // }}}

  [L_STC] = LAYOUT_planck_grid( // {{{ stenotype comfort
    STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
    STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_FN,  STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_FN,  STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    _______, STN_PWR, STN_RE1, STN_A,   STN_O,   STN_E,   STN_E,   STN_U,   STN_RE2, STN_RE2, STN_PWR, MO_MS
  ), // }}}

  [L_MS] = LAYOUT_planck_grid( // {{{ mouse
    KA_L1,   KC_ACL0, KC_BTN4, KC_MS_U, KC_BTN5, KC_WH_U, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, KC_BTN6, KA_L1,
    KA_L2,   KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, KC_BTN7, KA_L2,
    KA_L3,   KC_ACL2, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX, XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN8, KA_L3,
    MA_L4,   MA_L5,   MA_L6,   MA_L7,   KC_BTN2, KC_BTN1, KC_BTN1, KC_BTN3, KA_R7,   KA_R6,   KA_R5,   KA_R4
  ), // }}}

  [L_NP] = LAYOUT_planck_grid( // {{{ number pad
    KA_L1,   XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KA_L1,
    KA_L2,   XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KA_L2,
    KA_L3,   XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PENT, KA_L3,
    MA_L4,   MA_L5,   MA_L6,   MA_L7,   KA_LWR,  KA_SPC,  KA_SPC,  KA_RAI,  KA_R7,   KA_R6,   KA_R5,   KA_R4
  ), // }}}

  [L_GA] = LAYOUT_planck_grid( // {{{ gaming
    KC_ESC,  KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_GRV,  KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PMNS,
    MA_L2,   KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_BSLS, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    MA_L3,   KC_DEL,  KC_ENT,  KC_MINS, KC_EQL,  KC_SLSH, KC_LBRC, KC_RBRC, KC_P7,   KC_P8,   KC_P9,   KC_PENT,
    _______, MA_L5,   MA_L6,   MA_L7,   KA_GLWR, G_SPC,   G_SPC,   KA_GRAI, KC_P0,   XXXXXXX, KC_PDOT, XXXXXXX
  ), // }}}

  [L_GLWR] = LAYOUT_planck_grid( // {{{ gaming lower
    _______, KC_L,    KC_R,    KC_C,    KC_G,    KC_F,    XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX,
    _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,
    _______, KC_S,    KC_N,    KC_T,    KC_H,    KC_D,    XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,
    _______, _______, _______, _______, _______, _______, _______, _______, KA_R7,   KA_R6,   KA_R5,   KA_R4
  ), // }}}

  [L_GRAI] = LAYOUT_planck_grid( // {{{ gaming raise
    _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,
    _______, KC_Z,    KC_V,    KC_W,    KC_M,    KC_B,    XXXXXXX, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,
    _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    XXXXXXX, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, KA_R7,   KA_R6,   KA_R5,   KA_R4
  ), // }}}

  [L_GADJ] = LAYOUT_planck_grid( // {{{ gaming adjust
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, G_S_CY,  XXXXXXX, KC_NUM,  XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, KA_R7,   KA_R6,   KA_R5,   KA_R4
  ), // }}}

  [L_NAV] = LAYOUT_planck_grid( // {{{ navigation
    KA_L1,   KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_BTN3, KC_BTN4, KC_MS_U, KC_BTN5, KC_WH_U, KA_R1,
    KA_L2,   KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KA_R2,
    KA_L3,   KC_ENT,  KC_BSPC, XXXXXXX, KC_DEL,  KC_APP,  KC_BTN2, KC_WH_L, XXXXXXX, KC_WH_R, KC_ACL2, KA_R3,
    MA_L4,   MA_L5,   MA_L6,   MA_L7,   KA_LWR,  _______, _______, KA_RAI,  KA_R7A,  KA_R6A,  KA_R5A,  KA_R4A
  ), // }}}

  [L_LWR] = LAYOUT_planck_grid( // {{{ lower
    _______, KC_QUOT, KC_COMM, KC_DOT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, _______,
    _______, KC_GRV,  KC_MINS, KC_EQL,  KC_SLSH, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
    MA_L3,   KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, KC_RALT, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,    MA_R3,
    _______, _______, _______, _______, _______, KA_SPC,  KA_SPC,  KA_RAI,  KA_R7A,  KA_R6A,  KA_R5A,  KA_R4A
  ), // }}}

  [L_RAI] = LAYOUT_planck_grid( // {{{ raise
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_SYRQ, XXXXXXX, XXXXXXX, KC_CAPS, KC_SCRL, XXXXXXX, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM,  KC_PSCR, _______,
    MA_L3,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_BRK,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MA_R3,
    _______, _______, _______, _______, KA_LWR,  KA_SPC,  KA_SPC,  _______, KA_R7A,  KA_R6A,  KA_R5A,  KA_R4A
  ), // }}}

  [L_ADJ] = LAYOUT_planck_grid( // {{{ adjust
    _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  XXXXXXX, KC_BRIU, KC_VOLU, KC_MPRV, KC_MNXT, KC_MSEL, KC_PWR,
    _______, KC_F17,  KC_F18,  KC_F19,  KC_F20,  XXXXXXX, KC_BRID, KC_VOLD, KC_MSTP, KC_MPLY, XXXXXXX, KC_SLEP,
    _______, KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX, XXXXXXX, KC_MUTE, KC_MRWD, KC_MFFD, XXXXXXX, KC_WAKE,
    _______, _______, _______, _______, _______, KA_SPC,  KA_SPC,  _______, KA_R7A,  KA_R6A,  KA_R5A,  KA_R4A
  ), // }}}

  [L_HUB] = LAYOUT_planck_grid( // {{{ hub
    XXXXXXX,  XXXXXXX,  DF(L_SHV),XXXXXXX,  DF(L_NP), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  LED_CYC,  QK_BOOT,
    XXXXXXX,  DF(L_GA), DF(L_DV), DF(L_ST), DF(L_OH), XXXXXXX,  XXXXXXX,  RGB_TLC,  RGB_TOG,  RGB_SAI,  RGB_HUI,  XXXXXXX,
    MA_L3,    XXXXXXX,  DF(L_QT), DF(L_STC),DF(L_MS), XXXXXXX,  XXXXXXX,  RGB_SLD,  RGB_MOD,  RGB_SPI,  RGB_VAI,  MA_R3,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  AU_TOGG,  NK_TOGG,  XXXXXXX,  XXXXXXX
  ), // }}}
};
// clang-format on

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

const uint8_t PROGMEM color_map[C_MAX][3] = { // {{{
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

// clang-format off
const color_t PROGMEM ledmap[L_MAX][RGB_MATRIX_LED_COUNT] = {
  [L_BASE] = { // {{{
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_DV] = { // {{{
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_4,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_4,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_QT] = { // {{{
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_4,
    C_DS_4, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_2, C_DS_2, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_4,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_4,
    C_DS_5, C_DS_4, C_DS_4, C_DS_4, C_DS_5,     C_DS_5,     C_DS_5, C_DS_4, C_DS_4, C_DS_4, C_DS_4
  }, // }}}

  [L_OH] = { // {{{
    C_TO_4, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_4, C_____, C_____, C_____, C_____, C_TO_4,
    C_TO_4, C_TO_1, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_TO_4, C_____, C_____, C_____, C_____, C_TO_4,
    C_TO_4, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_4, C_____, C_____, C_____, C_____, C_TO_4,
    C_TO_5, C_TO_4, C_TO_4, C_TO_4, C_TO_5,     C_TO_5,     C_TO_5, C_TO_4, C_TO_4, C_TO_4, C_TO_4
  }, // }}}

  [L_OHA] = { // {{{
    C_TO_4, C_TO_3, C_TO_3, C_TO_3, C_TO_2, C_TO_2, C_TO_4, C_____, C_____, C_____, C_____, C_TO_4,
    C_TO_4, C_TO_1, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_TO_4, C_____, C_____, C_____, C_____, C_TO_4,
    C_TO_4, C_TO_3, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_4, C_____, C_____, C_____, C_____, C_TO_4,
    C_TO_5, C_TO_4, C_TO_4, C_TO_4, C_TO_5,     C_TO_5,     C_TO_5, C_TO_2, C_TO_2, C_TO_2, C_TO_2
  }, // }}}

  [L_ST] = { // {{{
    C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3,
    C_MA_4, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_2, C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_1,
    C_MA_4, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_2, C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_1,
    C_MA_5, C_MA_4, C_MA_3, C_MA_1, C_MA_1,     C_MA_5,     C_MA_1, C_MA_1, C_MA_3, C_MA_4, C_MA_5
  }, // }}}

  [L_STC] = { // {{{
    C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3,
    C_MA_4, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_2, C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_1,
    C_MA_4, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_2, C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_1,
    C_MA_5, C_MA_4, C_MA_3, C_MA_1, C_MA_1,     C_MA_5,     C_MA_1, C_MA_1, C_MA_3, C_MA_4, C_MA_5
  }, // }}}

  [L_GA] = { // {{{
    C_RU_2, C_RU_2, C_RU_2, C_RU_1, C_RU_2, C_RU_2, C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2,
    C_RU_4, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2,
    C_RU_4, C_RU_2, C_RU_2, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_1, C_RU_1, C_RU_1, C_RU_3,
    C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_5,     C_RU_2,     C_RU_5, C_RU_1, C_____, C_RU_1, C_____
  }, // }}}

  [L_GLWR] = { // {{{
    C_RU_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_____, C_____, C_RU_2, C_RU_2, C_RU_2, C_____,
    C_RU_4, C_TO_1, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_____, C_____, C_RU_2, C_RU_2, C_RU_2, C_____,
    C_RU_4, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_____, C_____, C_RU_2, C_RU_2, C_RU_2, C_RU_2,
    C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_5,     C_RU_2,     C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_4
  }, // }}}

  [L_GRAI] = { // {{{
    C_RU_2, C_TO_3, C_TO_3, C_TO_3, C_TO_2, C_TO_2, C_____, C_____, C_RU_3, C_RU_3, C_RU_3, C_RU_3,
    C_RU_4, C_TO_1, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_____, C_____, C_RU_3, C_RU_3, C_RU_3, C_RU_3,
    C_RU_4, C_TO_3, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_____, C_____, C_RU_3, C_RU_3, C_RU_3, C_RU_3,
    C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_5,     C_RU_2,     C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_4
  }, // }}}

  [L_GADJ] = { // {{{
    C_RU_2, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_RU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_RU_1, C_____, C_RU_1, C_____, C_____,
    C_RU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_5,     C_RU_2,     C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_4
  }, // }}}

  [L_MS] = { // {{{
    C_CC_4, C_CC_4, C_CC_2, C_CC_3, C_CC_2, C_CC_1, C_____, C_____, C_CC_1, C_____, C_CC_2, C_CC_4,
    C_CC_4, C_CC_4, C_CC_3, C_CC_3, C_CC_3, C_CC_1, C_____, C_CC_1, C_CC_1, C_CC_1, C_CC_2, C_CC_4,
    C_CC_4, C_CC_4, C_CC_1, C_____, C_CC_1, C_____, C_____, C_CC_4, C_CC_4, C_CC_4, C_CC_2, C_CC_4,
    C_CC_5, C_CC_4, C_CC_4, C_CC_4, C_CC_2,     C_CC_2,     C_CC_2, C_CC_4, C_CC_4, C_CC_4, C_CC_4
  }, // }}}

  [L_NP] = { // {{{
    C_SU_4, C_____, C_SU_1, C_SU_1, C_SU_1, C_____, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_SU_4,
    C_SU_4, C_____, C_SU_1, C_SU_1, C_SU_1, C_____, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_SU_4,
    C_SU_4, C_____, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_RU_1, C_RU_1, C_RU_1, C_RU_3, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_2, C_SU_2, C_SU_2, C_SU_2
  }, // }}}

  [L_NAV] = { // {{{
    C_SU_4, C_SU_3, C_SU_2, C_SU_1, C_SU_2, C_SU_2, C_CC_2, C_CC_2, C_CC_3, C_CC_2, C_CC_1, C_SU_4,
    C_SU_4, C_SU_3, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_CC_2, C_CC_3, C_CC_3, C_CC_3, C_CC_1, C_SU_4,
    C_SU_4, C_SU_3, C_SU_3, C_____, C_SU_3, C_SU_1, C_CC_2, C_CC_1, C_____, C_CC_1, C_CC_4, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_2, C_SU_2, C_SU_2, C_SU_2
  }, // }}}

  [L_LWR] = { // {{{
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_____, C_____, C_____, C_SU_3, C_SU_3, C_SU_3, C_____, C_SU_4,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_____, C_SU_3, C_SU_3, C_SU_3, C_____, C_SU_4,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_4, C_____, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_2, C_SU_2, C_SU_2, C_SU_2
  }, // }}}

  [L_RAI] = { // {{{
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_____, C_____, C_SU_2, C_SU_2, C_____, C_SU_4,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_____, C_____, C_____, C_SU_2, C_SU_2, C_SU_4,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_2, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_2, C_SU_2, C_SU_2, C_SU_2
  }, // }}}

  [L_ADJ] = { // {{{
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_RU_3, C_RU_2, C_RU_3, C_RU_3, C_RU_1, C_SU_1,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_____, C_SU_1,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_____, C_RU_1, C_RU_4, C_RU_4, C_____, C_SU_1,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_2, C_SU_2, C_SU_2, C_SU_2
  }, // }}}

  [L_HUB] = { // {{{
    C_____, C_____, C_____, C_____, C_SU_2, C_____, C_____, C_____, C_____, C_____, C_RU_3, C_SU_1,
    C_____, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_____, C_RU_1, C_RU_1, C_RU_2, C_RU_2, C_____,
    C_SU_3, C_____, C_SU_2, C_SU_2, C_SU_1, C_____, C_____, C_RU_3, C_RU_1, C_RU_2, C_RU_2, C_SU_3,
    C_SU_5, C_____, C_____, C_____, C_____,     C_____,     C_____, C_SU_1, C_SU_1, C_____, C_____
  }, // }}}
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

bool rgb_matrix_indicators_user(void) { // {{{
  if (rgb_matrix_get_suspend_state() || keyboard_config.disable_layer_led)
    return false;

  layer_state_t layers = layer_state | default_layer_state;
  uint8_t layer = get_highest_layer(layers);
  const color_t *colors = ledmap[layer];

  for (uint8_t i = 0; i <= RGB_MATRIX_LED_COUNT; i++)
    set_led_color(i, colors[i]);

  return false;
} // }}}

layer_state_t layer_state_set_user(layer_state_t state) { // {{{
  state = update_tri_layer_state(state, L_LWR, L_RAI, L_ADJ);
  state = update_tri_layer_state(state, L_GLWR, L_GRAI, L_GADJ);

  if (IS_LAYER_ON_STATE(state, L_LWR))
    planck_ez_left_led_on();
  else
    planck_ez_left_led_off();
  if (IS_LAYER_ON_STATE(state, L_RAI))
    planck_ez_right_led_on();
  else
    planck_ez_right_led_off();

  return state;
} // }}}

static uint16_t g_spc_kc = KC_SPC;
static uint16_t g_spc_last = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) { // {{{
  switch (keycode) {

  case LED_CYC:
    if (record->event.pressed) {
      keyboard_config.led_level = (keyboard_config.led_level + 1) % 4;
      planck_ez_right_led_level((uint8_t)keyboard_config.led_level * 255 / 4);
      planck_ez_left_led_level((uint8_t)keyboard_config.led_level * 255 / 4);
      layer_state_set_kb(layer_state);
    }
    return false;

  case RGB_SLD:
    if (record->event.pressed) {
      rgblight_mode(1);
    }
    return false;

  case G_SPC:
    if (record->event.pressed) {
      g_spc_last = g_spc_kc;
      register_code(g_spc_last);
    } else {
      if (g_spc_last != 0) {
        unregister_code(g_spc_last);
        g_spc_last = 0;
      }
    }
    return false;

  case G_S_CY:
    if (record->event.pressed) {
      if (g_spc_last != 0) {
        unregister_code(g_spc_last);
        g_spc_last = 0;
      }
      switch (g_spc_kc) {
      case KC_SPC:
        g_spc_kc = KC_UP;
        break;
      case KC_UP:
        g_spc_kc = KC_SPC;
        break;
      default:
        g_spc_kc = KC_SPC;
        break;
      }
    }
    return false;
  }

  return true;
} // }}}

layer_state_t default_layer_state_set_user(layer_state_t state) { // {{{
  layer_clear();

  return state;
} // }}}

void keyboard_post_init_user(void) { // {{{
  rgb_matrix_enable();
  steno_set_mode(STENO_MODE_GEMINI);
  default_layer_set(1 << L_DV);
  layer_clear();
} // }}}

/* vim: set foldmethod=marker shiftwidth=2 : */
