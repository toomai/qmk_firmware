/* Copyright 2019 Thomas Campistron
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

#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "muse.h"

enum preonic_layers {
  _AZERTY,
  _FN,
};

enum preonic_keycodes {
  AZERTY = SAFE_RANGE,
  FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * |   )  |   &  |   é  |   "  |  '   |   (  |   §  |   è  |  !   |   ç  |   à  | Bsp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  $   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   W  |   X  |   C  |   V  |   B  |   N  |   ,  |   ;  |   :  |   =  |  ^   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Super | Alt  | Del  |  -   |   Space     |RAISE | RALT  |   ù |   µ  |  <   |
 * `-----------------------------------------------------------------------------------'
 */
[_AZERTY] = LAYOUT_preonic_grid( \
  FR_RPRN,  KC_1,     KC_2,     KC_3,   KC_4,     KC_5,   KC_6,   KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPACE, \
  KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,     KC_T,   KC_Y,   KC_U,     KC_I,     KC_O,     KC_P,     KC_RBRC, \
  KC_ESC,   KC_A,     KC_S,     KC_D,   KC_F,     KC_G,   KC_H,   KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT, \
  KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,     KC_B,   KC_N,   KC_M,     KC_COMM,  KC_DOT,   KC_SLASH, KC_LBRC, \
  KC_LCTRL, KC_LGUI,  KC_LALT,  KC_DEL, KC_EQL,  KC_SPC, KC_SPC, MO(_FN),   KC_RALT,  KC_QUOT,  KC_NUHS,  FR_LABK   \
),

/* FN
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |Brigh+|   7  |   8  |   9  |  NO  |Print | Prev | Pause| Next | NO   | Vol+ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |Brigh-|   4  |   5  |   6  |  NO  |Caplok| Left | Down |  Up  |Right | Vol- |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |  .   |   1  |   2  |   3  |   0  |  NO  |  NO  |PGdown| Pgup |  NO  | Mute |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Super | Alt  | Del |    -  |    Space    |Enter |Option|  NO  |  NO  |Escape|
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_grid( \
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,      KC_F10,   KC_F11,   KC_F12,   \
  _______,  KC_BRIU,  KC_P7,    KC_P8,    KC_P9,    XXXXXXX,  KC_PSCR,  KC_MPRV,  KC_MPLY,    KC_MNXT,  XXXXXXX,  KC_VOLU,  \
  _______,  KC_BRID,  KC_P4,    KC_P5,    KC_P6,    XXXXXXX,  KC_CAPS,  KC_LEFT,  KC_DOWN,    KC_UP,    KC_RIGHT, KC_VOLD,  \
  _______,  KC_PDOT,  KC_P1,    KC_P2,    KC_P3,    KC_P0,    XXXXXXX,  XXXXXXX,  KC_PGDOWN,  KC_PGUP,  XXXXXXX,  KC_MUTE,  \
  _______,  _______,  _______,  _______,  KC_LEAD,  _______,  _______,  _______,  _______,    XXXXXXX,  XXXXXXX,  KC_ESC    \
),

};
LEADER_EXTERNS();

void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leading = false;
		leader_end();

		// leader -> r -> r
		SEQ_TWO_KEYS(KC_L, KC_L) {
			reset_keyboard();
		}
		// from bepo: leader -> k -> A
		SEQ_TWO_KEYS(KC_B, KC_A) {
			default_layer_set(_AZERTY);
		}
	}
}
