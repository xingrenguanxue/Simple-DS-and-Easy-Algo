/*用数组实现的栈——顺序栈*/
#include <stdio.h>

#define MAXSIZE 5 //栈的最大存储容量

/*顺序栈的结构体*/
typedef struct {
    int data[MAXSIZE]; //存储数据的数组
    int top; //栈顶下标
} StackArray;

/**
 * 顺序栈的初始化：将栈的栈顶下标置为 -1
 * stack: 指向要操作的栈的指针
 */
void init(StackArray *stack)
{
    stack->top = -1;
}

/**
 * 入栈操作
 * stack: 指向要操作的栈的指针
 * elem: 要入栈的数据
 * return: 0失败，1成功
 */
int push(StackArray *stack, int elem)
{
    if (stack->top == MAXSIZE - 1) {
        printf("栈已满，无法继续入栈。\n");
        return 0;
    }
    stack->top++;
    stack->data[stack->top] = elem;
    return 1;
}

/**
 * 出栈操作
 * stack: 指向要操作的栈的指针
 * elem: 指向保存变量的指针
 * return: 0失败，1成功
 */
int pop(StackArray *stack, int *elem)
{
    if (stack->top == -1) {
        printf("栈空，无元素可出栈。\n");
        return 0;
    }
    *elem = stack->data[stack->top];
    stack->top--;
    return 1;
}

/**
 * 打印栈
 * stack: 要打印的栈
 */
void output(StackArray stack)
{
    if (stack.top == -1) {
        printf("空栈。\n");
        return;
    }
    for (int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.data[i]);
    }
    printf("\n");
}

int main()
{
    //声明一个栈 stack
    StackArray stack;
    //初始化
    init(&stack);

    output(stack);

    push(&stack, 1);
    output(stack);
    push(&stack, 2);
    output(stack);
    push(&stack, 3);
    output(stack);
    push(&stack, 4);
    output(stack);
    push(&stack, 5);
    output(stack);

    push(&stack, 6);

    int elem;

    pop(&stack, &elem);
    printf("pop elem = %d\n", elem);
    output(stack);

    pop(&stack, &elem);
    printf("pop elem = %d\n", elem);
    output(stack);

    pop(&stack, &elem);
    printf("pop elem = %d\n", elem);
    output(stack);
    pop(&stack, &elem);
    printf("pop elem = %d\n", elem);
    output(stack);

    pop(&stack, &elem);
    printf("pop elem = %d\n", elem);
    output(stack);
    
    pop(&stack, &elem);
    output(stack);

    return 0;
}