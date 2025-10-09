#if !defined(WIN32_CURSOR_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Milad Khodabandeh $
   $Notice: (C) Copyright 2024 by Milad Khodabandeh. All Rights Reserved. $
   ======================================================================== */

#include <stdint.h>

#define internal static
#define local_persist static
#define global_variable static

#define STRINGIFY(x) #x
#define win32_debug(hr) win32_debug_implementation(hr, STRINGIFY(hr))


typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int32_t bool32;

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef float real32;
typedef double real64;

#define Kilobytes(value) ((value) * 1024LL)
#define Megabytes(value) (Kilobytes(value) * 1024LL)
#define Gigabytes(value) (Megabytes(value) * 1024LL)
#define Terabytes(value) (Gigabytes(value) * 1024LL)


#define WIN32_CURSOR_H
#endif
