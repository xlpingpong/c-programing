/************
C programing learning and practice.
put test code (function definition) in *.c file,
and their declaration here.
 ************/
#ifndef TEST_C_H
#define TEST_C_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Basic macro
#define SUCCESS 0
#define FAIL 1

// Basic enum
typedef enum RowColumIndex {
    ROW_COL_NUM_0 = 0,
    ROW_COL_NUM_1,
    ROW_COL_NUM_2,
    ROW_COL_NUM_3,
    ROW_COL_NUM_4,
    ROW_COL_NUM_5,
} RowColumIndex;


// Basic struct
typedef struct Point2D
{
    int x;
    int y;
} Point2D;

// data
#define TEST_DATA_3_4  (int data[ROW_COL_NUM_3][ROW_COL_NUM_4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};)

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
#endif // TEST_C_H
