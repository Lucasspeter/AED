#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarPessoa( void **pBuffer );
void listarTodos( void *pBuffer);
void buscarPessoa( void *pBuffer );
void removerPessoa( void **pBuffer );



int main() {
    void *pBuffer = malloc ( ( sizeof ( int ) * 3 ) + 256 ); // tamanho para o menu, a quantidade de pessoas, tamanho total do buffer e rascunho

    *( int* ) pBuffer = 0; //menu 
    *( ( int* ) pBuffer + 1 ) = 0; //quantidade de pessoas  
    *( ( int* ) pBuffer + 2 ) = ( sizeof ( int ) * 3 + 256 ); // tamanho total do buffer ( comeca com o cabecalho e rascunho )



    
     do{
        printf ( "\nEscolha a opcao: \n" );
        printf ( "1 - Cadastrar pessoa \n" );
        printf ( "2 - Remover pessoa \n" );
        printf ( "3 - Buscar pessoa \n" );
        printf ( "4 - Listar pessoas \n" );
        printf ( "5 - Sair\n " );
        scanf("%d", ( int* ) pBuffer ); //lendo o menu
        getchar(); // Limpa o "enter" que ficou no teclado
    
    
        switch ( *( int* ) pBuffer ) {
            case 1:
                adicionarPessoa ( &pBuffer );
                break;

            case 2:
                removerPessoa ( &pBuffer );
                break;

            case 3:
                buscarPessoa ( pBuffer );
                break;

            case 4:
                listarTodos ( pBuffer );
                break;

            case 5:
                printf ( "Finalizando programa" );
                break;


            default:
                printf( "Opcao invalida \n" );

        }


    } while ( *( int* ) pBuffer != 5 );

    free(pBuffer);
    return 0;

}


void adicionarPessoa( void **pBuffer ) {
    // Ponteiros de suporte (etiquetas)
    char *pRascunhoNome;
    char *pRascunhoEmail;
    int *pRascunhoIdade;
    int *pNovoBlocoTam;
    int *pAntigoTamTotal;

    // Definir onde é o rascunho (pula os 3 ints de controle)
    pRascunhoNome = ( char* )( *pBuffer ) + ( 3 * sizeof ( int ) ); // nome fica no inicio do rascunho
    pRascunhoEmail = pRascunhoNome + 100; // Reserva 100 bytes pro nome no rascunho
    pRascunhoIdade = ( int* )( pRascunhoEmail + 100 ); // Reserva 100 pro email e usa o resto pra idade

    // Coletar dados no rascunho
    printf( "\n\nNome: " );
    scanf( "%s", pRascunhoNome );
    printf( "Email: " );
    scanf( "%s", pRascunhoEmail );
    printf( "Idade: " );
    scanf( "%d", pRascunhoIdade );

    // Calcular o tamanho que esta nova pessoa ocupara
    // [int tam_bloco] + [int idade] + [string nome + \0] + [string email + \0]
    pNovoBlocoTam = ( int* ) ( pRascunhoIdade + 1 ); // Uso temporário de pNovoBlocoTam para guardar a conta
    *pNovoBlocoTam = ( sizeof ( int ) * 2 ) + ( strlen ( pRascunhoNome ) + 1 ) + ( strlen( pRascunhoEmail ) + 1 );


    // Atualizar o tamanho total e dar o Realloc
    pAntigoTamTotal = ( int* ) ( *pBuffer ) + 2; // Ponteiro para o "Tamanho Total" no cabecalho
    
    // Faz o realloc (o buffer pode mudar de lugar aqui)
    *pBuffer = realloc( *pBuffer, *pAntigoTamTotal + *pNovoBlocoTam );
    
    // Atualizar as etiquetas do rascunho com o novo endereço do buffer
    pRascunhoNome = ( char* ) ( *pBuffer ) + ( 3 * sizeof ( int ) );
    pRascunhoEmail = pRascunhoNome + 100;
    pRascunhoIdade = ( int* ) ( pRascunhoEmail + 100 );
    

    // Copiar os dados para o novo espaço alocado
    // recalculando o ponto de inserção usando o novo endereço de *pBuffer
    pNovoBlocoTam = ( int* ) ( ( char* ) ( *pBuffer ) + ( * ( ( int* ) ( *pBuffer ) + 2 ) ) ); // Usa o tamanho guardado na posição +2 para saber onde termina o buffer e inserir a nova pessoa lá, agora pNovoBlocoTam aponta para o local onde os dados da nova pessoa devem ser escritos
    
    // [int tam_bloco]
    *pNovoBlocoTam = ( sizeof ( int ) * 2 ) + ( strlen ( pRascunhoNome ) + 1 ) + ( strlen ( pRascunhoEmail ) + 1 ); // guardo o tamanho do bloco no inicio apos o cabecalho
    
    // [int idade] - Lendo do novo endereço correto do rascunho
    * ( pNovoBlocoTam + 1 ) = *pRascunhoIdade; // idade fica logo depois do tamanho do bloco( [tamanho do bloco][idade][nome\0][email\0] )
    
    // [string nome] - Lendo do novo endereço correto do rascunho
    strcpy ( ( char* ) ( pNovoBlocoTam + 2 ), pRascunhoNome );
    
    // [string email] - Lendo do novo endereço correto do rascunho
    strcpy ( ( char* ) ( pNovoBlocoTam + 2 ) + strlen ( pRascunhoNome ) + 1, pRascunhoEmail );

    // 6. Atualizar controles globais
    * ( ( int* ) ( *pBuffer ) + 1 ) += 1; // +1 pessoa
    * ( ( int* ) ( *pBuffer ) + 2 ) += *pNovoBlocoTam; // Atualiza tamanho total do buffer

    printf( "\nAdicionado!\n\n" );
}



