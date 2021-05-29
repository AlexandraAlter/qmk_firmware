#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"
#include "keymap_steno.h"
#include "keymap_steno_velotype.h"

// {{{ convenience macros
// clang-format off
#define LAYOUT_moonlander_mirrored( \
  k00, k01, k02, k03, k04, k05, k06, \
  k10, k11, k12, k13, k14, k15, k16, \
  k20, k21, k22, k23, k24, k25, k26, \
  k30, k31, k32, k33, k34, k35,      \
  k40, k41, k42, k43, k44,      k53, \
                      k50, k51, k52 \
) \
LAYOUT_moonlander( \
  k00, k01, k02, k03, k04, k05, k06, k06, k05, k04, k03, k02, k01, k00, \
  k10, k11, k12, k13, k14, k15, k16, k16, k15, k14, k13, k12, k11, k10, \
  k20, k21, k22, k23, k24, k25, k26, k26, k25, k24, k23, k22, k21, k20, \
  k30, k31, k32, k33, k34, k35,           k35, k34, k33, k32, k31, k30, \
  k40, k41, k42, k43, k44,    k53,     k53,    k44, k43, k42, k41, k40, \
                      k50, k51, k52, k52, k51, k50 \
)
// clang-format on

// clang-format off
#define LEDS_moonlander_both( \
  l00, l05, l10, l15, l20, l25, l29, l65, l61, l56, l51, l46, l41, l36, \
  l01, l06, l11, l16, l21, l26, l30, l66, l62, l57, l52, l47, l42, l37, \
  l02, l07, l12, l17, l22, l27, l31, l67, l63, l58, l53, l48, l43, l38, \
  l03, l08, l13, l18, l23, l28,           l64, l59, l54, l49, l44, l39, \
  l04, l09, l14, l19, l24,   l35,       l71,   l60, l55, l50, l45, l40, \
                      l32, l33, l34, l70, l69, l68 \
) \
{ \
  l00, l01, l02, l03, l04, \
  l05, l06, l07, l08, l09, \
  l10, l11, l12, l13, l14, \
  l15, l16, l17, l18, l19, \
  l20, l21, l22, l23, l24, \
  l25, l26, l27, l28, l29, \
  l30, l31, l32, l33, l34, \
  l35, \
  l36, l37, l38, l39, l40, \
  l41, l42, l43, l44, l45, \
  l46, l47, l48, l49, l50, \
  l51, l52, l53, l54, l55, \
  l56, l57, l58, l59, l60, \
  l61, l62, l63, l64, l65, \
  l66, l67, l68, l69, l70, \
  l71 \
}
// clang-format on

// clang-format off
#define LEDS_moonlander_left( \
  l00, l05, l10, l15, l20, l25, l29, \
  l01, l06, l11, l16, l21, l26, l30, \
  l02, l07, l12, l17, l22, l27, l31, \
  l03, l08, l13, l18, l23, l28,      \
  l04, l09, l14, l19, l24,   l35,    \
                      l32, l33, l34  \
) \
{ \
  l00, l01, l02, l03, l04, \
  l05, l06, l07, l08, l09, \
  l10, l11, l12, l13, l14, \
  l15, l16, l17, l18, l19, \
  l20, l21, l22, l23, l24, \
  l25, l26, l27, l28, l29, \
  l30, l31, l32, l33, l34, \
  l35 \
}
// clang-format on

// clang-format off
#define LEDS_moonlander_right( \
  l65, l61, l56, l51, l46, l41, l36, \
  l66, l62, l57, l52, l47, l42, l37, \
  l67, l63, l58, l53, l48, l43, l38, \
       l64, l59, l54, l49, l44, l39, \
     l71,   l60, l55, l50, l45, l40, \
  l70, l69, l68 \
) \
{ \
  l36, l37, l38, l39, l40, \
  l41, l42, l43, l44, l45, \
  l46, l47, l48, l49, l50, \
  l51, l52, l53, l54, l55, \
  l56, l57, l58, l59, l60, \
  l61, l62, l63, l64, l65, \
  l66, l67, l68, l69, l70, \
  l71 \
}
// clang-format on
// }}} convenience macros

typedef enum layer_t {
  // base layers
  L_BASE, // base
  L_DVK,  // dvorak
  L_QRTY, // qwerty
  L_STEN, // stenotype
  L_VELO, // velotype
  L_VELX, // velotype without footpedal
  L_GBA,  // gaming base
  L_OH,   // one-handed dvorak
  L_OHF,  // one-handed dvorak flipped
  L_OHS,  // one-handed symbols and numpad
  // utility layers
  L_MUS,  // music
  L_MOUS, // mouse
  L_SYMS, // symbols
  L_NAVI, // navigation
  L_NUM,  // numpad
  // layers 16+ below this point
  L_GNU,  // gaming numpad
  // layer switching and extras
  L_LAY,  // layer switching
  L_MEDI, // media
  L_CONF, // config
  L_MAX,
} layer_t;

typedef enum custom_keycode_t { // {{{
  // pause LED animation
  RGB_SLD = ML_SAFE_RANGE,
  // go directly to the two gaming layers
  TO_GAME,
} custom_keycode_t; // }}}

// {{{ key macros
#define RGB_TLC TOGGLE_LAYER_COLOR

