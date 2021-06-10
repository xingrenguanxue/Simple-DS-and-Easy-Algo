/*
 * 希尔排序
 */

#include <stdio.h>
#include "sort_need_function.h"

/* 希尔排序 
 * array : 数组
 * length : 数组长度
 */
void shell_sort(int *array, int length)
{
    int i, j, tmp;
    int k = length; // 增量 k，本例取4、2、1
    // 当增量 k 大于等于 1 时，排序
    do {
        k = k / 3 + 1; // 更新增量
        //按增量将元素分为若干组
        for (i = k; i <= length; i++) {
            if (array[i] < array[i - k]) {
                tmp = array[i];
                for (j = i - k; j >= 0 && tmp < array[j]; j = j - k) {
                    array[j + k] = array[j];
                }
                array[j + k] = tmp;
            }
        }
    } while (k > 1);
}

int main()
{
    int array[10] = {80, 70, 10, 90, 40, 60, 50, 20, 100, 30};
    printf("排序前：");
    output(array, 10);

    shell_sort(array, 10);

    printf("排序后：");
    output(array, 10);
    return 0;
}
