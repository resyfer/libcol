#include <libcol/col.h>
#include <stdio.h>

#define MAX 200

int main() {

	char color_green[MAX] = {0},
		color_yellow[MAX] = {0},
		color_red_italic[MAX] = {0},
		color_text_blue[MAX] = {0};

	col_str(GREEN, color_green);
	col_str(YELLOW, color_yellow);
	col_str_style(RED, ITALIC, color_red_italic);

	printf("%sHello World%s\n", color_green, RESET);
	printf("%sH%si%s\n", color_red_italic, color_yellow, RESET);

	colorify("Awesome library", BLUE, color_text_blue);
	printf("%s\n", color_text_blue);

	return 0;
}