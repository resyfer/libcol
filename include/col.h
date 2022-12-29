#ifndef __LIBCOL_H
#define __LIBCOL_H

#include <sys/types.h>

#include "global.h"

#define ESC '\033'
#define CSI '['

typedef enum {
	NORMAL = 0,
	BOLD = 1,
	ITALIC = 3,
	UNDERLINE = 4,
	STRIKETHROUGH = 9,
} style_t;

typedef enum {
	BLACK = 30,
	RED = 31,
	GREEN = 32,
	YELLOW = 33,
	BLUE = 34,
	PURPLE = 35,
	CYAN = 36,
	WHITE = 37,
} color_t;
// #define COLOR_CODE(COLOR, STYLE) (ESC "[" STR(STYLE) ";" STR(COLOR) "m")

static const char* RESET = "\033[0m"; // ESC CSI 0m

char* col_str(color_t color);
char* col_str_style(color_t color, style_t style);

char* colorify(char *text, color_t color);
char* colorify_style(char *text, color_t color, style_t style);

#endif