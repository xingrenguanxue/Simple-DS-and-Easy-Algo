/*用带头节点的单链表实现的链队列*/
#include<stdio.h>
#include<stdlib.h>

/*单链表的结点的结构体*/
typedef struct QueueNode {
    int data; //数据域
    struct QueueNode *next; //指针域
} QueueNode;

/*链队列的结构体*/
typedef struct {
    QueueNode *front; //队头指针
    QueueNode *rear; //队尾指针
} QueueLink;

/**
 * 创建链表结点
 * elem: 新结点的值
 * return: 指向新结点的指针
 */
QueueNode *create_node(int elem)
{
    QueueNode *new = (QueueNode *)malloc(sizeof(QueueNode));
    new->data = elem;
    new->next = NULL;
    return new;
}

/**
 * 初始化链队列：将队头指针和队尾指针指向头结点
 */
void init(QueueLink *queue)
{
    //创造头结点
    QueueNode *head_node = create_node(0);
    //队头指针 队尾指针指向头结点
    queue->front = head_node;
    queue->rear = head_node;
}

/**
 * 入队操作
 * queue: 指向队列的指针
 * elem: 入队的数据
 */
void en_queue(QueueLink *queue, int elem)
{
    //创造新结点
    QueueNode *new = create_node(elem);
    //入队（尾插法）
    queue->rear->next = new;
    queue->rear = new;
}

/**
 * 出队操作
 * queue: 指向队列的指针
 * elem: 指向保存变量的指针
 * return: 0失败，1成功
 */
int de_queue(QueueLink *queue, int *elem)
{
    //判读队列是否为空
    if (queue->front == queue->rear) {
        printf("队列空，无元素可出。\n");
        return 0;
    }
    QueueNode *front_node = queue->front->next; //队头元素
    //保存数据
    *elem = front_node->data;
    //队头元素出队（头删法）
    queue->front->next = front_node->next;
    //如果元素出完，队尾指针重新指向头结点
    if (front_node == queue->rear)
        queue->rear = queue->front;
    free(front_node);
}

/**
 * 打印队列
 */
void output(QueueLink *queue)
{
    //判读队列是否为空
    if (queue->front == queue->rear) {
        printf("队列空，无元素可打印。\n");
        return;
    }
    QueueNode *p = queue->front->next; //p指向队头元素
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    QueueLink queue;
    init(&queue);

    en_queue(&queue, 1);
    output(&queue);
    en_queue(&queue, 2);
    output(&queue);
    en_queue(&queue, 3);
    output(&queue);
    en_queue(&queue, 4);
    output(&queue);
    en_queue(&queue, 5);
    output(&queue);

    int elem = 0;

    de_queue(&queue, &elem);
    printf("%d出队\n", elem);
    output(&queue);
    de_queue(&queue, &elem);
    printf("%d出队\n", elem);
    output(&queue);
    de_queue(&queue, &elem);
    printf("%d出队\n", elem);
    output(&queue);
    de_queue(&queue, &elem);
    printf("%d出队\n", elem);
    output(&queue);
    de_queue(&queue, &elem);
    printf("%d出队\n", elem);
    output(&queue);

    en_queue(&queue, 1);
    output(&queue);
    en_queue(&queue, 2);
    output(&queue);
    return 0;
}