/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */



static int CompararInt( const void *a, const void *b ) {
	int		x;
	int		y;

	x = *( const int * )a;
	y = *( const int * )b;
	return ( x > y ) - ( x < y );
}

/*
====================
fourSum

	Assinatura exigida pelo LeetCode.
	returnSize        <- numero de quadruplas encontradas
	returnColumnSizes <- array com o tamanho de cada linha ( sempre 4 )
====================
*/
int **fourSum( int *nums, int numsSize, int target,
              int *returnSize, int **returnColumnSizes )
{
    int **ans;
    int capacidade;
    int i, j, left, right;

    *returnSize = 0;

    if ( numsSize < 4 )
    {
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort( nums, numsSize, sizeof( int ), CompararInt );

    capacidade = 16;

    ans = malloc( sizeof( int * ) * capacidade );
    *returnColumnSizes = malloc( sizeof( int ) * capacidade );

    for ( i = 0; i < numsSize - 3; i++ )
    {
        if ( i > 0 && nums[i] == nums[i - 1] )
            continue;

        for ( j = i + 1; j < numsSize - 2; j++ )
        {
            if ( j > i + 1 && nums[j] == nums[j - 1] )
                continue;

            left = j + 1;
            right = numsSize - 1;

            while ( left < right )
            {
                long long soma =
                    ( long long )nums[i] + nums[j] + nums[left] + nums[right];

                if ( soma == target )
                {
                    if ( *returnSize == capacidade )
                    {
                        capacidade *= 2;

                        ans = realloc( ans, sizeof(int *) * capacidade );

                        *returnColumnSizes =
                            realloc( *returnColumnSizes, sizeof(int) * capacidade );
                    }

                    ans[*returnSize] = malloc( sizeof( int ) * 4 );

                    ans[*returnSize][0] = nums[i];
                    ans[*returnSize][1] = nums[j];
                    ans[*returnSize][2] = nums[left];
                    ans[*returnSize][3] = nums[right];

                    (*returnColumnSizes)[*returnSize] = 4;

                    ( *returnSize )++;

                    left++;
                    right--;

                    while ( left < right && nums[left] == nums[left - 1] )
                        left++;

                    while ( left < right && nums[right] == nums[right + 1] )
                        right--;
                }
                else if ( soma < target )
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    return ans;
}