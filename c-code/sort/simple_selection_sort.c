/*
 * 简单选择排序
 */
#include <stdio.h>
#include "sort_need_function.h"

/*
 * 简单选择排序
 * array : 数组
 * length : 数组长度 
 */
void simple_selection_sort(int *array, int length)
{
    int i, j, min;
    for (int i = 0; i < length - 1; i++) {
        min = i; // 最小元素初始化为基准元素
        // 找最小元素
        for (int j = i + 1; j < length; j++) {
            if (array[min] > array[j]) {
                min = j;
            }
        }
        // 在基准元素之后的元素中找到了比基准元素小的值
        if (i != min) {
            swap(array, i, min); // 交换
        }
    }
}

int main()
{
    int array[10] = {80, 70, 10, 90, 40, 60, 50, 20, 100, 30};
    printf("排序前：");
    output(array, 10);

    simple_selection_sort(array, 10);

    printf("排序后：");
    output(array, 10);

    return 0;
}
