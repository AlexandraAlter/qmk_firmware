#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"
#include "keymap_steno.h"

typedef enum layer_t {
  L_BASE, // base
  L_GAME, // core: gaming base
  L_DVK,  // core: dvorak
  L_QRTY, // core: qwerty
  L_STEN, // core: stenotype
  L_ONEH, // core: one-handed
  L_SYMS, // utils: symbols
  L_NUM,  // utils: numpad
  L_NAVI, // utils: navigation
  L_SHRT, // utils: shortcuts
  L_FUNC, // utils: function keys
  L_WHAT, // who knows?
  // layers 0-11 above this line can be used in LT keys
  L_MIDI, // core: midi
  L_MOUS, // core: mouse
  L_G_NU, // core: gaming numpad
  L_O_GA, // overlay: gaming overlay
  L_O_SY, // overlay: symbols overlay
  L_O_NU, // overlay: numpad overlay
  L_O_MO, // overlay: mouse overlay
  L_HUB,  // one-shot: hub
  L_MEDI, // utils: media
  L_CONF, // utils: config
  L_MAX,
} layer_t;

typedef enum custom_keycode_t { // {{{
  RGB_SLD = ML_SAFE_RANGE, // pause LED animation
  GAMING, // go directly to the three gaming layers
  G_DVK, // toggle dvorak and the gaming numpad
} custom_keycode_t; // }}}

// {{{ layout key meta-def
// we assume that name(kc) is a macro that creates a mod-tap key
#define META_KEY(name, mod, default_kc) \
const uint16_t KA_##name = name(default_kc); \
const uint16_t MA_##name = mod;

#define META_PLAINKEY(name, mod, mod_kc) \
const uint16_t KA_##name = mod_kc; \
const uint16_t MA_##name = mod;
// }}}

// {{{ layout key defs
#define RGB_TLC TOGGLE_LAYER_COLOR
#define XXX KC_NO
#define ___ KC_TRNS

// modifier keys
#define KA_RALT OSM(MOD_RALT)

// shortcut keys
#define KA_UNDO LCTL(KC_Z)
#define KA_REDO LCTL(KC_Y)

#define KA_CUT  LCTL(KC_X)
#define KA_COPY LCTL(KC_C)
#define KA_PSTE LCTL(KC_V)

#define KA_QUIT LCTL(KC_Q)
#define KA_CLOS LCTL(KC_W)

// layer change keys
#define HUB     OSL(L_HUB)

#define DVORAK  TO(L_DVK)
#define QWERTY  TO(L_QRTY)
#define STENO   TO(L_STEN)
#define ONEHAND TO(L_ONEH)
#define MIDI    TO(L_MIDI)

#define MO_NAVI MO(L_NAVI)
#define MO_MEDI MO(L_MEDI)
#define MO_CONF MO(L_CONF)

// normal left modifiers
#define L1(kc) (LALT_T(kc))
META_KEY(L1, KC_LALT, KC_NO);
#define L2(kc) (LGUI_T(kc))
META_KEY(L2, KC_LGUI, KC_ESC);
#define L3(kc) (LCTL_T(kc))
META_KEY(L3, KC_LCTL, KC_BSPC);
#define L4(kc) (LSFT_T(kc))
META_PLAINKEY(L4, KC_LSFT, KC_LSPO);
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
META_KEY(L11, KC_LSFT, KC_BSLS);
#define L12(kc) (LSFT_T(kc))
META_KEY(L12, KC_LSFT, KC_NO);

