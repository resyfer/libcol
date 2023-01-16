#include <stdio.h>
#include <unistd.h>

#include <include/col.h>

static int __LIBCOL_SUPPORT_COLORS = 1;

void
color_init()
{
	if(!isatty(STDOUT_FILENO)) {
		__LIBCOL_SUPPORT_COLORS = 0;
	}
}

void
col_str_style(color_t color, style_t style, char* color_str)
{
	if(!__LIBCOL_SUPPORT_COLORS) {
		return;
	}

	snprintf(color_str, 8, "%c%c%d%c%dm", ESC, CSI, style, ';', color);
}

void
col_str(color_t color, char* color_str)
{
	col_str_style(color, NORMAL, color_str);
}

void
colorify_style(char *text, color_t color, style_t style, char* fmt_str)
{
	color_init();
	char color_str[50] = {0};
	col_str_style(color, style, color_str);

	snprintf(fmt_str, MAX_SIZE, "%s%s%s", color_str, text, RESET);
}

void
colorify(char *text, color_t color, char* color_str)
{
	colorify_style(text, color, NORMAL, color_str);
}