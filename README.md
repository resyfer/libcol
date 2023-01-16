# libcol

A C library for colored output (Uses printf internally). Pretty easy to use. For instructions on usage, please go [here](#usage).

For installation, please go [here](#installation). For documentation, please go [here](#documentation).

## Usage

### TL;DR

The shown below is a tl;dr version. Proper instructions are [here](#step-1)

```c
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
```

Compile and run:

```bash
$ gcc test.c -o test.o -lcol
$ ./test.o
```
Output:

![image](https://user-images.githubusercontent.com/74897008/209982661-88f2d16f-8e5c-4091-a138-1acb401d558e.png)

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
char color_green[MAX] = {0};
col_str(GREEN, color_green);
printf("%sHello World%s\n", color_green, RESET);

// or,

char color_text_blue[MAX] = {0};
colorify("Awesome library", BLUE, color_text_blue);
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