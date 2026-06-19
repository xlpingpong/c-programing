/*** 
 * 指针
***/
#ifndef TEST_STRING_POINTERS_H
#define TEST_STRING_POINTERS_H

#include "test_common.h"

// 字符串常量的地址
int test_pointer_const_strings_case0(void)
{
    const char *str1 = "hello";
    char str2[] = "hello";
    const char *str3 = "hello";

    printf("str1, size = %d, address: %x.\n", sizeof(str1), str1);
    printf("str2, size = %d, address: %x.\n", sizeof(str2), str2);
    printf("str3, size = %d, address: %x.\n", sizeof(str3), str3);
    return SUCCESS;
}

int test_pointer_const_strings_case1(void)
{
    char str1[6] = "hello";
    char str2[] = "hello";
    char str3[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str4[10] = {'h', 'e', '\0', 'l', 'l', 'o', '\0'};
    char str5[5] = {'h', 'e', 'l', 'l', 'o'};
    printf("str1, size = %d, address: %x, conten: %s.\n", sizeof(str1), str1, str1);
    printf("str2, size = %d, address: %x, conten: %s.\n", sizeof(str2), str2, str2);
    printf("str3, size = %d, address: %x, conten: %s.\n", sizeof(str3), str3, str3);
    printf("str4, size = %d, address: %x, conten: %s.\n", sizeof(str4), str4, str4);
    printf("str5, size = %d, address: %x, conten: %s.\n", sizeof(str5), str5, str5);
    return SUCCESS;
}


/* *************************************************
* 内存安全函数

* 1. strncpy() — 长度受限的字符串复制
char *strncpy(char *dest, const char *src, size_t n);
1) 不会越界，最多写 n 个字节到 dest
2) 不会自动补 `\0`，如果 src 长度 ≥ n，dest 不会以 null 结尾
3) 剩余空间填 `\0`，如果 src 长度 < n，剩余字节全部填充为 `\0` 

* 2. strncat() — 长度受限的字符串拼接
char *strncat(char *dest, const char *src, size_t n);
1) 自动补 `\0`，结果始终 null 结尾
2) n 是追加数量，不是 dest 的剩余空间大小
3) 需要 dest 已 `\0` 结尾，否则从 dest 末尾越界查找 `\0`

* 1. memmove() — 安全的内存块复制
void *memmove(void *dest, const void *src, size_t n);
1) 处理重叠，自动判断复制方向（从高地址或低地址开始）
2) 按字节复制，不检查内容，纯二进制复制 
3) 不处理 `\0`，复制 n 个字节，不管内容是什么

************************************************* */
int Test_strncpy_string_case0(void)
{
    const int num = 10;
    const int numSize = 10 * sizeof(int);
    int arrayA[5] = {1,2,3,4,5};
    int *ptrA = (int*)malloc(numSize);
    int *ptrB = (int*)malloc(numSize); 
    // memset((void*)ptr, 0, sizeof(int));
    memcpy((void*)ptrA, (void*)arrayA, sizeof(arrayA));
    strncpy((char*)ptrB, (char*)arrayA, numSize);
    
    printf("\nsizeof int[]: %d\n.", sizeof(arrayA));
    printf("\nsizeof ptrA: %d\n.", sizeof(ptrA));
    free(ptrA);
    free(ptrB);
    return 0;
}

// 字符串数组
int Test_stringArray_string_case0(void)
{
    char strA[][5] = {"what", "is", "your", "name"};
    // char* strB[] = {"what", "is", "your", "name"};
    char ptr[] = "is";
    printf("size of strA is: %x.\n", sizeof(strA));
    printf("address of strA[1] is: %x.\n", strA[1]);
    printf("address of ptr is: %x.\n", ptr);
    return 0;
}

// 字符串比较
int Test_strcmp_string_case0(void)
{
    char strA[10] = "wh\0at";
    char strB[10] = "wh\0ot";
    printf("strcmp result: %d.\n", strcmp(strA, strB));
    printf("strncmp result: %d.\n", strncmp(strA, strB, 5));

    char strC[4] = {'w', 'h', 'a', 't'};
    char strD[4] = {'w', 'h', 'a', 't'};
    printf("strcmp result: %d.\n", (strcmp(strC, strD)));
    printf("strncmp result: %d.\n", (strncmp(strC, strD, 4)));
    // printf("address of \"is\": %x.", ptr);
    return 0;
}

// 字符串拼接
int Test_strncat_string_case0(void)
{
    char strA[10] = "HE\0LLO";
    char strB[20] = "wh\0ot";
    char *p = strncat(strB, strA, 10);
    printf("strncat result: %s.\n", p);
    printf("address p: %x; address strB: %x;\n", p, strB);

    return 0;
}

#endif // TEST_STRING_POINTERS_H
 