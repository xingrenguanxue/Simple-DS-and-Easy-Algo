/*
 * 顺序查找
 */
#include <stdio.h>

/**
 * @description: 从头到尾遍历整个数组，查找目标值 key，返回其下标 index        
 * @param {int} *array 数组 为了说明问题简单，这里的数组元素不重复
 * @param {int} length 数组长度
 * @param {int} key 目标值，和关键字比较
 * @return {int} 如果找到，返回目标值下标；否则返回 -1
 */
int sequential_search(int *array, int length, int key)
{
    for (int index = 0; index < length; index++) {
        if (array[index] == key) {
            return index;
        }
    }
    return -1;
}

/**
 * @description: 顺序查找改进，增加哨兵
 * @param {int} *array array[0] 不存放数据元素，充当哨兵
 * @param {int} length 数组长度
 * @param {int} key 目标值
 * @return {int} 返回0，即哨兵下标，则查找失败；否则成功
 */
int sequential_search_pro(int *array, int length, int key)
{
    array[0] = key; // 哨兵
    int index = length - 1;
    while (array[index] != key) {
        index--;
    }
    return index;
}

int main()
{
    int array[10] = {11, 8, 4, 6, 9, 1, 16, 22, 14, 10};
    int index;
    index = sequential_search(array, 10, 1);
    printf("index = %d\n", index);

    index = sequential_search(array, 10, 0);
    printf("index = %d\n", index);

    int arr[11] = {-1, 11, 8, 4, 6, 9, 1, 16, 22, 14, 10};

    index = sequential_search_pro(arr, 10, 16);
    printf("index = %d\n", index);

    index = sequential_search_pro(arr, 10, 33);
    printf("index = %d\n", index);

    return 0;
}
