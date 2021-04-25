/*带头节点的双向链表*/
#include<stdio.h>
#include<stdlib.h>

/*双向链表的结点结构体*/
typedef struct _Node {
    int data; //数据域
    struct _Node *prev; //指向直接前驱结点的指针
    struct _Node *next; //指向直接后继结点的指针
} Node;

/**
 * 创造结点，返回指向该结点的指针
 * elem : 结点的数据域的值
 * return : 指向该结点的指针（该结点的地址）
 */
Node *create_node(int elem)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = elem;
    new->prev = NULL;
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
    if (head_node->next != NULL) { //不为空链表
        Node *first_node = head_node->next; //首结点：头结点的下一个结点
        //首结点的prev指针指向new结点
        first_node->prev = new;
        //new结点的next指针指向首结点
        new->next = first_node;
    }
    //new结点的prev指针指向头结点
    new->prev = head_node;
    //头结点的next指针指向new结点
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
    Node *tail = *p_head; //头结点
    while (tail->next != NULL) //遍历到链表尾
        tail = tail->next;
    new->prev = tail;
    tail->next = new;
}

/**
 * 头删法
 * p_head: 指向头指针的指针
 * elem: 指向保存变量的指针
 */
void delete_from_head(Node **p_head, int *elem)
{
    Node *head_node = *p_head; //头结点
    Node *first_node = head_node->next; //待删除的首结点：头结点的下一个结点
    if (head_node->next == NULL) { //判空
        printf("空链表，无元素可删。\n");
        return;
    }
    *elem = first_node->data; //保存数据
    
    if (first_node->next != NULL) {
        first_node->next->prev = first_node->prev;
    }
    first_node->prev->next = first_node->next;
    free(first_node);
}

/**
 * 尾删法
 * p_head: 指向头指针的指针
 * elem: 指向保存变量的指针
 */
void delete_from_tail(Node **p_head, int *elem)
{
    Node *head_node = *p_head; //头结点
    Node *tail = head_node; //指针
    if (head_node->next == NULL) { //判空
        printf("空链表，无元素可删。\n");
        return;
    }
    while (tail->next != NULL) { //遍历到尾，获取尾结点
        tail = tail->next;
    }
    *elem = tail->data;
    tail->prev->next = tail->next; //删除尾结点
    free(tail);
}

/**
 * 从头开始打印
 */
void output_from_head(Node *head)
{
    if (head->next == NULL) {
        printf("空链表\n");
        return;
    }
    for (Node *p = head->next; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

/**
 * 从尾开始打印
 */
void output_from_tail(Node *head)
{
    if (head->next == NULL) {
        printf("空链表\n");
        return;
    }
    //先遍历到尾结点
    Node *tail = head->next;
    while (tail->next != NULL)
        tail = tail->next;
    Node *p = tail;
    //再从链表尾遍历至头结点
    while (p != head) {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    init(&head);
    output_from_head(head);
    output_from_tail(head);

    insert_at_head(&head, 1);
    insert_at_tail(&head, 10);
    insert_at_head(&head, 2);
    insert_at_tail(&head, 20);
    insert_at_head(&head, 3);
    insert_at_tail(&head, 30);
    insert_at_head(&head, 4);
    insert_at_tail(&head, 40);

    output_from_head(head);
    output_from_tail(head);

    int elem = 0;
    // delete_from_head(&head, &elem);
    delete_from_tail(&head, &elem);
    printf("删除了元素%d\n", elem);
    output_from_head(head);

    // delete_from_head(&head, &elem);
    delete_from_tail(&head, &elem);
    printf("删除了元素%d\n", elem);
    output_from_head(head);

    // delete_from_head(&head, &elem);
    delete_from_tail(&head, &elem);
    printf("删除了元素%d\n", elem);
    output_from_head(head);

    // delete_from_head(&head, &elem);
    delete_from_tail(&head, &elem);
    printf("删除了元素%d\n", elem);
    output_from_head(head);

    // delete_from_head(&head, &elem);
    delete_from_tail(&head, &elem);
    printf("删除了元素%d\n", elem);
    output_from_head(head);

    // delete_from_head(&head, &elem);
    delete_from_tail(&head, &elem);
    printf("删除了元素%d\n", elem);
    output_from_head(head);

    // delete_from_head(&head, &elem);
    delete_from_tail(&head, &elem);
    printf("删除了元素%d\n", elem);
    output_from_head(head);

    // delete_from_head(&head, &elem);
    delete_from_tail(&head, &elem);
    printf("删除了元素%d\n", elem);
    output_from_head(head);

    // delete_from_head(&head, &elem);
    delete_from_tail(&head, &elem);

    insert_at_head(&head, 100);
    output_from_head(head);

    return 0;
}