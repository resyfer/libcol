# libcol

A C library for colored output (Uses printf internally). Pretty easy to use. For instructions on usage, please go [here](#usage).

For installation, please go [here](#installation). For documentation, please go [here](#documentation).

## Usage

### TL;DR

The shown below is a tl;dr version. Proper instructions are [here](#step-1)

```c
#include <libcol/col.h>
#include <stdio.h>

int main() {

	char *color_green = col_str(GREEN);
	printf("%sHello World%s\n", color_green, RESET);
	free(color_green);


	char *color_yellow = col_str(YELLOW);
	char *color_red_italic = col_str_style(RED, ITALIC);
	printf("%sH%si%s\n", color_red_italic, color_yellow, RESET);

	free(color_yellow);
	free(color_red_italic);

	printf("%s\n", colorify("Awesome library", BLUE));
	// The above method is possible, but the allocated memory
	// for the text is not free-d after use, so please use it like:
	//
	// char *text = colorify("Awesome library", BLUE);
	// printf("%s\n", text);
	// free(text);

	return 0;
}
```

Compile and run:

```bash
$ gcc test.c -o test.o -lcol
$ ./test.o
```
Output:

![image](https://user-images.githubusercontent.com/74897008/209649275-46b785c9-02e9-4998-9aa9-fdcc696cdd04.png)

### Step 1

Import the library:

```c
#include <libcol/col.h>
```

**NOTE**: Link the library and dependencies when compiling

```bash
$ gcc a.c -o a.o -lcol
```

### Step 2

Print in color:

```c
char *color_green = col_str(GREEN);
printf("%sHello World%s\n", color_green, RESET);
free(color_green);
// or

printf("%s\n", colorify("Awesome library", BLUE));
// Please use instead:
// char *text = colorify("Awesome library", BLUE);
// printf("%s\n", text);
// free(text);
```

## Allowed Colors

- BLACK
- RED
- GREEN
- YELLOW
- BLUE
- PURPLE
- CYAN
- WHITE

## Installation

Make sure to have [make](https://www.gnu.org/software/make/), [gcc](https://www.gnu.org/software/gcc/) and [git](https://git-scm.com/) installed.

```bash
git clone https://github.com/resyfer/libcol.git
cd libcol
make install
cd ..
rm -rf libcol
```

Provide the password when prompted.

## Documentation

### For getting the color string of colors or styles
```c
char* col_str(color_t color);
char* col_str_style(color_t color, style_t style);
```

### For coloring or styling a string
```c
char* colorify(char *text, color_t color);
char* colorify_style(char *text, color_t color, style_t style);
```