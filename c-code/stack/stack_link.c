/*用不带头结点的链表实现的栈——链栈*/
#include <stdio.h>
#include <stdlib.h>

/*链表结点的结构体*/
typedef struct StackNode {
    int data; //数据域
    struct StackNode *next; //指针域
} StackNode;

/*链栈的结构体*/
typedef struct {
    StackNode *top; //栈顶指针
    int length; //栈的长度
} StackLink;

/**
 * 初始化：将栈顶指针置为 NULL，长度置为 0
 * stack: 指向要操作的栈的指针
 */
void init(StackLink *stack)
{
    stack->top = NULL;
    stack->length = 0;
}

/**
 * 创建链表结点
 * elem: 新结点的值
 * return: 指向新结点的指针
 */
StackNode *create_node(int elem)
{
    StackNode *new = (StackNode *) malloc(sizeof(StackNode));
    new->data = elem;
    new->next = NULL;
    return new;
}

/**
 * 入栈操作: 本质是单链表的头插法
 * head: 头指针
 * elem: 要入栈的结点的值
 */
void push(StackLink *stack, int elem)
{
    StackNode *new = create_node(elem);
    // 链表的头插法
    new->next = stack->top;
    stack->top = new;
    //栈长度加一
    stack->length++;
}

/**
 * 出栈操作: 本质是单链表的头删法
 * stack: 指向要操作的栈的指针
 * elem: 指向保存变量的指针
 * return: 0失败，1成功
 */
int pop(StackLink *stack, int *elem)
{
    if (stack->length == 0) {
        printf("栈空，无元素可出栈。\n");
        return 0;
    }
    // top_node 指向栈顶结点
    StackNode *top_node = stack->top;
    //保存栈顶结点的值
    *elem = top_node->data;
    //栈顶指针下移
    stack->top = top_node->next;
    //释放 top_node
    free(top_node);
    stack->length--;
    return 1;
}

/**
 * 打印栈
 * stack: 要打印的栈
 */
void output(StackLink *stack)
{
    if (stack->length == 0) {
        printf("空栈。\n");
        return;
    }
    StackNode *p = stack->top;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    //初始化
    StackLink stack; //栈
    init(&stack);

    push(&stack, 1);
    output(&stack);
    push(&stack, 2);
    output(&stack);
    push(&stack, 3);
    output(&stack);
    push(&stack, 4);
    output(&stack);    
    push(&stack, 5);
    output(&stack);

    int elem;

    pop(&stack, &elem);
    printf("pop elem = %d\n", elem);
    output(&stack);
    pop(&stack, &elem);
    printf("pop elem = %d\n", elem);
    output(&stack);
    pop(&stack, &elem);
    printf("pop elem = %d\n", elem);
    output(&stack);
    pop(&stack, &elem);
    printf("pop elem = %d\n", elem);
    output(&stack);
    pop(&stack, &elem);
    printf("pop elem = %d\n", elem);
    output(&stack);
    pop(&stack, &elem);
    output(&stack);

    return 0;
}