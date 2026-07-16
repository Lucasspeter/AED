/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void aux(struct TreeNode* root, int* ans, int* i)
{
    if(root == NULL)
        return;

    aux(root->left, ans, i);

    aux(root->right, ans, i);
    
    ans[*i] = root->val;
    (*i)++;

    
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* ans = malloc(sizeof(int) * 100);

    int i = 0;

    aux(root, ans, &i);

    *returnSize = i;

    return ans;
}