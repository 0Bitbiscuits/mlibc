/*
 * Copyright (c) mlibc & plct lab
 *
 * SPDX-License-Identifier: MIT
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024/6/4   0Bitbiscuits  the first version
 */
#include <unistd.h>
#include <compiler.h>
#include <errno.h>

mlibc_weak off_t lseek(int fd, off_t offset, int whence)
{
    (void)fd;
    (void)offset;
    (void)whence;

    return -EINVAL;
}