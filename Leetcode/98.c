/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool valida(struct TreeNode* root, long min, long max)
{
    if(root == NULL)
        return true;

    if(root->val <= min || root->val >= max)
        return false;

    return valida(root->left, min, root->val)
        &&
           valida(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root)
{
    return valida(root, LONG_MIN, LONG_MAX);
}