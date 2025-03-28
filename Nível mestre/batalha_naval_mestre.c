#include <stdio.h>

#define TAMANHO_TABULEIRO 10  // Tabuleiro inicial 10x10
#define TAMANHO_HABILIDADE 7  // Tabuleiro da habilidade 7x7
#define NAVIO 3     // Representa um navio no tabuleiro
#define HABILIDADE_CONE 5 // Representa a área afetada pela habilidade Cone
#define HABILIDADE_CRUZ 6 // Representa a área afetada pela habilidade Cruz
#define HABILIDADE_OCTA 7 // Representa a área afetada pela habilidade Octaedro

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Definindo água (0)
        }
    }
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
        tabuleiro[linha][coluna] = NAVIO; // Posicionando o navio
    }
}

// Função para aplicar a habilidade Cone 
void aplicarCone(int tabuleiro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemX, int origemY) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = origemY - i; j <= origemY + i; j++) {
            if (j >= 0 && j < TAMANHO_HABILIDADE && i + origemX < TAMANHO_HABILIDADE) {
                tabuleiro[i + origemX][j] = HABILIDADE_CONE; // Marca a área afetada pelo Cone
            }
        }
    }
}

// Função para aplicar a habilidade Cruz 
void aplicarCruz(int tabuleiro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemX, int origemY) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        tabuleiro[origemX][i] = HABILIDADE_CRUZ; // Marca a linha da cruz
        tabuleiro[i][origemY] = HABILIDADE_CRUZ; // Marca a coluna da cruz
    }
}

// Função para aplicar a habilidade Octaedro 
void aplicarOctaedro(int tabuleiro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemX, int origemY) {
    // Laço para desenhar o formato de octaedro no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Condição para o formato de octaedro
            if ((i - origemX) + (j - origemY) <= 3) {
                tabuleiro[i][j] = HABILIDADE_OCTA; // Marca a área afetada pelo Octaedro
            }
        }
    }
}

// Função para imprimir o tabuleiro da habilidade 
void imprimirTabuleiroHabilidade(int tabuleiro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 "); // Água
            } else {
                printf("%d ", tabuleiro[i][j]); // Exibe o número da habilidade
            }
        }
        printf("\n");
    }
}

// Função para imprimir o tabuleiro inicial com a estrutura solicitada
void imprimirTabuleiroInicial(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf(" BATALHA NAVAL - TABULEIRO\n");
    printf("  ------------------------\n");
    printf("    A B C D E F G H I J \n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d | ", i);  // Exibe a linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 "); // Água
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("N "); // Navio
            }
        }
        printf("|\n");
    }
    printf("  ------------------------\n");
}

int main() {
    // Criando o tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);
    // Colocando os navios no tabuleiro
    posicionarNavio(tabuleiro, 1, 1); 
    posicionarNavio(tabuleiro, 2, 2); 
    posicionarNavio(tabuleiro, 2, 4); 
    posicionarNavio(tabuleiro, 3, 3); 
    posicionarNavio(tabuleiro, 4, 5); 
    posicionarNavio(tabuleiro, 5, 4); 
    posicionarNavio(tabuleiro, 5, 6); 
    posicionarNavio(tabuleiro, 6, 7); 
    posicionarNavio(tabuleiro, 7, 7);

    // Exibindo o tabuleiro inicial
    imprimirTabuleiroInicial(tabuleiro);
    
    // Exibindo o tabuleiro com Cone 
    int tabuleiroCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    aplicarCone(tabuleiroCone, 3, 3); 
    printf("\nTabuleiro cone:\n");
    imprimirTabuleiroHabilidade(tabuleiroCone); // Imprime a habilidade Cone
    
    // Exibindo o tabuleiro com Cruz (7x7)
    int tabuleiroCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    aplicarCruz(tabuleiroCruz, 3, 3); 
    printf("\nTabuleiro cruz:\n");
    imprimirTabuleiroHabilidade(tabuleiroCruz); // Imprime a habilidade Cruz
    
    // Exibindo o tabuleiro com Octaedro (7x7)
    int tabuleiroOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    aplicarOctaedro(tabuleiroOctaedro, 3, 3); 
    printf("\nTabuleiro octaedro:\n");
    imprimirTabuleiroHabilidade(tabuleiroOctaedro); // Imprime a habilidade Octaedro
    
    return 0;
}
