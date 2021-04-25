/*链式存储结构的二叉树，使用队列进行层序遍历*/
#include<stdio.h>
#include<stdlib.h>
#include"queue_in_tree.h" //引入队列的头文件

/**
 * 创造二叉树的结点
 * elem: 结点数据域的值
 */
TreeNode *create_tree_node(char elem)
{
    TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
    new->data = elem;
    new->left_child = NULL;
    new->right_child = NULL;
    return new;
}

/**
 * 创造一个二叉树
 * root: 指向根结点的指针的指针
 */
void create_binary_tree(TreeNode **root)
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

/**
 * 使用队列实现层序遍历
 */
void levelorder_travelsal_by_queue(TreeNode *root)
{
    Queue queue;
    TreeNode *curr;
    init_queue(&queue); //初始化队列

    en_queue(&queue, root); //入队

    while (!queue_is_empty(&queue)) {
        de_queue(&queue, &curr); //出队
        printf("%c", curr->data);
        if (curr->left_child != NULL) { //如果左孩子不为空
            en_queue(&queue, curr->left_child); //左孩子入队
        }
        if (curr->right_child != NULL) { //如果右孩子不为空
            en_queue(&queue, curr->right_child); //右孩子入队
        }
    }
}

int main()
{
    /***********************************
    //测试队列的功能
    Queue queue;
    init_queue(&queue); //初始化
    en_queue(&queue, create_tree_node('A')); //入队
    TreeNode *node;
    de_queue(&queue, &node); //出队
    printf("dequeue: %c\n", node->data);
    ***********************************/

    TreeNode *root;
    printf("请输入前序序列以构造二叉树\n");
    create_binary_tree(&root); //ABD##E##C#F##
    
    printf("层序遍历顺序为：");
    levelorder_travelsal_by_queue(root);

    return 0;
}