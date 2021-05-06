/*优先队列的实现*/
#include <stdio.h>
#include <stdlib.h>
#include "binary_heap_for_priority_queue.h"

/**
 * @description: 初始化优先队列，即置队列长度为 0
 * @param {PriorityQueue} *queue 队列指针
 * @return {*} 无
 */
void init_queue(PriorityQueue *queue)
{
    queue->length = 0;
}

/**
 * @description: 最大优先队列入队
 * @param {PriorityQueue} *queue 队列指针
 * @param {int} elem 入队元素
 * @return {*} 无
 */
void en_max_queue(PriorityQueue *queue, int elem)
{
    insert_into_max_heap(queue, elem);
}

/**
 * @description: 最大优先队列出队
 * @param {PriorityQueue} *queue 队列指针
 * @param {int} *elem 保存变量指针
 * @return {*} 无
 */
void de_max_queue(PriorityQueue *queue, int *elem)
{
    delete_from_max_heap(queue, elem);
}

/**
 * @description: 最小优先队列入队
 * @param {PriorityQueue} *queue 队列指针
 * @param {int} elem 入队元素
 * @return {*} 无
 */
void en_min_queue(PriorityQueue *queue, int elem)
{
    insert_into_min_heap(queue, elem);
}

/**
 * @description: 最小优先队列出队
 * @param {PriorityQueue} *queue 队列指针
 * @param {int} *elem 保存变量指针
 * @return {*} 无
 */
void de_min_queue(PriorityQueue *queue, int *elem)
{
    delete_from_min_heap(queue, elem);
}

void output(PriorityQueue queue)
{
    if (queue.length == 0) {
        printf("为空。\n");
        return;
    }
    for (int i = 0; i < queue.length; i++) {
        printf("%d ", queue.array[i]);
    }
    printf("\n");
}

int main()
{
    printf("***********测试最大优先队列***********\n");
    PriorityQueue max_queue;
    init_queue(&max_queue);

    printf("1 入队。\n");
    en_max_queue(&max_queue, 1);
    printf("4 入队。\n");
    en_max_queue(&max_queue, 4);
    printf("3 入队。\n");
    en_max_queue(&max_queue, 3);
    printf("5 入队。\n");
    en_max_queue(&max_queue, 5);
    printf("2 入队。\n");
    en_max_queue(&max_queue, 2);

    int elem;

    de_max_queue(&max_queue, &elem);
    printf("%d 出队。\n", elem);
    de_max_queue(&max_queue, &elem);
    printf("%d 出队。\n", elem);
    de_max_queue(&max_queue, &elem);
    printf("%d 出队。\n", elem);
    de_max_queue(&max_queue, &elem);
    printf("%d 出队。\n", elem);
    de_max_queue(&max_queue, &elem);
    printf("%d 出队。\n", elem);

    printf("***********测试最小优先队列***********\n");

    PriorityQueue min_queue;
    init_queue(&min_queue);

    printf("1 入队。\n");
    en_min_queue(&max_queue, 1);
    printf("4 入队。\n");
    en_min_queue(&max_queue, 4);
    printf("3 入队。\n");
    en_min_queue(&max_queue, 3);
    printf("5 入队。\n");
    en_min_queue(&max_queue, 5);
    printf("2 入队。\n");
    en_min_queue(&max_queue, 2);

    de_min_queue(&max_queue, &elem);
    printf("%d 出队。\n", elem);
    de_min_queue(&max_queue, &elem);
    printf("%d 出队。\n", elem);
    de_min_queue(&max_queue, &elem);
    printf("%d 出队。\n", elem);
    de_min_queue(&max_queue, &elem);
    printf("%d 出队。\n", elem);
    de_min_queue(&max_queue, &elem);
    printf("%d 出队。\n", elem);

    return 0;
}
