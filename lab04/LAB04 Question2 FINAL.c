#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool check(struct TreeNode* left, struct TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    if (left->val != right->val) return false;
    return check(left->left, right->right) && check(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;
    return check(root->left, root->right);
}