#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int helper(struct TreeNode* root, int current) {
    if (!root) return 0;
    current = current * 10 + root->val;
    if (!root->left && !root->right) return current;
    return helper(root->left, current) + helper(root->right, current);
}

int sumNumbers(struct TreeNode* root) {
    return helper(root, 0);
}