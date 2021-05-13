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

// {{{ layers
typedef enum layer_t {
  L_BASE = 0,
  L_DVK,    // dvorak
  L_VELO,   // velotype
  L_PLO,    // plover
  L_QRTY,   // qwerty
  L_G_AR,   // gaming arrows
  L_G_DV,   // gaming with dvorak
  L_G_DV_F, // gaming with dvorak flipped
  L_OH,     // one hand
  L_OH_F,   // one hand flipped
  L_G_NU,   // gaming numpad
  L_MS,     // mouse
  L_MS_F,   // mouse flipped
  L_SYMS,   // symbols
  L_NAVI,   // navigation
  L_NUM,    // numpad
  L_SHORT,  // shortcuts
  L_LAY,    // switching layers
  L_MEDIA,  // media
  L_MUS,    // music
  L_CONF,   // config
  L_MAX,
} layer_t;
// }}} layers

// {{{ keycodes
typedef enum custom_keycode_t {
  RGB_SLD = ML_SAFE_RANGE,
} custom_keycode_t;
// }}} keycodes

#define ZSA_COL TOGGLE_LAYER_COLOR

#define K_B_LT1 LT(L_SYMS, KC_SPC)
#define K_B_LT2 LT(L_NAVI, KC_TAB)
#define K_B_LT3 LT(L_NUM,  KC_ENT)
#define K_B_RT1 LT(L_SYMS, KC_ENT)
#define K_B_RT2 LT(L_NAVI, KC_DEL)
#define K_B_RT3 LT(L_NUM,  KC_APP)

