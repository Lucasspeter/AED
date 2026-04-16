/*Leia um numero real e imprima a quinta parte deste numero.*/


#include <stdio.h>

int main(){
    float n, nf;

    printf("Digite um numero real: ");
    scanf("%f", &n);

    nf = n/5;

    printf("A quinta parte desse numero e: %.2f", nf);
    return 0;
}