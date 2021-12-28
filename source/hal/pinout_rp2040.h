//
// Created by Samuel Jones on 12/21/21.
//

#ifndef BADGE2022_C_PINOUT_RP2040_H
#define BADGE2022_C_PINOUT_RP2040_H

#include "hardware/gpio.h"

#define BADGE_GPIO_DISPLAY_CS (1)
#define BADGE_GPIO_DISPLAY_SCK (2)
#define BADGE_GPIO_DISPLAY_MOSI (3)
#define BADGE_GPIO_DISPLAY_RESET (4)
#define BADGE_GPIO_DISPLAY_DC (5)
#define BADGE_GPIO_DISPLAY_BACKLIGHT (6) // PWM controlled

#define BADGE_GPIO_DPAD_UP (7)
#define BADGE_GPIO_DPAD_RIGHT (8)
#define BADGE_GPIO_DPAD_DOWN (9)
#define BADGE_GPIO_DPAD_LEFT (10)
#define BADGE_GPIO_BUTTON (11)

#define BADGE_GPIO_IR_TX (12)
#define BADGE_GPIO_IR_RX (13)

#define BADGE_GPIO_SPEAKER_PHASE1 (14)
#define BADGE_GPIO_SPEAKER_PHASE2 (15)

#define BADGE_GPIO_LED_RED (16)
#define BADGE_GPIO_LED_GREEN (17)
#define BADGE_GPIO_LED_BLUE (18)
#define BADGE_GPIO_LED_WHITE (19)


#endif //BADGE2022_C_PINOUT_RP2040_H
