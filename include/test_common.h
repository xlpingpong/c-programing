/*** 
 * 文件包含 C 语言学习与编程练习时的基本宏、结构体、枚举值
 * 
***/
#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Basic macro
#define SUCCESS 0
#define FAIL 1
# define ROW_COL_NUM_2 2
# define ROW_COL_NUM_3 3
# define ROW_COL_NUM_4 4

// Basic enum
typedef enum RowColumIndex {
    ROWCOL_IND_0 = 0,
    ROWCOL_IND_1,
    ROWCOL_IND_2,
    ROWCOL_IND_3,
    ROWCOL_IND_4,
    ROWCOL_IND_5,
} RowColumIndex;

// Basic struct
typedef struct Point2D
{
    int x;
    int y;
} Point2D;

// data
#define TEST_DATA_DEFINITION_3_4  (int data[ROW_COL_NUM_3][ROW_COL_NUM_4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};)

#endif // TEST_COMMON_H
