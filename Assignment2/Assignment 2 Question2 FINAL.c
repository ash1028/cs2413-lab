#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkAVL(struct TreeNode* root, long long minVal, long long maxVal)
{
    if (root == NULL)
        return 0;

    if (root->val <= minVal || root->val >= maxVal)
        return -1;

    int leftHeight = checkAVL(root->left, minVal, root->val);
    if (leftHeight == -1)
        return -1;

    int rightHeight = checkAVL(root->right, root->val, maxVal);
    if (rightHeight == -1)
        return -1;

    if (leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1)
        return -1;

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isAVL(struct TreeNode* root)
{
    return checkAVL(root, LLONG_MIN, LLONG_MAX) != -1;
}