#define K_DV_BS LCTL_T(KC_BSPC)

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
    TO(L_BASE), TO(L_DVK),  TO(L_VELO), TO(L_PLO),  TO(L_QRTY), TO(L_G_AR), TO(L_BASE),      TO(L_BASE), TO(L_G_AR), TO(L_QRTY), TO(L_PLO),  TO(L_VELO), TO(L_DVK),  TO(L_BASE),
    KC_LGUI,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_RGUI,
    KC_LCTL,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_RCTL,
    KC_LSFT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_RSFT,
    XXXXXXX,    KC_LALT,    XXXXXXX,    KC_LEFT,    KC_RGHT,         XXXXXXX,                     XXXXXXX,           KC_DOWN,    KC_UP,      XXXXXXX,    KC_RALT,    XXXXXXX,
                                                    K_B_LT1,    K_B_LT2,    K_B_LT3,         K_B_RT3,    K_B_RT2,    K_B_RT1
  ), // }}}

  // {{{ dvorak
  [L_DVK] = LAYOUT_moonlander(
    _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,         _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
    _______,    KC_QUOT,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,       XXXXXXX,         XXXXXXX,    KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       _______,
    K_DV_BS,    KC_A,       KC_O,       KC_E,       KC_U,       KC_I,       XXXXXXX,         XXXXXXX,    KC_D,       KC_H,       KC_T,       KC_N, LT(L_MEDIA, KC_S),RCTL_T(KC_MINUS),
    _______,    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X,                                    KC_B,       KC_M,       KC_W,       KC_V,      RCTL_T(KC_Z),_______,
    XXXXXXX,    _______,    XXXXXXX,    _______,    _______,         XXXXXXX,                     XXXXXXX,           _______,    _______,    XXXXXXX,    KC_LBRC,    KC_RBRC,
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
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    _______,    PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,     XXXXXXX,         XXXXXXX,    PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,     PV_NUM,
    _______,    PV_LS,      PV_LT,      PV_LP,      PV_LH,      PV_STAR,    XXXXXXX,         XXXXXXX,    PV_STAR,    PV_RF,      PV_RP,      PV_RL,      PV_RT,      PV_RD,
    _______,    PV_LS,      PV_LK,      PV_LW,      PV_LR,      PV_STAR,                                 PV_STAR,    PV_RR,      PV_RB,      PV_RG,      PV_RS,      PV_RZ,
    _______,    _______,    _______,    _______,    _______,         XXXXXXX,                     XXXXXXX,           _______,    _______,    _______,    _______,    _______,
                                                    PV_A,       PV_O,       XXXXXXX,         XXXXXXX,    PV_E,       PV_U
  ), // }}}

  // {{{ qwerty
  [L_QRTY] = LAYOUT_moonlander(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    _______,    _______,    _______,    _______,    _______,    KC_EQUAL,
    _______,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       _______,         _______,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_MINUS,
    _______,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       _______,         _______,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCOLON,  KC_QUOTE,
    _______,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                                    KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_BSLASH,
    _______,    _______,    _______,    _______,    _______,         _______,                     _______,           _______,     _______,   KC_LBRC,    KC_RBRC,    _______,
                                                    _______,    _______,    _______,         _______,    _______,    _______
  ), // }}}

  // {{{ gaming arrows
  [L_G_AR] = LAYOUT_moonlander(
    KC_GRAVE,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,         _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
    KC_ESC,     KC_TAB,     KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    KC_6,            KC_NLCK,    KC_PAST,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    KC_F12,
    KC_BSPC,    KC_DELETE,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDOWN,  KC_7,            _______,    KC_PSLS,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    _______,
    KC_LSFT,    KC_LCTRL,   KC_MINUS,   KC_EQUAL,   KC_SLASH,   KC_8,                                    KC_P0,      KC_P7,      KC_P8,      KC_P9,      _______,    _______,
    KC_LBRC,    KC_RBRC,    _______,    KC_0,       KC_9,            TG(L_G_DV),                  _______,           KC_PDOT,    _______,    _______,    _______,    _______,
                                                    KC_SPC,     KC_LALT,    KC_ENTER,        _______,    _______,    KC_PENT
  ), // }}}

  // {{{ gaming numpad
  [L_G_NU] = LAYOUT_moonlander(
    KC_GRAVE,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,         _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
    KC_ESC,     KC_TAB,     KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    KC_6,            KC_NLCK,    KC_PAST,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    KC_F12,
    KC_BSPC,    KC_DELETE,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDOWN,  KC_7,            _______,    KC_PSLS,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    _______,
    KC_LSFT,    KC_LCTRL,   KC_MINUS,   KC_EQUAL,   KC_SLASH,   KC_8,                                    KC_P0,      KC_P7,      KC_P8,      KC_P9,      _______,    _______,
    KC_LBRC,    KC_RBRC,    _______,    KC_0,       KC_9,            TG(L_G_DV),                  _______,           KC_PDOT,    _______,    _______,    _______,    _______,
                                                    KC_SPC,     KC_LALT,    KC_ENTER,        _______,    _______,    KC_PENT
  ), // }}}

  // {{{ gaming + dvorak typing
  [L_G_DV] = LAYOUT_moonlander(
    XXXXXXX,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    XXXXXXX,    KC_QUOTE,   KC_COMMA,   KC_DOT,     KC_P,       KC_Y,       XXXXXXX,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    K_DV_BS,    KC_A,       KC_O,       KC_E,       KC_U,       KC_I,       XXXXXXX,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_LSFT,    KC_SCOLON,  KC_Q,       KC_J,       KC_K,       KC_X,                                    _______,    _______,    _______,    _______,    _______,    _______,
    XXXXXXX,    KC_LALT,    XXXXXXX,    _______,    _______,         XXXXXXX,                     _______,           _______,    _______,    _______,    _______,    _______,
                                                    K_B_LT1,    K_B_LT2,    K_B_LT3,        _______,    _______,    _______
  ), // }}}

  // {{{ gaming + dvorak typing flipped
  [L_G_DV_F] = LAYOUT_moonlander(
    _______,    KC_0,       KC_9,       KC_8,       KC_7,       KC_6,       _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    KC_L,       KC_R,       KC_C,       KC_G,       KC_F,       _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_DELETE,  KC_S,       KC_N,       KC_T,       KC_H,       KC_D,       _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    KC_Z,       KC_V,       KC_W,       KC_M,       KC_B,                                    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,         _______,                     _______,           _______,    _______,    _______,    _______,    _______,
                                                    K_B_LT1,    K_B_LT2,    K_B_LT3,        _______,    _______,    _______
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

  // {{{ one-handed flipped
  [L_OH_F] = LAYOUT_moonlander(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    KC_L,       KC_R,       KC_C,       KC_G,       KC_F,       _______,         _______,    KC_Y,       KC_P,       KC_DOT,     KC_COMMA,   KC_QUOTE,   _______,
    _______,    KC_S,       KC_N,       KC_T,       KC_H,       KC_D,       _______,         _______,    KC_I,       KC_U,       KC_E,       KC_O,       KC_A,       _______,
    _______,    KC_Z,       KC_V,       KC_W,       KC_M,       KC_B,                                    KC_X,       KC_K,       KC_J,       KC_Q,       KC_SCOLON,  _______,
    _______,    _______,    _______,    _______,    _______,         _______,                      _______,          _______,    _______,    _______,    _______,    _______,
                                                    _______,    _______,    _______,         _______,    _______,    _______
  ), // }}}

  // {{{ mouse
  [L_MS] = LAYOUT_moonlander(
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    KC_RGUI,    XXXXXXX,    KC_BTN4,    KC_MS_U,    KC_BTN5,    XXXXXXX,    KC_RALT,         KC_RALT,    XXXXXXX,    XXXXXXX,    KC_WH_U,    XXXXXXX,    XXXXXXX,    KC_RGUI,
    KC_LCTRL,   KC_ACL2,    KC_MS_L,    KC_MS_D,    KC_MS_R,    XXXXXXX,    KC_LALT,         KC_LALT,    XXXXXXX,    KC_WH_L,    KC_WH_D,    KC_WH_R,    XXXXXXX,    KC_RCTRL,
    KC_LSFT,    MO(L_MS_F), XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    MO(L_MS_F), KC_RSFT,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ACL0,    KC_ACL1,         XXXXXXX,                      XXXXXXX,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    KC_BTN1,    KC_BTN2,    KC_BTN3,         KC_ACL0,    KC_ACL1,    KC_ACL2
  ), // }}}

  // {{{ mouse flipped
  [L_MS_F] = LAYOUT_moonlander(
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    _______,    XXXXXXX,    XXXXXXX,    KC_WH_U,    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    KC_MS_BTN4, KC_WH_U,    KC_MS_BTN5, XXXXXXX,    _______,
    _______,    XXXXXXX,    KC_WH_L,    KC_WH_D,    KC_WH_R,    XXXXXXX,    _______,         _______,    XXXXXXX,    KC_WH_L,    KC_WH_D,    KC_WH_R,    KC_ACL2,    _______,
    _______,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    _______,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ACL0,    KC_ACL1,         XXXXXXX,                      XXXXXXX,          KC_ACL1,    KC_ACL0,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    KC_ACL0,    KC_ACL1,    KC_ACL2,         KC_BTN3,    KC_BTN2,    KC_BTN1
  ), // }}}

  // {{{ symbols old
  /* [L_SYMS] = LAYOUT_moonlander( */
  /*   KC_NO,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,         _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_NO, */
  /*   _______,    KC_EXLM,    KC_AT,      KC_LCBR,    KC_RCBR,    KC_PIPE,    KC_F11,          KC_F12,     _______,    KC_KP_1,    KC_8,       KC_9,       KC_ASTR,    _______, */
  /*   _______,    KC_HASH,    KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRAVE,   _______,         _______,    _______,    KC_4,       KC_5,       KC_6,       KC_KP_PLUS, _______, */
  /*   _______,    KC_PERC,    KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_TILD,                                 KC_AMPR,    KC_1,       KC_2,       KC_3,       KC_BSLASH,  _______, */
  /*   _______,    KC_COMMA,   _______,    _______,    _______,         _______,                      _______,          _______,    KC_DOT,     KC_0,       KC_EQUAL,   _______, */
  /*                                                   _______,    _______,    _______,         _______,    _______,    _______ */
  /* ), // }}} */

  // {{{ symbols
  [L_SYMS] = LAYOUT_moonlander(
    XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,         _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     XXXXXXX,
    _______,    KC_EXLM,    KC_AT,      KC_LCBR,    KC_RCBR,    KC_PIPE,    KC_F11,          KC_F12,     KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    _______,
    _______,    KC_HASH,    KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRAVE,   _______,         _______,    _______,    KC_4,       KC_5,       KC_6,       KC_KP_PLUS, _______,
    _______,    KC_PERC,    KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_TILD,                                 _______,    KC_1,       KC_2,       KC_3,       KC_BSLASH,  _______,
    _______,    KC_COMMA,   _______,    _______,    _______,         _______,                      _______,          _______,    KC_DOT,     KC_0,       KC_EQUAL,   _______,
                                                    _______,    _______,    _______,         _______,    _______,    _______
  ), // }}}

  // {{{ navigation
  [L_NAVI] = LAYOUT_moonlander(
    KC_CAPS,    XXXXXXX,    KC_PSCR,    KC_SLCK,    KC_PAUS,    XXXXXXX,    _______,         _______,    XXXXXXX,    KC_PAUS,    KC_SLCK,    KC_PSCR,    XXXXXXX,   KC_CAPS,
    KC_ESC,     KC_TAB,     KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    XXXXXXX,         XXXXXXX,    KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_TAB,    KC_ESC,
    KC_BSPC,    KC_DEL,     KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,    KC_ENT,          KC_ENT,     KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_DEL,    KC_BSPC,
    KC_LSFT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_HOME,    KC_END,          XXXXXXX,                      XXXXXXX,          KC_PGDN,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX
  ), // }}}

  // {{{ numpad
  [L_NUM] = LAYOUT_moonlander(
    KC_NLCK,    KC_A,       KC_B,       KC_C,       KC_D,       KC_E,       _______,         _______,    KC_A,       KC_B,       KC_C,       KC_D,       KC_E,       KC_F,
    KC_X,       KC_PAST,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    KC_F,            KC_NLCK,    KC_PAST,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    KC_X,
    KC_LCTRL,   KC_PSLS,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    _______,         _______,    KC_PSLS,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    KC_RCTRL,
    KC_LSFT,    KC_PEQL,    KC_P7,      KC_P8,      KC_P9,      KC_P0,                                   KC_P0,      KC_P7,      KC_P8,      KC_P9,      KC_PEQL,    KC_RSFT,
    _______,    _______,    _______,    KC_PCMM,    KC_PDOT,         _______,                      _______,          KC_PDOT,    KC_PCMM,    _______,    _______,    _______,
                                                    KC_PENT,    _______,    _______,         _______,    _______,    KC_PENT
  ), // }}}

  // {{{ shortcuts
  [L_SHORT] = LAYOUT_moonlander(
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    _______,    XXXXXXX,    C(KC_X),    C(KC_C),    C(KC_V),    XXXXXXX,                                 XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,                      XXXXXXX,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX
  ), // }}}

  // {{{ media
  [L_MEDIA] = LAYOUT_moonlander(
    _______,    KC_CALC,    KC_MAIL,    KC_MYCM,    XXXXXXX,    XXXXXXX,    _______,         _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_EJCT,         KC_EJCT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_VOLD,    KC_VOLU,    XXXXXXX,                                 XXXXXXX,    KC_VOLD,    KC_VOLU,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MPRV,    KC_MNXT,         XXXXXXX,                      XXXXXXX,          KC_MPRV,    KC_MNXT,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    KC_MUTE,    KC_MPLY,    KC_MSTP,         KC_MSTP,    KC_MPLY,    KC_MUTE
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

  // {{{ switching layers
  [L_LAY] = LAYOUT_moonlander(
    TO(L_BASE), TO(L_DVK),  TO(L_VELO), TO(L_PLO),  TO(L_QRTY), TO(L_G_AR), TO(L_BASE),      TO(L_BASE), TO(L_G_AR), TO(L_QRTY), TO(L_PLO),  TO(L_VELO), TO(L_DVK),  TO(L_BASE),
    _______,    _______,    _______,    _______,    _______,    TO(L_MUS),  TO(L_CONF),      TO(L_CONF), TO(L_MUS),  _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                 _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,         _______,                      _______,          _______,    _______,    _______,    _______,    _______,
                                                    TO(L_BASE), _______,    _______,         _______,    _______,    TO(L_BASE)
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

// {{{ colors

#define C_____ C_NONE

typedef enum color_t {
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
} color_t;

const uint8_t PROGMEM color_map[C_MAX][3] = {
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
};
// }}} colors

// {{{ led defs
// LED configuration that declares all of the LEDs
typedef enum led_maps_both_t {
  LEDS_BASE,
  LEDS_DVK,
  LEDS_VELO,
  LEDS_PLO,
  LEDS_QRTY,
  LEDS_MS,
  LEDS_MS_F,
} led_maps_both_t;

// LED configuration that declares only left LEDs
// used by mirrored layers too
typedef enum led_maps_left_t {
  LEDS_G_AR,
  LEDS_OH,
  LEDS_OH_F,
  LEDS_SYMS,
  LEDS_NAVI,
  LEDS_NUM,
  LEDS_SHORT,
  LEDS_LAY,
  LEDS_MEDIA,
  LEDS_MUS,
  LEDS_CONF,
} led_maps_left_t;

// LED configuration that declares only right LEDs
typedef enum led_maps_right_t {
  LEDS_G_NU,
} led_maps_right_t;
// }}} leds defs

// {{{ led maps
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

  // {{{ base
  [LEDS_BASE] = {
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
  }, // }}}

  // {{{ dvorak
  [LEDS_DVK] = {
  }, // }}}

  // {{{ velotype
  [LEDS_VELO] = {
  }, // }}}

  // {{{ plover
  [LEDS_PLO] = {
  }, // }}}

  // {{{ qwerty
  [LEDS_QRTY] = {
  }, // }}}

  // {{{ mouse
  [LEDS_MS] = {
  }, // }}}

  // {{{ mouse flipped
  [LEDS_MS_F] = {
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

  // {{{ gaming arrows
  [LEDS_G_AR] = {
  }, // }}}

  // {{{ one-handed
  [LEDS_OH] = {
  }, // }}}

  // {{{ one-handed flipped
  [LEDS_OH_F] = {
  }, // }}}

  // {{{ symbols
  [LEDS_SYMS] = {
  }, // }}}

  // {{{ navigation
  [LEDS_NAVI] = {
  }, // }}}

  // {{{ numpad
  [LEDS_NUM] = {
  }, // }}}

  // {{{ shortcuts
  [LEDS_SHORT] = {
  }, // }}}

  // {{{ switching layers
  [LEDS_LAY] = {
  }, // }}}

  // {{{ media
  [LEDS_MEDIA] = {
  }, // }}}

  // {{{ music
  [LEDS_MUS] = {
  }, // }}}

  // {{{ config
  [LEDS_CONF] = {
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
  }, // }}}
};

typedef enum led_mode_t {
  LM_NONE,
  LM_BOTH,
  LM_MIRROR, // define left LEDs but mirror them
  LM_LEFT,
  LM_RIGHT,
} led_mode_t;

typedef struct layer_led_config_t {
  led_mode_t mode;
  const color_t *colors;
} layer_led_config_t;

const layer_led_config_t PROGMEM ledmap[L_MAX] = {
  [L_BASE]  = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_BASE],  },
  [L_DVK]   = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_DVK],   },
  [L_VELO]  = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_VELO],  },
  [L_PLO]   = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_PLO],   },
  [L_QRTY]  = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_QRTY],  },
  [L_G_AR]  = { .mode = LM_LEFT,   .colors = ledmap_left[LEDS_G_AR],  },
  [L_G_NU]  = { .mode = LM_RIGHT,  .colors = ledmap_right[LEDS_G_NU], },
  [L_OH]    = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_OH],    },
  [L_OH_F]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_OH_F],  },
  [L_MS]    = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_MS],    },
  [L_MS_F]  = { .mode = LM_BOTH,   .colors = ledmap_both[LEDS_MS_F],  },
  [L_SYMS]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_SYMS],  },
  [L_NAVI]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_NAVI],  },
  [L_NUM]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_NUM],   },
  [L_SHORT] = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_SHORT], },
  [L_LAY]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_LAY],   },
  [L_MEDIA] = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_MEDIA], },
  [L_MUS]   = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_MUS],   },
  [L_CONF]  = { .mode = LM_MIRROR, .colors = ledmap_left[LEDS_CONF],  },
};
// }}} modes