// normal right modifiers
#define R1(kc) (LALT_T(kc))
META_KEY(R1, KC_LALT, KC_NO);
#define R2(kc) (RGUI_T(kc))
META_KEY(R2, KC_RGUI, KC_ESC);
#define R3(kc) (RCTL_T(kc))
META_KEY(R3, KC_RCTL, KC_DEL);
#define R4(kc) (RSFT_T(kc))
META_PLAINKEY(R4, KC_RSFT, KC_RSPC);
#define R5(kc) (RALT_T(kc))
META_KEY(R5, KC_RALT, KC_BSPC);
#define R6(kc) (RGUI_T(kc))
META_KEY(R6, KC_RGUI, KC_RBRC);
#define R7(kc) (RCTL_T(kc))
META_KEY(R7, KC_RCTL, KC_RBRC);
#define R8(kc) (RSFT_T(kc))
META_KEY(R8, KC_RSFT, KC_UP);
#define R9(kc) (LALT_T(kc))
META_KEY(R9, KC_LALT, KC_DOWN);
#define R10(kc) (LALT_T(kc))
META_KEY(R10, KC_LALT, KC_RBRC);
#define R11(kc) (RSFT_T(kc))
META_KEY(R11, KC_RSFT, KC_SLSH);
#define R12(kc) (RSFT_T(kc))
META_KEY(R12, KC_RSFT, KC_NO);

// normal thumb keys
#define KA_LT1 LT(L_SYMS, KC_SPC)
#define KA_LT2 LT(L_NAVI, KC_TAB)
#define KA_LT3 LT(L_SHRT, KC_ENT)

#define KA_RT1 LT(L_FUNC, KC_SPC)
#define KA_RT2 LT(L_NUM,  KC_ENT)
#define KA_RT3 LT(L_SHRT, KC_TAB)

// dvorak specific keys
#define KA_DL1 L1(KC_GRV)

#define KA_DR1 R1(KC_EQL)
#define KA_DR2 R2(KC_SLSH)
#define KA_DR3 R3(KC_MINS)

// qwerty specific keys
#define KA_QL1 L1(KC_GRV)

#define KA_QR1 R1(KC_EQL)
#define KA_QR2 R2(KC_MINS)
#define KA_QR3 R3(KC_QUOT)

// one-handed specific keys
#define KA_OHL1 L1(KC_DOT)
#define KA_OHL5 L5(KC_QUOT)

#define KA_OHT1 LT(L_SYMS, KC_SPC)
#define KA_OHT2 LT(L_NUM,  KC_TAB)
#define KA_OHT3 LT(L_NAVI, KC_ENT)
// }}}

// {{{ layout convenience defs
// clang-format off
#define LAYOUT_moonlander_mirrored( \
  k00, k01, k02, k03, k04, k05, k06, \
  k10, k11, k12, k13, k14, k15, k16, \
  k20, k21, k22, k23, k24, k25, k26, \
  k30, k31, k32, k33, k34, k35, \
  k40, k41, k42, k43, k44,      k53, \
                      k50, k51, k52 \
) \
LAYOUT_moonlander( \
  k00, k01, k02, k03, k04, k05, k06,   k06, k05, k04, k03, k02, k01, k00, \
  k10, k11, k12, k13, k14, k15, k16,   k16, k15, k14, k13, k12, k11, k10, \
  k20, k21, k22, k23, k24, k25, k26,   k26, k25, k24, k23, k22, k21, k20, \
  k30, k31, k32, k33, k34, k35,             k35, k34, k33, k32, k31, k30, \
  k40, k41, k42, k43, k44,      k53,   k53,      k44, k43, k42, k41, k40, \
                      k50, k51, k52,   k52, k51, k50 \
)

