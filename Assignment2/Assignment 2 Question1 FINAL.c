#include <stddef.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) 
{
while (root !=NULL)
{
if (root->val == target)
{
return root;
}
if (target < root->val)
{
root = root->left;
}
else
{
root = root->right;
}
}
 return NULL;
}
