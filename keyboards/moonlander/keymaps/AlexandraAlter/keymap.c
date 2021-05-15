#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"
#include "keymap_plover.h"
#include "keymap_velotype.h"

// planning
/* Base layers:
 *  Dvorak
 *  Velotype
 *  Plover
 *  Qwerty
 *  Gaming Arrows
 *
 *
 **/

typedef enum layer_t {
  // {{{
  L_BASE = 0,
  L_G_BA,  // gaming base
  L_DVK,   // dvorak
  L_VELO,  // velotype
  L_PLO,   // plover
  L_QRTY,  // qwerty
  L_MUS,   // music
  L_SYMS,  // symbols
  L_NAVI,  // navigation
  L_NUM,   // numpad
  L_SHRT,  // shortcuts
  L_MOUS,  // mouse
  L_OH,    // one hand
  L_G_NU,  // gaming numpad
  L_MEDI,  // media
  // layers 16+ below this point
  L_WEB,   // web
  L_SYS,   // system
  L_CONF,  // config
  L_MAX,
  // }}}
} layer_t;

typedef enum custom_keycode_t {
  // {{{
  RGB_SLD = ML_SAFE_RANGE,
  KA_TO_G,
  // }}}
} custom_keycode_t;

#define ZSA_COL TOGGLE_LAYER_COLOR

#define KA_LT1 LT(L_SYMS, KC_SPC)
#define KA_LT2 LT(L_NAVI, KC_TAB)
#define KA_LT3 LT(L_SHRT, KC_ENT)
#define KA_RT1 LT(L_NAVI, KC_ENT)
#define KA_RT2 LT(L_NUM,  KC_DEL)
#define KA_RT3 LT(L_SHRT, KC_APP)

#define KA_ESC  LGUI_T(KC_ESC)
#define KA_BSPC LCTL_T(KC_BSPC)
#define KA_LBRC LALT_T(KC_LBRC)
#define KA_SLSH RGUI_T(KC_SLSH)
#define KA_MINS RCTL_T(KC_MINS)
#define KA_RBRC RALT_T(KC_RBRC)

