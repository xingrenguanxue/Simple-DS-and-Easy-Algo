/*
 * 二叉最大堆
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 20 // 数组的最大存储空间

/*二叉堆的结构体*/
typedef struct {
    int array[MAXSIZE]; // 存储数组
    int length; // 当前堆长度（结点数）
} BinaryHeap;

/**
 * @description: 初始化二叉堆
 * @param {BinaryHeap} *heap 二叉堆
 * @param {int} *array 数组首地址，该数组是一个无序完全二叉树
 * @param {int} arr_length 数组长度。若初始化空堆，则长度设 0 即可，数组内容随意
 * @return {*} 无
 */
void init_heap(BinaryHeap *heap, int *array, int arr_length)
{
    // array 拷贝到 heap 中
    memcpy(heap->array, array, arr_length * sizeof(int));
    // 设置堆长度
    heap->length = arr_length;
}

/*交换指针i j 指向的变量值*/
void swap(int *i, int *j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

/**
 * @description: 最大堆调整，调整某个非叶子结点，即下标为 parent_index 的结点（借助swap函数实现交换）
 * @param {BinaryHeap} *heap 待调整的二叉堆
 * @param {int} parent_index 待调整的非叶子结点
 * @return {*} 无
 */
void adjust_for_max_heap(BinaryHeap *heap, int parent_index)
{
    // value 保存非叶子结点 parent 的值
    int value = heap->array[parent_index];
    // 双亲结点 parent 的左孩子下标
    int child_index = parent_index * 2 + 1;

    int last_child_index = heap->length - 1;

    // 双亲结点 parent 有孩子
    while (child_index <= last_child_index) {
        // 如果双亲结点 parent 有左孩子和右孩子
        if (child_index < last_child_index) {

            if (heap->array[child_index] < heap->array[child_index + 1]) {
                child_index = child_index + 1;
            }
        }
        // 双亲值小于孩子值
        if (heap->array[parent_index] < heap->array[child_index]) {
            // 交换二者，实现大值结点上浮
            swap(&heap->array[parent_index], &heap->array[child_index]);
            // 更新双亲及孩子下标，待下一次比较交换
            parent_index = child_index;
            child_index = parent_index * 2 + 1;
        } else {
            break;
        }
    }
}


/**
 * @description: 创造一个最大堆
 * @param {BinaryHeap} *heap 待调整的二叉堆
 * @return {*} 无
 */
void create_max_heap(BinaryHeap *heap)
{
    // 从最后一个非叶子结点开始，调整所有非叶子结点
    for (int i = (heap->length - 2) / 2; i >= 0; i--) {
        adjust_for_max_heap(heap, i);
    }
}

/**
 * @description: 向最大堆中插入一个元素
 * @param {BinaryHeap} *heap 最大堆指针
 * @param {int} elem 新元素
 * @return {*} 无
 */
void insert_into_max_heap(BinaryHeap *heap, int elem)
{
    if (heap->length == MAXSIZE) {
        printf("二叉堆已满，无法插入。\n");
        return;
    }
    heap->array[heap->length] = elem;
    heap->length++;
    create_max_heap(heap);
}

/**
 * @description: 删除最大堆的堆顶
 * @param {BinaryHeap} *heap 最大堆指针
 * @param {int} *elem 保存变量指针
 * @return {*} 无
 */
void delete_from_max_heap(BinaryHeap *heap, int *elem)
{
    if (heap->length == 0) {
        printf("二叉堆空，无元素可删。\n");
        return;
    }
    *elem = heap->array[0];
    heap->array[0] = heap->array[heap->length - 1];
    heap->length--;
    create_max_heap(heap);
}

void output_heap(BinaryHeap heap)
{
    if (heap.length == 0) {
        printf("二叉堆空，无元素可打印。\n");
        return;
    }
    for (int i = 0; i < heap.length; i++) {
        printf("%d ", heap.array[i]);
    }
    printf("\n");
}

int main()
{
    int array[10] = {2, 4, 6, 3, 7, 5, 8, 9, 1, 10};
    
    BinaryHeap heap;

    init_heap(&heap, array, 10);

    //init_heap(&heap, array, 0); // 若设置空堆，长度置 0 即可，数组内容随意

    printf("原完全二叉树（未调整）：\n");
    output_heap(heap);

    create_max_heap(&heap);

    printf("调整得到最大堆：\n");
    output_heap(heap);

    insert_into_max_heap(&heap, 11);

    printf("插入元素后，调整得到最大堆：\n");
    output_heap(heap);

    int elem;
    delete_from_max_heap(&heap, &elem);
    printf("delete elem = %d from max heap\n", elem);
    printf("删除堆顶后，调整得到最大堆：\n");
    output_heap(heap);

    return 0;
}