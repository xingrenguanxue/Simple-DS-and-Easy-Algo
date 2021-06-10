/*
 * 暴力排序
 */

#include <stdio.h>
#include "sort_need_function.h"


/* 暴力排序
 * array : 数组
 * length : 数组长度
 */
void violent_sort(int *array, int length)
{
    int i, j;
    // 外层循环，遍历数组，控制轮数
    for (i = 0; i < length; i++) {
        // 内层循环，循环比较 array[i] 和其之后的元素，控制循环次数
        for (j = i + 1; j < length; j++) {
            if (array[i] > array[j]) { // 如果大于则交换
                swap(array, i, j);
            }
        }
    }
}

int main()
{
    int array[10] = {80, 70, 10, 90, 40, 60, 50, 20, 100, 30};
    printf("排序前：");
    output(array, 10);

    violent_sort(array, 10);

    printf("排序前：");
    output(array, 10);

    return 0;
}