#define KA_QMINS RGUI_T(KC_MINS)
#define KA_QQUOT RCTL_T(KC_QUOT)

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

  // {{{ base
  [L_BASE] = LAYOUT_moonlander(
    TO(L_BASE), TO(L_DVK),  TO(L_VELO), KA_TO_G,    XXXXXXX,    XXXXXXX,    TO(L_BASE),      TO(L_BASE), XXXXXXX,    XXXXXXX,    KA_TO_G,    TO(L_VELO), TO(L_DVK),  TO(L_BASE),
    KC_LGUI,    TO(L_QRTY), TO(L_PLO),  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TO(L_PLO),  TO(L_QRTY), KC_RGUI,
    KC_LCTL,    MO(L_MEDI), XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TG(L_NUM),       TG(L_NAVI), XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    MO(L_MEDI), KC_RCTL,
    KC_LSFT,    MO(L_CONF), XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    MO(L_CONF), KC_RSFT,
    XXXXXXX,    KC_RALT,    KC_LALT,    KC_LEFT,    KC_RGHT,         TG(L_MOUS),                  XXXXXXX,           KC_DOWN,    KC_UP,      KC_LALT,    KC_RALT,    XXXXXXX,
                                                    KA_LT1,     KA_LT2,     KA_LT3,          KA_RT3,     KA_RT2,     KA_RT1
  ), // }}}

  // {{{ dvorak
  [L_DVK] = LAYOUT_moonlander(
    KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,         _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_EQL,
    KA_ESC,     KC_QUOT,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,       XXXXXXX,         XXXXXXX,    KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       KA_SLSH,
    KA_BSPC,    KC_A,       KC_O,       KC_E,       KC_U,       KC_I,       _______,         _______,    KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       KA_MINS,
    KC_LSPO,    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X,                                    KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       KC_RSPC,
    XXXXXXX,    _______,    KA_LBRC,    _______,    _______,         XXXXXXX,                     XXXXXXX,           _______,    _______,    KA_RBRC,    _______,    KC_BSLS,
                                                    _______,    _______,    _______,         _______,    _______,    _______
  ), // }}}

  // {{{ qwerty
  [L_QRTY] = LAYOUT_moonlander(
    KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,         _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_EQL,
    KA_ESC,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       XXXXXXX,         XXXXXXX,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KA_QMINS,
    KA_BSPC,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       XXXXXXX,         XXXXXXX,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCOLON,  KA_QQUOT,
    KC_LSPO,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                                    KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_RSPC,
    XXXXXXX,    _______,    KC_LBRC,    _______,    _______,         XXXXXXX,                     XXXXXXX,           _______,    _______,    KA_RBRC,    _______,    KC_BSLS,
                                                    _______,    _______,    _______,         _______,    _______,    _______
  ), // }}}

  // {{{ velotype
  [L_VELO] = LAYOUT_moonlander(
    XXXXXXX,    KC_F17,     KC_F18,     KC_F19,     KC_F20,     XXXXXXX,    _______,         _______,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    VL_LP,      VL_LK,      VL_LI,      VL_APO,     XXXXXXX,         XXXXXXX,    VL_APO,     VL_RO,      VL_RK,      VL_RP,      XXXXXXX,    XXXXXXX,
    VL_LZ,      VL_LF,      VL_LT,      VL_LJ,      VL_LO,      VL_U,       XXXXXXX,         XXXXXXX,    VL_U,       VL_RI,      VL_RJ,      VL_RT,      VL_RF,      VL_RZ,
    VL_LZ,      VL_LS,      VL_LC,      VL_LR,      VL_LE,      VL_A,                                    VL_A,       VL_RE,      VL_RR,      VL_RC,      VL_RS,      VL_RZ,
    VL_H,       VL_LSH,     XXXXXXX,    VL_LSYM,    VL_Y,            VL_NOS,                      VL_NOS,            VL_Y,       VL_RSYM,    XXXXXXX,    VL_RSH,      VL_H,
                                                    VL_LL,      VL_LN,      VL_NOS,          VL_NOS,     VL_RN,      VL_RL
  ), // }}}

  // {{{ plover
  [L_PLO] = LAYOUT_moonlander(
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
    _______,    PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,     XXXXXXX,         XXXXXXX,    PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,
    _______,    PV_LS,      PV_LT,      PV_LP,      PV_LH,      PV_STAR,    XXXXXXX,         XXXXXXX,    PV_STAR,    PV_RF,      PV_RP,      PV_RL,      PV_RT,      PV_RD,
    _______,    PV_LS,      PV_LK,      PV_LW,      PV_LR,      PV_STAR,                                 PV_STAR,    PV_RR,      PV_RB,      PV_RG,      PV_RS,      PV_RZ,
    XXXXXXX,    _______,    _______,    _______,    _______,         XXXXXXX,                     XXXXXXX,           _______,    _______,    XXXXXXX,    _______,    XXXXXXX,
                                                    PV_A,       PV_O,       XXXXXXX,         XXXXXXX,    PV_E,       PV_U
  ), // }}}

  // {{{ gaming base
  [L_G_BA] = LAYOUT_moonlander(
    KC_GRAVE,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_ESC,     KC_TAB,     KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    KC_6,            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_BSPC,    KC_DELETE,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDOWN,  KC_7,            _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_LSFT,    KC_LCTRL,   KC_MINUS,   KC_EQUAL,   KC_SLASH,   KC_8,                                    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    KC_LBRC,    KC_RBRC,    KC_0,       KC_9,            XXXXXXX,                    _______,           _______,    _______,    _______,    _______,    _______,
                                                    KC_SPC,     KC_LALT,    KC_ENTER,        _______,    _______,    _______
  ), // }}}

  // {{{ gaming numpad
  [L_G_NU] = LAYOUT_moonlander(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         KC_NLCK,    KC_PAST,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    KC_F12,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    KC_PSLS,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    KC_RCTL,
    _______,    _______,    _______,    _______,    _______,    _______,                                 KC_P0,      KC_P7,      KC_P8,      KC_P9,      KC_LALT,    KC_RSFT,
    _______,    _______,    _______,    _______,    _______,         TG(L_DVK),                   _______,           KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,
                                                    _______,    _______,    _______,         _______,    KC_PDOT,    KC_PENT
  ), // }}}

  // {{{ music
  [L_MUS] = LAYOUT_moonlander(
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         MU_TOG,                       MU_MOD,           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX
  ), // }}}

  // {{{ symbols
  [L_SYMS] = LAYOUT_moonlander(
    XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,         _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     XXXXXXX,
    KC_LGUI,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_F11,          KC_F12,     KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_RGUI,
    KC_LCTL,    KC_TILD,    KC_DQUO,    KC_COLN,    US_PND,     KC_LCBR,    XXXXXXX,         XXXXXXX,    KC_RCBR,    KC_PIPE,    KC_UNDS,    KC_QUES,    KC_PLUS,    KC_RCTL,
    KC_LSFT,    KC_GRV,     KC_QUOT,    KC_SCLN,    XXXXXXX,    KC_LBRC,                                 KC_RBRC,    KC_BSLS,    KC_MINS,    KC_SLSH,    KC_EQL,     KC_RSFT,
    SH_MON,     KC_LALT,    KC_RALT,    XXXXXXX,    XXXXXXX,         XXXXXXX,                      XXXXXXX,          XXXXXXX,    XXXXXXX,    KC_RALT,    KC_LALT,    SH_MON,
                                                    _______,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    _______
  ), // }}}

  // {{{ navigation
  [L_NAVI] = LAYOUT_moonlander(
    KC_CAPS,    XXXXXXX,    KC_PSCR,    KC_SLCK,    KC_PAUS,    XXXXXXX,    _______,         _______,    XXXXXXX,    KC_PAUS,    KC_SLCK,    KC_PSCR,    XXXXXXX,   KC_CAPS,
    KC_LGUI,    KC_TAB,     KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    XXXXXXX,         XXXXXXX,    KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_TAB,    KC_RGUI,
    KC_LCTL,    KC_ESC,     KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,    KC_ENT,          KC_ENT,     KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ESC,    KC_RCTL,
    KC_LSFT,    KC_BSPC,    KC_DEL,     XXXXXXX,    XXXXXXX,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_DEL,     KC_BSPC,   KC_RSFT,
    XXXXXXX,    KC_LALT,    KC_RALT,    XXXXXXX,    XXXXXXX,         XXXXXXX,                     XXXXXXX,           XXXXXXX,    XXXXXXX,    KC_RALT,    KC_LALT,   XXXXXXX,
                                                    XXXXXXX,    _______,    XXXXXXX,         XXXXXXX,    _______,    XXXXXXX
  ), // }}}

  // {{{ numpad
  [L_NUM] = LAYOUT_moonlander(
    KC_NLCK,    KC_A,       KC_B,       KC_C,       KC_D,       KC_E,       _______,         _______,    KC_A,       KC_B,       KC_C,       KC_D,       KC_E,       KC_F,
    KC_X,       KC_PAST,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    KC_F,            KC_NLCK,    KC_PAST,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    KC_X,
    KC_LCTL,    KC_PSLS,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    XXXXXXX,         XXXXXXX,    KC_PSLS,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    KC_RCTL,
    KC_LSFT,    KC_PEQL,    KC_P7,      KC_P8,      KC_P9,      KC_P0,                                   KC_P0,      KC_P7,      KC_P8,      KC_P9,      KC_PEQL,    KC_RSFT,
    XXXXXXX,    KC_LALT,    KC_RALT,    KC_PCMM,    KC_PDOT,         XXXXXXX,                      XXXXXXX,          KC_PDOT,    KC_PCMM,    KC_RALT,    KC_LALT,    XXXXXXX,
                                                    KC_PENT,    XXXXXXX,    _______,         _______,    XXXXXXX,    KC_PENT
  ), // }}}

  // {{{ shortcuts
  [L_SHRT] = LAYOUT_moonlander(
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    _______,    XXXXXXX,    C(KC_X),    C(KC_C),    C(KC_V),    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,                      XXXXXXX,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX
  ), // }}}

  // {{{ one-handed
  [L_OH] = LAYOUT_moonlander(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                 _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,         _______,                      _______,          _______,    _______,    _______,    _______,    _______,
                                                    _______,    _______,    _______,         _______,    _______,    _______
  ), // }}}

  // {{{ mouse
  [L_MOUS] = LAYOUT_moonlander(
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    KC_LGUI,    XXXXXXX,    KC_BTN4,    KC_MS_U,    KC_BTN5,    KC_WH_U,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_WH_U,    XXXXXXX,    XXXXXXX,    KC_RGUI,
    KC_LCTL,    KC_ACL2,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_D,    XXXXXXX,         XXXXXXX,    XXXXXXX,    KC_WH_L,    KC_WH_D,    KC_WH_R,    XXXXXXX,    KC_RCTL,
    KC_LSFT,    XXXXXXX,    KC_WH_L,    XXXXXXX,    KC_WH_R,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_RSFT,
    XXXXXXX,    KC_RALT,    KC_LALT,    KC_ACL0,    KC_ACL1,         XXXXXXX,                      XXXXXXX,          XXXXXXX,    XXXXXXX,    KC_LALT,    KC_RALT,    XXXXXXX,
                                                    KC_BTN1,    KC_BTN2,    KC_BTN3,         KC_ACL0,    KC_ACL1,    KC_ACL2
  ), // }}}

  // {{{ media
  [L_MEDI] = LAYOUT_moonlander(
    _______,    KC_CALC,    KC_MAIL,    KC_MYCM,    KC_MSEL,    XXXXXXX,    _______,         _______,    XXXXXXX,    KC_MSEL,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_VOLD,    KC_VOLU,    XXXXXXX,    KC_EJCT,         KC_EJCT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MPRV,    KC_MNXT,    XXXXXXX,                                 XXXXXXX,    KC_VOLD,    KC_VOLU,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MFFD,    KC_MRWD,         XXXXXXX,                      XXXXXXX,          KC_MPRV,    KC_MNXT,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    KC_MUTE,    KC_MPLY,    KC_MSTP,         KC_MSTP,    KC_MPLY,    KC_MUTE
  ), // }}}

  // {{{ web
  [L_WEB] = LAYOUT_moonlander(
    _______,    KC_WHOM,    KC_WFAV,    XXXXXXX,    KC_WSCH,    KC_WREF,    _______,         _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,                      XXXXXXX,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    KC_WBAK,    KC_WFWD,    KC_WSTP,         XXXXXXX,    XXXXXXX,    XXXXXXX
  ), // }}}

  // {{{ system
  [L_SYS] = LAYOUT_moonlander(
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_PWR,          KC_PWR,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_SLEP,         KC_SLEP,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         KC_WAKE,                      KC_WAKE,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX
  ), // }}}

  // {{{ config
  [L_CONF] = LAYOUT_moonlander(
    _______,    MU_TOG,     AU_TOG,     LED_LEVEL,  NK_TOGG,    XXXXXXX,    _______,         _______,    XXXXXXX,    NK_TOGG,    LED_LEVEL,  AU_TOG,     MU_TOG,     _______,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_SAD,    RGB_SAI,    XXXXXXX,    KC_POWER,        KC_POWER,   XXXXXXX,    RGB_SAD,    RGB_SAI,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_SPD,    RGB_SPI,    XXXXXXX,    RESET,           RESET,      XXXXXXX,    RGB_SPD,    RGB_SPI,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_VAD,    RGB_VAI,    XXXXXXX,                                 XXXXXXX,    RGB_VAD,    RGB_VAI,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_HUD,    RGB_HUI,         RGB_TOG,                      RGB_TOG,          RGB_HUD,    RGB_HUI,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    ZSA_COL,    RGB_SLD,    RGB_MOD,         RGB_MOD,    RGB_SLD,    ZSA_COL
  ), // }}}
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define C_____ C_NONE