void listarTodos( void *pBuffer ) {
    char *pAux;
    int *pLimite;
    int *pContadorPessoas;

    pContadorPessoas = ( int* ) pBuffer + 1; // Ponteiro para o contador de pessoas no cabeçalho

    if ( *pContadorPessoas == 0 ) {
        printf( "\n\nAgenda vazia!\n" );
        return;
    }

    // Onde começa a primeira pessoa (Depois do cabeçalho fixo)
    pAux = ( char* ) pBuffer + ( 3 * sizeof ( int ) ) + 256;
    
    // Onde o buffer termina (Valor guardado no Tamanho Total)
    pLimite = ( int* ) ( ( char* ) pBuffer + *( ( int* ) pBuffer + 2 ) ); // uso o tamanho total guardado no cabeçalho para saber onde termina o buffer

    printf( "\n--- LISTA DE CONTATOS ---\n" );
    // Enquanto o endereço atual for menor que o endereço do limite
    while ( ( int* ) pAux < pLimite ) {
        // [int tam][int idade][nome\0][email\0]
        printf( "Nome: %s | ", pAux + ( sizeof ( int ) * 2 ) );
        printf( "Idade: %d | ", *( int* ) ( pAux + sizeof ( int ) ) );
        printf( "Email: %s\n", pAux + ( sizeof ( int ) * 2 ) + strlen( pAux + ( sizeof ( int ) * 2 ) ) + 1 );

        // pAux avança o tamanho do bloco (que está no primeiro int)
        pAux = pAux + ( * ( int* ) pAux );
    }
}



