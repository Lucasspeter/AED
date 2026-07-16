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


bool isBalanced(struct TreeNode* root) {
    if(root == NULL)
        return true;

    int esq = maxDepth(root->left);
    int dir = maxDepth(root->right);

    if(abs(esq - dir) > 1)
        return false;

    return isBalanced(root->left)
        && isBalanced(root->right);
}


