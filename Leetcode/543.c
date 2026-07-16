/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int diametro;

int maxDepth(struct TreeNode* root)
{
    if(root == NULL)
        return 0;

    int esq = maxDepth(root->left);
    int dir = maxDepth(root->right);

    if(esq + dir > diametro)
        diametro = esq + dir;

    return (esq > dir ? esq : dir) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    diametro = 0;

    maxDepth(root);

    return diametro;
}