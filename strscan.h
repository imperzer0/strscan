// Copyright (c) 2022 Perets Dmytro
// Author: Perets Dmytro <imperator999mcpe@gmail.com>
//
// Personal usage is allowed only if this comment was not changed or deleted.
// Commercial usage must be agreed with the author of this comment.

#ifndef STRSCAN_STRSCAN_
#define STRSCAN_STRSCAN_

#include <string.h>
#include <stdarg.h>
#include <stdio.h>


/// Maps source string to substrings using the given format
/// @param source The source string
/// @param format The format string
/// @param ... The substrings
extern int strscanf(const char* __restrict source, const char* __restrict format, ...);

/// Maps source string to substrings using the given format (va_list version)
/// @param source The source string
/// @param format The format string
/// @param args The substrings
extern int vstrscanf(const char* __restrict source, const char* __restrict format, va_list args);

#endif //STRSCAN_STRSCAN_
