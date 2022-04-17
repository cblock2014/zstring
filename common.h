/******************************************************************************
 * This file is part of ZSTRING.
 *
 * ZEMB is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ZEMB is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ZEMB.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Project: zemb
 * Author : FergusZeng
 * Email  : cblock@126.com
 * git	  : https://gitee.com/newgolo/zstring.git
 * Copyright 2022~2025 @ ShenZhen ,China
*******************************************************************************/

#ifndef __COMMON_H__
#define __COMMON_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG   1

#define PRINT(fmt,...)          do{printf(fmt "\n",##__VA_ARGS__);}while(0)
#define PRINT_RED(fmt,...)      do{printf("\033[31m\033[1m" fmt "\033[0m\n",##__VA_ARGS__);}while(0)
#define PRINT_GREEN(fmt,...)    do{printf("\033[32m\033[1m" fmt "\033[0m\n",##__VA_ARGS__);}while(0)
#define PRINT_YELLOW(fmt,...)   do{printf("\033[33m\033[1m" fmt "\033[0m\n",##__VA_ARGS__);}while(0)
#define PRINT_PINK(fmt,...)     do{printf("\033[35m\033[1m" fmt "\033[0m\n",##__VA_ARGS__);}while(0)
#define PRINT_CYAN(fmt,...)     do{printf("\033[36m\033[1m" fmt "\033[0m\n",##__VA_ARGS__);}while(0)
#define PRINT_WARN(fmt,...)     {PRINT_YELLOW("%s,L%d:" fmt,__FUNCTION__,__LINE__,##__VA_ARGS__);}
#define PRINT_ERR(fmt,...)      {PRINT_RED("%s,L%d:" fmt,__FUNCTION__,__LINE__,##__VA_ARGS__);}
#if DEBUG
#define PRINT_DBG(fmt,...)      {PRINT_GREEN("%s,L%d:" fmt,__FUNCTION__,__LINE__,##__VA_ARGS__);}
#else
#define PRINT_DBG(fmt,...)
#endif

/* 为便于嵌入式平台移植,以下常用函数使用宏替代 */
#define MALLOC(...)             malloc(__VA_ARGS__)
#define FREE(...)               free(__VA_ARGS__)
#define FREE_SAFE(ptr)          do{if (ptr) {free(ptr); ptr = NULL;}}while(0)
#define REALLOC(...)            realloc(__VA_ARGS__)
#define MEMCPY(...)             memcpy(__VA_ARGS__)
#define MEMMOVE(...)            memmove(__VA_ARGS__)
#define MEMSET(...)             memset(__VA_ARGS__)

#endif