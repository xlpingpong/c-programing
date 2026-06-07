/************
C programing learning and practice.
put test code (function definition) in *.c file,
and their declaration here.
 ************/
#ifndef TEST_C_H
#define TEST_C_H

#include "test_common.h"
#include "test_basic_datatype.h"

/************
array and pointer.
 ************/
// test functions
int Test2DArrayAndPointer_case0(void);
int Test2DArrayAndPointer_case1(void);


// TODO: muti-file link
/************
1. 访问二维数组使用行指针，且指针的数据列数要对应。
2. 如有特殊需要，可以使用强制类型转换改变列数，注意内存访问越界！
3. 行指针在内存上占用空间和普通指针相同，列数仅声明内存排布方式。
 ************/
int Test2DArrayAndPointer_case0(void)
{
    int r = 1;
    int c = 2;
    int data[ROW_COL_NUM_3][ROW_COL_NUM_4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    int (*p)[ROW_COL_NUM_4] = data;
    int (*q)[ROW_COL_NUM_3] = NULL;
    q = (int (*)[ROW_COL_NUM_3])(data); // 强制类型转换，注意内存越界

    printf("output by array is: %d,\n", data[r][c]);
    printf("size of data is: %d.\n\n", sizeof(data));
    printf("output by pointer p is: %d.\n", p[r][c]);
    printf("size of pointer p is: %d.\n\n", sizeof(p));
    printf("output by pointer q is: %d.\n", q[r][c]);
    printf("size of pointer q is: %d.\n\n", sizeof(q));
    return 0;
}

// 申请动态内存的方式保存二维数组
int Test2DArrayAndPointer_case1(void)
{
    int r = 1;
    int c = 2;
    const int data_size = sizeof(int) * ROW_COL_NUM_3 * ROW_COL_NUM_4;
    void *p = (void * )malloc(data_size);

    int ( *data)[ROW_COL_NUM_4] = (int (*)[ROW_COL_NUM_4]) p;
    printf("output by pointer data is: %d.\n", data[r][c]);
    printf("size of pointer data is: %d.\n\n", sizeof(data));

    memset(p, 0, data_size);
    printf("output by pointer data is: %d.\n", data[r][c]);
    printf("size of pointer data is: %d.\n\n", sizeof(data));

    free(p);
    p = NULL;
    data = NULL;
    return 0;
}

// 行指针做形参
int TestRead2DArray(int(*p)[ROW_COL_NUM_4], unsigned r, unsigned c)
{
    return p[r][c];
}
int Test2DArrayAndPointer_case2(void)
{
    int r = 1;
    int c = 2;
    int data[ROW_COL_NUM_3][ROW_COL_NUM_4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    int (*p)[ROW_COL_NUM_4] = data;
    printf("output by pointer data is: %d.\n", TestRead2DArray(p, r, c));
    return 0;
}

// 自定义结构体行指针
int Test2DPointAndPointer_case0(void)
{
    int r = 1;
    int c = 2;
    Point2D data[ROW_COL_NUM_2][ROW_COL_NUM_3] = {{{1, 2}, {3, 4}, {5, 6}}, {{7, 8}, {9, 10}, {11, 12}}};

    Point2D (*p)[ROW_COL_NUM_3] = (Point2D (*)[ROW_COL_NUM_3])data;
    printf("output by pointer p is: %d.\n", p[r][c]);
    printf("output by pointer p is: %d, %d.\n\n", p[r][c].x, p[r][c].y);

    // 报错：
    // Point2D *(*q)[ROW_COL_NUM_3] = &(Point2D (*)[ROW_COL_NUM_3])data;  // 报错

    // 报错： data 是指向 Point2D 类型的（行）指针，但是 q 解读为指向指针的数组
    // (Point2D *(*)[ROW_COL_NUM_3])data 也是错的，因为 data 指向的内存是按 Point2D 排布的，不是指针
    // Point2D *(*q)[ROW_COL_NUM_3] = (Point2D *(*)[ROW_COL_NUM_3])data;
    // printf("output by pointer p is: %d, %d.\n", q[0][0]->x, q[0][0]->y);

    Point2D *dataAddr[ROW_COL_NUM_2][ROW_COL_NUM_3] = {0};
    Point2D *(*q)[ROW_COL_NUM_3] = (Point2D *(*)[ROW_COL_NUM_3])dataAddr;
    for (int j = 0; j < ROW_COL_NUM_2; j++) {
        for (int k = 0; k < ROW_COL_NUM_3; k++) {
            q[j][k] = &data[j][k]; // q or dataAddr
        }
    }
    printf("output by pointer dataAddr is: %d, %d.\n\n", dataAddr[1][1]->x, dataAddr[1][1]->y);
    printf("size of data is: %d.\n", sizeof(data));
    printf("size of pointer dataAddr is: %d.\n\n", sizeof(dataAddr));
    printf("size of pointer p is: %d.\n", sizeof(p));
    printf("size of pointer q is: %d.\n\n", sizeof(q));
    return 0;
}


// 变量所占的内存大小
int TestVariableSize_case0(void)
{
    printf("size of Point2D is: %d.\n", sizeof(Point2D)); // 8 byte
    printf("size of int is: %d.\n", sizeof(int)); // 4
    printf("size of pointer Point2D* is: %d.\n", sizeof(Point2D *)); // 8
    return 0;
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
int Test_strncpy_case0(void)
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
int Test_stringArray_case0(void)
{
    char strA[][6] = {"what", "is", "your", "name"};
    // char* strB[] = {"what", "is", "your", "name"};
    char ptr[] = "is";
    printf("address of \"is\": %x.", ptr);
    // printf("address of \"is\": %x.", ptr);
    return 0;
}

// 字符串比较
int Test_strcmp_case0(void)
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

#endif // TEST_C_H
