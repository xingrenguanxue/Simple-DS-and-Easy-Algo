/*
 * 冒泡排序
 */

#include <stdio.h>
#include "sort_need_function.h"


/* 冒泡排序 Version 1 
 * array : 数组
 * length : 数组长度
 */
void bubble_sort_v1(int *array, int length)
{
    int i, j;
    // 外层循环，控制轮数。每一轮排好一个元素
    for (i = 0; i < length; i++) {
        // 内层循环，循环比较数组中未排序的元素
        for (j = 0; j < length - i - 1; j++) {
            // 若前者大于后者则交换
            if (array[j] > array[j + 1]) {
                swap(array, j, j + 1);
            }
        }
    }
}

/* 冒泡排序 Version 2
 * 本质和 Version 1 相同
 * Version 1 从前向后比较
 * Version 2 从后向前比较
 */
void bubble_sort_v2(int *array, int length)
{
    int i, j;
    // 外层循环，控制轮数。每一轮排好一个元素
    for (i = 0; i < length; i++) {
        // 内层循环，循环比较数组中未排序的元素
        for (j = length - 2; j >= i; j--) {
             // 若前者大于后者则交换
            if (array[j] > array[j + 1]) {
                swap(array, j, j + 1);
            }
        }
    }
}


/* 冒泡排序 Version 3
 * 对 Version 1 的优化
 */
void bubble_sort_v3(int *array, int length)
{
    int i, j;
    int unsorted = 1; // 标识变量
    for (i = 0; i < length && unsorted; i++) {
        unsorted = 0;
        for (j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array, j, j + 1);
                unsorted = 1; // 发生交换，说明尚未有序
            }
        }
    }
}



int main()
{
    int array[10] = {80, 70, 10, 90, 40, 60, 50, 20, 100, 30};
    //int array[10] = {20, 10, 30, 40, 50, 60, 70, 80, 90, 100};
    printf("排序前：");
    output(array, 10);

    bubble_sort_v1(array, 10);
    //bubble_sort_v2(array, 10);
    //bubble_sort_v3(array, 10);

    printf("排序后：");
    output(array, 10);

    return 0;
}