// {{{ led functions
void set_led_color(int led, color_t col) {
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
}

#define MATRIX_FIRST_RIGHT_ROW (MATRIX_ROWS / 2)

// inverted_rows is used to write a left-side LED map onto the right hand side
void set_board_colors(const color_t *colors, led_mode_t led_mode, bool mask_left, bool mask_right) {
  if (led_mode == LM_NONE) {
    return;
  }

  int color_ind = 0;
  bool inverted_cols = false;

  if (led_mode != LM_RIGHT) {
    for (int row_ind = 0; row_ind < MATRIX_FIRST_RIGHT_ROW; row_ind++) {
      for (int col_ind = 0; col_ind < MATRIX_COLS; col_ind++) {
        int real_col_ind = inverted_cols ? MATRIX_COLS - col_ind - 1 : col_ind;

        uint16_t led = g_led_config.matrix_co[row_ind][real_col_ind];
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
        int real_col_ind = inverted_cols ? MATRIX_COLS - col_ind - 1 : col_ind;

        uint16_t led = g_led_config.matrix_co[row_ind][real_col_ind];
        if (led == NO_LED) { continue; }

        if (!mask_right) {
          set_led_color(led, colors[color_ind]);
        }

        color_ind++;
      }
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }

  bool right_leds_set = false, left_leds_set = false;
  layer_state_t layers = layer_state | default_layer_state;
  /* check top layer first */
  for (int8_t layer = MAX_LAYER - 1; layer >= 0; layer--) {
    if (layers & (1UL << layer)) {
      const layer_led_config_t *led_config = &ledmap[layer];

      set_board_colors(led_config->colors, led_config->mode, left_leds_set, right_leds_set);

      switch (led_config->mode) {
        case LM_NONE:
          break;
        case LM_BOTH:
        case LM_MIRROR:
          left_leds_set = right_leds_set = true;
          break;
        case LM_LEFT:
          left_leds_set = true;
          break;
        case LM_RIGHT:
          right_leds_set = true;
          break;
        default:
          break;
      }

      if (right_leds_set && left_leds_set) { return; }
    }
  }

  if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
    rgb_matrix_set_color_all(0, 0, 0);
  }
}
// }}} led functions

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

/* vim: set foldmethod=marker : */
