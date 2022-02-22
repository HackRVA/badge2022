
#include "display_s6b33.h"
#include "framebuffer.h"
#include "colors.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

bool flipped = false;
bool rotated = false;

// gdk requires byte-size color values
uint8_t display_array[LCD_YSIZE][LCD_XSIZE][3];

static uint8_t rect_x = 0;
static uint8_t rect_y = 0;
static uint8_t max_x = 0;
static uint8_t max_y = 0;

static int16_t cur_x;
static int16_t cur_y;

void S6B33_init_device(void) {

}

void S6B33_init_gpio(void) {

}

void S6B33_reset(void) {
    memset(display_array, 0, sizeof(display_array));
}

void S6B33_rect(int x, int y, int width, int height) {
    rect_x = x;
    rect_y = y;
    max_x = x+width;
    max_y = y+height;
    if (rotated) {
        cur_y = y + height;
        cur_x = x;
    } else if (flipped) {
        cur_y = y + height;
        cur_x = x + width;
    } else {
        cur_y = y;
        cur_x = x;
    }
}

void S6B33_pixel(unsigned short pixel) {

    if (cur_x > max_x || cur_y > max_y) {
        return;
    }

    display_array[cur_y][cur_x][0] = (pixel & RED) >> 8;
    display_array[cur_y][cur_x][1] = (pixel & GREEN) >> 3;
    display_array[cur_y][cur_x][2] = (pixel & BLUE) << 3;

    if (rotated) {
        cur_y--;
        if (cur_y < rect_y) {
            cur_y = max_y;
            cur_x += 1;
        }
    } else if (flipped) {
        cur_x--;
        if (cur_x < rect_x) {
            cur_x = max_x;
            cur_y -= 1;
        }
    } else {
        cur_x++;
        if (cur_x > max_x) {
            cur_x = rect_x;
            cur_y += 1;
        }
    };
}

/** Updates a consecutive sequence of pixels. */
void S6B33_pixels(unsigned short *pixel, int number) {
    for (int i=0; i<number; i++) {
        S6B33_pixel(pixel[i]);
    }
}

/** invert display */
void S6B33_set_display_mode_inverted(void) {
    flipped = true;
    rotated = false;
}
/** uninvert display */
void S6B33_set_display_mode_noninverted(void) {
    flipped = false;
}
/** get current display mode variable setting */
unsigned char S6B33_get_display_mode(void) {
    return flipped ? DISPLAY_MODE_INVERTED : DISPLAY_MODE_NORMAL;
}

int S6B33_get_rotation(void) {

    return rotated ? 0 : 1;
}
void S6B33_set_rotation(int yes) {
    if (yes) {
        flipped = false;
        rotated = true;
    } else {
        rotated = false;
    }
}

void S6B33_color(unsigned short pixel) {
    for (int i=0; i<LCD_XSIZE; i++) {
        for (int j=0; j<LCD_YSIZE; j++) {
            S6B33_pixel(pixel);
        }
    }
}