#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"
#include "keymap_steno.h"
#include "keymap_plover.h"
#include "keymap_velotype.h"

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
// }}} convenience macros

typedef enum layer_t { // {{{
  L_BASE, // base
  L_DVK,  // dvorak
  L_QRTY, // qwerty
  L_VELO, // velotype
  L_PLO,  // plover
  L_PLOS, // plover via steno
  L_GBA,  // gaming base
  L_OH,   // one hand
  L_OHF,  // one hand flipped
  L_OHS,  // one hand symbols
  L_GNU,  // gaming numpad
  L_MUS,  // music
  L_MOUS, // mouse
  L_SYMS, // symbols
  L_NAVI, // navigation
  L_NUM,  // numpad
  L_SHRT, // shortcuts
  // layers 16+ below this point
  L_LAY,  // layer switching
  L_MEDI, // media
  L_WEB,  // web
  L_SYS,  // system
  L_CONF, // config
  L_MAX,
} layer_t; // }}}

typedef enum custom_keycode_t { // {{{
  RGB_SLD = ML_SAFE_RANGE,
  TO_GAME,
} custom_keycode_t; // }}}

#define ZSA_COL TOGGLE_LAYER_COLOR

#define KA_GESC LGUI_T(KC_ESC)

#define KA_CBS  LCTL_T(KC_BSPC)
#define KA_LSFT KC_LSFT
#define KA_LBRC RCTL_T(KC_LBRC)
#define KA_ML1  KC_LALT
#define KA_ML2  KC_RALT
#define KA_LEFT LGUI_T(KC_LEFT)
#define KA_RGHT LALT_T(KC_RGHT)

#define KA_UP   RGUI_T(KC_UP)
#define KA_DOWN LALT_T(KC_DOWN)
#define KA_MR2  KC_RALT
#define KA_MR1  KC_LALT
#define KA_RBRC RCTL_T(KC_RBRC)
#define KA_RSFT KC_RSFT
#define KA_CDEL RCTL_T(KC_DEL)

#define KA_LT1 LT(L_SYMS, KC_SPC)
#define KA_LT2 LT(L_NAVI, KC_TAB)
#define KA_LT3 LT(L_SHRT, KC_ENT)
#define KA_RT1 LT(L_NAVI, KC_ENT)
#define KA_RT2 LT(L_NUM,  KC_DEL)
#define KA_RT3 LT(L_SHRT, KC_APP)

#define KA_OHT1 LT(L_OHF,  KC_SPC)
#define KA_OHT2 LT(L_OHS,  KC_TAB)
#define KA_OHT3 LT(L_NAVI, KC_ENT)

