/*二叉线索树的创造及其遍历*/
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

int main()
{
    return 0;
}