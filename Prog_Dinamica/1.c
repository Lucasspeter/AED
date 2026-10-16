#include <stdio.h>
#include <limits.h>

void trocoMinimoBottomUp(int V, int moedas[], int num_moedas) {
    int dp[V + 1];
    
    dp[0] = 0;
    
    for (int i = 1; i <= V; i++) {
        dp[i] = INT_MAX - 1;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < num_moedas; j++) {
            if (moedas[j] <= i) {
                if (dp[i - moedas[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - moedas[j]] + 1;
                }
            }
        }
    }

    printf("--- Tabela de Tabulacao (Bottom-up) ---\n");
    for (int i = 0; i <= V; i++) {
        printf("Valor %2d: %2d moeda(s)\n", i, dp[i] == INT_MAX - 1 ? -1 : dp[i]);
    }
    
    printf("\nQuantidade minima de moedas para %d centavos: %d\n", V, dp[V]);
}

int main() {
    int moedas[] = {1, 3, 4};
    int num_moedas = sizeof(moedas) / sizeof(moedas[0]);
    int V = 6;
    
    trocoMinimoBottomUp(V, moedas, num_moedas);
    
    return 0;
}