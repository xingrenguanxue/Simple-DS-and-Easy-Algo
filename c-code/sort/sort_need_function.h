/*
 * 排序时需要的几个通用函数
 */


/*交换数组 array 中下标为 i 和 j 的元素的值*/
void swap(int *array, int i, int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

/*打印数组*/
void output(int *array, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
