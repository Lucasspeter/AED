/*Leia um numero real e imprima o resultado do quadrado desse numero.*/


#include <stdio.h>

int main(){
    float n, nf;

    printf("Digite um numero real: ");
    scanf("%f", &n);

    nf = n * n;

    printf("O numero digitado ao quadrado e: %.2f", nf);
    return 0;
}