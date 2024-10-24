/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #include "keyboards/fingerpunch/src/config_pre.h"

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// For shift register (and optionally trackball)
#define SPI_SCK_PIN GP22
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP23
#define POINTING_DEVICE_CS_PIN GP21

#define ROTATIONAL_TRANSFORM_ANGLE -25
#define POINTING_DEVICE_INVERT_X
#define PMW33XX_LIFTOFF_DISTANCE 0x02

// wiring of each half
#define MATRIX_COL_PINS { GP2, GP3, GP4, GP5, GP6, GP7 }
#define MATRIX_ROW_PINS { GP8, GP9, GP12, GP13 }
#define MATRIX_COL_PINS_RIGHT { GP2, GP3, GP4, GP5, GP6, GP7 }
#define MATRIX_ROW_PINS_RIGHT { GP8, GP9, GP12, GP13 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

// #define ENCODERS_PAD_A { GP7 }
// #define ENCODERS_PAD_B { GP8 }

// Got help from https://www.eisbahn.jp/yoichiro/2022/08/luankey_pico_qmk_firmware.html
#define MASTER_RIGHT
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_POINTING_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_HAPTIC_ENABLE
#define SERIAL_PIO_USE_PIO0

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#ifdef FP_TRACKBALL_ENABLE
    // Trackball config
    #define PMW33XX_CS_PIN GP21
    #undef PMW33XX_CPI
    #define PMW33XX_CPI 1000
    #define PMW33XX_CS_DIVISOR 8

    /* SPI config for pmw3360 sensor. */
    #define SPI_DRIVER SPID0
    // #define SPI_SCK_PAL_MODE 5 // already defined in chibios
    // #define SPI_MOSI_PAL_MODE 5 // already defined in chibios
    // #define SPI_MISO_PAL_MODE 5 // already defined in chibios
#endif

#if defined(FP_TRACKBALL_RIGHT_ONLY)
    #define POINTING_DEVICE_RIGHT               // one pointing device, on the right
    #define POINTING_DEVICE_INVERT_X_RIGHT      // for trackball on the right
#endif

#ifdef POINTING_DEVICE_ENABLE
    #define PMW33XX_CPI 1000

// Add MOUSE_EXTENDED_REPORT by default
#    ifndef FP_POINTING_EXTENDED_MOUSE_REPORT_DISABLE
#        define MOUSE_EXTENDED_REPORT
#    endif

#    ifndef FP_POINTING_DEFAULT_DPI
#        define FP_POINTING_DEFAULT_DPI 10
#    endif

#    ifndef FP_POINTING_MIN_DPI
#        define FP_POINTING_MIN_DPI 2
#    endif

#    ifndef FP_POINTING_MAX_DPI
#        define FP_POINTING_MAX_DPI 60
#    endif

#    ifndef FP_POINTING_SNIPING_DPI
#        define FP_POINTING_SNIPING_DPI 2
#    endif

#    ifndef FP_POINTING_SNIPING_LAYER
#        define FP_POINTING_SNIPING_LAYER 2
#    endif

#    ifndef FP_POINTING_SNIPING_MIN_DPI
#        define FP_POINTING_SNIPING_MIN_DPI 2
#    endif

#    ifndef FP_POINTING_SNIPING_MAX_DPI
#        define FP_POINTING_SNIPING_MAX_DPI 5
#    endif

#    ifndef FP_POINTING_SCROLLING_DPI
#        define FP_POINTING_SCROLLING_DPI 2
#    endif

#    ifndef FP_POINTING_SCROLLING_LAYER
#        define FP_POINTING_SCROLLING_LAYER 3
#    endif

#    ifndef FP_POINTING_SCROLLING_MIN_DPI
#        define FP_POINTING_SCROLLING_MIN_DPI 2
#    endif

#    ifndef FP_POINTING_SCROLLING_MAX_DPI
#        define FP_POINTING_SCROLLING_MAX_DPI 10
#    endif

#    ifndef FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY
#        define FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY 3
#    endif

#    ifndef FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY_X
#        define FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY_X FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY
#    endif

#    ifndef FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY_Y
#        define FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY_Y FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY
#    endif

#    ifndef FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY_H
#        define FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY_H FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY
#    endif

#    ifndef FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY_V
#        define FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY_V FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY
#    endif

#    ifndef FP_POINTING_ZOOMING_LAYER
#        define FP_POINTING_ZOOMING_LAYER 1
#    endif

#endif