typedef enum color_t {
  // {{{
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
  // }}}
} color_t;

const uint8_t PROGMEM color_map[C_MAX][3] = {
  // {{{
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
  // }}}
};

// LED configuration that declares all of the LEDs
typedef enum led_maps_both_t {
  // {{{
  LEDS_VELO,
  LEDS_PLO,
  LEDS_MOUS,
  // }}}
} led_maps_both_t;

// LED configuration that declares only left LEDs
// used by mirrored layers too
typedef enum led_maps_left_t {
  // {{{
  LEDS_BASE,
  LEDS_DVK,
  LEDS_QRTY,
  LEDS_MUS,
  LEDS_G_BA,
  LEDS_OH,
  LEDS_SYMS,
  LEDS_NAVI,
  LEDS_NUM,
  LEDS_SHRT,
  LEDS_MEDI,
  LEDS_CONF,
  // }}}
} led_maps_left_t;

// LED configuration that declares only right LEDs
typedef enum led_maps_right_t {
  // {{{
  LEDS_G_NU,
  // }}}
} led_maps_right_t;

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

  // {{{ velotype
  [LEDS_VELO] = {
  }, // }}}

  // {{{ plover
  [LEDS_PLO] = {
  }, // }}}

  // {{{ mouse
  [LEDS_MOUS] = {
  }, // }}}
};

