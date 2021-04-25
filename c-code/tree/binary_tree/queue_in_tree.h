/**
 * 此文件为队列的头文件，供 binary_tree_link_level_travel_by_queue.c 使用，
 * 其中包括二叉树结点的结构体
 *        队列的结构体
 *        借助队列进行层序遍历二叉树时用到的必要操作
 */
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5 //队列的最大存储容量

/*二叉树的结点的结构体*/
typedef struct Node {
    char data; //数据域
    struct Node *left_child; //左孩子指针
    struct Node *right_child; //右孩子指针
} TreeNode;

/*队列的结构体*/
typedef struct {
    TreeNode *nodes[MAXSIZE];
    int front; //队头下标
    int rear; //队尾下标
} Queue;

/**
 * 返回1，队列为空
 */
int queue_is_empty(Queue *queue)
{
    if (queue->front == queue->rear) {
        return 1;
    }
    return 0;
}

/**
 * 返回1，则队列满
 */
int queue_is_full(Queue *queue)
{
    if ((queue->rear + 1) % MAXSIZE == queue->front) {
        return 1;
    }
    return 0;
}

/**
 * 初始化队列
 */
void init_queue(Queue *queue)
{
    for (int i = 0; i < MAXSIZE; i++) {
        queue->nodes[i] = NULL;
    }
    queue->front = 0;
    queue->rear = 0;
}

/**
 * 树结点指针入队列
 */
int en_queue(Queue *queue, TreeNode *node)
{
    if (queue_is_full(queue)) {
        printf("队列满，无法继续入队列！\n");
        return 0;
    }
    queue->nodes[queue->rear] = node;
    queue->rear = (queue->rear + 1) % MAXSIZE;
    return 1;
}

/**
 * 树结点指针出队列
 * node: 指向 保存树结点指针的变量 的指针
 */
int de_queue(Queue *queue, TreeNode **node)
{
    if (queue_is_empty(queue)) {
        printf("队列空，无元素可出队列！\n");
        return 0;
    }
    *node = queue->nodes[queue->front];
    queue->front = (queue->front + 1) % MAXSIZE;
    return 1;
}