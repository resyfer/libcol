#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#include "util.h"

#ifndef __LIBCOL_GLOBAL_H
#define __LIBCOL_GLOBAL_H

int __LIBCOL_SUPPORT_COLORS = 1;

#ifndef OS
	#ifdef __unix__
		#ifdef __linux__
			#define OS "Linux"
		#else
			#define OS "Unix"
		#endif
	#elif __APPLE__
		#define OS "Darwin"
	#elif _WIN32
		#define OS "Win32"
	#endif
#endif

#endif