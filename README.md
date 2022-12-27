# libcol

A C library for colored output (Uses printf internally). Pretty easy to use. For instructions on usage, please go [here](#usage).

For installation, please go [here](#installation). For documentation, please go [here](#documentation).

## Usage

### TL;DR

The shown below is a tl;dr version. Proper instructions are [here](#step-1)

```c
#include <libcol.h>
#include <stdio.h>

int main() {
  PCOL("Hello\n", RED);
  printf("Msg: %s <- Msg Done\n", print_col("world", GREEN));
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
#include <libcol.h>
```

**NOTE**: Link the library and dependencies when compiling

```bash
$ gcc a.c -o a.o -lcol
```

### Step 2

Print in color:

```c
printf("Msg: %s <- Msg Done\n", print_col("world", GREEN));
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

#### Coloring Parts of Printf

```c
char *print_col(char *text, color_t color);
```

#### Entire colored line

```c
PCOL(TEXT, COLOR);
```