#define LAYERS TG(L_LAY)
#define ABORT  TO(L_BASE)

// {{{ left basic modifiers
#define L1(kc)  LALT_T(kc)
#define L2(kc)  LGUI_T(kc)
#define L3(kc)  LCTL_T(kc)
#define L4(kc)  LSFT_T(kc)
#define L5(kc)  RALT_T(kc)
#define L6(la)  MO(la)
#define L7(kc)  LGUI_T(kc)
#define L8(kc)  LCTL_T(kc)
#define L9(kc)  LALT_T(kc)
#define L10(kc) LALT_T(kc)
#define L11(kc) XXXXXXX

#define KA_L1  KC_LALT
#define KA_L2  L2(KC_ESC)
#define KA_L3  L3(KC_BSPC)
#define KA_L4  KC_LSPO
#define KA_L5  L5(KC_LBRC)
#define KA_L6  L6(L_MEDI)
#define KA_L7  KC_LGUI
#define KA_L8  L8(KC_LEFT)
#define KA_L9  L9(KC_RGHT)
#define KA_L10 L10(KC_LBRC)
#define KA_L11 XXXXXXX

#define KA_L8M KC_LCTL
#define KA_L9M KC_LALT

#define KA_LT1 LT(L_SYMS, KC_SPC)
#define KA_LT2 LT(L_NAVI, KC_TAB)
#define KA_LT3 KC_ENT
#define KA_LTA TG(L_MOUS)
// }}}

// {{{ right basic modifiers
#define R1(kc)  LALT_T(kc)
#define R2(kc)  RGUI_T(kc)
#define R3(kc)  RCTL_T(kc)
#define R4(kc)  RSFT_T(kc)
#define R5(kc)  RALT_T(kc)
#define R6(la)  MO(la)
#define R7(kc)  RGUI_T(kc)
#define R8(kc)  RCTL_T(kc)
#define R9(kc)  LALT_T(kc)
#define R10(kc) LALT_T(kc)
#define R11(kc) XXXXXXX

#define KA_R1  KC_LALT
#define KA_R2  R2(KC_ESC)
#define KA_R3  R3(KC_DEL)
#define KA_R4  KC_RSPC
#define KA_R5  R5(KC_RBRC)
#define KA_R6  R6(L_MEDI)
#define KA_R7  KC_RGUI
#define KA_R8  R8(KC_UP)
#define KA_R9  R9(KC_DOWN)
#define KA_R10 R10(KC_RBRC)
#define KA_R11 XXXXXXX

#define KA_R8M KC_RCTL
#define KA_R9M KC_LALT

#define KA_RT1 LT(L_SYMS, KC_SPC)
#define KA_RT2 LT(L_NUM,  KC_ENT)
#define KA_RT3 KC_APP
#define KA_RTA TG(L_NUM)
// }}}

// {{{ one-handed modifiers
#define KA_O8 LGUI_T(KC_RGHT)
#define KA_O9 LALT_T(KC_LEFT)

#define KA_OHT1 LT(L_OHF,  KC_SPC)
#define KA_OHT2 LT(L_OHS,  KC_TAB)
#define KA_OHT3 LT(L_NAVI, KC_ENT)
// }}}
// }}}

