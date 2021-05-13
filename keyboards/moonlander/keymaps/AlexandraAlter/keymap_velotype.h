/* Copyright 2021 Alexandra Alter
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "keymap.h"

// clang-format off

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │   │   │ P │ K │ I │ ' │ O │ K │ P │   │   │   │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │ F │ T │ J │ O │ U │ I │ J │ T │ F │   │   │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │      │ Z │ S │ C │ R │ E │ A │ E │ R │ C │ S │ Z │        │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
 * │        │ H │LSh│ ´ │ L │ N │ Y │ N │ L │ ` │RSh│          │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │        NoSpace         │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */

// Row 1
#define VL_LP    KC_3
#define VL_LK    KC_4
#define VL_LI    KC_5
#define VL_APO   KC_6
#define VL_RO    KC_7
#define VL_RK    KC_8
#define VL_RP    KC_9

// Row 2
#define VL_LF   KC_W
#define VL_LT   KC_E
#define VL_LJ   KC_R
#define VL_LO   KC_Y
#define VL_U    KC_U
#define VL_RI   KC_I
#define VL_RJ   KC_O
#define VL_RT   KC_P
#define VL_RF   KC_LBRC

// Row 3
#define VL_LZ   KC_A
#define VL_LS   KC_S
#define VL_LC   KC_D
#define VL_LR   KC_F
#define VL_LE   KC_G
#define VL_A    KC_H
#define VL_RE   KC_J
#define VL_RR   KC_K
#define VL_RC   KC_L
#define VL_RS   KC_SCLN
#define VL_RZ   KC_QUOT

// Row 4
#define VL_H    KC_Z
#define VL_LSH  KC_X
#define VL_LSYM KC_C
#define VL_LL   KC_V
#define VL_LN   KC_B
#define VL_Y    KC_N
#define VL_RN   KC_M
#define VL_RL   KC_COMM
#define VL_RSYM KC_DOT
#define VL_RSH  KC_SLSH

// Row 5
#define VL_NOS  KC_SPC

