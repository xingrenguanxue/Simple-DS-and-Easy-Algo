/*二叉堆的创建、结点插入、结点删除*/
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
 * @description: 最小堆调整 针对某个非叶子结点进行到底的下沉调整
 *              最大堆调整(binary_max_heap.c/adjust_for_min_heap)借助 swap 函数实现，
 *              作为对比，该函数不使用，但二者本质相同。
 * @param {BinaryHeap} *heap 二叉堆（无序）
 * @param {int} parent_index 某个非叶子结点
 * @return {*} 无
 */
void adjust_for_min_heap(BinaryHeap *heap, int parent_index)
{
    // value 保存非叶子结点的值
    int value = heap->array[parent_index];
    // child_index 标识左孩子
    int child_index = parent_index * 2 + 1;
    // 最后一个结点的下标
    int last_child_index = heap->length - 1;

    // 双亲结点 parent 至少有一个孩子
    while (child_index <= last_child_index) {
        // 如果双亲结点 parent 有左孩子和右孩子
        if (child_index < last_child_index) {
            // 比较左孩子和右孩子谁小，如果右孩子小，
            if (heap->array[child_index] > heap->array[child_index + 1]) {
                // 则 child_index 标识右孩子
                child_index = child_index + 1;
            }
        }
        // 如果双亲的值大于 child 的值
        if (value > heap->array[child_index]) {
            heap->array[parent_index] = heap->array[child_index]; // 小节点上浮
            parent_index = child_index; // 更新双亲下标
            child_index = parent_index * 2 + 1; // 更新孩子下标
        } else { // 不做操作，跳出循环
            break;
        }
        // 大节点下沉
        heap->array[parent_index] = value;
    }
}

/**
 * @description: 构造最小堆
 * @param {BinaryHeap} *heap 二叉堆（无序）
 * @return {*} 无
 */
void create_min_heap(BinaryHeap *heap)
{
    // 每个非叶子结点都调整
    for (int i = (heap->length - 2) / 2; i >= 0; i--) {
        adjust_for_min_heap(heap, i);
    }
}

/**
 * @description: 向最小堆中插入一个元素
 * @param {BinaryHeap} *heap 最小堆指针
 * @param {int} elem 新元素
 * @return {*} 无
 */
void insert_into_min_heap(BinaryHeap *heap, int elem)
{
    if (heap->length == MAXSIZE) {
        printf("二叉堆已满，无法插入。\n");
        return;
    }
    heap->array[heap->length] = elem;  // 插入
    heap->length++; // 更新长度
    create_min_heap(heap); // 重新构造
}



/**
 * @description: 删除最小堆的堆顶
 * @param {BinaryHeap} *heap 最小堆指针
 * @param {int} *elem 保存变量指针
 * @return {*} 无
 */
void delete_from_min_heap(BinaryHeap *heap, int *elem)
{
    if (heap->length == 0) {
        printf("二叉堆空，无元素可删。\n");
        return;
    }
    *elem = heap->array[0];
    heap->array[0] = heap->array[heap->length - 1]; // 移动到堆顶
    heap->length--; // 更新长度
    create_min_heap(heap); //重新构造
}



/**
 * @description: 打印二叉堆
 * @param {BinaryHeap} heap 二叉堆
 * @return {*} 无
 */
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

    printf("原完全二叉树（未调整）：\n");
    output_heap(heap);

    create_min_heap(&heap);

    printf("调整得到最小堆：\n");
    output_heap(heap);

    insert_into_min_heap(&heap, 0);

    printf("插入元素后，调整得到最小堆：\n");
    output_heap(heap);

    int elem;
    delete_from_min_heap(&heap, &elem);
    printf("delete elem = %d from min heap\n", elem);
    printf("删除堆顶后，调整得到最小堆：\n");
    output_heap(heap);
    
    return 0;
}