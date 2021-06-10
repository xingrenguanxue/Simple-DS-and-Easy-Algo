/*
 * 堆排序（最大堆）
 */
#include <stdio.h>
#include "sort_need_function.h"

/*
 * 堆调整
 * array: 数组
 * left right 为数组中的某两个左右下标
 * 该函数将数组中 left 至 right 之间的元素调整为大顶堆
 */
void heap_adjust(int *array, int left, int right)
{
    int parent = left; // 父结点下标
    int child = parent * 2 + 1; // 左孩子下标

    // left 有孩子
    while (child <= right) {
        if (child < right) {
            if (array[child] < array[child + 1]) {
                child = child + 1;
            }
        }
        if (array[child] > array[parent]) {
            swap(array, child, parent);
            parent = child;
            child = parent * 2 + 1;
        } else {
            break;
        }
    }
    
}

/* 堆排序 
 * array : 数组
 * length : 数组长度
 */
void heap_sort(int *array, int length)
{
    int i;
    for (i = (length - 2) / 2; i >= 0; i--) {
        heap_adjust(array, i, length - 1);
    }

    for (i = length - 1; i >= 0; i--) {
        swap(array, 0, i);
        heap_adjust(array, 0, i - 1);
    }
}

int main()
{
    int array[10] = {80, 70, 10, 90, 40, 60, 50, 20, 100, 30};
    printf("排序前：");
    output(array, 10);

    heap_sort(array, 10);

    printf("排序后：");
    output(array, 10);
    return 0;
}
