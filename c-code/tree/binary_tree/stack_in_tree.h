/**
 * 此文件为头文件栈，供 binary_tree_link_travel_by_stack.c 使用，
 * 其中包括二叉树结点的结构体
 *        栈的结构体
 *        借助栈进行遍历二叉树时用到的必要操作
 */
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10 //栈的最大存储容量

/*二叉树的结点的结构体*/
typedef struct Node {
    char data; //数据域
    struct Node *left_child; //左孩子指针
    struct Node *right_child; //右孩子指针
} TreeNode;

/*栈的结构体*/
typedef struct {
    TreeNode *nodes[MAXSIZE]; //数组中存储二叉树的结点
    int top; //栈顶指针
} Stack;

/**
 * 初始化栈
 */
void init_stack(Stack *stack)
{
    for (int i = 0; i < MAXSIZE; i++) {
        stack->nodes[i] = NULL;
    }
    stack->top = -1;
}

/**
 * 是否为空栈，1为空栈
 */
int stack_is_empty(Stack *stack)
{
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

/**
 * 是否为满栈
 */
int stack_is_full(Stack *stack)
{
    if (stack->top == MAXSIZE - 1) {
        return 1;
    }
    return 0;
}

/**
 * 入栈操作，入的是指向二叉树结点的指针
 */
int push(Stack *stack, TreeNode *node)
{
    if (stack_is_full(stack)) {
        printf("栈满，不能再入\n");
        return 0;
    }
    stack->top++;
    stack->nodes[stack->top] = node;
    return 1;
}

/**
 * 出栈操作，出的是指向 指向二叉树结点的指针 的指针
 */
int pop(Stack *stack, TreeNode **node)
{
    if (stack_is_empty(stack)) {
        printf("空栈，无元素可出\n");
        return 0;
    }
    *node = stack->nodes[stack->top];
    stack->top--;
    return 1;
}

/**
 * 读取栈顶元素
 */
void get_top(Stack *stack, TreeNode **node)
{
    if (stack_is_empty(stack)) {
        printf("空栈，无栈顶元素\n");
        return;
    }
    *node = stack->nodes[stack->top];
}