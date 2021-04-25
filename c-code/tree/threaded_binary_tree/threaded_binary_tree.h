/**
 * 该头文件包括线索二叉树的
 * 结构体、创造结点的函数、构造普通二叉树的函数
 * 以提供给threaded_binary_tree_preorder.c
 *        threaded_binary_tree_inorder.c
 *        threaded_binary_tree_postorder.c
 * 使用
 */
#include<stdio.h>
#include<stdlib.h>

/*线索二叉树的结点的结构体*/
typedef struct Node {
    char data; //数据域
    struct Node *left_child; //左指针域
    int left_flag; //左指针标志位
    struct Node *right_child; //右指针域
    int right_flag; //右指针标志位
} TTreeNode;

/**
 * 创造线索二叉树的结点
 * elem: 结点数据域的值
 */
TTreeNode *create_tree_node(char elem)
{
    TTreeNode *new = (TTreeNode *)malloc(sizeof(TTreeNode));
    new->data = elem;
    new->left_child = NULL;
    new->right_child = NULL;
    new->left_flag = 0; //标志位默认为0，即指针默认为指向孩子的指针
    new->right_flag = 0;
    return new;
}

/**
 * 先序创造一颗普通二叉树
 * root: 指向根结点的指针的指针
 */
void create_binary_tree(TTreeNode **root)
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