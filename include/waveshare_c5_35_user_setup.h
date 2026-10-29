// SquachWatch — Waveshare ESP32-C5 3.5" TFT_eSPI user setup
//
// This is the board-specific TFT_eSPI config for the Waveshare ESP32-C5 3.5"
// display. It is intentionally minimal and mirrors the repo's other board
// headers: the app is responsible for board-specific runtime logic, while this
// file just tells TFT_eSPI which panel type and pins to use.
#pragma once

#define USER_SETUP_INFO "SquachWatch / Waveshare ESP32-C5 3.5 inch / ST7796"
#define ST7796_DRIVER

// Native portrait size. The app rotates at runtime to landscape in the usual
// SquachWatch pattern, so the panel is configured in the same way as the other
// ST7796 boards in this repo.
#define TFT_WIDTH   320
#define TFT_HEIGHT  480

// Waveshare 3.5" C5 board wiring used by the current build config.
#define TFT_MISO  2
#define TFT_MOSI  7
#define TFT_SCLK  6
#define TFT_CS     8
#define TFT_DC     5
#define TFT_RST   -1
#define TFT_BL    -1

// The board reports a GT911 touch controller on I2C, not an XPT2046 on the
// TFT SPI bus. The shared TFT_eSPI config therefore does not define TOUCH_CS.
// The app-side I2C touch code uses TOUCH_SDA/TOUCH_SCL/TOUCH_INT instead.

// Backlight is not wired through a GPIO on this panel's board config, so leave it
// disabled here and let the app handle LEDs separately if needed.
#define TFT_BACKLIGHT_ON HIGH

// Use the same conservative SPI timing as the other ST7796 boards in this repo.
#ifndef SPI_FREQUENCY
#define SPI_FREQUENCY      40000000
#endif
#define SPI_READ_FREQUENCY 20000000

// Load the built-in fonts used by the app. This keeps the TFT_eSPI setup aligned
// with the assumptions already made in the project build flags.
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT

// Common ST7796 polarity choice for these panels. If the panel shows inverted
// colours or a blank image after the app boots, the actual runtime override is in
// the app code and can be adjusted there.
#define TFT_INVERSION_ON
#define TFT_RGB_ORDER TFT_BGR
