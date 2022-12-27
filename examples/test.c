#include <libcol.h>
#include <stdio.h>

int main() {
	PCOL("Hello\n", RED);
	printf("Msg: %s <- Msg Done\n", print_col("world", GREEN));
	return 0;
}