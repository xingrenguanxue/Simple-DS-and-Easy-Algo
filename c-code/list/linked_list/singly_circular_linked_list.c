/*带头结点的单向循环链表*/
#include <stdio.h>
#include <stdlib.h>

/*单向循环链表的结点的结构体*/
typedef struct _Node {
    int data; //数据域：存储数据
    struct _Node *next; //指针域：存储直接后继结点的地址
} Node;

/**
 * 创造结点，返回指向该结点的指针
 * elem : 结点的数据域的值
 * return : 指向该结点的指针（该结点的地址）
 */
Node *create_node(int elem)
{
    Node *new = (Node *) malloc(sizeof(Node));
    new->data = elem;
    new->next = NULL;
    return new;
}

/**
 * 初始化链表
 * p_head: 指向头指针的指针
 */
void init(Node **p_head)
{
    //创建头结点
    Node *head_node = create_node(0);
    //头指针指向头结点
    *p_head = head_node;
    //头结点的next指针指向其本身，构成环
    head_node->next = head_node;
}

/**
 * 头插法，新结点为头结点的直接后继
 * p_head: 指向头指针的指针
 * elem: 新结点的数据
 */
void insert_at_head(Node **p_head, int elem)
{
    Node *new = create_node(elem);
    Node *head_node = *p_head; //头结点
    //新结点插入头结点之后
    new->next = head_node->next;
    head_node->next = new;
}

/**
 * 尾插法：新插入的结点始终在链表尾
 * p_head: 指向头指针的指针
 * elem: 新结点的数据
 */
void insert_at_tail(Node **p_head, int elem)
{
    Node *new = create_node(elem);
    Node *head_node = *p_head; //头结点
    Node *tail = head_node; //tail指针指向头结点
    while (tail->next != head_node) { //tail遍历至链表尾
        tail = tail->next;
    }
    //尾插
    new->next = tail->next;
    tail->next = new;
}

/**
 * 头删法：删除头结点之后的结点
 * p_head: 指向头指针的指针
 * elem: 指向保存数据变量的指针
 */
void delete_from_head(Node **p_head, int *elem)
{
    Node *head_node = *p_head; //头结点
    if (head_node->next == head_node) {
        printf("空链表，无元素可删。\n");
        return;
    }
    Node *first_node = head_node->next; //首结点：头结点的下一个结点
    *elem = first_node->data; //保存被删除结点的数据
    head_node->next = first_node->next; //删除结点
    free(first_node); //释放
}

/**
 * 尾删法：删除尾结点
 * p_head: 指向头指针的指针
 * elem: 指向保存数据变量的指针
 */
void delete_from_tail(Node **p_head, int *elem)
{
    Node *head_node = *p_head;
    Node *tail = head_node; //尾指针
    Node *prev = NULL; //始终指向 尾指针指向的结点 的直接前驱
    if (head_node->next == head_node) { //判空
        printf("空链表，无元素可删。\n");
        return;
    }
    while (tail->next != head_node) { //遍历尾指针至尾结点
        prev = tail;
        tail = tail->next;
    }
    *elem = tail->data; //保存数据
    prev->next = tail->next; //删除尾结点
    free(tail);
}

/**
 * 打印链表
 */
void output(Node *head)
{
    if (head->next == head) {
        printf("空链表。\n");
        return;
    }
    for (Node *p = head->next; p != head; p = p->next) {
        if (p != head) {
            printf("%d ", p->data);
        }
    }
    printf("\n");
}

/**
 * 循环打印20次结点
 */
void output_20(Node *head)
{
    if (head->next == head) {
        printf("空链表。\n");
        return;
    }
    Node *p = head->next;
    for (int i = 0; i <= 20; i++) {
        if (p != head) { //不打印头结点
            printf("%d ", p->data);
        }
        p = p->next;
    }
    printf("\n");
}


int main()
{
    //创建头指针并初始化链表
    Node *head = NULL;
    init(&head);
    output(head);

    insert_at_head(&head, 10);
    insert_at_head(&head, 20);
    insert_at_tail(&head, 1);
    insert_at_tail(&head, 2);
    // insert_at_head(&head, 30);
    // insert_at_tail(&head, 3);
    // insert_at_tail(&head, 4);
    // insert_at_tail(&head, 5);
    // insert_at_head(&head, 40);
    // insert_at_head(&head, 50);
    output(head);

    int elem = 0;

    delete_from_head(&head, &elem);
    printf("删除了%d\n", elem);
    output(head);
    delete_from_head(&head, &elem);
    printf("删除了%d\n", elem);
    output(head);
    delete_from_tail(&head, &elem);
    printf("删除了%d\n", elem);
    output(head);
    delete_from_tail(&head, &elem);
    printf("删除了%d\n", elem);
    output(head);
    delete_from_tail(&head, &elem);
    printf("删除了%d\n", elem);
    output(head);

    insert_at_head(&head, 100);
    output(head);

    return 0;
}