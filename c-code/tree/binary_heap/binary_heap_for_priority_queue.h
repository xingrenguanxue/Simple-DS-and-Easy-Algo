/*
 * 二叉堆的相关操作
 * 为了不使优先队列的代码显得繁琐，特抽取成头文件，供 priority_queue.c 使用
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 5

// 二叉堆的结构体，即为优先队列的结构体
typedef struct {
    int array[MAXSIZE];
    int length;
} BinaryHeap, PriorityQueue;

void adjust_for_max_heap(BinaryHeap *heap, int parent_index)
{
    int value = heap->array[parent_index];
    int child_index = parent_index * 2 + 1;
    int last_child_index = heap->length - 1;
    while (child_index <= last_child_index) {
        if (child_index < last_child_index) {
            if (heap->array[child_index] < heap->array[child_index + 1]) {
                child_index = child_index + 1;
            }
        }
        if (value < heap->array[child_index]) {
            heap->array[parent_index] = heap->array[child_index];
            parent_index = child_index;
            child_index = parent_index * 2 + 1;
        } else {
            break;
        }
        heap->array[parent_index] = value;
    }
}


void create_max_heap(BinaryHeap *heap)
{
    for (int i = (heap->length - 2) / 2; i >= 0; i--) {
        adjust_for_max_heap(heap, i);
    }
}


void adjust_for_min_heap(BinaryHeap *heap, int parent_index)
{
    int value = heap->array[parent_index];
    int child_index = parent_index * 2 + 1;
    int last_child_index = heap->length - 1;

    while (child_index <= last_child_index) {
        if (child_index < last_child_index) {
            if (heap->array[child_index] > heap->array[child_index + 1]) {
                child_index = child_index + 1;
            }
        }
        if (value > heap->array[child_index]) {
            heap->array[parent_index] = heap->array[child_index];
            parent_index = child_index;
            child_index = parent_index * 2 + 1;
        } else {
            break;
        }
        heap->array[parent_index] = value;
    }
}

void create_min_heap(BinaryHeap *heap)
{
    for (int i = (heap->length - 2) / 2; i >= 0; i--) {
        adjust_for_min_heap(heap, i);
    }
}

void insert_into_min_heap(BinaryHeap *heap, int elem)
{
    if (heap->length == MAXSIZE) {
        printf("二叉堆已满，无法插入。\n");
        return;
    }
    heap->array[heap->length] = elem;
    heap->length++;
    create_min_heap(heap);
}


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

void delete_from_min_heap(BinaryHeap *heap, int *elem)
{
    if (heap->length == 0) {
        printf("二叉堆空，无元素可删。\n");
        return;
    }
    *elem = heap->array[0];
    heap->array[0] = heap->array[heap->length - 1];
    heap->length--;
    create_min_heap(heap);
}

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
