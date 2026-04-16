/*Faca um programa que receba dois numeros e mostre qual deles e o maior.*/

#include <stdio.h>

int main(){

    float n1, n2;

    printf("Digite o primeiro numero para ver qual o maior: ");
    scanf("%f", &n1);
    printf("Digite o segundo: ");
    scanf("%f", &n2);

    if(n1>n2){
        printf("O primerio e maior: %.2f", n1);
        return 0;
    } else {
        printf("O segundo e maior: %.2f", n2);
        return 0;
    }


}