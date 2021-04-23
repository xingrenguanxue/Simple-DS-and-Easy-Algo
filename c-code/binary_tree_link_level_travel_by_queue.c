/*链式存储结构的二叉树，使用队列进行层序遍历*/
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
 * 创造二叉树的结点
 * elem: 结点数据域的值
 */
TreeNode *create_tree_node(char elem)
{
    TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
    new->data = elem;
    new->left_child = NULL;
    new->right_child = NULL;
    return new;
}

/**
 * 创造一个二叉树
 * root: 指向根结点的指针的指针
 */
void create_binary_tree(TreeNode **root)
{
    char elem;
    scanf("%c", &elem);
    if (elem == '#') {
        *root = NULL;
    } else {
        *root = create_tree_node(elem);
        create_binary_tree(&((*root)->left_child));
        create_binary_tree(&((*root)->right_child));
    }
}

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

/**
 * 使用队列实现层序遍历
 */
void levelorder_travelsal_by_queue(TreeNode *root)
{
    Queue queue;
    TreeNode *curr;
    init_queue(&queue); //初始化队列

    en_queue(&queue, root); //入队

    while (!queue_is_empty(&queue)) {
        de_queue(&queue, &curr); //出队
        printf("%c", curr->data);
        if (curr->left_child != NULL) { //如果左孩子不为空
            en_queue(&queue, curr->left_child); //左孩子入队
        }
        if (curr->right_child != NULL) { //如果右孩子不为空
            en_queue(&queue, curr->right_child); //右孩子入队
        }
    }
}

int main()
{
    /***********************************
    //测试队列的功能
    Queue queue;
    init_queue(&queue); //初始化
    en_queue(&queue, create_tree_node('A')); //入队
    TreeNode *node;
    de_queue(&queue, &node); //出队
    printf("dequeue: %c\n", node->data);
    ***********************************/

    TreeNode *root;
    create_binary_tree(&root); //ABD##E##C#F##
    printf("层序遍历顺序为：");
    levelorder_travelsal_by_queue(root);

    return 0;
}