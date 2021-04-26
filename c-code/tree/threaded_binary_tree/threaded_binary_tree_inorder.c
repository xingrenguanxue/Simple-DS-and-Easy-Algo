/*二叉线索树的创造及其遍历*/
#include<stdio.h>
#include<stdlib.h>
//引入头文件
#include "threaded_binary_tree.h"


//全局变量 prev 指针，指向刚访问过的结点
TTreeNode *prev = NULL;

/**
 * 中序线索化
 */
void inorder_threading(TTreeNode *root)
{
    if (root == NULL) { //若二叉树为空，做空操作
        return;
    }
    inorder_threading(root->left_child);
    if (root->left_child == NULL) {
        root->left_flag = 1;
        root->left_child = prev;
    }
    if (prev != NULL && prev->right_child == NULL) {
        prev->right_flag = 1;
        prev->right_child = root;
    }
    prev = root;
    inorder_threading(root->right_child);
}

/**
 * 中序次序遍历
 */
void inorder_traversing(TTreeNode *root)
{
    TTreeNode *p = root;
    while (p != NULL) {
        //找到在中序次序下的第一个元素：最下最左边的一个
        while (p->left_flag == 0) {
            p = p->left_child;
        }
        printf("%c", p->data);
        //找到p在中序次序下的直接后继
        while (p->right_flag == 1 && p->right_child != NULL) {
            p = p->right_child;
            printf("%c", p->data);
        }
        p = p->right_child; //进入右子树
    }
    printf("\n");
}

/**
 * 获取某个结点在中序次序下的直接前驱
 * node: 指向某个结点的指针
 * return: 直接前驱的地址
 */
TTreeNode *get_prev_node_inorder(TTreeNode *node)
{
    //如果左指针是线索
    if (node->left_flag == 1) {
        return node->left_child;
    }
    //如果其左指针不是线索
    //找到其左子树
    TTreeNode *p = node->left_child;
    //根据中序遍历的特点：某结点的直接前驱，为其左子树中最后一个被遍历的结点
    //左子树中的 最下最右结点 为最后一个被遍历
    //找到其左子树中 最下最右边的结点
    while (p != NULL && p->right_flag == 0) { //右指针不是线索
        p = p->right_child;
    }
    return p;
}

/**
 * 获取某个结点在中序次序下的直接后继
 * node: 指向某个结点的指针
 * return: 直接后继的地址
 */
TTreeNode *get_next_node_inorder(TTreeNode *node)
{
    //如果右指针是线索
    if (node->right_flag == 1) {
        return node->right_child;
    }
    //如果右指针不是线索
    //找到其右子树
    TTreeNode *p = node->right_child;
    //根据中序遍历的特点：某结点的直接后继，为其右子树中第一个被遍历的结点
    //右子树中的 最下最左结点 为第一个被遍历
    //找到其右子树中 最下最左边的结点
    while (p != NULL && p->left_flag == 0) {
        p = p->left_child;
    }
    return p;
}

int main()
{
    TTreeNode *root;
    printf("请输入先序序列以构造二叉树\n");
    create_binary_tree(&root); //ABD##EG###C#F##

    inorder_threading(root);
    prev->right_flag = 1; //将最后一个结点的右标识位修改为 1
    prev->right_child = NULL;
    printf("线索二叉树，中序次序：\n"); //DBGEACF
    inorder_traversing(root);

    printf("root is %c\n", root->data);

    TTreeNode *p = get_next_node_inorder(root);
    printf("root->next is %c\n", p->data);
    p = get_next_node_inorder(p);
    printf("root->next->next is %c\n", p->data);
    p = get_next_node_inorder(p);
    printf("root->next->next->next is %c\n", p->data);

    p = get_prev_node_inorder(root);
    printf("root->prev is %c\n", p->data);

    return 0;
}