const uint16_t PROGMEM keymaps[L_MAX][MATRIX_ROWS][MATRIX_COLS] = {
  /* {{{ template
  [L_] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______,             _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,     _______, _______, _______
  ), */ // }}}

  [L_BASE] = LAYOUT_moonlander( // {{{ base
    KA_L1,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    LAYERS,      LAYERS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KA_R1,
    KA_L2,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_L11,      KA_R11,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R2,
    KA_L3,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_L10,      KA_R10,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R3,
    KA_L4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R4,
    KA_L5,   KA_L6,   KA_L7,   KA_L8,   KA_L9,        KA_LTA,              KA_RTA,       KA_R9,   KA_R8,   KA_R7,   KA_R6,   KA_R5,
                                        KA_LT1,  KA_LT2,  KA_LT3,      KA_RT3,  KA_RT2, KA_RT1
  ), // }}}

  [L_DVK] = LAYOUT_moonlander( // {{{ dvorak
    L1(KC_GRV), _______, _______, _______, _______, _______, LAYERS,      LAYERS,  _______, _______, _______, _______, _______, R1(KC_EQL),
    _______,    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    TG(L_OH),    TG(L_OH),KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    R2(KC_SLSH),
    _______,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______,     _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    R3(KC_MINS),
    _______,    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                          KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,
    L5(KC_DEL), _______, _______, _______, _______,      _______,             _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,     _______, _______, _______
  ), // }}}

  [L_OH] = LAYOUT_moonlander( // {{{ one-handed dvorak
    KA_L1,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    LAYERS,      LAYERS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KA_R1,
    KA_L2,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______,     _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KA_R2,
    KA_L3,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______,     _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KA_R3,
    KA_L4,   KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                          KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KA_R4,
    KA_L5,   KA_L6,   KA_L7,   KA_L8,   KA_L9,        _______,             _______,      KA_R9,   KA_R8,   KA_R7,   KA_R6,   KA_R5,
                                        KA_OHT1, KA_OHT2, KA_OHT3,     KA_OHT3, KA_OHT2, KA_OHT1
  ), // }}}

  [L_OHF] = LAYOUT_moonlander( // {{{ one-handed dvorak flipped
    KA_R1,   KC_0,    KC_9,    KC_8,    KC_7,    KC_6,    LAYERS,      LAYERS,  KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    KA_L1,
    KA_R2,   KC_L,    KC_R,    KC_C,    KC_G,    KC_F,    _______,     _______, KC_Y,    KC_P,    KC_DOT,  KC_COMM, KC_QUOT, KA_L2,
    KA_R3,   KC_S,    KC_N,    KC_T,    KC_H,    KC_D,    _______,     _______, KC_I,    KC_U,    KC_E,    KC_O,    KC_A,    KA_L3,
    KA_R4,   KC_Z,    KC_V,    KC_W,    KC_M,    KC_B,                          KC_X,    KC_K,    KC_J,    KC_Q,    KC_SCLN, KA_L4,
    KA_R5,   KA_R6,   KA_R7,   KA_R8M,  KA_R9M,       _______,             _______,      KA_L9M,  KA_L8M,  KA_L7,   KA_L6,   KA_L5,
                                        _______, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, _______
  ), // }}}

  [L_OHS] = LAYOUT_moonlander( // {{{ one-handed symbols and numbers
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   LAYERS,      LAYERS,  KC_F5,   KC_F4,   KC_F3,   KC_F2,   KC_F1,   _______,
    _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_LBRC, KC_RBRC,     KC_LBRC, KC_RBRC, KC_1,    KC_2,    KC_3,    KC_GRV,  _______,
    _______, KC_SLSH, KC_4,    KC_5,    KC_6,    KC_MINS, KC_EQL,      KC_EQL,  KC_MINS, KC_4,    KC_5,    KC_6,    KC_SLSH, _______,
    _______, KC_BSLS, KC_7,    KC_8,    KC_9,    KC_0,                          KC_0,    KC_7,    KC_8,    KC_9,    KC_BSLS, _______,
    _______, _______, _______, _______, _______,      _______,             _______,      _______, _______, _______, _______, _______,
                                        XXXXXXX, _______, XXXXXXX,     XXXXXXX, _______, XXXXXXX
  ), // }}}

  [L_QRTY] = LAYOUT_moonlander( // {{{ qwerty
    L1(KC_GRV), _______, _______, _______, _______, _______, LAYERS,      LAYERS,  _______, _______, _______, _______, _______, R1(KC_EQL),
    _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,     _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    R2(KC_MINS),
    _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,     _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, R3(KC_QUOT),
    _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______,    _______, _______, _______, _______,      _______,             _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,     _______, _______, _______
  ), // }}}

  [L_STEN] = LAYOUT_moonlander( // {{{ stenotype
    STN_PWR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LAYERS,      LAYERS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, STN_PWR,
    STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  XXXXXXX,     XXXXXXX, STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
    STN_RE1, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, XXXXXXX,     XXXXXXX, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    STN_RE2, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,                       STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______,             _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        STN_A,   STN_O,   STN_FN,      STN_FN,  STN_E,   STN_U
  ), // }}}

  [L_VELO] = LAYOUT_moonlander( // {{{ velotype
    STN_PWR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LAYERS,      LAYERS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, STN_PWR,
    XXXXXXX, XXXXXXX, VL_PL,   VL_KL,   VL_IL,   VL_APO,  XXXXXXX,     XXXXXXX, VL_APO,  VL_OR,   VL_KR,   VL_PR,   XXXXXXX, XXXXXXX,
    VL_ZL,   VL_FL,   VL_TL,   VL_JL,   VL_OL,   VL_U,    XXXXXXX,     XXXXXXX, VL_U,    VL_IR,   VL_JR,   VL_TR,   VL_FR,   VL_ZR,
    VL_ZL,   VL_SL,   VL_CL,   VL_RL,   VL_EL,   VL_A,                          VL_A,    VL_ER,   VL_RR,   VL_CR,   VL_SR,   VL_ZR,
    VL_SH,   VL_SH,   VL_SH,   VL_SYML, VL_SYML,      _______,             _______,      VL_SYMR, VL_SYMR, VL_SH,   VL_SH,   VL_SH,
                                        VL_LL,   VL_NL,   VL_Y,        VL_Y,    VL_NR,   VL_LR
  ), // }}}

  [L_VELX] = LAYOUT_moonlander( // {{{ velotype without footpedal
    STN_PWR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LAYERS,      LAYERS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, VL_PL,   VL_KL,   VL_IL,   VL_APO,  XXXXXXX,     XXXXXXX, VL_APO,  VL_OR,   VL_KR,   VL_PR,   XXXXXXX, XXXXXXX,
    VL_ZL,   VL_FL,   VL_TL,   VL_JL,   VL_OL,   VL_U,    XXXXXXX,     XXXXXXX, VL_U,    VL_IR,   VL_JR,   VL_TR,   VL_FR,   VL_ZR,
    VL_ZL,   VL_SL,   VL_CL,   VL_RL,   VL_EL,   VL_A,                          VL_A,    VL_ER,   VL_RR,   VL_CR,   VL_SR,   VL_ZR,
    VL_SH,   VL_SH,   VL_SH,   VL_SYML, VL_Y,         VL_H,                VL_NOS,       VL_Y,    VL_SYMR, VL_SH,   VL_SH,   VL_SH,
                                        VL_LL,   VL_NL,   VL_H,        VL_NOS,  VL_NR,   VL_LR
  ), // }}}

  [L_GBA] = LAYOUT_moonlander( // {{{ gaming base
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    LAYERS,      LAYERS,  _______, _______, _______, _______, _______, _______,
    KC_ESC,  KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_6,        _______, _______, _______, _______, _______, _______, _______,
    KC_BSPC, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_7,        _______, _______, _______, _______, _______, _______, _______,
    KC_LSFT, KC_LCTL, KC_MINS, KC_EQL,  KC_SLSH, KC_8,                          _______, _______, _______, _______, _______, _______,
    KC_LGUI, KC_LBRC, KC_RBRC, KC_0,    KC_9,         TG(L_OH),            TG(L_GNU),    _______, _______, _______, _______, _______,
                                        KC_SPC,  KC_LALT, KC_ENT,      _______, _______, _______
  ), // }}}

  [L_GNU] = LAYOUT_moonlander( // {{{ gaming numpad
    _______, _______, _______, _______, _______, _______, LAYERS,      LAYERS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______, _______,     KC_F5,   KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_F12,
    _______, _______, _______, _______, _______, _______, _______,     KC_F4,   KC_PSLS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_RALT,
    _______, _______, _______, _______, _______, _______,                       KC_F3,   KC_P7,   KC_P8,   KC_P9,   KC_RCTL, KC_RSFT,
    _______, _______, _______, _______, _______,      _______,             TG(L_GNU),    KC_F2,   KC_F1,   XXXXXXX, XXXXXXX, KC_RGUI,
                                        _______, _______, _______,     KC_PDOT, KC_PENT, KC_P0
  ), // }}}

  [L_MUS] = LAYOUT_moonlander( // {{{ music
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LAYERS,      LAYERS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      MU_TOG,              MU_MOD,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
  ), // }}}

  [L_MOUS] = LAYOUT_moonlander( // {{{ mouse
    KA_L1,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LAYERS,      LAYERS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R1,
    KA_L2,   XXXXXXX, KC_BTN4, KC_MS_U, KC_BTN5, KC_WH_U, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, KA_R2,
    KA_L3,   KC_ACL2, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX,     XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, KA_R3,
    KA_L4,   XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R4,
    KA_L5,   KA_L6,   KA_L7,   KC_ACL0, KC_ACL1,      _______,             _______,      KA_R9,   KA_R8,   KA_R7,   KA_R6,   KA_R5,
                                        KC_BTN1, KC_BTN2, KC_BTN3,     KC_ACL0, KC_ACL1, KC_ACL2
  ), // }}}

  [L_SYMS] = LAYOUT_moonlander( // {{{ symbols
    KA_L1,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   LAYERS,      LAYERS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KA_R1,
    KA_L2,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_F11,      KC_F12,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KA_R2,
    KA_L3,   KC_GRV,  KC_QUOT, KC_BSLS, KC_LBRC, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_RBRC, KC_SLSH, KC_MINS, KC_EQL,  KA_R3,
    KA_L4,   KC_TILD, KC_DQUO, KC_PIPE, KC_LCBR, XXXXXXX,                       XXXXXXX, KC_RCBR, KC_QUES, KC_UNDS, KC_PLUS, KA_R4,
    KA_L5,   KA_L6,   KA_L7,   KA_L8,   KA_L9,        _______,             _______,      KA_R9,   KA_R8,   KA_R7,   KA_R6,   KA_R5,
                                        _______, _______, _______,     _______, _______, _______
  ), // }}}

  [L_NAVI] = LAYOUT_moonlander( // {{{ navigation
    KA_L1,   KC_CAPS, KC_INS,  KC_PSCR, KC_SLCK, KC_PAUS, LAYERS,      LAYERS,  KC_PAUS, KC_SLCK, KC_PSCR, KC_INS,  KC_CAPS, KA_R1,
    KA_L2,   KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,     XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_TAB,  KA_R2,
    KA_L3,   KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_ENT,      KC_ENT,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ESC,  KA_R3,
    KA_L4,   XXXXXXX, KC_BSPC, XXXXXXX, KC_DEL,  XXXXXXX,                       XXXXXXX, KC_BSPC, XXXXXXX, KC_DEL,  XXXXXXX, KA_R4,
    KA_L5,   KA_L6,   KA_L7,   KA_L8,   KA_L9,        _______,             _______,      KA_R9,   KA_R8,   KA_R7,   KA_R6,   KA_R5,
                                        _______, _______, _______,     _______, _______, _______
  ), // }}}

  [L_NUM] = LAYOUT_moonlander( // {{{ numpad
    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    LAYERS,      LAYERS,  KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,
    KA_L2,   KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_NLCK,     KC_NLCK, KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KA_R2,
    KA_L3,   KC_PSLS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PENT,     KC_PENT, KC_PSLS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KA_R3,
    KA_L4,   KC_PEQL, KC_P7,   KC_P8,   KC_P9,   KC_P0,                         KC_P0,   KC_P7,   KC_P8,   KC_P9,   KC_PEQL, KA_R4,
    KA_L5,   KA_L6,   KA_L7,   KC_PCMM, KC_PDOT,      _______,             _______,      KC_PDOT, KC_PCMM, KA_R7,   KA_R6,   KA_R5,
                                        _______, _______, _______,     _______, _______, _______
  ), // }}}

  [L_LAY] = LAYOUT_moonlander_mirrored( // {{{ layer switching
    ABORT,      TO(L_DVK),  TO(L_STEN), TO_GAME,    XXXXXXX,    TO(L_MUS),    LAYERS,
    XXXXXXX,    TO(L_QRTY), TO(L_VELO), XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX,
    MO(L_CONF), XXXXXXX,    TO(L_VELX), XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,           XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,      XXXXXXX
  ), // }}}

  [L_MEDI] = LAYOUT_moonlander_mirrored( // {{{ media
    XXXXXXX, KC_CALC, KC_MAIL, KC_MYCM, KC_MSEL, XXXXXXX, ABORT,
    KC_WHOM, KC_WSTP, KC_WBAK, KC_WFWD, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_WFAV, KC_WSCH, KC_WREF, KC_VOLD, KC_VOLU, XXXXXXX, KC_EJCT,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MFFD, KC_MRWD,      XXXXXXX,
                                        KC_MUTE, KC_MPLY, KC_MSTP
  ), // }}}

  [L_CONF] = LAYOUT_moonlander_mirrored( // {{{ config
    RESET,   AU_TOG,  NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, ABORT,
    XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_HUI, KC_WAKE, KC_SLEP,
    XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI, XXXXXXX, KC_PWR,
    XXXXXXX, XXXXXXX, XXXXXXX, RGB_SAD, RGB_SAI, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPD, RGB_SPI,      RGB_TOG,
                                        RGB_TLC, RGB_MOD, RGB_SLD
  ), // }}}
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void matrix_init_user(void) {
  layer_move(L_DVK);
  steno_set_mode(STENO_MODE_GEMINI);
}

#define C_____ C_NONE

typedef enum color_t { // {{{
  C_NONE,

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
  [C_NONE] = {0,   0,   0},

  // sunset
  [C_SU_1] = {14,  222, 242},
  [C_SU_2] = {255, 220, 201},
  [C_SU_3] = {233, 218, 217},
  [C_SU_4] = {205, 255, 255},
  [C_SU_5] = {180, 255, 233},

  // tomorrow
  [C_TO_1] = {50,  153, 244},
  [C_TO_2] = {20,  177, 225},
  [C_TO_3] = {154, 86,  255},
  [C_TO_4] = {252, 119, 255},
  [C_TO_5] = {195, 61,  255},

  // rubik's cube
  [C_RU_1] = {105, 255, 255},
  [C_RU_2] = {249, 228, 255},
  [C_RU_3] = {35,  255, 255},
  [C_RU_4] = {154, 255, 255},
  [C_RU_5] = {14,  255, 255},

  // desert sun
  [C_DS_1] = {14,  255, 255},
  [C_DS_2] = {33,  255, 255},
  [C_DS_3] = {30,  96,  255},
  [C_DS_4] = {0,   0,   255},
  [C_DS_5] = {141, 255, 233},

  // cosmic chocolate
  [C_CC_1] = {15,  166, 195},
  [C_CC_2] = {0,   205, 155},
  [C_CC_3] = {0,   183, 238},
  [C_CC_4] = {0,   0,   255},
  [C_CC_5] = {31,  255, 255},

  // material
  [C_MA_1] = {32,  176, 255},
  [C_MA_2] = {10,  225, 255},
  [C_MA_3] = {243, 222, 234},
  [C_MA_4] = {85,  203, 158},
  [C_MA_5] = {134, 255, 213},

  // solarized
  [C_SO_1] = {32,  255, 234},
  [C_SO_2] = {12,  225, 241},
  [C_SO_3] = {1,   204, 255},
  [C_SO_4] = {168, 120, 255},
  [C_SO_5] = {145, 224, 255},

  // raspberry
  [C_RA_1] = {252, 199, 190},
  [C_RA_2] = {248, 159, 255},
  [C_RA_3] = {28,  126, 255},
  [C_RA_4] = {16,  97,  236},
  [C_RA_5] = {16,  177, 169},
}; // }}}

// LED configuration that declares all of the LEDs
typedef enum led_maps_both_t {
  LEDS_STEN,
  LEDS_MOUS,
} led_maps_both_t;

const color_t PROGMEM ledmap_both[][DRIVER_LED_TOTAL] = {
  /* {{{ template
   * the last row holds the thumb keys
   * the launch key is closest to the inner edge
  [L_] = LEDS_moonlander_both(
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____,                    C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____,     C_____,            C_____,     C_____, C_____, C_____, C_____, C_____,
                                    C_____, C_____, C_____,    C_____, C_____, C_____
  ), */ // }}}

  [LEDS_STEN] = LEDS_moonlander_both( // {{{ stenotype
    C_RA_4, C_____, C_____, C_____, C_____, C_____, C_RA_5,    C_RA_5, C_____, C_____, C_____, C_____, C_____, C_RA_4,
    C_RA_3, C_RA_3, C_RA_3, C_RA_3, C_RA_3, C_RA_3, C_____,    C_____, C_RA_3, C_RA_3, C_RA_3, C_RA_3, C_RA_3, C_RA_3,
    C_RA_4, C_RA_1, C_RA_1, C_RA_1, C_RA_1, C_RA_2, C_____,    C_____, C_RA_2, C_RA_1, C_RA_1, C_RA_1, C_RA_1, C_RA_1,
    C_RA_4, C_RA_1, C_RA_1, C_RA_1, C_RA_1, C_RA_2,                    C_RA_2, C_RA_1, C_RA_1, C_RA_1, C_RA_1, C_RA_1,
    C_____, C_____, C_____, C_____, C_____,     C_RA_5,            C_RA_5,     C_____, C_____, C_____, C_____, C_____,
                                    C_RA_1, C_RA_1, C_RA_4,    C_RA_4, C_RA_1, C_RA_1
  ), // }}}

  [LEDS_MOUS] = LEDS_moonlander_both( // {{{ mouse
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_SU_5,    C_SU_5, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_SU_2, C_SU_1, C_SU_2, C_SU_2, C_____,    C_____, C_____, C_____, C_SU_1, C_____, C_____, C_SU_4,
    C_SU_4, C_SU_3, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_____,    C_____, C_____, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_4,
    C_SU_4, C_____, C_SU_2, C_____, C_SU_2, C_____,                    C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_SU_4, C_SU_4, C_SU_3, C_SU_3,     C_SU_5,            C_SU_5,     C_SU_3, C_SU_3, C_SU_4, C_SU_4, C_SU_4,
                                    C_SU_1, C_SU_1, C_SU_1,    C_SU_3, C_SU_3, C_SU_3
  ), // }}}
};

// LED configuration that declares only left LEDs
// used by mirrored layers too
typedef enum led_maps_left_t {
  LEDS_BASE,
  LEDS_DVK,
  LEDS_OH,
  LEDS_OHS,
  LEDS_QRTY,
  LEDS_VELO,
  LEDS_VELX,
  LEDS_GBA,
  LEDS_MUS,
  LEDS_SYMS,
  LEDS_NAVI,
  LEDS_NUM,
  LEDS_LAY,
  LEDS_MEDI,
  LEDS_SYS,
  LEDS_CONF,
} led_maps_left_t;

// used by mirrored layers too
const color_t PROGMEM ledmap_left[][DRIVER_LED_TOTAL / 2] = {
  /* {{{ template
   * the last row holds the thumb keys
   * the launch key is rightmost
  [L_] = LEDS_moonlander_left(
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____,     C_____,
                                    C_____, C_____, C_____
  ), */ // }}}

  [LEDS_BASE] = LEDS_moonlander_left( // {{{ base
    C_SU_4, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_5,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_SU_2,
    C_SU_4, C_____, C_____, C_____, C_____, C_____,
    C_SU_4, C_SU_4, C_SU_4, C_SU_3, C_SU_3,     C_SU_5,
                                    C_SU_5, C_SU_5, C_SU_5
  ), // }}}

  [LEDS_DVK] = LEDS_moonlander_left( // {{{ dvorak
    C_SU_4, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_5,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_5,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_4,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2,
    C_SU_4, C_SU_4, C_SU_4, C_SU_3, C_SU_3,     C_SU_5,
                                    C_SU_5, C_SU_5, C_SU_5
  ), // }}}

  [LEDS_OH] = LEDS_moonlander_left( // {{{ one-handed dvorak
    C_TO_4, C_TO_3, C_TO_3, C_TO_3, C_TO_3, C_TO_3, C_TO_5,
    C_TO_4, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_5,
    C_TO_4, C_TO_1, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_TO_5,
    C_TO_4, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2,
    C_TO_4, C_TO_4, C_TO_4, C_TO_3, C_TO_3,     C_TO_5,
                                    C_TO_5, C_TO_5, C_TO_5
  ), // }}}

  [LEDS_OHS] = LEDS_moonlander_left( // {{{ one-handed symbols and numpad
    C_TO_4, C_TO_3, C_TO_3, C_TO_3, C_TO_3, C_TO_3, C_TO_5,
    C_TO_4, C_TO_2, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_TO_2,
    C_TO_4, C_TO_2, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_TO_2,
    C_TO_4, C_TO_2, C_TO_1, C_TO_1, C_TO_1, C_TO_1,
    C_TO_4, C_TO_4, C_TO_4, C_TO_4, C_TO_4,     C_____,
                                    C_____, C_____, C_____
  ), // }}}

  [LEDS_QRTY] = LEDS_moonlander_left( // {{{ qwerty
    C_DS_4, C_DS_3, C_DS_3, C_DS_3, C_DS_3, C_DS_3, C_DS_5,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_____,
    C_DS_4, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_2, C_DS_4,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2,
    C_DS_4, C_DS_4, C_DS_4, C_DS_3, C_DS_3,     C_DS_5,
                                    C_DS_5, C_DS_5, C_DS_5
  ), // }}}

  [LEDS_VELO] = LEDS_moonlander_left( // {{{ velotype
    C_MA_4, C_____, C_____, C_____, C_____, C_____, C_MA_5,
    C_____, C_____, C_MA_2, C_MA_2, C_MA_2, C_MA_2, C_____,
    C_MA_2, C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_2, C_____,
    C_MA_2, C_MA_1, C_MA_2, C_MA_2, C_MA_2, C_MA_2,
    C_MA_3, C_MA_3, C_MA_3, C_MA_2, C_MA_2,     C_MA_5,
                                    C_MA_2, C_MA_1, C_MA_2
  ), // }}}

  [LEDS_VELX] = LEDS_moonlander_left( // {{{ velotype without footpedal
    C_MA_4, C_____, C_____, C_____, C_____, C_____, C_MA_5,
    C_____, C_____, C_MA_2, C_MA_2, C_MA_2, C_MA_2, C_____,
    C_MA_2, C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_2, C_____,
    C_MA_2, C_MA_1, C_MA_2, C_MA_2, C_MA_2, C_MA_2,
    C_MA_3, C_MA_3, C_MA_3, C_MA_2, C_MA_2,     C_MA_3,
                                    C_MA_2, C_MA_1, C_MA_3
  ), // }}}

  [LEDS_GBA] = LEDS_moonlander_left( // {{{ gaming base
    C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_5,
    C_RU_2, C_RU_2, C_RU_2, C_RU_1, C_RU_2, C_RU_2, C_RU_3,
    C_RU_2, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,
    C_RU_4, C_RU_4, C_RU_2, C_RU_2, C_RU_2, C_RU_3,
    C_RU_4, C_RU_2, C_RU_2, C_RU_3, C_RU_3,     C_RU_5,
                                    C_RU_2, C_RU_4, C_RU_2
  ), // }}}

  [LEDS_MUS] = LEDS_moonlander_left( // {{{ music
    C_____, C_____, C_____, C_____, C_____, C_____, C_TO_5,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____,     C_TO_5,
                                    C_____, C_____, C_____
  ), // }}}

  [LEDS_SYMS] = LEDS_moonlander_left( // {{{ symbols
    C_SU_4, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_5,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_3,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_____, C_____,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_____,
    C_SU_4, C_SU_4, C_SU_4, C_SU_3, C_SU_3,     C_____,
                                    C_____, C_____, C_____
  ), // }}}

  [LEDS_NAVI] = LEDS_moonlander_left( // {{{ navigation
    C_SU_4, C_RU_1, C_RU_2, C_RU_3, C_RU_4, C_RU_5, C_SU_5,
    C_SU_4, C_SU_2, C_SU_2, C_SU_1, C_SU_2, C_SU_2, C_____,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_2,
    C_SU_4, C_____, C_SU_2, C_____, C_SU_2, C_____,
    C_SU_4, C_SU_4, C_SU_4, C_SU_4, C_SU_4,     C_____,
                                    C_____, C_____, C_____
  ), // }}}

  [LEDS_NUM] = LEDS_moonlander_left( // {{{ numpad
    C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_5,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_1,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_1,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_1,
    C_SU_4, C_SU_4, C_SU_4, C_SU_2, C_SU_2,     C_SU_5,
                                    C_____, C_____, C_____
  ), // }}}

  [LEDS_LAY] = LEDS_moonlander_left( // {{{ layer switching
    C_SU_5, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_1, C_____,
    C_____, C_SU_1, C_SU_1, C_____, C_____, C_____, C_____,
    C_SU_4, C_____, C_SU_1, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____,     C_____,
                                    C_____, C_____, C_____
  ), // }}}

  [LEDS_MEDI] = LEDS_moonlander_left( // {{{ media
    C_____, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_____, C_SU_5,
    C_DS_2, C_DS_1, C_DS_1, C_DS_1, C_____, C_____, C_____,
    C_DS_2, C_DS_2, C_DS_2, C_SU_4, C_SU_4, C_____, C_SU_4,
    C_____, C_____, C_____, C_SU_4, C_SU_4, C_____,
    C_____, C_____, C_____, C_SU_4, C_SU_4,     C_____,
                                    C_SU_4, C_SU_4, C_SU_4
  ), // }}}

  [LEDS_CONF] = LEDS_moonlander_left( // {{{ config
    C_SU_1, C_SU_2, C_SU_2, C_____, C_____, C_____, C_SU_5,
    C_____, C_____, C_____, C_DS_2, C_DS_2, C_SU_2, C_SU_1,
    C_____, C_____, C_____, C_DS_2, C_DS_2, C_____, C_SU_1,
    C_____, C_____, C_____, C_DS_2, C_DS_2, C_____,
    C_____, C_____, C_____, C_DS_2, C_DS_2,     C_DS_2,
                                    C_DS_2, C_DS_2, C_DS_2
  ), // }}}
};

// LED configuration that declares only right LEDs
typedef enum led_maps_right_t {
  LEDS_GNU,
} led_maps_right_t;

const color_t PROGMEM ledmap_right[][DRIVER_LED_TOTAL / 2] = {
  /* {{{ template
   * the last row holds the thumb keys
   * the launch key is leftmost
  [L_] = LEDS_moonlander_right(
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
            C_____, C_____, C_____, C_____, C_____, C_____,
        C_____,     C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____
  ), */ // }}}

  // {{{ gaming numpad
  [LEDS_GNU] = LEDS_moonlander_right(
    C_RU_5, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3,
    C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,
    C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_4,
            C_RU_3, C_RU_1, C_RU_1, C_RU_1, C_RU_4, C_RU_4,
        C_RU_5,     C_RU_3, C_RU_3, C_____, C_____, C_RU_4,
    C_RU_2, C_RU_1, C_RU_1
  ), // }}}
};

typedef enum led_mode_t { // {{{
  LM_NONE,
  LM_BOTH,
  LM_MIRROR, // define left LEDs but mirror them
  LM_LEFT,
  LM_RIGHT,
} led_mode_t; // }}}

typedef struct layer_led_config_t {
  led_mode_t mode;
  const color_t *colors;
  const uint8_t inds; // first four LED indicators of the board
} layer_led_config_t;

const layer_led_config_t PROGMEM ledmap[L_MAX] = { // {{{
  [L_BASE]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_BASE], .inds = 0b111, },
  [L_DVK]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_DVK],  .inds = 0b000, },
  [L_QRTY]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_QRTY], .inds = 0b001, },
  [L_STEN]  = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_STEN], .inds = 0b010, },
  [L_VELO]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_VELO], .inds = 0b010, },
  [L_VELX]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_VELX], .inds = 0b010, },
  [L_GBA]   = { .mode = LM_LEFT,   .colors = ledmap_left[LEDS_GBA],  .inds = 0b100, },
  [L_GNU]   = { .mode = LM_RIGHT,  .colors = ledmap_right[LEDS_GNU], .inds = 0b100, },
  [L_OH]    = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_OH],   .inds = 0b001, },
  [L_OHF]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_OH],   .inds = 0b001, },
  [L_OHS]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_OHS],  .inds = 0b001, },
  [L_MUS]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_MUS],  .inds = 0b111, },
  [L_MOUS]  = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_MOUS], .inds = 0b100, },
  [L_SYMS]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_SYMS], .inds = 0b110, },
  [L_NAVI]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_NAVI], .inds = 0b101, },
  [L_NUM]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_NUM],  .inds = 0b011, },
  [L_LAY]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_LAY],  .inds = 0b111, },
  [L_MEDI]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_MEDI], .inds = 0b111, },
  [L_CONF]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_CONF], .inds = 0b111, },
}; // }}}

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
    float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
    rgb_matrix_set_color(led, f * rgb.r, f * rgb.g, f * rgb.b);
  }
} // }}}

