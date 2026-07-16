/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements( int* nums, int numsSize, int* returnSize ) {
    int* ans = ( int* ) malloc ( sizeof ( int ) * numsSize );
    int pilha[ numsSize ];
    int top = -1;
    
    

    for ( int i = 2 * numsSize - 1; i >= 0; i-- ) {
        while ( top != -1 && nums[pilha[ top ] ] <= nums[ i % numsSize ] ){
            top--;
        }
        ans[ i % numsSize ] = top == -1 ? -1 : nums[pilha[ top ]];
        pilha[ ++top ] = i % numsSize;
    }

    *returnSize = numsSize;
    return ans;
}