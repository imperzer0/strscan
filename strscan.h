// Copyright (c) 2022 Perets Dmytro
// Author: Perets Dmytro <dmytroperets@gmail.com>

#ifndef STRSCAN_STRSCAN_H
#define STRSCAN_STRSCAN_H

#ifdef __cplusplus


#include <cstring>
#include <cstdarg>
#include <cstdio>

#else

#include <string.h>
#include <stdio.h>


#endif


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

#endif //STRSCAN_STRSCAN_H
