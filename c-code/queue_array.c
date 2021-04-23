/*用数组实现的队列——顺序队列*/
#include <stdio.h>

#define MAXSIZE 5 //顺序队列的最大存储容量，但只存4个元素

/*顺序队列的结构体*/
typedef struct {
    int data[MAXSIZE];
    int front; //队头下标
    int rear; //队尾下标
} QueueArray;

/**
 * 初始化顺序队列：将队头下标和队尾下标置为0
 * queue: 指向队列的指针
 */
void init(QueueArray *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

/**
 * 入队操作
 * queue: 指向队列的指针
 * elem: 入队的数据
 * return: 0失败，1成功
 */
int en_queue(QueueArray *queue, int elem)
{
    //判断队列是否已满
    if ((queue->rear + 1) % MAXSIZE == queue->front) {
        printf("队列已满，无法继续入队。\n");
        return 0;
    }
    //元素入队
    queue->data[queue->rear] = elem;
    //队尾下标加一
    queue->rear = (queue->rear + 1) % MAXSIZE;
    return 1;
}

/**
 * 出队操作
 * queue: 指向队列的指针
 * elem: 指向保存出队数据的变量
 * return: 0失败，1成功
 */
int de_queue(QueueArray *queue, int *elem)
{
    //判读队列是否为空
    if (queue->front == queue->rear) {
        printf("队列空，无元素可出。\n");
        return 0;
    }
    //元素出队
    *elem = queue->data[queue->front];
    //队头下标加一
    queue->front = (queue->front + 1) % MAXSIZE;
    return 1;
}

/**
 * 获取队列长度
 */
int get_length(QueueArray queue)
{
    return (queue.rear - queue.front + MAXSIZE) % MAXSIZE;
}

/**
 * 打印队列
 */
void output(QueueArray queue)
{
    //判读队列是否为空
    if (queue.front == queue.rear) {
        printf("队列空，无元素可打印。\n");
        return;
    }
    int i = queue.front;
    while (i % MAXSIZE != queue.rear) {
        printf("%d ", queue.data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

int main()
{
    QueueArray queue;
    init(&queue);

    printf("队列长度为：%d\n", get_length(queue));

    en_queue(&queue, 1);
    output(queue);
    en_queue(&queue, 2);
    output(queue);
    en_queue(&queue, 3);
    output(queue);
    en_queue(&queue, 4);
    output(queue);

    printf("队列长度为：%d\n", get_length(queue));

    en_queue(&queue, 5);


    int elem = 0;

    de_queue(&queue, &elem);
    printf("%d出队\n", elem);
    output(queue);
    de_queue(&queue, &elem);
    printf("%d出队\n", elem);
    output(queue);
    en_queue(&queue, 3);
    output(queue);
    en_queue(&queue, 4);
    output(queue);
    de_queue(&queue, &elem);
    printf("%d出队\n", elem);
    output(queue);
    de_queue(&queue, &elem);
    printf("%d出队\n", elem);
    output(queue);

    de_queue(&queue, &elem);
    printf("%d出队\n", elem);
    output(queue);
    en_queue(&queue, 3);
    output(queue);
    en_queue(&queue, 4);
    output(queue);
    return 0;
}