// also used for mirrored maps
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

  // {{{ base
  [LEDS_BASE] = {
    C_SU_5, C_SU_1, C_SU_1, C_SU_1, C_____, C_____, C_SU_5,
    C_SU_4, C_SU_1, C_SU_1, C_____, C_____, C_____, C_____,
    C_SU_4, C_SU_1, C_____, C_____, C_____, C_____, C_SU_5,
    C_SU_4, C_SU_1, C_____, C_____, C_____, C_____,
    C_____, C_SU_4, C_SU_4, C_SU_3, C_SU_3,
    C_SU_4, C_SU_4, C_SU_4, C_SU_5,
  }, // }}}

  // {{{ dvorak
  [LEDS_DVK] = {
    C_SU_2, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_5,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_____,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_____,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2,
    C_____, C_SU_4, C_SU_4, C_SU_3, C_SU_3,
    C_SU_5, C_SU_5, C_SU_5, C_____,
  }, // }}}

  // {{{ qwerty
  [LEDS_QRTY] = {
    C_DS_2, C_DS_3, C_DS_3, C_DS_3, C_DS_3, C_DS_3, C_DS_5,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_____,
    C_DS_4, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_2, C_____,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2,
    C_____, C_DS_4, C_DS_4, C_DS_3, C_DS_3,
    C_DS_5, C_DS_5, C_DS_5, C_____,
  }, // }}}

  // {{{ one-handed
  [LEDS_OH] = {
  }, // }}}

  // {{{ gaming base
  [LEDS_G_BA] = {
    C_RU_2, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_5,
    C_RU_4, C_RU_2, C_RU_2, C_RU_1, C_RU_2, C_RU_2, C_RU_3,
    C_RU_4, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,
    C_RU_4, C_RU_2, C_RU_2, C_RU_2, C_RU_2, C_RU_3,
    C_____, C_RU_3, C_RU_3, C_RU_3, C_RU_3,
    C_RU_2, C_RU_2, C_RU_2, C_RU_5,
  }, // }}}

  // {{{ symbols
  [LEDS_SYMS] = {
    C_____, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_5,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_3,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_____,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2,
    C_SU_5, C_SU_4, C_SU_4, C_____, C_____,
    C_SU_5, C_____, C_____, C_____,
  }, // }}}

  // {{{ navigation
  [LEDS_NAVI] = {
    C_SU_4, C_____, C_SU_4, C_SU_4, C_SU_4, C_____, C_SU_5,
    C_SU_3, C_SU_2, C_SU_2, C_SU_1, C_SU_2, C_SU_2, C_____,
    C_SU_3, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_2,
    C_SU_3, C_SU_2, C_SU_2, C_____, C_____, C_____,
    C_____, C_SU_3, C_SU_3, C_____, C_____,
    C_____, C_SU_5, C_____, C_____,
  }, // }}}

  // {{{ numpad
  [LEDS_NUM] = {
    C_SU_1, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_5,
    C_SU_3, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_3,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_____,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_1,
    C_____, C_SU_4, C_SU_4, C_SU_2, C_SU_2,
    C_SU_1, C_____, C_____, C_____,
  }, // }}}

  // {{{ shortcuts
  [LEDS_SHRT] = {
  }, // }}}

  // {{{ media
  [LEDS_MEDI] = {
  }, // }}}

  // {{{ music
  [LEDS_MUS] = {
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
  [LEDS_G_NU] = {
    C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_4, C_RU_4, C_RU_4,
    C_RU_4, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_4,
    C_____, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,
            C_RU_1, C_RU_1, C_RU_1, C_RU_1, C_RU_3, C_RU_3,
                    C_____, C_RU_4, C_RU_4, C_RU_4, C_RU_4,
                            C_____, C_____, C_RU_2, C_RU_1,
  }, // }}}
};