void set_led_colors(int first_led, int last_led, const color_t *colors) { // {{{
  int color_ind = 0;
  for (int led_ind = first_led; led_ind <= last_led; led_ind++) {
    set_led_color(led_ind, colors[color_ind]);
    color_ind++;
  }
} // }}}

void rgb_matrix_indicators_user(void) { // {{{
  if (g_suspend_state || keyboard_config.disable_layer_led) return;

  int first_l_led = 0;
  int last_l_led = (DRIVER_LED_TOTAL / 2) - 1;
  int first_r_led = DRIVER_LED_TOTAL / 2;
  int last_r_led = DRIVER_LED_TOTAL - 1;

  bool left_leds_set = false, right_leds_set = false;
  layer_state_t layers = layer_state | default_layer_state;

  for (int8_t layer = MAX_LAYER - 1; layer >= 0; layer--) {
    if (layers & (1UL << layer)) {
      const layer_led_config_t *led_config = &ledmap[layer];
      led_mode_t mode = led_config->mode;

      if (mode == LM_NONE) continue;

      if (!left_leds_set && (mode == LM_MIRROR || mode == LM_BOTH || mode == LM_LEFT)) {
        set_led_colors(first_l_led, last_l_led, led_config->colors);
        left_leds_set = true;
      }

      if (!right_leds_set) {
        if (mode == LM_RIGHT || mode == LM_MIRROR) {
          set_led_colors(first_r_led, last_r_led, led_config->colors);
          right_leds_set = true;
        } else if (mode == LM_BOTH) {
          set_led_colors(first_r_led, last_r_led, led_config->colors + first_r_led);
          right_leds_set = true;
        }
      }

      if (right_leds_set && left_leds_set) return;
    }
  }

  if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
    rgb_matrix_set_color_all(0, 0, 0);
  }
} // }}}

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
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        keyboard_config.disable_layer_led ^= 1;
        if (keyboard_config.disable_layer_led) rgb_matrix_set_color_all(0, 0, 0);
        eeconfig_update_kb(keyboard_config.raw);
      }
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TO_GAME:
      if (record->event.pressed) {
        layer_clear();
        layer_on(L_GBA);
        layer_on(L_GNU);
      }
      return false;
  }
  return true;
} // }}}

layer_state_t layer_state_set_user(layer_state_t layer_state) { // {{{
  layer_state_t layers = layer_state | default_layer_state;

  for (int8_t layer = MAX_LAYER - 1; layer >= 0; layer--) {
    if (layers & (1UL << layer)) {
      uint8_t inds = ledmap[layer].inds;
      ML_LED_4((inds & 0b001) != 0);
      ML_LED_5((inds & 0b010) != 0);
      ML_LED_6((inds & 0b100) != 0);
      break;
    }
  }

  return layer_state;
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

/* vim: set foldmethod=marker : */
