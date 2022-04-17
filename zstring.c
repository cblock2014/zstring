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
#include "zstring.h"
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

const int ZString_npos = -1;

typedef struct ZStringHandler {
    ZString m_object;
    char* m_data;
    int m_length;
} ZStringHandler;

ZString* ZString_create() {
    ZStringHandler* handler = (ZStringHandler*)MALLOC(sizeof(ZStringHandler));
    if (!handler) {
        printf("%s(L%d): ZString memory allocate exception!\n", __FILE__, __LINE__);
        exit(0);
    }
    handler->m_data = (char*)MALLOC(1);
    if (!handler->m_data) {
        FREE_SAFE(handler);
        printf("%s(L%d): ZString memory allocate exception!\n", __FILE__, __LINE__);
        exit(0);
    }
    handler->m_length = 0;
    handler->m_data[handler->m_length] = '\0';
    handler->m_object.thiz = &handler->m_object;
    return &handler->m_object;
}

ZString* ZString_createWithStr(const char* str) {
    ZString* thiz = ZString_create();
    ZString_appendStr(thiz, str);
    return thiz;
}

ZString* ZString_clone(ZString* thiz) {
    ZString* object = ZString_create();
    ZStringHandler* handler = (ZStringHandler*)(thiz);
    if (handler->m_length > 0) {
        ZString_appendData(object, handler->m_data, handler->m_length);
    }
    return object;
}

void ZString_destroy(ZString* thiz) {
    if (thiz) {
        ZStringHandler* handler = (ZStringHandler*)(thiz);
        FREE_SAFE(handler->m_data);
        handler->m_data = NULL;
        FREE_SAFE(handler);
        handler = NULL;
    }
}

char* ZString_data(ZString* thiz) {
    ZStringHandler* handler = (ZStringHandler*)(thiz);
    return handler->m_data;
}

int ZString_size(ZString* thiz) {
    ZStringHandler* handler = (ZStringHandler*)(thiz);
    return handler->m_length;
}

void ZString_clear(ZString* thiz) {
    ZStringHandler* handler = (ZStringHandler*)(thiz);
    handler->m_data = (char*)REALLOC(handler->m_data, 1);
    if (!handler->m_data) {
        printf("%s(L%d): ZString memory allocate exception!\n", __FILE__, __LINE__);
        exit(0);
    }
    handler->m_length = 0;
    handler->m_data[handler->m_length] = '\0';
}

int ZString_find(ZString* thiz, const char* str) {
    ZStringHandler* handler = (ZStringHandler*)(thiz);
    char* find = strstr(handler->m_data, str);
    if (!find) {
        return ZString_npos;
    }
    return (int)(find - handler->m_data);
}

int ZString_findAt(ZString* thiz, const char* str, int pos) {
    ZStringHandler* handler = (ZStringHandler*)(thiz);
    char* find = strstr(handler->m_data + pos, str);
    if (!find) {
        return ZString_npos;
    }
    return (int)(find - handler->m_data);
}

void ZString_appendCh(ZString* thiz, char ch) {
    ZStringHandler* handler = (ZStringHandler*)(thiz);
    handler->m_data = (char*)REALLOC(handler->m_data, handler->m_length + 2);
    if (!handler->m_data) {
        printf("%s(L%d): ZString memory allocate exception!\n", __FILE__, __LINE__);
        exit(0);
    }
    handler->m_data[handler->m_length++] = ch;
    handler->m_data[handler->m_length] = '\0';
}

void ZString_appendStr(ZString* thiz, const char* str) {
    ZString_appendData(thiz, str, strlen(str));
}

void ZString_appendData(ZString* thiz, const char* data, int size) {
    ZStringHandler* handler = (ZStringHandler*)(thiz);
    handler->m_data = (char*)REALLOC(handler->m_data, handler->m_length + size + 1);
    if (!handler->m_data) {
        printf("%s(L%d): ZString memory allocate exception!\n", __FILE__, __LINE__);
        exit(0);
    }
    MEMCPY(handler->m_data + handler->m_length, data, size);
    handler->m_length += size;
    handler->m_data[handler->m_length] = '\0';
}

ZString* ZString_append(ZString* thiz, const ZString* object) {
    ZStringHandler* handler = (ZStringHandler*)(object);
    ZString_appendData(thiz, handler->m_data, handler->m_length);
    return thiz;
}

void ZString_erase(ZString* thiz, int start, int len) {
    ZStringHandler* handler = (ZStringHandler*)(thiz);
    MEMMOVE(handler->m_data + start, handler->m_data + start + len, handler->m_length - start - len);
    handler->m_length -= len;
    handler->m_data = (char*)REALLOC(handler->m_data, handler->m_length + 1);
    if (!handler->m_data) {
        printf("%s(L%d): ZString memory allocate exception!\n", __FILE__, __LINE__);
        exit(0);
    }
    handler->m_data[handler->m_length] = '\0';
}

void ZString_insert(ZString* thiz, int pos, const ZString* object) {
    ZStringHandler* handler = (ZStringHandler*)(object);
    ZString_insertData(thiz, pos, handler->m_data, handler->m_length);
}

void ZString_insertData(ZString* thiz, int pos, const char* buffer, int len) {
    ZStringHandler* handler = (ZStringHandler*)(thiz);
    handler->m_data = (char*)REALLOC(handler->m_data, handler->m_length + len);
    if (!handler->m_data) {
        printf("%s(L%d): ZString memory allocate exception!\n", __FILE__, __LINE__);
        exit(0);
    }
    MEMMOVE(handler->m_data + pos + len, handler->m_data + pos, handler->m_length - pos);
    MEMCPY(handler->m_data + pos, buffer, len);
    handler->m_length += len;
    handler->m_data[handler->m_length] = '\0';
}

ZString* ZString_substr(ZString* thiz, int start, int len) {
    ZStringHandler* handler = (ZStringHandler*)(thiz);
    ZString* object = ZString_create();
    if (object) {
        ZString_appendData(object, handler->m_data + start, len);
    }
    return object;
}
#ifdef __cplusplus
}
#endif