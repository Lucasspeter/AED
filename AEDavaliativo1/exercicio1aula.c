


int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    
    int r = 0;
    int tam = 0;

    *mat =(int *)malloc(sizeof(int) * matSize);
    
    for(int i = 0; i < *matColSize; i++){
        mat[i] = (int *)malloc(sizeof(int)); //erro aqui tambem
        tam++;
    }

    int *result = (int *)malloc(sizeof(int) * matSize * tam);

        
    for(int l = 0; l < matSize; l++){
        for (int c = 0; c < *matColSize; c++){
            result[r] = mat[l][c];
            r++;
        }
    }/*pensei em usar varios if ou alguma condicao que compara as variaveis l e c pra fazer isso pois precisa aumentar e diminuir elas em algum padrao mas no papel nao funcionou entao nem botei aqui*/


    
    *returnSize = matSize * tam;
    return result;
    
}