// mirrored layout, save for the 3x3 'inner' area centred on the middle finger
#define LAYOUT_moonlander_mirrored_outer( \
  k00, k01, k02, k03, k04, k05, k06, \
  k10, k11, k12, k13, k14, k15, k16, \
  k20, k21, k22, k23, k24, k25, k26, \
  k30, k31, k32, k33, k34, k35, \
  k40, k41, k42, k43, k44,      k53, \
                      k50, k51, k52 \
) \
LAYOUT_moonlander( \
  k00, k01, k02, k03, k04, k05, k06,   k06, k05, k04, k03, k02, k01, k00, \
  k10, k11, k12, k13, k14, k15, k16,   k16, k15, k12, k13, k14, k11, k10, \
  k20, k21, k22, k23, k24, k25, k26,   k26, k25, k22, k23, k24, k21, k20, \
  k30, k31, k32, k33, k34, k35,             k35, k32, k33, k34, k31, k30, \
  k40, k41, k42, k43, k44,      k53,   k53,      k44, k43, k42, k41, k40, \
                      k50, k51, k52,   k52, k51, k50 \
)
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

  [L_BASE] = LAYOUT_moonlander( // {{{ base
    KA_L1,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KA_L12,     KA_R12,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KA_R1,
    KA_L2,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_L11,     KA_R11,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R2,
    KA_L3,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_L10,     KA_R10,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R3,
    KA_L4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R4,
    KA_L5,   KA_L6,   KA_L7,   KA_L8,   KA_L9,        HUB,                HUB,          KA_R9,   KA_R8,   KA_R7,   KA_R6,   KA_R5,
                                        KA_LT1,  KA_LT2,  KA_LT3,     KA_RT3,  KA_RT2,  KA_RT1
  ), // }}}

  [L_DVK] = LAYOUT_moonlander( // {{{ dvorak
    KA_DL1,  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, KA_DR1,
    _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______,    _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KA_DR2,
    _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______,    _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KA_DR3,
    _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,
    _______, _______, _______, _______, _______,      _______,            _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,    _______, _______, _______
  ), // }}}

  [L_QRTY] = LAYOUT_moonlander( // {{{ qwerty
    KA_QL1,  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, KA_QR1,
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,    _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KA_QR2,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,    _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KA_QR3,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______, _______, _______,      _______,            _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,    _______, _______, _______
  ), // }}}

  [L_STEN] = LAYOUT_moonlander( // {{{ stenotype
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HUB,        HUB,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  XXXXXXX,    XXXXXXX, STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
    STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_N2,     STN_NB,  STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    STN_FN,  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,                      STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    MO_NAVI, STN_PWR, STN_PWR, STN_N1,  STN_N1,       STN_RE1,            STN_RE2,      STN_NC,  STN_NC,  STN_DR,  STN_DR,  MO_NAVI,
                                        STN_A,   STN_O,   STN_RE1,    STN_RE2, STN_E,   STN_U
  ), // }}}

  [L_ONEH] = LAYOUT_moonlander_mirrored( // {{{ one-handed
    KA_OHL1, KC_COMM, KC_Q,    KC_J,    KC_K,    KC_X,    XXXXXXX,
    KA_L2,   KC_L,    KC_R,    KC_C,    KC_G,    KC_F,    L11(KC_Y),
    KA_L3,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    L10(KC_B),
    L4(KC_P),KC_S,    KC_N,    KC_T,    KC_H,    KC_D,
    KA_OHL5, L6(KC_Z),L7(KC_V),L8(KC_W),L9(KC_M),     _______,
                                        KA_OHT1, KA_OHT2, KA_OHT3
  ), // }}}

  [L_GAME] = LAYOUT_moonlander( // {{{ gaming base
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    HUB,        _______, _______, _______, _______, _______, _______, _______,
    KC_ESC,  KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_6,       _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_7,       _______, _______, _______, _______, _______, _______, _______,
    KC_LSFT, KC_DEL,  KC_ENT,  KC_MINS, KC_EQL,  KC_8,                         _______, _______, _______, _______, _______, _______,
    KC_LGUI, KC_LBRC, KC_RBRC, KC_0,    KC_9,         _______,            _______,      _______, _______, _______, _______, _______,
                                        KC_SPC,  KC_LALT, KC_RALT,    _______, _______, _______
  ), // }}}

  [L_G_NU] = LAYOUT_moonlander( // {{{ gaming numpad
    _______, _______, _______, _______, _______, _______, _______,    HUB,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______, _______,    KC_F5,   KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_F12,
    _______, _______, _______, _______, _______, _______, _______,    KC_F4,   KC_PSLS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_RCTL,
    _______, _______, _______, _______, _______, _______,                      KC_F3,   KC_P7,   KC_P8,   KC_P9,   XXXXXXX, KC_RSFT,
    _______, _______, _______, _______, _______,      _______,            _______,      KC_F2,   KC_F1,   XXXXXXX, KC_RALT, KC_RGUI,
                                        _______, _______, _______,    KC_PENT, KC_PDOT, KC_P0
  ), // }}}

  [L_O_GA] = LAYOUT_moonlander( // {{{ gaming overlay
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      TG(L_ONEH),         G_DVK,        _______, _______, _______, _______, _______,
                                        _______, _______, _______,    _______, _______, _______
  ), // }}}

  [L_MIDI] = LAYOUT_moonlander( // {{{ midi
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HUB,        HUB,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      MI_TOG,             MI_TOG,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
  ), // }}}

  [L_MOUS] = LAYOUT_moonlander_mirrored_outer( // {{{ mouse
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_ACL0, KC_BTN4, KC_MS_U, KC_BTN5, KC_WH_U, _______,
    _______, KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,
    _______, KC_ACL2, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX,
    _______, _______, _______, _______, _______,      _______,
                                        KC_BTN1, KC_BTN2, KC_BTN3
  ), // }}}

  [L_O_MO] = LAYOUT_moonlander( // {{{ mouse overlay
    _______, _______, _______, _______, _______, _______, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______,      _______,            _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,    KC_ACL0, KC_ACL1, KC_ACL2
  ), // }}}

  [L_SYMS] = LAYOUT_moonlander( // {{{ symbols
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_GRV,  KC_QUOT, KC_LBRC, KC_RBRC, KC_EQL,  _______,    _______, KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT, KC_GRV,  _______,
    _______, KC_COMM, KC_DOT,  KC_BSLS, KC_SLSH, KC_MINS, _______,    _______, KC_MINS, KC_BSLS, KC_SLSH, KC_COMM, KC_DOT,  _______,
    MA_L4,   XXXXXXX, KC_SCLN, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN, XXXXXXX, MA_R4,
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
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_PAST, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______,    _______, KC_CIRC, KC_P1,   KC_P2,   KC_P3,   KC_PAST, _______,
    _______, KC_PSLS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_NLCK,    KC_NLCK, KC_COMM, KC_P4,   KC_P5,   KC_P6,   KC_PSLS, _______,
    _______, KC_PEQL, KC_P7,   KC_P8,   KC_P9,   KC_P0,                        KC_PEQL, KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______,
    _______, _______, _______, KC_PDOT, KC_PCMM,      _______,            _______,      KC_PDOT, KC_PCMM, _______, _______, _______,
                                        _______, _______, _______,    _______, _______, _______
  ), // }}}

  [L_O_NU] = LAYOUT_moonlander( // {{{ numpad overlay
    _______, _______, _______, _______, _______, _______, _______,    _______, XXXXXXX, XXXXXXX, KC_HASH, KC_DLR,  US_EURO, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, XXXXXXX, KC_A,    KC_B,    KC_C,    XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, KC_COLN, KC_D,    KC_E,    KC_F,    XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______,                      KC_SCLN, KC_COMM, KC_DOT,  KC_X,    XXXXXXX, _______,
    _______, _______, _______, _______, _______,      _______,            _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,    _______, _______, _______
  ), // }}}

  [L_NAVI] = LAYOUT_moonlander_mirrored_outer( // {{{ navigation
    _______, KC_INS,  XXXXXXX, KC_PSCR, XXXXXXX, KC_PAUS, _______,
    _______, KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_SLCK,
    _______, KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_CAPS,
    _______, XXXXXXX, KC_BSPC, XXXXXXX, KC_DEL,  KC_ENT,
    _______, _______, _______, _______, _______,      TG(L_NAVI),
                                        _______, _______, _______
  ), // }}}

  [L_FUNC] = LAYOUT_moonlander( // {{{ function keys
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, _______,    _______, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, _______,    _______, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                      XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, _______, _______, _______, _______,      _______,            _______,      _______, _______, _______, _______, _______,
                                        _______, _______, _______,    _______, _______, _______
  ), // }}}

  [L_SHRT] = LAYOUT_moonlander_mirrored( // {{{ shortcuts
    _______, KC_MYCM, KC_CALC, KC_MAIL, KC_MSEL, KC_WREF, _______,
    _______, KA_QUIT, KA_CLOS, XXXXXXX, XXXXXXX, KC_WHOM, KC_WFAV,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WSCH,
    _______, KA_UNDO, KA_CUT,  KA_COPY, KA_PSTE, KC_APP,
    _______, KA_REDO, KC_WSTP, KC_WBAK, KC_WFWD,      TG(L_MOUS),
                                        _______, _______, _______
  ), // }}}

  [L_HUB] = LAYOUT_moonlander_mirrored( // {{{ hub
    XXXXXXX, KC_CAPS, KC_NLCK, KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, QWERTY,  MIDI,    XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, DVORAK,  STENO,   GAMING,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, ONEHAND, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,
                                        XXXXXXX, MO_MEDI, MO_CONF
  ), // }}}

  [L_MEDI] = LAYOUT_moonlander_mirrored( // {{{ media
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_VOLU, KC_MSTP, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_VOLD, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, KC_EJCT,
    XXXXXXX, KC_MUTE, KC_MRWD, KC_MFFD, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______,
                                        _______, _______, _______
  ), // }}}

  [L_CONF] = LAYOUT_moonlander_mirrored( // {{{ config
    XXXXXXX, AU_TOG,  NK_TOGG, XXXXXXX, RGB_TLC, RGB_TOG, XXXXXXX,
    KC_PWR,  RGB_HUI, RGB_VAI, RGB_SAI, RGB_SPI, RGB_MOD, XXXXXXX,
    KC_SLEP, RGB_HUD, RGB_VAD, RGB_SAD, RGB_SPD, RGB_SLD, RESET,
    KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______,
                                        _______, _______, _______
  ), // }}}
};

