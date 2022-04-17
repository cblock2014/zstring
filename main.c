/******************************************************************************
 * This file is part of ZSTRING.
 *
 * ZSTRING is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ZSTRING is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ZEMB.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Project: zstring
 * Author : FergusZeng
 * Email  : cblock@126.com
 * git	  : https://gitee.com/newgolo/zstring.git
 * Copyright 2022~2025 @ ShenZhen ,China
*******************************************************************************/
#include "common.h"
#include "zstring.h"

int main(int argc, char** argv) {
    ZString* s1 = ZString_create();
    ZString_appendData(s1, "hello",5);
    
    PRINT_DBG("s1---1:[%s] size:%d",ZString_data(s1),ZString_size(s1));
    ZString_appendCh(s1,',');
    PRINT_DBG("s1---2:[%s] size:%d",ZString_data(s1),ZString_size(s1));
    ZString_append(s1,ZString_createWithStr("world!"));
    PRINT_DBG("s1---3:[%s] size:%d",ZString_data(s1),ZString_size(s1));
    
    ZString* s2 = ZString_clone(s1);
    ZString_appendStr(s2," I am s2.");
    PRINT_DBG("s2:[%s] size:%d",ZString_data(s2),ZString_size(s2));

    int pos = ZString_find(s2,"world");
    PRINT_DBG("world pos: %d", pos);

    ZString_clear(s1);
    PRINT_DBG("clear s1, s1:%s, size:%d",ZString_data(s1),ZString_size(s1));

    ZString_erase(s2,6,6);
    PRINT_DBG("erase s2(6,6), s2:[%s] size:%d",ZString_data(s2),ZString_size(s2));

    ZString_insert(s2,6,ZString_createWithStr("world!"));
    PRINT_DBG("insert s2(6,\"world!\"), s2:[%s] size:%d",ZString_data(s2),ZString_size(s2));

    ZString_insertData(s2,6,"======",6);
    PRINT_DBG("insert s2(6,\"======\"), s2:[%s] size:%d",ZString_data(s2),ZString_size(s2));

    ZString_destroy(s1);
    ZString_destroy(s2);
    PRINT_DBG("delete, s1:%x, s2:%x",s1, s2);
    return 0;
}