const uint16_t PROGMEM keymaps[L_MAX][MATRIX_ROWS][MATRIX_COLS] = {
  /* {{{ template
  [L_] = LAYOUT_moonlander(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                 _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,         _______,                     _______,           _______,    _______,    _______,    _______,    _______,
                                                    _______,    _______,    _______,         _______,    _______,    _______
  ), */ // }}}

  [L_BASE] = LAYOUT_moonlander( // {{{ base
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TG(L_LAY),       TG(L_LAY),  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    KA_GESC,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TG(L_OH),        TG(L_OH),   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KA_GESC,
    KA_CBS,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KA_CDEL,
    KA_LSFT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KA_RSFT,
    KA_LBRC,    KA_MR1,     KA_MR2,     KA_LEFT,    KA_RGHT,         TG(L_MOUS),                  TG(L_NUM),         KA_DOWN,    KA_UP,      KA_MR2,     KA_MR1,     KA_RBRC,
                                                    KA_LT1,     KA_LT2,     KA_LT3,          KA_RT3,     KA_RT2,     KA_RT1
  ), // }}}

  [L_DVK] = LAYOUT_moonlander( // {{{ dvorak
    KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,         _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_EQL,
    _______,    KC_QUOT,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,       _______,         _______,    KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       RGUI_T(KC_SLSH),
    _______,    KC_A,       KC_O,       KC_E,       KC_U,       KC_I,       _______,         _______,    KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       RCTL_T(KC_MINS),
    _______,    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X,                                    KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       _______,
    _______,    _______,    _______,    _______,    _______,         _______,                     _______,           _______,    _______,    _______,    _______,    _______,
                                                    _______,    _______,    _______,         _______,    _______,    _______
  ), // }}}

  [L_OH] = LAYOUT_moonlander( // {{{ one-handed
    _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,         _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
    KA_GESC,    KC_QUOT,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,       _______,         _______,    KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       _______,
    KA_CBS,     KC_A,       KC_O,       KC_E,       KC_U,       KC_I,       _______,         _______,    KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       _______,
    KA_LSFT,    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X,                                    KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       _______,
    KA_LBRC,    KA_MR1,     KA_MR2,     KA_LEFT,    KA_RGHT,         _______,                     _______,           _______,    _______,    _______,    _______,    _______,
                                                    KA_OHT1,    KA_OHT2,    KA_OHT3,         KA_OHT3,    KA_OHT2,    KA_OHT1
  ), // }}}

  [L_OHF] = LAYOUT_moonlander( // {{{ one-handed flipped
    _______,    KC_0,       KC_9,       KC_8,       KC_7,       KC_6,       _______,         _______,    KC_5,       KC_4,       KC_3,       KC_2,       KC_1,       _______,
    _______,    KC_L,       KC_R,       KC_C,       KC_G,       KC_F,       _______,         _______,    KC_Y,       KC_P,       KC_DOT,     KC_COMM,    KC_QUOT,    _______,
    _______,    KC_S,       KC_N,       KC_T,       KC_H,       KC_D,       _______,         _______,    KC_I,       KC_U,       KC_E,       KC_O,       KC_A,       _______,
    _______,    KC_Z,       KC_V,       KC_W,       KC_M,       KC_B,                                    KC_X,       KC_K,       KC_J,       KC_Q,       KC_SCLN,    _______,
    _______,    _______,    _______,    _______,    _______,         _______,                     _______,           _______,    _______,    _______,    _______,    _______,
                                                    _______,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    _______
  ), // }}}

  [L_OHS] = LAYOUT_moonlander_mirrored( // {{{ one-handed symbols
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
    KC_LGUI,    KC_GRV,     KC_1,       KC_2,       KC_3,       KC_LBRC,    KC_RBRC,
    KC_LCTL,    KC_SLSH,    KC_4,       KC_5,       KC_6,       KC_MINS,    KC_EQL,
    KC_LSFT,    KC_BSLS,    KC_7,       KC_8,       KC_9,       KC_0,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         _______,
                                                    _______,    _______,    _______
  ), // }}}

  [L_QRTY] = LAYOUT_moonlander( // {{{ qwerty
    KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,         _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_EQL,
    _______,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       _______,         _______,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       RGUI_T(KC_MINS),
    _______,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       _______,         _______,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCOLON,  RCTL_T(KC_QUOT),
    _______,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                                    KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   _______,
    _______,    _______,    _______,    _______,    _______,         _______,                     _______,           _______,    _______,    _______,    _______,    _______,
                                                    _______,    _______,    _______,         _______,    _______,    _______
  ), // }}}

  [L_VELO] = LAYOUT_moonlander( // {{{ velotype
    XXXXXXX,    KC_F17,     KC_F18,     KC_F19,     KC_F20,     XXXXXXX,    _______,         _______,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    VL_LP,      VL_LK,      VL_LI,      VL_APO,     XXXXXXX,         XXXXXXX,    VL_APO,     VL_RO,      VL_RK,      VL_RP,      XXXXXXX,    XXXXXXX,
    VL_LZ,      VL_LF,      VL_LT,      VL_LJ,      VL_LO,      VL_U,       XXXXXXX,         XXXXXXX,    VL_U,       VL_RI,      VL_RJ,      VL_RT,      VL_RF,      VL_RZ,
    VL_LZ,      VL_LS,      VL_LC,      VL_LR,      VL_LE,      VL_A,                                    VL_A,       VL_RE,      VL_RR,      VL_RC,      VL_RS,      VL_RZ,
    VL_H,       VL_LSH,     XXXXXXX,    VL_LSYM,    VL_Y,            VL_NOS,                      VL_NOS,            VL_Y,       VL_RSYM,    XXXXXXX,    VL_RSH,      VL_H,
                                                    VL_LL,      VL_LN,      VL_NOS,          VL_NOS,     VL_RN,      VL_RL
  ), // }}}

  [L_PLO] = LAYOUT_moonlander( // {{{ plover via keyboard
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,     XXXXXXX,         XXXXXXX,    PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,
    XXXXXXX,    PV_LS,      PV_LT,      PV_LP,      PV_LH,      PV_STAR,    XXXXXXX,         XXXXXXX,    PV_STAR,    PV_RF,      PV_RP,      PV_RL,      PV_RT,      PV_RD,
    XXXXXXX,    PV_LS,      PV_LK,      PV_LW,      PV_LR,      PV_STAR,                                 PV_STAR,    PV_RR,      PV_RB,      PV_RG,      PV_RS,      PV_RZ,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         _______,                     _______,           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    PV_A,       PV_O,       XXXXXXX,         XXXXXXX,    PV_E,       PV_U
  ), // }}}

  [L_PLOS] = LAYOUT_moonlander( // {{{ plover via gemini pr
    STN_PWR,    STN_FN,     STN_RE1,    STN_RE2,    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    STN_NA,     STN_N1,     STN_N2,     STN_N3,     STN_N4,     STN_N5,     XXXXXXX,         XXXXXXX,    STN_N6,     STN_N7,     STN_N8,     STN_N9,     STN_NB,     STN_NC,
    XXXXXXX,    STN_S1,     STN_TL,     STN_PL,     STN_HL,     STN_ST1,    XXXXXXX,         XXXXXXX,    STN_ST3,    STN_FR,     STN_PR,     STN_LR,     STN_TR,     STN_DR,
    XXXXXXX,    STN_S2,     STN_KL,     STN_WL,     STN_RL,     STN_ST2,                                 STN_ST4,    STN_RR,     STN_BR,     STN_GR,     STN_SR,     STN_ZR,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         _______,                     _______,           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    STN_A,      STN_O,      XXXXXXX,         XXXXXXX,    STN_E,      STN_U
  ), // }}}

  [L_GBA] = LAYOUT_moonlander( // {{{ gaming base
    KC_GRAVE,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_ESC,     KC_TAB,     KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    KC_6,            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_BSPC,    KC_DEL,     KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDOWN,  KC_7,            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_LSFT,    KC_LCTRL,   KC_MINUS,   KC_EQUAL,   KC_SLASH,   KC_8,                                    _______,    _______,    _______,    _______,    _______,    _______,
    XXXXXXX,    KC_LBRC,    KC_RBRC,    KC_0,       KC_9,            TG(L_OH),                    _______,           _______,    _______,    _______,    _______,    _______,
                                                    KC_SPC,     KC_LALT,    KC_ENTER,        _______,    _______,    _______
  ), // }}}

  [L_GNU] = LAYOUT_moonlander( // {{{ gaming numpad
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         KC_NLCK,    KC_PAST,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    KC_F12,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         XXXXXXX,    KC_PSLS,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    KC_RCTL,
    _______,    _______,    _______,    _______,    _______,    _______,                                 KC_P0,      KC_P7,      KC_P8,      KC_P9,      KC_LALT,    KC_RSFT,
    _______,    _______,    _______,    _______,    _______,         _______,                     _______,           KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,
                                                    _______,    _______,    _______,         XXXXXXX,    KC_PDOT,    KC_PENT
  ), // }}}

  [L_MUS] = LAYOUT_moonlander( // {{{ music
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         MU_TOG,                       MU_MOD,           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX
  ), // }}}

  [L_MOUS] = LAYOUT_moonlander( // {{{ mouse
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    KC_LGUI,    XXXXXXX,    KC_BTN4,    KC_MS_U,    KC_BTN5,    KC_WH_U,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_WH_U,    XXXXXXX,    XXXXXXX,    KC_RGUI,
    KC_LCTL,    KC_ACL2,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_D,    XXXXXXX,         XXXXXXX,    XXXXXXX,    KC_WH_L,    KC_WH_D,    KC_WH_R,    XXXXXXX,    KC_RCTL,
    KC_LSFT,    XXXXXXX,    KC_WH_L,    XXXXXXX,    KC_WH_R,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_RSFT,
    KC_LCTL,    KC_LALT,    KC_RALT,    KC_ACL0,    KC_ACL1,         _______,                      _______,          KC_LALT,    KC_RGUI,    KC_RALT,    KC_LALT,    KC_RCTL,
                                                    KC_BTN1,    KC_BTN2,    KC_BTN3,         KC_ACL0,    KC_ACL1,    KC_ACL2
  ), // }}}

  [L_SYMS] = LAYOUT_moonlander( // {{{ symbols
    XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,         _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     XXXXXXX,
    KC_LGUI,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_F11,          KC_F12,     KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_RGUI,
    KC_LCTL,    KC_TILD,    KC_DQUO,    KC_COLN,    US_PND,     KC_LCBR,    XXXXXXX,         XXXXXXX,    KC_RCBR,    KC_PIPE,    KC_UNDS,    KC_QUES,    KC_PLUS,    KC_RCTL,
    KC_LSFT,    KC_GRV,     KC_QUOT,    KC_SCLN,    XXXXXXX,    KC_LBRC,                                 KC_RBRC,    KC_BSLS,    KC_MINS,    KC_SLSH,    KC_EQL,     KC_RSFT,
    SH_MON,     KC_LALT,    KC_RALT,    XXXXXXX,    XXXXXXX,         XXXXXXX,                      XXXXXXX,          XXXXXXX,    XXXXXXX,    KC_RALT,    KC_LALT,    SH_MON,
                                                    _______,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    _______
  ), // }}}

  [L_NAVI] = LAYOUT_moonlander( // {{{ navigation
    KC_CAPS,    XXXXXXX,    KC_PSCR,    KC_SLCK,    KC_PAUS,    XXXXXXX,    _______,         _______,    XXXXXXX,    KC_PAUS,    KC_SLCK,    KC_PSCR,    XXXXXXX,   KC_CAPS,
    KC_LGUI,    KC_TAB,     KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    XXXXXXX,         XXXXXXX,    KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_TAB,    KC_RGUI,
    KC_LCTL,    KC_ESC,     KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,    KC_ENT,          KC_ENT,     KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ESC,    KC_RCTL,
    KC_LSFT,    XXXXXXX,    KC_BSPC,    XXXXXXX,    KC_DEL,     XXXXXXX,                                 XXXXXXX,    KC_BSPC,    XXXXXXX,    KC_DEL,     XXXXXXX,   KC_RSFT,
    KC_LCTL,    KC_LALT,    KC_RALT,    KC_LGUI,    KC_LALT,         XXXXXXX,                     XXXXXXX,           KC_LALT,    KC_RGUI,    KC_RALT,    KC_LALT,   KC_RCTL,
                                                    _______,    _______,    _______,         _______,    _______,    _______
  ), // }}}

  [L_NUM] = LAYOUT_moonlander( // {{{ numpad
    KC_NLCK,    KC_A,       KC_B,       KC_C,       KC_D,       KC_E,       _______,         _______,    KC_A,       KC_B,       KC_C,       KC_D,       KC_E,       KC_F,
    KC_LGUI,    KC_PAST,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    KC_F,            KC_NLCK,    KC_PAST,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    KC_RGUI,
    KC_LCTL,    KC_PSLS,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    KC_PENT,         KC_PENT,    KC_PSLS,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    KC_RCTL,
    KC_LSFT,    KC_PEQL,    KC_P7,      KC_P8,      KC_P9,      KC_P0,                                   KC_P0,      KC_P7,      KC_P8,      KC_P9,      KC_PEQL,    KC_RSFT,
    KC_LCTL,    KC_LALT,    KC_RALT,    KC_PCMM,    KC_PDOT,         XXXXXXX,                      XXXXXXX,          KC_PDOT,    KC_PCMM,    KC_RALT,    KC_LALT,    XXXXXXX,
                                                    _______,    _______,    _______,         _______,    _______,    _______
  ), // }}}

  [L_SHRT] = LAYOUT_moonlander_mirrored( // {{{ shortcuts
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
    _______,    XXXXXXX,    C(KC_X),    C(KC_C),    C(KC_V),    XXXXXXX,
    _______,    _______,    _______,    _______,    _______,         XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,    _______
  ), // }}}

  [L_LAY] = LAYOUT_moonlander_mirrored( // {{{ layer switching
    TO(L_BASE), TO(L_DVK),  TO(L_VELO), TO_GAME,    XXXXXXX,    TO(L_MUS),  _______,
    MO(L_SYS),  TO(L_QRTY), TO(L_PLO),  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    MO(L_CONF), XXXXXXX,    TO(L_PLOS), XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    MO(L_MEDI), XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    MO(L_WEB),  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,    XXXXXXX
  ), // }}}

  [L_MEDI] = LAYOUT_moonlander_mirrored( // {{{ media
    _______,    KC_CALC,    KC_MAIL,    KC_MYCM,    KC_MSEL,    XXXXXXX,    _______,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_VOLD,    KC_VOLU,    XXXXXXX,    KC_EJCT,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MPRV,    KC_MNXT,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MFFD,    KC_MRWD,         XXXXXXX,
                                                    KC_MUTE,    KC_MPLY,    KC_MSTP
  ), // }}}

  [L_WEB] = LAYOUT_moonlander_mirrored( // {{{ web
    _______,    KC_WHOM,    KC_WFAV,    XXXXXXX,    KC_WSCH,    KC_WREF,    _______,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,
                                                    KC_WBAK,    KC_WFWD,    KC_WSTP
  ), // }}}

  [L_SYS] = LAYOUT_moonlander_mirrored( // {{{ system
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_SLEP,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_PWR,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,
                                                    KC_WAKE,    KC_WAKE,    KC_WAKE
  ), // }}}

  [L_CONF] = LAYOUT_moonlander_mirrored( // {{{ config
    _______,    MU_TOG,     AU_TOG,     LED_LEVEL,  NK_TOGG,    XXXXXXX,    _______,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_SAD,    RGB_SAI,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_SPD,    RGB_SPI,    XXXXXXX,    RESET,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_VAD,    RGB_VAI,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_HUD,    RGB_HUI,         RGB_TOG,
                                                    ZSA_COL,    RGB_SLD,    RGB_MOD
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
  LEDS_VELO,
  LEDS_PLO,
  LEDS_PLOS,
  LEDS_MOUS,
} led_maps_both_t;

const color_t PROGMEM ledmap_both[][DRIVER_LED_TOTAL] = {
  /* {{{ template
   * the last row holds the thumb keys
   * the launch key is closest to the inner edge
  [L_] = {
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____,

    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
            C_____, C_____, C_____, C_____, C_____, C_____,
                    C_____, C_____, C_____, C_____, C_____,
                            C_____, C_____, C_____, C_____
  }, */ // }}}

  [LEDS_VELO] = { // {{{ velotype
  }, // }}}

  [LEDS_PLO] = { // {{{ plover via keyboard
  }, // }}}

  [LEDS_PLOS] = { // {{{ plover via gemini pr
  }, // }}}

  [LEDS_MOUS] = { // {{{ mouse
    C_____, C_____, C_____, C_____, C_____, C_____, C_SU_5,
    C_SU_4, C_____, C_SU_2, C_SU_1, C_SU_2, C_SU_2, C_____,
    C_SU_4, C_SU_3, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_____,
    C_SU_4, C_____, C_SU_2, C_____, C_SU_2, C_____,
    C_____, C_SU_4, C_SU_4, C_SU_3, C_SU_3,
    C_SU_1, C_SU_1, C_SU_1, C_SU_5,

    C_SU_5, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_SU_1, C_____, C_____, C_SU_4,
    C_____, C_____, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_4,
            C_____, C_____, C_____, C_____, C_____, C_SU_4,
                    C_____, C_____, C_SU_4, C_SU_4, C_____,
                            C_____, C_SU_3, C_SU_3, C_SU_3,
  }, // }}}
};

// LED configuration that declares only left LEDs
// used by mirrored layers too
typedef enum led_maps_left_t {
  LEDS_BASE,
  LEDS_DVK,
  LEDS_OH,
  LEDS_OHS,
  LEDS_QRTY,
  LEDS_GBA,
  LEDS_MUS,
  LEDS_SYMS,
  LEDS_NAVI,
  LEDS_NUM,
  LEDS_SHRT,
  LEDS_LAY,
  LEDS_MEDI,
  LEDS_WEB,
  LEDS_SYS,
  LEDS_CONF,
} led_maps_left_t;

// used by mirrored layers too
const color_t PROGMEM ledmap_left[][DRIVER_LED_TOTAL / 2] = {
  /* {{{ template
   * the last row holds the thumb keys
   * the launch key is rightmost
  [L_] = {
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____,
  }, */ // }}}

  [LEDS_BASE] = { // {{{ base
    C_____, C_____, C_____, C_____, C_____, C_____, C_SU_5,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_SU_5,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_SU_5,
    C_SU_4, C_____, C_____, C_____, C_____, C_____,
    C_SU_4, C_SU_4, C_SU_4, C_SU_3, C_SU_3,
    C_SU_5, C_SU_5, C_SU_5, C_SU_5,
  }, // }}}

  [LEDS_DVK] = { // {{{ dvorak
    C_SU_2, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_5,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_5,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_5,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2,
    C_SU_4, C_SU_4, C_SU_4, C_SU_3, C_SU_3,
    C_SU_5, C_SU_5, C_SU_5, C_SU_5,
  }, // }}}

  [LEDS_OH] = { // {{{ one hand
    C_TO_2, C_TO_3, C_TO_3, C_TO_3, C_TO_3, C_TO_3, C_TO_5,
    C_TO_4, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_5,
    C_TO_4, C_TO_1, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_TO_5,
    C_TO_4, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2,
    C_TO_4, C_TO_4, C_TO_4, C_TO_3, C_TO_3,
    C_TO_5, C_TO_5, C_TO_5, C_TO_5,
  }, // }}}

  [LEDS_OHS] = { // {{{ one hand
    C_____, C_____, C_____, C_____, C_____, C_____, C_TO_5,
    C_TO_4, C_TO_2, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_TO_2,
    C_TO_4, C_TO_2, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_TO_2,
    C_TO_4, C_TO_2, C_TO_1, C_TO_1, C_TO_1, C_TO_1,
    C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____,
  }, // }}}

  [LEDS_QRTY] = { // {{{ qwerty
    C_DS_2, C_DS_3, C_DS_3, C_DS_3, C_DS_3, C_DS_3, C_DS_5,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_5,
    C_DS_4, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_2, C_DS_5,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2,
    C_DS_4, C_DS_4, C_DS_4, C_DS_3, C_DS_3,
    C_DS_5, C_DS_5, C_DS_5, C_DS_5,
  }, // }}}

  [LEDS_GBA] = { // {{{ gaming base
    C_RU_2, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_5,
    C_RU_4, C_RU_2, C_RU_2, C_RU_1, C_RU_2, C_RU_2, C_RU_3,
    C_RU_4, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,
    C_RU_4, C_RU_2, C_RU_2, C_RU_2, C_RU_2, C_RU_3,
    C_____, C_RU_3, C_RU_3, C_RU_3, C_RU_3,
    C_RU_2, C_RU_2, C_RU_2, C_RU_5,
  }, // }}}

  [LEDS_MUS] = { // {{{ music
    C_____, C_____, C_____, C_____, C_____, C_____, C_TO_5,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_TO_5,
  }, // }}}

  [LEDS_SYMS] = { // {{{ symbols
    C_____, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_5,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_3,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_____,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2,
    C_SU_1, C_SU_4, C_SU_4, C_____, C_____,
    C_____, C_____, C_____, C_____,
  }, // }}}

  [LEDS_NAVI] = { // {{{ navigation
    C_SU_4, C_____, C_SU_4, C_SU_4, C_SU_4, C_____, C_SU_5,
    C_SU_3, C_SU_2, C_SU_2, C_SU_1, C_SU_2, C_SU_2, C_____,
    C_SU_3, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_2,
    C_SU_3, C_____, C_SU_2, C_____, C_SU_2, C_____,
    C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3,
    C_____, C_____, C_____, C_____,
  }, // }}}

  [LEDS_NUM] = { // {{{ numpad
    C_SU_1, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_5,
    C_SU_3, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_3,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_1,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_1,
    C_SU_4, C_SU_4, C_SU_4, C_SU_2, C_SU_2,
    C_____, C_____, C_____, C_____,
  }, // }}}

  [LEDS_SHRT] = { // {{{ shortcuts
    C_____, C_____, C_____, C_____, C_____, C_____, C_SU_5,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____,
    C_SU_4, C_____, C_SU_1, C_SU_1, C_SU_1, C_____,
    C_SU_4, C_SU_4, C_SU_4, C_SU_3, C_SU_3,
    C_____, C_____, C_____, C_____,
  }, // }}}

  [LEDS_LAY] = { // {{{ layer switching
    C_SU_5, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_1, C_____,
    C_SU_4, C_SU_1, C_SU_1, C_____, C_____, C_____, C_____,
    C_SU_4, C_____, C_SU_1, C_____, C_____, C_____, C_____,
    C_SU_4, C_____, C_____, C_____, C_____, C_____,
    C_SU_4, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____,
  }, // }}}

  [LEDS_MEDI] = { // {{{ media
    C_SU_5, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_____, C_SU_5,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_SU_1, C_SU_1, C_____, C_SU_2,
    C_____, C_____, C_____, C_SU_1, C_SU_1, C_____,
    C_____, C_____, C_____, C_SU_1, C_SU_1,
    C_SU_1, C_SU_1, C_SU_1, C_____,
  }, // }}}

  [LEDS_WEB] = { // {{{ web
    C_SU_5, C_SU_1, C_SU_1, C_____, C_SU_1, C_SU_1, C_SU_5,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____,
    C_SU_1, C_SU_1, C_SU_1, C_____,
  }, // }}}

  [LEDS_SYS] = { // {{{ system
    C_SU_5, C_____, C_____, C_____, C_____, C_____, C_SU_5,
    C_____, C_____, C_____, C_____, C_____, C_____, C_SU_1,
    C_____, C_____, C_____, C_____, C_____, C_____, C_SU_1,
    C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____,
    C_SU_1, C_SU_1, C_SU_1, C_____,
  }, // }}}

  // {{{ config
  [LEDS_CONF] = {
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4, C_____, C_SU_5,
    C_____, C_____, C_____, C_SU_2, C_SU_2, C_____, C_SU_4,
    C_____, C_____, C_____, C_SU_2, C_SU_2, C_____, C_SU_4,
    C_____, C_____, C_____, C_SU_2, C_SU_2, C_____,
    C_____, C_____, C_____, C_SU_2, C_SU_2,
    C_SU_2, C_SU_2, C_SU_2, C_SU_2,
  }, // }}}
};

// LED configuration that declares only right LEDs
typedef enum led_maps_right_t {
  LEDS_GNU,
} led_maps_right_t;

const color_t PROGMEM ledmap_right[][DRIVER_LED_TOTAL / 2] = {
  /* {{{ template
   * the last row holds the thumb keys
   * the launch key is leftmost
  [L_] = {
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
            C_____, C_____, C_____, C_____, C_____, C_____,
                    C_____, C_____, C_____, C_____, C_____,
                            C_____, C_____, C_____, C_____,
  }, */ // }}}

  // {{{ gaming numpad
  [L_GNU] = {
    C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_4, C_RU_4, C_RU_4,
    C_RU_4, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_4,
    C_____, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,
            C_RU_1, C_RU_1, C_RU_1, C_RU_1, C_RU_3, C_RU_3,
                    C_____, C_RU_4, C_RU_4, C_RU_4, C_RU_4,
                            C_____, C_____, C_RU_2, C_RU_1,
  }, // }}}
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
  [L_BASE]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_BASE], .inds = 0b0000, },
  [L_DVK]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_DVK],  .inds = 0b0001, },
  [L_QRTY]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_QRTY], .inds = 0b0001, },
  [L_VELO]  = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_VELO], .inds = 0b0010, },
  [L_PLO]   = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_PLO],  .inds = 0b0010, },
  [L_PLOS]  = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_PLOS], .inds = 0b0011, },
  [L_GBA]   = { .mode = LM_LEFT,   .colors = ledmap_left[LEDS_GBA],  .inds = 0b0000, },
  [L_GNU]   = { .mode = LM_RIGHT,  .colors = ledmap_right[LEDS_GNU], .inds = 0b0100, },
  [L_MUS]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_MUS],  .inds = 0b0111, },
  [L_OH]    = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_OH],   .inds = 0b0000, },
  [L_OHF]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_OH],   .inds = 0b1100, },
  [L_OHS]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_OHS],  .inds = 0b1001, },
  [L_MOUS]  = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_MOUS], .inds = 0b0111, },
  [L_SYMS]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_SYMS], .inds = 0b1001, },
  [L_NAVI]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_NAVI], .inds = 0b1010, },
  [L_NUM]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_NUM],  .inds = 0b1100, },
  [L_SHRT]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_SHRT], .inds = 0b1011, },
  [L_LAY]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_LAY],  .inds = 0b1000, },
  [L_MEDI]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_MEDI], .inds = 0b1101, },
  [L_WEB]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_WEB],  .inds = 0b1110, },
  [L_SYS]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_SYS],  .inds = 0b1111, },
  [L_CONF]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_CONF], .inds = 0b1111, },
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

