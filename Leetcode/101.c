/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool mirror( struct TreeNode* p, struct TreeNode* q )
{
    if ( p == NULL && q == NULL )
        return true;

    if ( p == NULL || q == NULL )
        return false;

    if ( p->val != q->val )
        return false;

    return mirror( p->left, q->right )
        && mirror( p->right, q->left );
}

bool isSymmetric( struct TreeNode* root )
{
    return mirror( root->left, root->right );
}