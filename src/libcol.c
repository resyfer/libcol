#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <include/libcol.h>
#include <include/global.h>

void
color_init()
{
	if(!isatty(STDOUT_FILENO)) {
		SUPPORT_COLORS = 0;
	}
}

const char*
colorify(color_t color)
{
	if(!SUPPORT_COLORS) {
		return "";
	}

	if(color < BLACK || color > WHITE) {
		printf("Incorrected Colors\n");
		exit(1);
	}

	/*
	 * FUTURE: Wanted to give an option for bold,
	 * but too much redundant code.
	 */
	// if(text_style != NORMAL && text_style != BOLD) {
	// 	printf("Incorrect Text Style\n");
	// 	exit(1);
	// }

	switch(color) {
	case BLACK:
		return ESC "[" STR(NORMAL) ";" STR(BLACK) "m";
	case RED:
		return ESC "[" STR(NORMAL) ";" STR(RED) "m";
	case GREEN:
		return ESC "[" STR(NORMAL) ";" STR(GREEN) "m";
	case YELLOW:
		return ESC "[" STR(NORMAL) ";" STR(YELLOW) "m";
	case BLUE:
		return ESC "[" STR(NORMAL) ";" STR(BLUE) "m";
	case PURPLE:
		return ESC "[" STR(NORMAL) ";" STR(PURPLE) "m";
	case CYAN:
		return ESC "[" STR(NORMAL) ";" STR(CYAN) "m";
	case WHITE:
		return ESC "[" STR(NORMAL) ";" STR(WHITE) "m";
	default:
		return "";
	}
}

char*
print_col(char *text, color_t color)
{
	color_init();
	char *fmt_text = (char*) malloc(MAX_SIZE * sizeof(char));
	snprintf(fmt_text, MAX_SIZE, "%s%s%s", colorify(color), text, RESET);

	return fmt_text;
}