/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root,
                  int* returnSize,
                  int** returnColumnSizes)
{
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode* queue[2000];
    int front = 0, back = 0;

    queue[back++] = root;

    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);

    int level = 0;

    while(front < back)
    {
        int size = back - front;

        result[level] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[level] = size;

        for(int i = 0; i < size; i++)
        {
            struct TreeNode* node = queue[front++];

            result[level][i] = node->val;

            if(node->left != NULL)
                queue[back++] = node->left;

            if(node->right != NULL)
                queue[back++] = node->right;
        }

        level++;
    }

    *returnSize = level;
    return result;
}