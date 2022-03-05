/* Copyright 2022 @ Emil Erlandsson
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
#include "emilerl.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_DBLBR: // Double brackets for Obsidian
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("88"));
            }
            return false;  // Skip all further processing of this key
        case KC_MLOCK: // CTRL + CMD + q to lock the mac
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_Q);
            } else {
                unregister_code(KC_Q);
                unregister_code(KC_LGUI);
                unregister_code(KC_LCTL);
            }
            return false;  // Skip all further processing of this key
        case KC_FRSH: // Trigger the Start Fresh Keyboard Maestro command
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LGUI);
                register_code(KC_F);
            } else {
                unregister_code(KC_F);
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
            }
            return false;  // Skip all further processing of this key
        case KC_PST: // Trigger the paste as plain text Keyboard Maestro command
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                register_code(KC_V);
            } else {
                unregister_code(KC_V);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_B) {
            SEND_STRING("Best regards,\nEmil");
        }

        SEQ_ONE_KEY(KC_D) {
            SEND_STRING("<date");
        }

        SEQ_ONE_KEY(KC_M) {
            SEND_STRING("Mvh,\nEmil");
        }

        SEQ_TWO_KEYS(KC_E, KC_E) {
            SEND_STRING("ee");
            SEND_STRING(SS_LALT("2"));
            SEND_STRING("a2isystems.com");
        }

        SEQ_THREE_KEYS(KC_E, KC_B, KC_U) {
            SEND_STRING("emil");
            SEND_STRING(SS_LALT("2"));
            SEND_STRING("buglix.org");
        }
    }
}
