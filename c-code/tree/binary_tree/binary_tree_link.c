/*链式存储结构的二叉树，使用递归遍历*/
#include<stdio.h>
#include<stdlib.h>

/*二叉树的结点的结构体*/
typedef struct Node {
    char data; //数据域
    struct Node *left_child; //左孩子指针
    struct Node *right_child; //右孩子指针
} TreeNode;

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
 * 先序遍历
 * root: 指向根结点的指针
 */
void preorder_traversal(TreeNode *root)
{
    if (root == NULL) { //若二叉树为空，做空操作
        return;
    }
    printf("%c", root->data); //访问根结点
    preorder_traversal(root->left_child); //递归遍历左子树
    preorder_traversal(root->right_child); //递归遍历右子树
}

/**
 * 中序遍历
 * root: 指向根结点的指针
 */
void inorder_traversal(TreeNode *root)
{
    if (root == NULL) { //若二叉树为空，做空操作
        return;
    }
    inorder_traversal(root->left_child); //递归遍历左子树
    printf("%c", root->data); //访问根结点
    inorder_traversal(root->right_child); //递归遍历右子树
}

/**
 * 后序遍历
 * root: 指向根结点的指针
 */
void postorder_traversal(TreeNode *root)
{
    if (root == NULL) { //若二叉树为空，做空操作
        return;
    }
    postorder_traversal(root->left_child); //递归遍历左子树
    postorder_traversal(root->right_child); //递归遍历右子树
    printf("%c", root->data); //访问根结点
}

int main()
{
    TreeNode *root = NULL;
    printf("请输入前序序列以构造二叉树\n");
    create_binary_tree(&root); //ABD##EG###C#F##
    
    printf("先序遍历为：");
    preorder_traversal(root); //ABDEGCF
    printf("\n");

    printf("中序遍历为：");
    inorder_traversal(root); //DBGEACF
    printf("\n");

    printf("后序遍历为：");
    postorder_traversal(root); //DGEBFCA
    printf("\n");

    return 0;
}