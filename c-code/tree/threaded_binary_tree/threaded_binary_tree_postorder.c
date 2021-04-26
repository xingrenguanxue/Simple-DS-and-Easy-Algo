/*二叉线索树的创造及其遍历*/
#include <stdio.h>
#include <stdlib.h>
//引入头文件
#include "threaded_binary_tree.h"

//全局变量 prev 指针，指向刚访问过的结点
TTreeNode *prev = NULL;

/**
 * 后序线索化
 */
void postorder_threading(TTreeNode *root)
{
    if (root == NULL) {
        return;
    }
    postorder_threading(root->left_child);
    postorder_threading(root->right_child);
    if (root->left_child == NULL) {
        root->left_flag = 1;
        root->left_child = prev;
    }
    if (prev != NULL && prev->right_child == NULL) {
        prev->right_flag = 1;
        prev->right_child = root;
    }
    prev = root;
}

/**
 * 后序次序遍历
 */
void postorder_traversing(TTreeNode *root)
{
    //TODO:完善后序次序遍历代码
}

int main()
{
    TTreeNode *root;
    printf("请输入先序序列以构造二叉树\n");
    create_binary_tree(&root); //ABD##EG###C#F##

    postorder_threading(root);
    printf("线索二叉树，后序次序：\n"); //DGEBFCA
    //postorder_traversing(root);

}