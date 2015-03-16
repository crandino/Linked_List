#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include <Windows.h>
#include <stdlib.h>
#include <stdarg.h>

#define MIN(a,b) (a<b ? a : b)
#define MAX(a,b) (a>b ? a : b)
#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__)

void log(const char file[], int line, const char* format, ...)
{
	static char tmp_string[4096];
	static char tmp_string2[4096];
	static va_list ap;
	va_start(ap, format);
	vsprintf_s(tmp_string, 4096, format, ap);
	va_end(ap);
	sprintf_s(tmp_string2, 4096, "\n%s(%d) : %s\n", file, line, tmp_string);
	OutputDebugString(tmp_string2);
}

template <class TYPE1>
void swap(TYPE1 &a, TYPE1 &b) {
	TYPE1 tmp;
	tmp = a;
	a = b;
	b = tmp;
}


#endif