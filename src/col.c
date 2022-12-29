#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <include/col.h>

void
color_init()
{
	if(!isatty(STDOUT_FILENO)) {
		__LIBCOL_SUPPORT_COLORS = 0;
	}
}

char*
col_str_style(color_t color, style_t style)
{
	if(!__LIBCOL_SUPPORT_COLORS) {
		return "";
	}

	char *color_str = malloc(8 * sizeof(char));
	snprintf(color_str, 8, "%c%c%d%c%dm", ESC, CSI, style, ';', color);

	return color_str;
}

char*
col_str(color_t color)
{
	return col_str_style(color, NORMAL);
}

char*
colorify_style(char *text, color_t color, style_t style)
{
	color_init();
	char *fmt_text = (char*) malloc(MAX_SIZE * sizeof(char));
	char *color_str = col_str_style(color, style);

	snprintf(fmt_text, MAX_SIZE, "%s%s%s", color_str, text, RESET);
	fmt_text = realloc(fmt_text, sizeof(char) * (strlen(fmt_text) + 1));

	free(color_str);

	return fmt_text;
}

char*
colorify(char *text, color_t color)
{
	return colorify_style(text, color, NORMAL);
}