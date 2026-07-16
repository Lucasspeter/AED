/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth( struct TreeNode* root ) {

    if(root == NULL)
        return 0;

    int esq = maxDepth ( root->left );
    int dir = maxDepth ( root->right );

    return ( esq > dir ? esq : dir ) + 1;
}