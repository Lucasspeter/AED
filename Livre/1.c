#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

typedef struct{
    int idade;
    char nome[30];
    float salario;
}pessoa;

char n[30];
char variavel;
int cont = 0;

pessoa *p1 = NULL;

printf("voce deseja adicionar um funcionario?\n(resposta s/n): ");
if (scanf(" %c", &variavel) != 1) {
    return 1;
}

if (variavel == 'n'){
    printf("#------------------------------#\n");
    printf("Nenhum funcionario adicionado.\n");
    printf("Programa encerrado.\n");
    printf("#------------------------------#\n");
    return 0;
}

while(variavel != 'n'){
    pessoa *temp = realloc(p1, (cont + 1) * sizeof *temp);
    if (temp == NULL) {
        free(p1);
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }
    p1 = temp;

    printf("digite a idade do funcionario: ");
    scanf("%d", &p1[cont].idade);
    printf("digite o salario do funcionario: ");
    scanf("%f", &p1[cont].salario);

    getchar();

    printf("Digite o nome do funcionario: ");
    fgets(n, sizeof n, stdin);

    n[strcspn(n, "\n")] = '\0';
    strcpy(p1[cont].nome, n);

    cont++;

    printf("voce deseja adicionar outro funcionario?\n(resposta s/n): ");
    if (scanf(" %c", &variavel) != 1) {
        break;
    }
};


for(int i = 0; i < cont; i++){
    printf("#------------------------------#\n");
    printf("Funcionario %d\n", i + 1);
    printf("nome: %s\nidade: %d\nsalario: %f\n",p1[i].nome,p1[i].idade, p1[i].salario);
    printf("#------------------------------#\n");
}


return 0;
}