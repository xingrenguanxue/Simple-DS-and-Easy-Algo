/*
 * 直接插入排序
 */
#include <stdio.h>
#include "sort_need_function.h"

/*
 * 直接插入排序
 * array : 数组
 * length : 数组长度 
 */
void straight_insertion_sort(int *array, int length)
{
    int i, j;
    // 外层循环 决定待插入值
    for (i = 1; i < length; i++) {
        if (array[i] < array[i - 1]) {
            int tmp = array[i]; // 待插入值
            // 内层循环 在有序区中为待插入值腾出位置
            for (j = i - 1; j >= 0 && array[j] > tmp; j--) {
                array[j + 1] = array[j];
            }
            array[j + 1] = tmp; // 插入
        }
    }
}

int main()
{
    int array[10] = {80, 70, 10, 90, 40, 60, 50, 20, 100, 30};
    printf("排序前：");
    output(array, 10);

    straight_insertion_sort(array, 10);

    printf("排序后：");
    output(array, 10);
    return 0;
}
