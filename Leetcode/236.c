/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(
    struct TreeNode* root,
    struct TreeNode* p,
    struct TreeNode* q)
{
    if(root == NULL)
        return NULL;

    if(root == p || root == q)
        return root;

    struct TreeNode* esq =
        lowestCommonAncestor(root->left, p, q);

    struct TreeNode* dir =
        lowestCommonAncestor(root->right, p, q);

    if(esq && dir)
        return root;

    return esq ? esq : dir;
}