/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sums[10000];
int freq[10000];
int size;
int maxFreq;

void addSum(int sum)
{
    for(int i = 0; i < size; i++)
    {
        if(sums[i] == sum)
        {
            freq[i]++;

            if(freq[i] > maxFreq)
                maxFreq = freq[i];

            return;
        }
    }

    sums[size] = sum;
    freq[size] = 1;

    if(maxFreq < 1)
        maxFreq = 1;

    size++;
}

int dfs(struct TreeNode* root)
{
    if(root == NULL)
        return 0;

    int esq = dfs(root->left);
    int dir = dfs(root->right);

    int soma = root->val + esq + dir;

    addSum(soma);

    return soma;
}

int* findFrequentTreeSum(struct TreeNode* root,
                         int* returnSize)
{
    size = 0;
    maxFreq = 0;

    dfs(root);

    int qtd = 0;

    for(int i = 0; i < size; i++)
    {
        if(freq[i] == maxFreq)
            qtd++;
    }

    int* ans = (int*)malloc(sizeof(int) * qtd);

    int j = 0;

    for(int i = 0; i < size; i++)
    {
        if(freq[i] == maxFreq)
            ans[j++] = sums[i];
    }

    *returnSize = qtd;

    return ans;
}