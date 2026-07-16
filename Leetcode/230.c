/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int resposta;
int contador;
int kGlobal;

void inorder(struct TreeNode* root)
{
    if(root == NULL)
        return;

    inorder(root->left);

    contador++;

    if(contador == kGlobal)
    {
        resposta = root->val;
        return;
    }

    inorder(root->right);
}

int kthSmallest(struct TreeNode* root, int k)
{
    contador = 0;
    resposta = 0;
    kGlobal = k;

    inorder(root);

    return resposta;
}