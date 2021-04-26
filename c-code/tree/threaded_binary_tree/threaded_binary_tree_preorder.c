/*二叉线索树的创造及其遍历*/
#include <stdio.h>
#include <stdlib.h>
// 引入头文件
#include "threaded_binary_tree.h"

// 全局变量 prev 指针，指向刚访问过的结点
TTreeNode *prev = NULL;

/**
 * 先序线索化
 */
void preorder_threading(TTreeNode *root)
{
    if (root == NULL) {
        return;
    }
    if (root->left_child == NULL) {
        root->left_flag = 1;
        root->left_child = prev;
    }
    if (prev != NULL && prev->right_child == NULL) {
        prev->right_flag = 1;
        prev->right_child = root;
    }
    prev = root;
    if (root->left_flag == 0) {
        preorder_threading(root->left_child);
    }
    if (root->right_flag == 0) {
        preorder_threading(root->right_child);
    }
}


/**
 * 先序次序遍历
 */
void preorder_traversing(TTreeNode *root)
{
    TTreeNode *p = root;
    while (p != NULL) {
        // 根结点为先序次序的第一个元素
        printf("%c", p->data);

        while (p->left_flag == 0) {
            p = p->left_child;
            printf("%c", p->data);
        }
        // 找到p在先序次序下的直接后继
        while (p->right_flag == 1 && p->right_child != NULL) {
            p = p->right_child;
            printf("%c", p->data);
        }
        p = p->right_child; //进入右子树
    }
    printf("\n");
}

/**
 * 获取某个结点在先序次序下的双亲结点
 * root: 树的根结点
 * child: 某个结点
 * return: 直接前驱的地址
 */
TTreeNode *get_parent_node(TTreeNode *root, TTreeNode *child)
{
    TTreeNode *p = NULL;
    if (root == NULL || child == NULL || root == child) {
        return NULL;
    }
    if ((root->left_flag == 0 && root->left_child == child) || (root->right_flag == 0 && root->right_child == child)) {
        return root;
    }
    
    if (root->left_flag == 0) {
        p = get_parent_node(root->left_child, child);
    }
    if (p == NULL && root->right_flag == 0) {
        p = get_parent_node(root->right_child, child);
    }
    return p;
}

/**
 * 获取某个结点在先序次序下的直接前驱
 * root: 树的根结点
 * node: 某个结点
 * return: 直接前驱的地址
 */
TTreeNode *get_prev_node_preorder(TTreeNode *root, TTreeNode *node)
{
    // 如果左指针使线索，直接返回左孩子
    if (node->left_flag == 1) {
        return node->left_child;
    }
    // 如果左指针不是线索，找到其双亲结点，并返回
    return get_parent_node(root, node);
}

/**
 * 获取某个结点在先序次序下的直接后继
 * node: 指向某个结点的指针
 * return: 直接后继的地址
 */
TTreeNode *get_next_node_preorder(TTreeNode *node)
{
    // 右指针为线索，直接返回右孩子
    if (node->right_flag == 1) {
        return node->right_child;
    }
    // 如果右指针不是线索
    // 根据先序遍历的特点，某结点的左孩子为其直接后继
    if (node->left_flag == 0 && node->left_child != NULL) {
        return node->left_child;
    }
    // 如果某结点没有左孩子，那么右孩子为其直接后继
    if (node->right_flag == 0 && node->right_child != NULL) {
        return node->right_child;
    }
    // 以上均不符
    return NULL;
    
}

int main()
{
    TTreeNode *root;
    printf("请输入先序序列以构造二叉树\n");
    create_binary_tree(&root); // ABD##EG###C#F##
    
    preorder_threading(root);
    prev->right_flag = 1; // 将最后一个结点的右标识位修改为 1
    prev->right_child = NULL;

    printf("线索二叉树，先序次序：\n"); // ABDEGCF
    preorder_traversing(root);

    TTreeNode *p;
    TTreeNode *node = root->left_child->left_child;
    // p = get_parent_node(root, node);
    // printf("%c\n", p->data);

    printf("root = %c\n", root->data);
    printf("node = %c\n", node->data);

    p = get_prev_node_preorder(root, node);
    printf("node->prev = %c\n", p->data);

    p = get_next_node_preorder(node);
    printf("node->next = %c\n", p->data);

    return 0;
}