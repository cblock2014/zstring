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
#ifndef __ZSTRING_H__
#define __ZSTRING_H__

#ifdef __cplusplus
extern "C" {
#endif

extern const int ZString_npos;
typedef struct ZString {
    void* thiz;
} ZString;

/**
 * @brief create ZString
 * @return ZString*
 */
ZString* ZString_create();

/**
 * @brief create ZString from string
 * @param str
 * @return ZString*
 */
ZString* ZString_createWithStr(const char* str);

/**
 * @brief clone a ZString
 * @param thiz
 * @return ZString*
 */
ZString* ZString_clone(ZString* thiz);

/**
 * @brief destroy ZString
 * @param thiz
 */
void ZString_destroy(ZString* thiz);

/**
 * @brief get ZString data
 * @param thiz
 * @return char*
 */
char* ZString_data(ZString* thiz);

/**
 * @brief get ZString length
 * @param thiz
 * @return int
 */
int ZString_size(ZString* thiz);

/**
 * @brief clear ZString
 * @param thiz
 */
void ZString_clear(ZString* thiz);

/**
 * @brief find str position in ZString
 * @param thiz
 * @param str
 * @return int
 */
int ZString_find(ZString* thiz,const char* str);

/**
 * @brief find str position in ZString from a begin pos
 * @param thiz 
 * @param str 
 * @param pos 
 * @return int 
 */
int ZString_findAt(ZString* thiz,const char* str, int pos);

/**
 * @brief append a ZString to the end of ZString
 * @param thiz
 * @param object
 */
ZString* ZString_append(ZString* thiz, const ZString* object);

/**
 * @brief append a char to the end of ZString
 * @param thiz
 * @param ch
 */
void ZString_appendCh(ZString* thiz, char ch);

/**
 * @brief append a str to the end of ZString
 * @param thiz
 * @param str
 */
void ZString_appendStr(ZString* thiz,const char* str);

/**
 * @brief append byte array to the end of ZString
 * @param thiz
 * @param data
 * @param size
 */
void ZString_appendData(ZString* thiz,const char* data, int size);

/**
 * @brief erase ZString from start position
 * @param thiz
 * @param start
 * @param len
 */
void ZString_erase(ZString* thiz, int start, int len);

/**
 * @brief insert an ZString at the position pos
 * @param thiz
 * @param object
 */
void ZString_insert(ZString* thiz, int pos, const ZString* object);

/**
 * @brief insert byte array at the position pos
 * @param thiz
 * @param pos
 * @param data
 * @param len
 */
void ZString_insertData(ZString* thiz, int pos, const char* data, int len);

/**
 * @brief get a sub string of ZString
 * @param thiz 
 * @param start 
 * @param len 
 * @return ZString* return a new ZString object, remember destroy it!
 */
ZString* ZString_substr(ZString* thiz, int start, int len);

#ifdef __cplusplus
}
#endif
#endif