void buscarPessoa( void *pBuffer ) {
    char *pBusca;
    int *pFlagEncontrado;
    char *pAux;
    char *pLimite;

    // termo de busca (Início do rascunho)
    pBusca = ( char* ) pBuffer + ( 3 * sizeof ( int ) ); // O rascunho começa aqui

    // onde guardar se encontrar (No final do rascunho, byte 200)
    pFlagEncontrado = ( int* ) ( pBusca + 200 );
    *pFlagEncontrado = 0; // Começa como 0 (não encontrado)

    if ( * ( ( int* ) pBuffer + 1 ) == 0 ) {
        printf( "\n\nAgenda vazia!\n" );
        return;
    }

    printf( "\n\nDigite o nome para buscar: " );
    scanf( "%s", pBusca );

    // Preparar o while (igual ao listar)
    pAux = ( char* ) pBuffer + ( 3 * sizeof ( int ) ) + 256;
    pLimite = ( char* ) pBuffer + *( ( int* ) pBuffer + 2 );

    while ( pAux < pLimite ) {
        // O Nome começa após os 2 ints (Tamanho e Idade)
        // strcmp compara o que o usuario digitou com o nome na memoria
        if ( strcmp(pBusca, pAux + (sizeof(int) * 2)) == 0) {
            printf("\n--- Pessoa Encontrada! ---\n");
            printf( "Nome: %s\n", pAux + ( sizeof ( int ) * 2 ) );
            printf( "Idade: %d\n", *( int* ) ( pAux + sizeof ( int ) ) );
            printf( "Email: %s\n", pAux + ( sizeof ( int ) * 2 ) + strlen( pAux + ( sizeof ( int ) * 2 ) ) + 1 );
            
            *pFlagEncontrado = 1; // Marca que achou
            break; // Pode parar de procurar
        }

        // Pula para a próxima pessoa usando o tamanho do bloco atual
        pAux = pAux + ( *( int* ) pAux );
    }

    if ( *pFlagEncontrado == 0 ) {
        printf( "\nUsuario '%s' nao encontrado.\n", pBusca );
    }
}



void removerPessoa( void **pBuffer ) {
    char *pBusca;
    char *pAux;
    char *pLimite;
    int *pFlagEncontrado;

    // Configurar ponteiros de controle no rascunho
    pBusca = ( char* ) ( *pBuffer ) + ( 3 * sizeof ( int ) ); // Início do rascunho
    pFlagEncontrado = (int*)(pBusca + 200);         // Status no final do rascunho igual o da busca
    *pFlagEncontrado = 0;

    if ( *( ( int* ) ( *pBuffer ) + 1 ) == 0 ) {
        printf( "\n\nAgenda vazia!\n" );
        return;
    }

    printf( "\n\nDigite o nome exato para remover: " );
    scanf( "%s", pBusca );

    // Iniciar busca (igual a função buscar)
    pAux = ( char* )(*pBuffer) + ( 3 * sizeof ( int ) ) + 256;
    pLimite = ( char* )(*pBuffer) + *( ( int* ) (*pBuffer) + 2 );

    while ( pAux < pLimite ) {
        // Se encontramos o nome (pula os 2 ints iniciais do bloco)
        if ( strcmp ( pBusca, pAux + ( sizeof ( int ) * 2 ) ) == 0 ) {
            *pFlagEncontrado = 1;

            // Remocao
            
            // Guarda o tamanho desta pessoa no rascunho (para subtrair depois)
            // Usamos o rascunho + 210 como "váriavel temporária"
            *( ( int* ) ( pBusca + 210 ) ) = *( ( int* ) pAux ); // Tamanho do bloco que queremos remover, primeiro lugar da pessoa tem o tamanho dela

            // Desloca a memória (memmove)
            // memmove(destino, origem, tamanho_para_copiar)
            // Destino: Onde a pessoa removida começa (pAux)
            // Origem: Onde a próxima pessoa começa (pAux + tamanho_da_atual)
            // Tamanho: O resto da fita (Limite - Origem)
            memmove(pAux, 
                    pAux + ( * ( int* ) pAux ), 
                    pLimite - ( pAux + ( * ( int* ) pAux ) )); // trazer tudo que esta depois da pessoa removida para o lugar dela, sobreescrevendo a pessoa removida   

            // Atualizar cabeçalho global
            *( ( int* ) ( *pBuffer ) + 1 ) -= 1; // Menos 1 pessoa
            *( ( int* ) ( *pBuffer ) + 2 ) -= *( ( int* ) ( pBusca + 210 ) ); // Diminui tamanho total tirando o tamanho que guardei no final do rascunho

            // Encolher o buffer com realloc
            *pBuffer = realloc( *pBuffer, *( ( int* ) ( *pBuffer ) + 2 ) ); // Usando o novo tamanho total
            
            printf( "\nPessoa removida com sucesso!\n" );
            break; 
        }

        // Se não for essa, pula para a próxima
        pAux = pAux + (*(int*)pAux);
    }

    if ( *pFlagEncontrado == 0 ) {
        printf( "\nNome '%s' nao encontrado.\n", pBusca );
    }
}

