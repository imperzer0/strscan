// Copyright (c) 2022 Perets Dmytro
// Author: Perets Dmytro <imperator999mcpe@gmail.com>
//
// Personal usage is allowed only if this comment was not changed or deleted.
// Commercial usage must be agreed with the author of this comment.

#include <malloc.h>
#include <stdarg.h>
#include "strscan.h"


#define STR(exp) #exp
#define PRINT_ERROR(function, message, args) fprintf(stderr, \
"Error in file '" __FILE_NAME__ "' in function '" STR(function) "' on line '%d': " STR(message) "\n", __LINE__, args)
#define PRINT_ERROR_NOARGS(function, message) fprintf(stderr, \
"Error in file '" __FILE_NAME__ "' in function '" STR(function) "' on line '%d': " STR(message) "\n", __LINE__)


int strscanf(const char* __restrict source, const char* __restrict format, ...)
{
	va_list args;
	va_start(args, format);
	int res = vstrscanf(source, format, args);
	va_end(args);
	return res;
}

int streq(const char* __restrict source_piece, const char* __restrict format_piece, size_t length);

int vstrscanf(const char* __restrict source, const char* __restrict format, va_list args)
{
	for (; *source && *format; ++source)
	{
		if (*format == '%')
			switch (*++format)
			{
				case 's':
				{
					++format;
					
					size_t pattern_size = 0;
					for (const char* format_it = format; *format_it; ++format_it, ++pattern_size)
						if (*format_it == '%' && *++format_it != '%') break;
					
					size_t arg_size = 0;
					const char* source_it = source;
					for (; *source_it && !streq(source_it, format, pattern_size); ++source_it, ++arg_size);
					
					char** result = va_arg(args, char**);
					
					if (!*format) arg_size = strlen(source);
					
					*result = (char*)calloc(arg_size + 1, sizeof(char));
					strncpy(*result, source, arg_size);
					(*result)[arg_size] = 0;
					
					source = source_it;
					format += pattern_size;
					
					if (!*source) return 0;
				}
					break;
				case 'c':
				{
					char* result = va_arg(args, char*);
					*result = *source;
					++format;
				}
					break;
				case '%':
					break;
				default:
				{
					PRINT_ERROR(void strscanv(const char* source, const char* format, va_list args),
					            Invalid format argument: %%%c, *format);
					return 0;
				}
			}
		
	}
	
	return 1;
}

int streq(const char* __restrict source_piece, const char* __restrict format_piece, size_t length)
{
	if (length == 0) return 0;
	for (int i = 0; i < length; ++i)
	{
		if (format_piece[i] == '%' && format_piece[i + 1] == '%') ++format_piece;
		if (source_piece[i] != format_piece[i]) return 0;
	}
	return 1;
}