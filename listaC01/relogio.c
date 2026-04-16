#include <stdio.h>

int main() {
    int totalSegundos = 135; 

    
    int minutos = totalSegundos / 60; 

    
    int segundosRestantes = totalSegundos % 60; 

    printf("%d segundos sao %d minutos e %d segundos.\n", 
            totalSegundos, minutos, segundosRestantes);
    
    return 0;
}