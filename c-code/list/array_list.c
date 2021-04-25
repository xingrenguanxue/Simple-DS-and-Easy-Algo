/*用数组实现的顺序存储方式的线性表，及对其进行的增删改查等操作*/

#include <stdio.h>

#define MAXSIZE 10 //线性表的最大存储容量

typedef struct {
    int data[MAXSIZE]; //存储数据的数组
    int length; //线性表的长度
} ArrayList;

/**
 * 初始化线性表，将线性表的长度置为0
 * list : 要操作的线性表的地址
 */
void init(ArrayList *list)
{
    list->length = 0;
}

/**
 * 向线性表的指定位置插入指定值
 * list : 要操作的线性表的地址
 * position : 要插入的位置 (1 <= position <= list->length + 1)
 * elem : 要插入的值
 * return 0 : 插入失败；return 1 : 插入成功
 */
int insert(ArrayList *list, int position, int elem)
{
    if (list->length == MAXSIZE) {
        printf("线性表已满\n");
        return 0;
    }
    if (position < 1 || position > list->length + 1) {
        printf("插入位置不合法\n");
        return 0;
    }
    for (int i = list->length - 1; i >= position - 1; i--) {
        list->data[i + 1] = list->data[i];//向后赋值
    }
    list->data[position - 1] = elem;
    list->length++;
    return 1;
}

/**
 * 删除指定位置的元素，并保存其值
 * list : 要操作的线性表的地址
 * position : 要删除的元素位置
 * elem : 保存变量的地址
 * return 0 : 删除失败；return 1 : 删除成功
 */
int delete(ArrayList *list, int position, int *elem)
{
    if (list->length == 0) {
        printf("线性表为空\n");
        return 0;
    }
    if (position < 1 || position > list->length) {
        printf("删除位置不合法\n");
        return 0;
    }
    *elem = list->data[position - 1];
    for (int i = position - 1; i < list->length - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->length--;
    return 1;
}

/**
 * 查询指定位置的元素
 * list : 要操作的线性表
 * position : 要查询的元素位置
 * elem : 保存变量的地址
 * return 0 : 查询失败；return 1 : 查询成功
 */
int get(ArrayList list, int position, int *elem)
{
    if (list.length == 0) {
        printf("线性表为空\n");
        return 0;
    }
    if (position < 1 || position > list.length) {
        printf("位置不合法\n");
        return 0;
    }
    *elem = list.data[position - 1];
    return 1;
}

/**
 * 更新指定位置的元素
 * list : 要操作的线性表的地址
 * position : 要更新的元素位置
 * elem : 要更新的值
 * return 0 : 更新失败；return 1 : 更新成功
 */
int update(ArrayList *list, int position, int elem)
{
    if (list->length == 0) {
        printf("线性表为空\n");
        return 0;
    }
    if (position < 1 || position > list->length) {
        printf("位置不合法\n");
        return 0;
    }
    list->data[position - 1] = elem;
    return 1;
}

/*打印线性表*/
void output(ArrayList list)
{
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");
}

int main()
{
    //声明一个线性表
    ArrayList list;
    //将其初始化为空线性表
    init(&list);
    
    /*----测试---*/
    insert(&list, 1, 1);
    output(list);
    insert(&list, 2, 2);
    output(list);
    insert(&list, 3, 3);
    output(list);
    insert(&list, 4, 4);
    output(list);

    int value;

    get(list, 2, &value);
    printf("查询了 %d\n", value);

    update(&list, 1, 100);
    output(list);

    
    delete(&list, 1, &value);
    printf("删除了 %d\n", value);
    output(list);
    
    return 0;
}