/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    
    int r = 0;
    int tam = 0, l = 0, c = 0;

    
    tam = matSize * ( *matColSize ); // como a matriz e retangular, o numero de elementos e o numero de linhas vezes o numero de colunas, entao nao tem matrizes irregulares,

    int *result = (int *)malloc(sizeof(int) * tam);

        
    while( r < tam ){
        if(( l + c ) % 2 == 0){ // pares vao para cima
           if (( c + 1 ) >= *matColSize ){
            result[r] = mat[l][c];
            r++;
            l++;
            }else if( l == 0 ){ 
            result[r] = mat[l][c];
            r++;
            c++;
            } 
            else {
            result[r] = mat[l][c];
            r++;
            c++;
            l--;
            }
            
            } else { // impares vao para baixo
            if (( l + 1 ) >= matSize ){
            result[r] = mat[l][c];
            r++;
            c++;
            } else if( c  == 0 ){ 
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