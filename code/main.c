/*** 
 * 主入口 main 函数
***/
#include <stdio.h>
#include "../include/test_c.h"
#include "../leetcode/codingsoltions.h"

/************
 * debug -exec x/4wx ptr
 ************/
int main()
{
    printf("Program start.\n\n");
    // 代码开始
    test_size_t();

    // 代码结束
    printf("\nProgram ends!\n");
    return 0;
}

 
/************
 * leetcode/codingsoltions.h
 * 临时存放
 ************/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// #define MAX_STR_LEN 100
// #define MAX_CHAR_NUM 26
// char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
//     unsigned int memSize = ((unsigned int) strsSize) * sizeof(int);
//     unsigned int *hashValue = (unsigned int *)malloc(memSize);
//     memset(hashValue, 0, memSize);

//     memSize = ((unsigned int) strsSize) * sizeof(int);
//     unsigned int *pValue = (unsigned int *)malloc(memSize);
//     memset(hashValue, 0, memSize);
//     int tempNumList[MAX_CHAR_NUM] = {0};

//     int k, j, m, id;
//     char *strTmp = NULL;
//     memSize = MAX_CHAR_NUM * sizeof(int);
//     for (k = 0; k < strsSize; k++) {
//         hashValue[k] = 0;
//         j = 0;

//         strTmp = strs[k];
//         memset(tempNumList, 0, memSize);
//         // printf("addr: %p", strs);
//         while(((j < MAX_STR_LEN) && strTmp[j] != '\0')) {
//             id = strTmp[j] - 'a';
//             tempNumList[id] += 1;
//             j++;
//         }
//         for (j = 0; j < MAX_CHAR_NUM; j++) {
//             hashValue[k] += (tempNumList[id] * (1 << (j + 1)));
//         }
//         m = 0;
//         while ((hashValue[k] != hashValue[m]) && (m < k)) {
//             m++;
//         }
//         pValue[m]++;
//     }
//     int diffNum = 0;
//     memSize = ((unsigned int) strsSize) * sizeof(int);
//     unsigned int *hashValue = (unsigned int *)malloc(memSize);
//     for (k = 0; k < strsSize; k++) {

//         diffNum += 1;
//     }
//     free(hashValue);
//     return NULL;
// }
