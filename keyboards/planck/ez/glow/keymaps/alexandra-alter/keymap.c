#include QMK_KEYBOARD_H
#include "keymap_steno.h"
#include "keymap_us_international.h"
#include "muse.h"
#include "version.h"

extern keymap_config_t keymap_config;

typedef enum layer_t {
  L_BASE,
  L_DV,
  L_QT,
  L_OH,
  L_ST,
  L_LOWER,
  L_RAISE,
  L_ADJUST,
  L_FN,
  L_MAX,
} layer_t;

typedef enum custom_keycode_t {
  _ = SAFE_RANGE,
} custom_keycode_t;

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
#define XXX KC_NO
#define ___ KC_TRNS

#define L1(kc) (LGUI_T(kc))
META_KEY(L1, KC_LGUI, KC_ESC);
#define L2(kc) (LCTL_T(kc))
META_KEY(L2, KC_LCTL, KC_BSPC);
#define L3(kc) (LSFT_T(kc))
META_KEY(L3, KC_LSFT, KC_TAB);
#define L4(kc) (LSFT_T(kc))
META_KEY(L4, MO(L_FN), XXXXXXX);
#define L5(kc) (LCTL_T(kc))
META_KEY(L5, KC_LSFT, XXXXXXX);
#define L6(kc) (LALT_T(kc))
META_KEY(L6, KC_LALT, XXXXXXX);
#define L7(kc) (LGUI_T(kc))
META_KEY(L7, KC_LGUI, XXXXXXX);

#define LWR(kc) (LM(L_LOWER, kc))
META_KEY(LWR, MO(L_LOWER), XXXXXXX);
#define RAI(kc) (LM(L_RAISE, kc))
META_KEY(RAI, MO(L_RAISE), XXXXXXX);

#define R1(kc) (LGUI_T(kc))
META_KEY(R1, KC_LGUI, KC_BSPC);
#define R2(kc) (LCTL_T(kc))
META_KEY(R2, KC_LCTL, XXXXXXX);
#define R3(kc) (LSFT_T(kc))
META_KEY(R3, KC_LSFT, KC_ENT);

#define R4(kc) (LALT_T(kc))
META_KEY(R4, KC_LALT, KC_LEFT);
#define R5(kc) (LSFT_T(kc))
META_KEY(R5, KC_LSFT, KC_DOWN);
#define R6(kc) (LCTL_T(kc))
META_KEY(R6, KC_LCTL, KC_UP);
#define R7(kc) (LGUI_T(kc))
META_KEY(R7, KC_LGUI, KC_RIGHT);
// }}}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_BASE] = LAYOUT_planck_grid(
    KA_L1,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R1,
    KA_L2,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R2,
    KA_L3,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R3,
    KA_L4,   KA_L5,   KA_L6,   KA_L7,   KA_LWR,  KC_SPC,  KC_SPC,  KA_RAI,  KA_R7,   KA_R6,   KA_R5,   KA_R4
  ),

  [L_DV] = LAYOUT_planck_grid(
    _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    _______,
    _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [L_QT] = LAYOUT_planck_grid(
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [L_OH] = LAYOUT_planck_grid(
    _______, _______, KC_L,    KC_R,    KC_C,    KC_G,    KC_F,    KC_Y,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_W,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_B,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_P,    KC_S,    KC_N,    KC_T,    KC_H,    KC_D,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_Z,    KC_V,    KC_W,    KC_M,    KC_B,    _______, _______, _______, _______, _______, _______, _______
  ),

  [L_ST] = LAYOUT_planck_grid(
    STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
    STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    STN_FN,  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    XXXXXXX, STN_RE1, STN_RE1, STN_A,   STN_O,   TG(L_ST),TG(L_ST),STN_E,   STN_U,   STN_RE2, STN_RE2, XXXXXXX
  ),

  [L_LOWER] = LAYOUT_planck_grid(
    KC_TILD, _______, _______, _______, _______, _______, _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______,
    KC_DEL,  _______, _______, _______, _______, _______, _______, _______, KC_DLR,  KC_PERC, KC_CIRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [L_RAISE] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, KC_1,    KC_2,    KC_3,    _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, KC_4,    KC_5,    KC_6,    _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_0,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [L_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, TO(L_DV),TO(L_DV),TO(L_QT),TO(L_ST),_______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF,_______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [L_FN] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};
// clang-format off

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

// clang-format off
const color_t PROGMEM ledmap[L_MAX][DRIVER_LED_TOTAL] = {
  [L_BASE] = { // {{{
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_1,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_DV] = { // {{{
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_4,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_4,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_1,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_QT] = { // {{{
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_4,
    C_DS_4, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_2, C_DS_2, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_4,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_4,
    C_DS_5, C_DS_4, C_DS_4, C_DS_4, C_DS_5,     C_DS_1,     C_DS_5, C_DS_4, C_DS_4, C_DS_4, C_DS_4
  }, // }}}

  [L_OH] = { // {{{
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_1,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_ST] = { // {{{
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_1,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_LOWER] = { // {{{
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_1,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_RAISE] = { // {{{
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_1,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_ADJUST] = { // {{{
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_1,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_FN] = { // {{{
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_1,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
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

void rgb_matrix_indicators_user(void) { // {{{
  if (rgb_matrix_get_suspend_state() || keyboard_config.disable_layer_led)
    return;

  if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
    rgb_matrix_set_color_all(0, 0, 0);
    return;
  }

  layer_state_t layers = layer_state | default_layer_state;
  uint8_t layer = get_highest_layer(layers);
  const color_t *colors = ledmap[layer];

  for (int led_ind = 0; led_ind <= DRIVER_LED_TOTAL; led_ind++) {
    set_led_color(led_ind, colors[led_ind]);
  }
} // }}}

void keyboard_post_init_user(void) { // {{{
  rgb_matrix_enable_noeeprom();
  steno_set_mode(STENO_MODE_GEMINI);
  layer_move(L_DV);
} // }}}

layer_state_t layer_state_set_user(layer_state_t state) { // {{{
  planck_ez_left_led_off();
  planck_ez_right_led_off();
  uint8_t layer = get_highest_layer(state);
  switch (layer) {
  case L_LOWER:
    planck_ez_left_led_on();
    break;
  case L_RAISE:
    planck_ez_right_led_on();
    break;
  case L_ADJUST:
    planck_ez_right_led_on();
    planck_ez_left_led_on();
    break;
  }
  state = update_tri_layer_state(state, L_LOWER, L_RAISE, L_ADJUST);
  return state;
} // }}}

bool process_record_user(uint16_t keycode, keyrecord_t *record) { // {{{
  return true;
} // }}}

/* vim: set foldmethod=marker shiftwidth=2 : */
