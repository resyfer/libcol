#include <libcol/col.h>
#include <stdio.h>

int main() {

	char *color_green = col_str(GREEN);
	char *color_yellow = col_str(YELLOW);
	char *color_red_italic = col_str_style(RED, ITALIC);

	printf("%sHello World%s\n", color_green, RESET);
	printf("%sH%si%s\n", color_red_italic, color_yellow, RESET);

	printf("%s\n", colorify("Awesome library", BLUE));
	// The above method is possible, but the allocated memory
	// for the text is not free-d after use, so please use it like:
	//
	// char *text = colorify("Awesome library", BLUE);
	// printf("%s\n", text);
	// free(text);

	free(color_green);
	free(color_yellow);
	free(color_red_italic);

	return 0;
}