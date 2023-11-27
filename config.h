// Copyright 2020-2023 Stefan Kerkmann (@karlk90)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* MATRIX CONFIG */
#define DEBUG_MATRIX_SCAN_RATE

/* SPLIT CONFIG */
#define SPLIT_HAND_PIN C13
#define SPLIT_LAYER_STATE_ENABLE

#if 0
// VBUS detection using the ideal diode circuit is notorously buggy depending
// on the op-amp used. Therefore we'll resort to the watchdog implementation by
// default. If you're board sucessfully works with VBUS detection enable this
// define.
#    define USB_VBUS_PIN A9
#endif

/* CRC DRIVER */
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

/* WS2812 DRIVER */
#define DRIVER_LED_TOTAL 80
#define WS2812_PWM_TARGET_PERIOD 800000
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 6
#define WS2812_DMA_CHANNEL 5
#define WS2812_EXTERNAL_PULLUP
#define FASTLED_SCALE8_FIXED 1

/* RGB MATRIX CONFIG */
#define RGB_MATRIX_LED_COUNT DRIVER_LED_TOTAL

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

// #undef RGBLIGHT_DEFAULT_MODE
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

/* SERIAL SPLIT DRIVER */
#define SERIAL_USART_TX_PIN B10
#define SERIAL_USART_RX_PIN B11
#define SERIAL_USART_DRIVER SD3
#define SERIAL_USART_FULL_DUPLEX

/* I2C DRIVER */
#define EEPROM_I2C_CAT24C512

/* OLED DRIVER CONFIG */
#define OLED_DISPLAY_64X128
#define OLED_IC OLED_IC_SH1107
/* Lowering the pre charge period fixes coil whining for the used display modules. */
#define OLED_PRE_CHARGE_PERIOD 0x22
#define OLED_VCOM_DETECT 0x35
#define OLED_TIMEOUT 15000

/* TAPPING CONFIG */
#define QUICK_TAP 0