/*
 * 二叉搜索树（二叉排序树）
 */
#include <stdio.h>
#include <stdlib.h>

/*二叉搜索树的结点*/
typedef struct _BSTNode{
    int data;
    struct _BSTNode * left_child;
    struct _BSTNode * right_child;
} BSTNode;


/**
 * @description: 查找
 * @param {BSTNode*} root 根结点指针
 * @param {int} key 目标值
 * @param {BSTNode**} p （二级指针）若查找成功，指向已找到的结点指针；
 *                      若查找失败，指向上次最后一个访问的结点指针
 * @param {BSTNode*} q 初始为空，以后始终指向上一个根结点
 * @return {int} 成功返回1；失败返回0
 */
int bst_search(BSTNode *root, int key, BSTNode **p, BSTNode *q)
{
    if (root == NULL) { // 空树，查找失败
        *p = q;
        return 0;
    } 
    if (key == root->data) { // 目标值相等根结点的值，查找成功
        *p = root;
        return 1;
    } else if (key < root->data) { // 目标值小于根结点的值，递归进入左子树
        return bst_search(root->left_child, key, p, root);
    } else { // 目标值大于根结点的值，递归进入右子树
        return bst_search(root->right_child, key, p, root);
    }
}

/**
 * @description: 创建结点
 * @param {int} data 值
 * @return {BSTNode*} 返回结点地址
 */
BSTNode *create_bst_node(int data)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->data = data;
    node->left_child = NULL;
    node->right_child = NULL;
    return node;
}

/**
 * @description: 向二叉查找树中插入一个结点
 * @param {BSTNode**} p_root 二级指针，指向根结点指针
 * @param {int} key 待插入值
 * @return {int} 插入成功返回1；失败返回0
 */
int insert_bst_node(BSTNode **p_root, int key)
{
    BSTNode *p;
    if (bst_search(*p_root, key, &p, NULL) == 0) { // 没有查找到 key
        BSTNode *new = create_bst_node(key); // 创建新结点
        if (p == NULL) { // 空树，新节点直接作为根结点
            *p_root = new;
            return 1;
        }
        if (key < p->data) { // 插入值小于 p 的值，插入到左子树
            p->left_child = new;
            return 1;
        }
        if (key > p->data) {  // 插入值大于 p 的值，插入到右子树
            p->right_child = new;
            return 1;
        }
    }
    return 0; // 插入失败
}

/**
 * @description: 创建二叉查找树
 * @param {BSTNode**}  p_root 二级指针，指向根结点指针
 * @param {int*} array 数组
 * @param {int} length 数组长度
 * @return {*} 无
 */
void create_bst(BSTNode **root, int *array, int length)
{
    // 循环向空二叉查找树中插入若干结点
    for (int i = 0; i < length; i++) {
        insert_bst_node(root, array[i]);
    }
}

/**
 * @description: 删除某个结点后重新调整二叉查找树
 * @param {BSTNode**} p_node 指向待删除结点的二级指针
 * @return {int} 成功返回1；失败返回0
 */
int rebuild_bst_after_delete(BSTNode **p_node)
{
    BSTNode *prev, *tmp;
    tmp = *p_node;
    if ((*p_node)->left_child == NULL) { // 左子树为空，重接右子树
        *p_node = (*p_node)->right_child;
        free(tmp);
        return 1;
    }
    if ((*p_node)->right_child == NULL) { // 右子树为空，重接左子树
        *p_node = (*p_node)->left_child;
        free(tmp);
        return 1;
    }
    // 左右子树均不为空
    if ((*p_node)->left_child != NULL && (*p_node)->right_child != NULL) {
        prev = (*p_node)->left_child;
        while (prev->right_child != NULL) { // 找到待删除结点的直接前驱
            tmp = prev;
            prev = prev->right_child;
        }
        (*p_node)->data = prev->data; // 赋值
        if (tmp != *p_node) { // 待删除结点有子孙结点
            tmp->right_child = prev->left_child;
        } else { // 待删除结点只有两个孩子结点，没有子孙结点
            tmp->left_child = prev->left_child;
        }
        free(prev);
        return 1;
    }
    return 0;
}

/**
 * @description: 删除目标值结点
 * @param {BSTNode**} 二级指针，指向 指向树根结点的指针 的指针
 * @param {int} key 目标值
 * @return {int} 删除成功返回1；否则返回0
 */
int delete_bst_node(BSTNode **p_root, int key)
{
    if (*p_root == NULL) {
        return 0;
    }
    if (key == (*p_root)->data) { // 找到要删除的目标值 key
        rebuild_bst_after_delete(p_root);
    } else if (key < (*p_root)->data) { // 目标值小于根结点，递归进入左子树
        return delete_bst_node(&(*p_root)->left_child, key);
    } else { // 目标值大于右子树，递归进入右子树
        return delete_bst_node(&(*p_root)->right_child, key);
    }
}



int main()
{
    int array[11] = {16, 41, 14, 30, 10, 12, 54, 5, 22, 66, 32};
    BSTNode *root = NULL;
    BSTNode *p = NULL;
    create_bst(&root, array, 11);

    int status = bst_search(root, 10, &p, NULL);
    printf("是否查找成功（1是，0否）： %d\n", status);
    printf("p->data = %d\n", p->data);

    status = bst_search(root, 111, &p, NULL);
    printf("是否查找成功（1是，0否）： %d\n", status);
    printf("上次最后一个访问的结点：p->data = %d\n", p->data);

    status = bst_search(root, 41, &p, NULL);
    printf("是否查找成功（1是，0否）： %d\n", status);
    status = delete_bst_node(&root, 41);
    printf("是否删除成功（1是，0否）： %d\n", status);
    status = bst_search(root, 41, &p, NULL);
    printf("是否查找成功（1是，0否）： %d\n", status);
}