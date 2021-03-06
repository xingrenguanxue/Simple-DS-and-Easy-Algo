/*不带头结点的单链表及其基本操作*/
#include <stdio.h>
#include <stdlib.h>
//结点
typedef struct Node {
    int data; //数据域：存储数据
    struct Node *next; //指针域：存储直接后继结点的地址
} Node;

/**
 * 创造结点，返回指向该结点的指针
 * elem : 结点的数据域的值
 * return : 指向该结点的指针（该结点的地址）
 */
Node *create_node(int elem)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = elem;
    node->next = NULL;
    return node;
}

/**
 * 头插法：新插入的节点始终被头指针所指向
 * p_head: 指向头指针的指针
 * elem: 新结点的数据
 */
void insert_at_head(Node **p_head, int elem)
{
    Node *new = create_node(elem);
    new->next = *p_head;
    *p_head = new;
}

/**
 * 尾插法：新插入的结点始终在链表尾
 * p_head: 指向头指针的指针
 * elem: 新结点的数据
 */
void insert_at_tail(Node **p_head, int elem)
{
    Node *new = create_node(elem);
    Node *p = *p_head;
    while (p->next != NULL)   //从头遍历至链表尾
        p = p->next;
    p->next = new;
}

/**
 * 获取链表结点数量
 */
int get_length(Node *head)
{
    int length = 0;
    Node *p = head;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

/**
 * 指定插入位置
 * p_head: 指向头指针的指针
 * position: 指定位置 (1 <= position <= length + 1)
 * elem: 新结点的数据
 */ 
void insert(Node **p_head, int position, int elem)
{
    Node *new = create_node(elem);
    Node *previous = NULL;
    Node *current = *p_head;
    int length = get_length(*p_head);
    if (position < 1 || position > length + 1) {
        printf("插入位置不合法\n");
        return;
    }
    for (int i = 0; current != NULL && i < position - 1; i++) {
        previous = current;
        current = current->next;
    }
    new->next = current;
    if (previous == NULL)
        *p_head = new;
    else
        previous->next = new;
}

/**
 * 删除指定位置的结点
 * p_head: 指向头指针的指针
 * position: 指定位置 (1 <= position <= length + 1)
 * elem: 使用该指针指向的变量接收删除的值
 */
void delete(Node **p_head, int position, int *elem)
{
    Node *previous = NULL;
    Node *current = *p_head;
    int length = get_length(*p_head);
    if (length == 0) {
        printf("空链表\n");
        return;
    }
    if (position < 1 || position > length) {
        printf("删除位置不合法\n");
        return;
    }
    for (int i = 0; current->next != NULL && i < position - 1; i++) {
        previous = current;
        current = current->next;
    }
    *elem = current->data;
    if (previous == NULL)
        *p_head = (*p_head)->next;
    else
        previous->next = current->next;
    free(current);
}

/**
 * 查找指定位置的结点值
 * head: 链表的头指针
 * position: 查找的位置
 * elem: 使用该指针指向的变量接收删除的值
 */
void get(Node *head, int position, int *elem)
{
    Node *p = head; //辅助指针
    if (get_length(head) == 0) {
        printf("空链表.\n");
        return;
    }
    if (position < 1 || position > get_length(head)) {
        printf("删除位置不合法\n");
        return;
    }
    for (int i = 0; i < position - 1; i++)
        p = p->next;
    *elem = p->data;
}

/**
 * 修改指定位置的结点值
 * p_head: 指向链表的头指针的指针
 * position: 修改的位置
 * elem: 修改的值
 */
void update(Node **p_head, int position, int elem)
{
    Node *p = *p_head;
    if (get_length(*p_head) == 0) {
        printf("空链表.\n");
        return;
    }
    if (position < 1 || position > get_length(*p_head)) {
        printf("删除位置不合法\n");
        return;
    }
    for (int i = 0; i < position - 1; i++)
        p = p->next;
    p->data = elem;
}

/**
 * 打印整个链表
 */
void output(Node *head)
{
    for (Node *p = head; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}


int main()
{
    //创建头指针
    Node *head = NULL;

    insert_at_head(&head, 1);
    insert_at_head(&head, 2);
    insert_at_head(&head, 3);
    insert_at_head(&head, 4);

    output(head);
    printf("length = %d\n", get_length(head));

    insert_at_tail(&head, 1);
    insert_at_tail(&head, 2);
    insert_at_tail(&head, 3);
    insert_at_tail(&head, 4);

    output(head);
    printf("length = %d\n", get_length(head));

    insert(&head, 1, 10);
    output(head);   

    insert(&head, 5, 100);
    output(head);   
    printf("length = %d\n", get_length(head));

    insert(&head, 11, 100);
    output(head);   
    printf("length = %d\n", get_length(head));

    int elem;
    delete(&head, 1, &elem);
    output(head);   
    printf("length = %d, elem = %d\n", get_length(head), elem);

    delete(&head, 5, &elem);
    output(head);   
    printf("length = %d, elem = %d\n", get_length(head), elem);

    delete(&head, 9, &elem);
    output(head);   
    printf("length = %d, elem = %d\n", get_length(head), elem);

    get(head, 1, &elem);
    printf("elem = %d\n", elem);

    get(head, 5, &elem);
    printf("elem = %d\n", elem);

    get(head, 8, &elem);
    printf("elem = %d\n", elem);

    update(&head, 1, 55);
    update(&head, 5, 55);
    update(&head, 8, 55);
    output(head);
    return 0;
}