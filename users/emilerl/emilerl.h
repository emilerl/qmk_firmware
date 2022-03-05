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

#pragma once

enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_DBLBR,
    KC_MLOCK,
    KC_FRSH,
    KC_PST
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
