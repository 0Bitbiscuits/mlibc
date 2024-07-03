/*
 * Copyright (c) mlibc & plct lab
 *
 * SPDX-License-Identifier: MIT
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024/6/28   0Bitbiscuits the first version
 */
#include "../internal/printf.h"
#include <stdio.h>
#include <compiler.h>

mlibc_weak int snprintf(char* buffer, size_t count, const char* format, ...)
{
    va_list va;
    int ret = 0;

    va_start(va, format);
    ret = vsnprintf(buffer, count, format, va);
    va_end(va);
    
    return ret;
}