/*
 * Copyright (c) mlibc & plct lab
 *
 * SPDX-License-Identifier: MIT
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024/5/6   0Bitbiscuits  realize sys_close
 */
#include <libc_config.h>
#ifdef MLIBC_RUNNING_RTTHREAD

#include <rtconfig.h>
#ifdef RT_USING_DFS

#include <sys/sys_fio.h>
#include <dfs_file.h>
#include <errno.h>
#include <unistd.h>

/**
 * @brief the function will close the open file descriptor.
 * 
 * @param fd the file descriptor
 * @return int 0 on successful, -1 on failed.
 */
int __mlibc_sys_close(int fd)
{
    close(fd);

    return 0;
}

#endif /* RT_USING_DFS */
#endif /* MLIBC_RUNNING_RT_THREAD */