// {{{ led convenience defs
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

// used by mirrored layers too
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
// }}}

typedef enum color_t { // {{{
  C_NONE,
  C_____ = C_NONE,

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

/* {{{ LED templates
const color_t PROGMEM ledmap_template[DRIVER_LED_TOTAL] = LEDS_moonlander_both(
  C_____, C_____, C_____, C_____, C_____, C_____, C_____,    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____, C_____, C_____,    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____, C_____, C_____,    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____, C_____,                    C_____, C_____, C_____, C_____, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____,     C_____,            C_____,     C_____, C_____, C_____, C_____, C_____,
                                  C_____, C_____, C_____,    C_____, C_____, C_____
);

const color_t PROGMEM ledmap_template[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left(
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____, C_____,
    C_____, C_____, C_____, C_____, C_____,     C_____,
                                    C_____, C_____, C_____
);

const color_t PROGMEM ledmap_template[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_right(
  C_____, C_____, C_____, C_____, C_____, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____, C_____, C_____,
          C_____, C_____, C_____, C_____, C_____, C_____,
      C_____,     C_____, C_____, C_____, C_____, C_____,
  C_____, C_____, C_____
); }}} */

const color_t PROGMEM ledmap_steno[DRIVER_LED_TOTAL] = LEDS_moonlander_both( // {{{
  C_____, C_____, C_____, C_____, C_____, C_____, C_MA_5,    C_MA_5, C_____, C_____, C_____, C_____, C_____, C_____,
  C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_____,    C_____, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3,
  C_MA_4, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_2, C_MA_3,    C_MA_3, C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_1,
  C_MA_4, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_2,                    C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_1,
  C_MA_5, C_MA_4, C_MA_4, C_MA_3, C_MA_3,     C_MA_4,            C_MA_4,     C_MA_3, C_MA_3, C_MA_1, C_MA_1, C_MA_5,
                                  C_MA_1, C_MA_1, C_MA_4,    C_MA_4, C_MA_1, C_MA_1
); // }}}

const color_t PROGMEM ledmap_mouse[DRIVER_LED_TOTAL] = LEDS_moonlander_left( // {{{
  C_SU_4, C_____, C_____, C_____, C_____, C_____, C_SU_5,
  C_SU_4, C_____, C_SU_2, C_SU_1, C_SU_2, C_SU_2, C_____,
  C_SU_4, C_SU_3, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_____,
  C_SU_4, C_SU_3, C_SU_2, C_____, C_SU_2, C_____,
  C_SU_4, C_SU_4, C_SU_4, C_____, C_SU_3,     C_SU_5,
                                  C_SU_1, C_SU_1, C_SU_1
); // }}}

const color_t PROGMEM ledmap_o_mouse[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_right( // {{{
  C_SU_5, C_____, C_____, C_____, C_____, C_____, C_SU_4,
  C_____, C_____, C_____, C_SU_1, C_____, C_____, C_SU_4,
  C_____, C_____, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_4,
          C_____, C_____, C_____, C_____, C_____, C_SU_4,
      C_SU_5,     C_SU_3, C_SU_3, C_SU_4, C_SU_4, C_SU_4,
  C_SU_3, C_SU_3, C_SU_3
); // }}}

const color_t PROGMEM ledmap_base[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_SU_4, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_5,
  C_SU_4, C_____, C_____, C_____, C_____, C_____, C_SU_4,
  C_SU_4, C_____, C_____, C_____, C_____, C_____, C_SU_4,
  C_SU_4, C_____, C_____, C_____, C_____, C_____,
  C_SU_4, C_SU_4, C_SU_4, C_SU_3, C_SU_3,     C_SU_5,
                                  C_SU_5, C_SU_5, C_SU_5
); // }}}

const color_t PROGMEM ledmap_dvorak[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_SU_4, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_5,
  C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_4,
  C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_4,
  C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2,
  C_SU_4, C_SU_4, C_SU_4, C_SU_3, C_SU_3,     C_SU_5,
                                  C_SU_5, C_SU_5, C_SU_5
); // }}}

const color_t PROGMEM ledmap_qwerty[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_DS_4, C_DS_3, C_DS_3, C_DS_3, C_DS_3, C_DS_3, C_DS_5,
  C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_4,
  C_DS_4, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_2, C_DS_4,
  C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2,
  C_DS_4, C_DS_4, C_DS_4, C_DS_3, C_DS_3,     C_DS_5,
                                  C_DS_5, C_DS_5, C_DS_5
); // }}}

const color_t PROGMEM ledmap_gaming[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_5,
  C_RU_2, C_RU_2, C_RU_2, C_RU_1, C_RU_2, C_RU_2, C_RU_3,
  C_RU_4, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,
  C_RU_4, C_RU_2, C_RU_2, C_RU_2, C_RU_2, C_RU_3,
  C_RU_4, C_RU_2, C_RU_2, C_RU_3, C_RU_3,     C_RU_5,
                                  C_RU_2, C_RU_4, C_RU_4
); // }}}

const color_t PROGMEM ledmap_g_numpad[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_right( // {{{
  C_RU_5, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3,
  C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3,
  C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_4,
          C_RU_3, C_RU_1, C_RU_1, C_RU_1, C_____, C_RU_4,
      C_RU_5,     C_RU_3, C_RU_3, C_____, C_RU_4, C_RU_4,
  C_RU_1, C_RU_2, C_RU_1
); // }}}

const color_t PROGMEM ledmap_midi[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_____, C_____, C_____, C_____, C_____, C_____, C_TO_5,
  C_____, C_____, C_____, C_____, C_____, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____,     C_TO_5,
                                  C_____, C_____, C_____
); // }}}

const color_t PROGMEM ledmap_onehand[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_TO_4, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_5,
  C_TO_4, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_3,
  C_TO_4, C_TO_1, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_TO_3,
  C_TO_4, C_TO_2, C_TO_2, C_TO_2, C_TO_2, C_TO_2,
  C_TO_4, C_TO_3, C_TO_3, C_TO_3, C_TO_3,     C_TO_5,
                                  C_TO_5, C_TO_5, C_TO_5
); // }}}

const color_t PROGMEM ledmap_symbols[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_SU_4, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_5,
  C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_3,
  C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_1,
  C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2,
  C_SU_4, C_SU_4, C_SU_4, C_SU_3, C_SU_3,     C_SU_5,
                                  C_____, C_____, C_____
); // }}}

const color_t PROGMEM ledmap_o_symbols[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_right( // {{{
  C_SU_5, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3,
  C_SU_3, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_3,
  C_SU_3, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_4,
          C_SU_3, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_4,
      C_SU_5,     C_SU_3, C_SU_3, C_____, C_SU_4, C_SU_4,
  C_SU_1, C_SU_2, C_SU_1
); // }}}

const color_t PROGMEM ledmap_navigation[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_SU_4, C_RU_1, C_____, C_RU_3, C_____, C_RU_3, C_SU_5,
  C_SU_4, C_SU_2, C_SU_2, C_SU_1, C_SU_2, C_SU_2, C_RU_1,
  C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_RU_1,
  C_SU_4, C_____, C_SU_2, C_____, C_SU_2, C_SU_2,
  C_SU_4, C_SU_4, C_SU_4, C_SU_4, C_SU_4,     C_SU_5,
                                  C_SU_2, C_SU_2, C_SU_2
); // }}}

const color_t PROGMEM ledmap_numpad[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_SU_4, C_____, C_____, C_____, C_SU_3, C_SU_3, C_SU_5,
  C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_4,
  C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_RU_1,
  C_SU_4, C_SU_3, C_SU_1, C_SU_1, C_SU_1, C_SU_1,
  C_SU_4, C_SU_4, C_SU_4, C_SU_4, C_SU_4,     C_SU_5,
                                  C_SU_5, C_SU_5, C_SU_2
); // }}}

const color_t PROGMEM ledmap_o_numpad[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_right( // {{{
  C_SU_5, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_3,
  C_SU_3, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_3,
  C_SU_3, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_4,
          C_SU_3, C_SU_1, C_SU_1, C_SU_1, C_____, C_SU_4,
      C_SU_5,     C_SU_3, C_SU_3, C_____, C_SU_4, C_SU_4,
  C_SU_1, C_SU_2, C_SU_1
); // }}}

const color_t PROGMEM ledmap_shortcuts[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_SU_4, C_SU_1, C_SU_2, C_SU_2, C_SU_2, C_MA_1, C_SU_5,
  C_SU_4, C_SU_1, C_SU_2, C_____, C_____, C_MA_1, C_MA_1,
  C_SU_5, C_____, C_____, C_____, C_____, C_____, C_MA_1,
  C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_1,
  C_SU_4, C_SU_2, C_MA_1, C_MA_1, C_MA_1,     C_SU_5,
                                  C_____, C_____, C_____
); // }}}

const color_t PROGMEM ledmap_hub[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_SU_5, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_5,
  C_____, C_SU_1, C_____, C_____, C_SU_1, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____, C_____, C_SU_2,
  C_____, C_____, C_____, C_____, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____,     C_____,
                                  C_____, C_SU_5, C_SU_5
); // }}}

const color_t PROGMEM ledmap_media[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_SU_5, C_____, C_____, C_____, C_____, C_____, C_SU_5,
  C_____, C_SU_2, C_SU_1, C_SU_1, C_____, C_____, C_____,
  C_____, C_SU_2, C_SU_2, C_SU_2, C_____, C_____, C_SU_4,
  C_____, C_SU_1, C_SU_2, C_SU_2, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____,     C_____,
                                  C_____, C_____, C_____
); // }}}

const color_t PROGMEM ledmap_config[DRIVER_LED_TOTAL / 2] = LEDS_moonlander_left( // {{{
  C_SU_5, C_SU_2, C_SU_2, C_____, C_DS_1, C_DS_2, C_SU_5,
  C_SU_1, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_____,
  C_SU_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_SU_5,
  C_SU_2, C_____, C_____, C_____, C_____, C_____,
  C_____, C_____, C_____, C_____, C_____,     C_____,
                                  C_____, C_____, C_____
); // }}}

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
  const uint8_t inds; // last three LED indicators of the board
} layer_led_config_t;

const layer_led_config_t PROGMEM ledmap[L_MAX] = { // {{{
  [L_BASE]  = { .mode = LM_MIRROR, .colors = ledmap_base,       .inds = 0b111, },
  [L_DVK]   = { .mode = LM_MIRROR, .colors = ledmap_dvorak,     .inds = 0b000, },
  [L_QRTY]  = { .mode = LM_MIRROR, .colors = ledmap_qwerty,     .inds = 0b001, },
  [L_ONEH]  = { .mode = LM_MIRROR, .colors = ledmap_onehand,    .inds = 0b001, },
  [L_STEN]  = { .mode = LM_BOTH,   .colors = ledmap_steno,      .inds = 0b010, },
  [L_GAME]  = { .mode = LM_LEFT,   .colors = ledmap_gaming,     .inds = 0b100, },
  [L_G_NU]  = { .mode = LM_RIGHT,  .colors = ledmap_g_numpad,   .inds = 0b100, },
  [L_O_GA]  = { .mode = LM_NONE,   .colors = NULL,              .inds = 0b000, },
  [L_MIDI]  = { .mode = LM_MIRROR, .colors = ledmap_midi,       .inds = 0b111, },
  [L_MOUS]  = { .mode = LM_MIRROR, .colors = ledmap_mouse,      .inds = 0b100, },
  [L_O_MO]  = { .mode = LM_RIGHT,  .colors = ledmap_o_mouse,    .inds = 0b100, },
  [L_SYMS]  = { .mode = LM_MIRROR, .colors = ledmap_symbols,    .inds = 0b110, },
  [L_O_SY]  = { .mode = LM_RIGHT,  .colors = ledmap_o_symbols,  .inds = 0b011, },
  [L_NUM]   = { .mode = LM_MIRROR, .colors = ledmap_numpad,     .inds = 0b011, },
  [L_O_NU]  = { .mode = LM_RIGHT,  .colors = ledmap_o_numpad,   .inds = 0b011, },
  [L_NAVI]  = { .mode = LM_MIRROR, .colors = ledmap_navigation, .inds = 0b101, },
  [L_SHRT]  = { .mode = LM_MIRROR, .colors = ledmap_shortcuts,  .inds = 0b111, },
  [L_HUB]   = { .mode = LM_MIRROR, .colors = ledmap_hub,        .inds = 0b111, },
  [L_MEDI]  = { .mode = LM_MIRROR, .colors = ledmap_media,      .inds = 0b111, },
  [L_CONF]  = { .mode = LM_MIRROR, .colors = ledmap_config,     .inds = 0b111, },
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
    float f = (float)rgb_matrix_get_val() / UINT8_MAX;
    rgb_matrix_set_color(led, f * rgb.r, f * rgb.g, f * rgb.b);
  }
} // }}}

void set_led_colors(int first_led, int last_led, const color_t *colors) { // {{{
  for (int led_ind = first_led, color_ind = 0; led_ind <= last_led; led_ind++, color_ind++) {
    set_led_color(led_ind, colors[color_ind]);
  }
} // }}}

void rgb_matrix_indicators_user(void) { // {{{
  if (rgb_matrix_get_suspend_state() || keyboard_config.disable_layer_led) return;

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

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void matrix_init_user(void) {
  layer_move(L_DVK);
  steno_set_mode(STENO_MODE_GEMINI);
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

    case GAMING:
      if (record->event.pressed) {
        layer_move(L_GAME);
        layer_on(L_G_NU);
        layer_on(L_O_GA);
      }
      return false;

    case G_DVK:
      if (record->event.pressed) {
        layer_invert(L_G_NU);
        layer_invert(L_DVK);
      }

      return false;
  }

  return true;
} // }}}

layer_state_t layer_state_set_user(layer_state_t state) { // {{{
  // if we're not in one-handed mode, we can add extras to the right-hand side
  if (IS_LAYER_OFF(L_ONEH)) {
  }
  state = update_tri_layer_state(state, L_NUM, L_NAVI, L_FUNC); // function keys

  layer_state_t state_with_default = state | default_layer_state;

  for (int8_t layer = MAX_LAYER - 1; layer >= 0; layer--) {
    if (state_with_default & (1UL << layer)) {
      uint8_t inds = ledmap[layer].inds;
      ML_LED_4((inds & 0b001) != 0);
      ML_LED_5((inds & 0b010) != 0);
      ML_LED_6((inds & 0b100) != 0);
      break;
    }
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

/* vim: set foldmethod=marker : */
