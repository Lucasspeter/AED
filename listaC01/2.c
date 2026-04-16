/*Faca um programa que leia um numero real e o imprima. */

#include <stdio.h>

int main(){
    float n;

    printf("Digite um numero real: ");
    scanf("%f", &n);

    printf("O numero digitado foi: %.2f", n);
    return 0;
}