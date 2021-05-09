/*
 * 二分查找
 * 求 mid 时有溢出风险，可改为 mid = left + (right - left) / 2
 * 这里为了说明问题简单起见，使用最简单原始的考虑：mid = (left + right) / 2
 */
#include <stdio.h>

/**
 * @description: 二分查找
 * @param {int} *array 有序数组
 * @param {int} length 数组长度
 * @param {int} key 目标值，和关键字比较
 * @return {int} 返回目标值下标；若查找失败，则返回 -1
 */
int binary_search(int *array, int length, int key)
{
    int left, mid, right;
    left = 0;
    right = length - 1;
    while (left <= right) {
        
        mid = (left + right) / 2; // 中间下标
        if (key < array[mid]) { // key 比中间值小
            right = mid - 1; // 更新最右下标，进入左半区
        } else if (key > array[mid]) { // key 比中间值大
            left = mid + 1; // 更新最左下标，进入右半区
        } else {
            return mid; // key 等于中间值，返回其下标
        }
    }
    return -1; //未找到，返回 -1
}

int main()
{
    int array[11] = {5, 9, 14, 16, 22, 28, 30, 33, 39, 42, 45};

    int index = binary_search(array, 11, 33);
    printf("index = %d\n", index);

    return 0;
}