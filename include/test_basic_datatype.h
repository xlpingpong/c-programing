/*** 
 * 文件包含 C 语言学习与编程练习：基本数据类型
 * 
***/
#ifndef TEST_BASIC_DATATYPE_H
#define TEST_BASIC_DATATYPE_H

#include "test_common.h"
#include <stdio.h>

// size_t
int test_size_of(void)
{
    size_t num = 5;
    printf("sizeof size_t: %d.\n", sizeof(num));
    int a = 5;
    printf("sizeof int: %d.\n", sizeof(a));
    int *pa = &a;
    printf("sizeof int pointer: %d.\n", sizeof(pa));
    float b = 5;
    printf("sizeof float: %d.\n", sizeof(b));
    double c = 5;
    printf("sizeof double: %d.\n", sizeof(c));
    return SUCCESS;
}

// unsigned char, 翻转
int test_unsigned_char(void)
{
    unsigned char val0 = 255;
    unsigned char val1 = val0 + 1;
    printf("unsigned char: value = %d, value + 1 is %d, size is %d.\n", val0, val1, sizeof(val0));
    return SUCCESS;
}

// unsigned char, 翻转
int test_unsigned_char(void)
{
    unsigned char val0 = 255;
    unsigned char val1 = val0 + 1;
    printf("unsigned char: value = %d, value + 1 is %d, size is %d.\n", val0, val1, sizeof(val0));
    return SUCCESS;
}

#endif // TEST_BASIC_DATATYPE_H