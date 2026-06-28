/*
 * ============================================================
 * 第四阶段：树与图 - 二叉树
 * 学习目标：理解树的结构和三种遍历方式
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：三种遍历结果
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(TreeNode* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    printf("========== 二叉树遍历演示 ==========\n\n");

    /*
     * 构建树：
     *       1
     *      / \
     *     2   3
     *    / \
     *   4   5
     */
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("树结构：\n");
    printf("      1\n");
    printf("     / \\\n");
    printf("    2   3\n");
    printf("   / \\\n");
    printf("  4   5\n\n");

    printf("前序遍历（根→左→右）：");
    preOrder(root);
    printf("\n");

    printf("中序遍历（左→根→右）：");
    inOrder(root);
    printf("\n");

    printf("后序遍历（左→右→根）：");
    postOrder(root);
    printf("\n");

    printf("\n--- 记忆口诀 ---\n");
    printf("  前序：根左右\n");
    printf("  中序：左根右\n");
    printf("  后序：左右根\n");

    return 0;
}