#include <stdio.h>
#include <stdlib.h>


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

int main() {

    int nums[] = {1, 2, 1};
    int numsSize = sizeof ( nums ) / sizeof ( nums[0] ) ;

    int returnSize;

    int* resultado = nextGreaterElements ( nums, numsSize, &returnSize );

    printf( "Resultado:\n" );

    for ( int i = 0; i < returnSize; i++ ) {
        printf ( "%d ", resultado[i] );
    }

    printf ( "\n" );

    
    free ( resultado );

    return 0;
}