typedef enum led_mode_t {
  // {{{
  LM_NONE,
  LM_BOTH,
  LM_MIRROR, // define left LEDs but mirror them
  LM_LEFT,
  LM_RIGHT,
  // }}}
} led_mode_t;

typedef struct layer_led_config_t {
  led_mode_t mode;
  const color_t *colors;
} layer_led_config_t;

const layer_led_config_t PROGMEM ledmap[L_MAX] = {
  // {{{
  [L_BASE]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_BASE],  },
  [L_DVK]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_DVK],   },
  [L_VELO]  = { .mode = LM_BOTH,   .colors = ledmap_left[LEDS_VELO],  },
  [L_PLO]   = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_PLO],   },
  [L_QRTY]  = { .mode = LM_MIRROR, .colors = ledmap_both[LEDS_QRTY],  },
  [L_MUS]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_MUS],   },
  [L_G_BA]  = { .mode = LM_LEFT,   .colors = ledmap_left[LEDS_G_BA],  },
  [L_G_NU]  = { .mode = LM_RIGHT,  .colors = ledmap_right[LEDS_G_NU], },
  [L_OH]    = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_OH],    },
  [L_MOUS]  = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_MOUS],  },
  [L_SYMS]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_SYMS],  },
  [L_NAVI]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_NAVI],  },
  [L_NUM]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_NUM],   },
  [L_SHRT]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_SHRT],  },
  [L_MEDI]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_MEDI],  },
  [L_CONF]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_CONF],  },
  // }}}
};