// inverted_rows is used to write a left-side LED map onto the right hand side
void set_board_colors(const color_t *colors, led_mode_t led_mode, bool mask_left, bool mask_right) { // {{{
  if (led_mode == LM_NONE) {
    return;
  }

  int color_ind = 0;
  bool inverted_cols = false;

  if (led_mode != LM_RIGHT) {
    for (int row_ind = 0; row_ind < (MATRIX_ROWS / 2); row_ind++) {
      for (int col_ind = 0; col_ind < MATRIX_COLS; col_ind++) {
        int real_row_ind = row_ind;
        int real_col_ind = inverted_cols ? MATRIX_COLS - col_ind - 1 : col_ind;
#ifdef SWAP_HANDS_ENABLE
        if (swap_hands) {
          const keypos_t *pos = &hand_swap_config[real_row_ind][real_col_ind];
          real_row_ind = pos->row;
          real_col_ind = pos->col;
        }
#endif

        uint16_t led = g_led_config.matrix_co[real_row_ind][real_col_ind];
        if (led == NO_LED) { continue; }

        if (!mask_left) {
          set_led_color(led, colors[color_ind]);
        }

        color_ind++;
      }
    }
  }

  if (led_mode == LM_MIRROR) {
    inverted_cols = true;
    color_ind = 0;
  }

  if (led_mode != LM_LEFT) {
    for (int row_ind = (MATRIX_ROWS / 2) ; row_ind < MATRIX_ROWS; row_ind++) {
      for (int col_ind = 0; col_ind < MATRIX_COLS; col_ind++) {
        int real_row_ind = row_ind;
        int real_col_ind = inverted_cols ? MATRIX_COLS - col_ind - 1 : col_ind;
#ifdef SWAP_HANDS_ENABLE
        if (swap_hands) {
          const keypos_t *pos = &hand_swap_config[real_row_ind][real_col_ind];
          real_row_ind = pos->row;
          real_col_ind = pos->col;
        }
#endif

        uint16_t led = g_led_config.matrix_co[real_row_ind][real_col_ind];
        if (led == NO_LED) { continue; }

        if (!mask_right) {
          set_led_color(led, colors[color_ind]);
        }

        color_ind++;
      }
    }
  }
} // }}}

