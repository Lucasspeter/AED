#include <stdio.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    
    int r = 0;
    int tam = 0;
    int l = 0;
    int c = 0;

    
    tam = matSize * ( *matColSize ); // como a matriz e retangular, o numero de elementos e o numero de linhas vezes o numero de colunas, entao nao tem matrizes irregulares

    int *result = (int *)malloc( sizeof ( int ) * tam );

        
    while( r < tam ){
        if( ( l + c ) % 2 == 0){ // pares vao para cima
           if ( ( c + 1 ) >= *matColSize ){ // verificar se a coluna pode aumentar
                result[r] = mat[l][c];
                r++;
                l++;
            } else if( l == 0 ){ // verificar se a linha pode diminuir
                result[r] = mat[l][c];
                r++;
                c++;
            } else {
                result[r] = mat[l][c];
                r++;
                c++;
                l--;
            }
            
            } else { // impares vao para baixo
            if ( ( l + 1 ) >= matSize ){ // verificar se a linha pode aumentar
                result[r] = mat[l][c];
                r++;
                c++;
            } else if( c  == 0 ){  // verificar se a coluna pode diminuir
                result[r] = mat[l][c];
                r++;
                l++;
            } else {
                result[r] = mat[l][c];
                r++;
                c--;
                l++;
            }
        }
    }

    *returnSize = tam;
    return result;
    
}


int main() {

    int matSize = 3;
    int cols = 3;

    
    int** mat = ( int** ) malloc( sizeof( int* ) * matSize );

    for (int i = 0; i < matSize; i++) {
        mat[i] = ( int* ) malloc( sizeof( int ) * cols );
    }

    
    int valor = 1;
    for ( int i = 0; i < matSize; i++ ) {
        for ( int j = 0; j < cols; j++ ) {
            mat[i][j] = valor++;
        }
    }

    
    int* matColSize = &cols;

    int returnSize = 0;

    int* result = findDiagonalOrder(mat, matSize, matColSize, &returnSize);

    
    printf( "Resultado:\n" );
    for ( int i = 0; i < returnSize; i++ ) {
        printf("%d ", result[i]);
    }
    printf("\n");

    
    free( result );

    for ( int i = 0; i < matSize; i++ ) {
        free( mat[i] );
    }
    free( mat );

    return 0;
}