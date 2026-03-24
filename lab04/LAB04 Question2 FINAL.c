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
    if (left->val !=