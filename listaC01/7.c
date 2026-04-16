/*Leia um numero inteiro de 4 dıgitos (de 1000 a 9999) e imprima 1 dıgito por linha*/

#include <stdio.h>

int main(){
    int n;

    printf("Digite um numero inteiro de 4 digitos: ");
    scanf("%d", &n);

    printf("\n\nprimerio numero: %d\n", n/1000); // divide 1234 em 1
    printf("segundo numero: %d\n", (n/100) % 10); // divide 1234 em 12 e depois divide 12 por 10 = 1 e sobra 2
    printf("terceiro numero: %d\n", (n/10) % 10); // divide 1234 em 123 e depois divide 123 por 10 = 12 e sobra 3
    printf("quarto numero: %d\n\n\n", n %10); // divide 1234 =123 sobra 4
    return 0;
}