void rgb_matrix_indicators_user(void) { // {{{
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }

  bool right_leds_set = false, left_leds_set = false;
  layer_state_t layers = layer_state | default_layer_state;
  /* check top layer first */
  for (int8_t layer = MAX_LAYER - 1; layer >= 0; layer--) {
    if (layers & (1UL << layer)) {
      const layer_led_config_t *led_config = &ledmap[layer];
      led_mode_t mode = led_config->mode;

      set_board_colors(led_config->colors, mode, left_leds_set, right_leds_set);

      if (mode == LM_MIRROR || mode == LM_BOTH || mode == LM_LEFT) {
        left_leds_set = true;
      }

      if (mode == LM_MIRROR || mode == LM_BOTH || mode == LM_RIGHT) {
        right_leds_set = true;
      }

      if (right_leds_set && left_leds_set) { return; }
    }
  }

  if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
    rgb_matrix_set_color_all(0, 0, 0);
  }
} // }}}

bool process_record_user(uint16_t keycode, keyrecord_t *record) { // {{{
  switch (keycode) {
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

layer_state_t layer_state_set_user(layer_state_t state) { // {{{
  /* check top layer first */
  for (int8_t layer = MAX_LAYER - 1; layer >= 0; layer--) {
    if (state & (1UL << layer)) {
      uint8_t inds = ledmap[layer].inds;
      if (inds || layer == 0) {
        ML_LED_1((inds & 0b0001) != 0);
        ML_LED_2((inds & 0b0010) != 0);
        ML_LED_3((inds & 0b0100) != 0);
        ML_LED_4((inds & 0b1000) != 0);
        break;
      }
    }
  }

  /* ML_LED_5(overflow || (layer & 0b010000)); */
  /* ML_LED_6(overflow || (layer & 0b100000)); */

  return state;
} // }}}

/* vim: set foldmethod=marker : */
