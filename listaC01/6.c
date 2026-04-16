/*Leia uma temperatura em graus Celsius e apresente-a convertida em graus Fahrenheit.
A formula de conversao e:  F = C∗(9.0/5.0)+32.0, sendo F a temperatura em Fahrenheit
e C a temperatura em Celsius*/

#include <stdio.h>

int main(){
    float c, f;

    printf("Digite uma temperatura em C: ");
    scanf("%f", &c);

    f = c*(9.0/5.0) + 32;

    printf("A temperatura em Fahrenheit e: %.3f", f);
    return 0;
}