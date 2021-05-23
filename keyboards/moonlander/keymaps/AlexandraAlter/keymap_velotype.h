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
#define VL_PL    KC_3
#define VL_KL    KC_4
#define VL_IL    KC_5
#define VL_APO   KC_6
#define VL_OR    KC_7
#define VL_KR    KC_8
#define VL_PR    KC_9

// Row 2
#define VL_FL   KC_W
#define VL_TL   KC_E
#define VL_JL   KC_R
#define VL_OL   KC_Y
#define VL_U    KC_U
#define VL_IR   KC_I
#define VL_JR   KC_O
#define VL_TR   KC_P
#define VL_FR   KC_LBRC

// Row 3
#define VL_ZL   KC_A
#define VL_SL   KC_S
#define VL_CL   KC_D
#define VL_RL   KC_F
#define VL_EL   KC_G
#define VL_A    KC_H
#define VL_ER   KC_J
#define VL_RR   KC_K
#define VL_CR   KC_L
#define VL_SR   KC_SCLN
#define VL_ZR   KC_QUOT

// Row 4
#define VL_H    KC_Z
#define VL_SHL  KC_X
#define VL_SYML KC_C
#define VL_LL   KC_V
#define VL_NL   KC_B
#define VL_Y    KC_N
#define VL_NR   KC_M
#define VL_LR   KC_COMM
#define VL_SYMR KC_DOT
#define VL_SHR  KC_SLSH

// Row 5
#define VL_NOS  KC_SPC

