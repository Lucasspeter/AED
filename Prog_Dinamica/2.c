#include <stdio.h>

#define MAX_N 100

long long memo[MAX_N];

void inicializaMemo() {
    for (int i = 0; i < MAX_N; i++) {
        memo[i] = -1;
    }
}

long long contaParentesesTopDown(int n) {
    if (n <= 1) return 1;
    
    if (memo[n] != -1) return memo[n];
    
    long long total_expressoes = 0;
    
    for (int i = 0; i < n; i++) {
        total_expressoes += contaParentesesTopDown(i) * contaParentesesTopDown(n - 1 - i);
    }
    
    return memo[n] = total_expressoes;
}

int main() {
    inicializaMemo();
    
    int n = 3;
    long long resultado = contaParentesesTopDown(n);
    
    printf("Para n = %d, o numero de expressoes validas de parenteses e: %lld\n", n, resultado);
    
    return 0;
}