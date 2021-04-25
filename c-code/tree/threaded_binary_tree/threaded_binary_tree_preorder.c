/*二叉线索树的创造及其遍历*/
#include <stdio.h>
#include <stdlib.h>
//引入头文件
#include "threaded_binary_tree.h"

//全局变量 prev 指针，指向刚访问过的结点
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
        //根结点为先序次序的第一个元素
        printf("%c", p->data);

        while (p->left_flag == 0) {
            p = p->left_child;
            printf("%c", p->data);
        }
        //找到p在先序次序下的直接后继
        while (p->right_flag == 1 && p->right_child != NULL) {
            p = p->right_child;
            printf("%c", p->data);
        }
        p = p->right_child; //进入右子树
    }
    printf("\n");
}

int main()
{
    TTreeNode *root;
    printf("请输入先序序列以构造二叉树\n");
    create_binary_tree(&root); //ABD##EG###C#F##
    
    preorder_threading(root);
    printf("线索二叉树，先序次序：\n"); //ABDEGCF
    preorder_traversing(root);

    return 0;
}