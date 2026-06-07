#ifndef TEST_C_VESION_H
#define TEST_C_VESION_H

// gcc -std=c11 "D:\Programs\vscodeprograms\CProgram260405\c-programing\include\test.c" -o test.exe
// C23 特性测试：#embed 或 typeof
// #if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
//     #define STD_NAME "C23"
// #elif __STDC_VERSION__ >= 201710L
//     #define STD_NAME "C17"
// #elif __STDC_VERSION__ >= 201112L
//     #define STD_NAME "C11"
// #elif __STDC_VERSION__ >= 199901L
//     #define STD_NAME "C99"
// #else
//     #define STD_NAME "C89/C90"
// #endif

// int PrintCStandardInfo(void) {
//     printf("Current C standard: %s\n", STD_NAME);
//     printf("__STDC_VERSION__: %ld\n", (long)__STDC_VERSION__);
//     return 0;
// }


// // _Generic 用于
// #define TYPEOF(x) _Generic((x), \
//     int: "int", \
//     float: "float", \
//     double: "double", \
//     default: "unknown" \
// )

#endif // TEST_C_VESION_H
