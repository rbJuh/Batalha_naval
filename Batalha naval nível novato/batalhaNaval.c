#include <stdio.h>

int main() {
    int TAMANHO = 10;  // Tamanho do tabuleiro
    int TAM_NAVIO = 3; // Tamanho dos navios
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializando todas as posições como 0 (mar)
    for (int i = 0; i < TAMANHO; i++) {          // Laço para percorrer todas as linhas do tabuleiro
        for (int j = 0; j < TAMANHO; j++) {      // Laço para percorrer todas as colunas de cada linha
            tabuleiro[i][j] = 0;                // Preenche a posição com 0 (mar)
        }
    }

    // Coordenadas fixas para os navios
    int linhaH = 2, colunaH = 4; // O navio horizontal começa na posição (2,4)
    int linhaV = 5, colunaV = 7; // O navio vertical começa na posição (5,7)

    // Posicionando o navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {  // Loop para colocar o navio horizontal
        tabuleiro[linhaH][colunaH + i] = 3; // Coloca o valor 3 (representando o navio) nas posições horizontais
    }

    // Posicionando o navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {  // Loop para colocar o navio vertical
        tabuleiro[linhaV + i][colunaV] = 3; // Coloca o valor 3 (representando o navio) nas posições verticais
    }

    // Exibindo o tabuleiro atualizado
    printf("\n  BATALHA NAVAL - TABULEIRO\n");  // Cabeçalho
    printf("  ------------------------\n");

    // Impressão do índice das colunas (A a J)
    printf("    ");
    for (int j = 0; j < TAMANHO; j++) {  // Laço para imprimir as letras das colunas
        printf("%c ", 'A' + j);  // 'A' é o código ASCII para a letra A, e j é o índice que adiciona a sequência
    }
    printf("\n");

    // Imprime o tabuleiro linha por linha
    for (int i = 0; i < TAMANHO; i++) {  // Laço para percorrer todas as linhas
        printf("%d | ", i); // Índice da linha, no formato "0 |"
        for (int j = 0; j < TAMANHO; j++) {  // Laço para percorrer todas as colunas de cada linha
            if (tabuleiro[i][j] == 3) {  // Se a posição for 3, significa que é parte de um navio
                printf("3 ");  // Imprime o ícone do navio
            } else {
                printf("0 ");  // Se for 0, significa água, então imprime o ícone de água
            }
        }
        printf("|\n");  // Fecha a linha
    }
    printf("  ------------------------\n");  // Finaliza a borda do tabuleiro

    return 0;  // Finaliza o programa
}
