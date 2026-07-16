/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum)
{
    if ( root == NULL )
        return false;

    targetSum -= root->val;

    if ( root->left == NULL && root->right == NULL )
        return targetSum == 0; // se targetSum == 0, retorna true, se nao false

    return hasPathSum( root->left, targetSum )
        || hasPathSum( root->right, targetSum );
}