void set_led_color(int led, color_t col) {
  // {{{
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
  // }}}
}

#define MATRIX_FIRST_RIGHT_ROW (MATRIX_ROWS / 2)

// inverted_rows is used to write a left-side LED map onto the right hand side
void set_board_colors(const color_t *colors, led_mode_t led_mode, bool mask_left, bool mask_right) {
  // {{{
  if (led_mode == LM_NONE) {
    return;
  }

  int color_ind = 0;
  bool inverted_cols = false;

  if (led_mode != LM_RIGHT) {
    for (int row_ind = 0; row_ind < MATRIX_FIRST_RIGHT_ROW; row_ind++) {
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
    for (int row_ind = MATRIX_FIRST_RIGHT_ROW ; row_ind < MATRIX_ROWS; row_ind++) {
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
  // }}}
}

void rgb_matrix_indicators_user(void) {
  // {{{
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
  // }}}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // {{{
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case KA_TO_G:
      if (record->event.pressed) {
        layer_clear();
        layer_on(L_G_BA);
        layer_on(L_G_NU);
      }
      return false;
  }
  return true;
  // }}}
}

const uint8_t PROGMEM ledind_map[L_MAX] = {
  // {{{
  [L_BASE] = 0b0000,
  [L_G_BA] = 0b0000,
  [L_DVK]  = 0b0001,
  [L_VELO] = 0b0010,
  [L_PLO]  = 0b0011,
  [L_QRTY] = 0b0100,
  [L_MUS]  = 0b0111,
  [L_G_NU] = 0b0000,
  [L_OH]   = 0b0000,
  [L_MOUS] = 0b0000,
  [L_SYMS] = 0b0000,
  [L_NAVI] = 0b0000,
  [L_NUM]  = 0b0000,
  [L_SHRT] = 0b1101,
  [L_MEDI] = 0b1110,
  [L_CONF] = 0b1111,
  // }}}
};

layer_state_t layer_state_set_user(layer_state_t state) {
  // {{{
  layer_state_t layers = layer_state | default_layer_state;
  /* check top layer first */
  for (int8_t layer = MAX_LAYER - 1; layer >= 0; layer--) {
    if (layers & (1UL << layer)) {
      uint8_t inds = ledind_map[layer];
      if (inds != 0 || layer == 0) {
        ML_LED_1(inds & 0b0001);
        ML_LED_2(inds & 0b0010);
        ML_LED_3(inds & 0b0100);
        ML_LED_4(inds & 0b1000);
        break;
      }
    }
  }

  /* ML_LED_5(overflow || (layer & 0b010000)); */
  /* ML_LED_6(overflow || (layer & 0b100000)); */

  return state;
  // }}}
}

/* vim: set foldmethod=marker : */
