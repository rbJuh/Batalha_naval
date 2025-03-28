#include <stdio.h> 

#define TAMANHO 10   // Define o tamanho do tabuleiro como uma matriz 10x10
#define TAM_NAVIO 3  // Define o tamanho dos navios como sendo de 3 posições

// Função para inicializar o tabuleiro preenchendo todas as posições com 0 (representando água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função que verifica se um navio pode ser posicionado sem sair dos limites ou sobrepor outro navio
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int novaLinha = linha + i * deltaLinha;
        int novaColuna = coluna + i * deltaColuna;
        
        // Verifica se o navio está dentro dos limites e se não sobrepõe outro navio
        if (novaLinha < 0 || novaLinha >= TAMANHO || novaColuna < 0 || novaColuna >= TAMANHO || tabuleiro[novaLinha][novaColuna] != 0) {
            return 0; // Retorna falso se não puder posicionar o navio
        }
    }
    return 1; // Retorna verdadeiro se for possível posicionar o navio
}

// Função que posiciona um navio no tabuleiro atribuindo o valor 3 às posições ocupadas
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i * deltaLinha][coluna + i * deltaColuna] = 3;
    }
}

// Função que exibe o tabuleiro no console, formatando a saída para melhor visualização
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n  BATALHA NAVAL - TABULEIRO\n");
    printf("  ------------------------\n");
    printf("    ");
    
    // Impressão dos índices das colunas (A a J)
    for (int j = 0; j < TAMANHO; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");
    
    // Impressão do tabuleiro linha por linha
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d | ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("  ------------------------\n");
}


int main() {
    int tabuleiro[TAMANHO][TAMANHO]; // Declaração da matriz que representa o tabuleiro
    inicializarTabuleiro(tabuleiro); // Inicializa o tabuleiro com valores 0
    
    // Matriz contendo as coordenadas iniciais e direções dos quatro navios
    int navios[4][4] = {
        {2, 4, 0, 1},  // Navio posicionado horizontalmente
        {5, 7, 1, 0},  // Navio posicionado verticalmente
        {1, 1, 1, 1},  // Navio posicionado na diagonal 1
        {3, 6, 1, -1}  // Navio posicionado na diagonal 2
    };
    
    // Loop para posicionar os navios no tabuleiro
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int deltaLinha = navios[i][2];
        int deltaColuna = navios[i][3];
        
        // Verifica se o navio pode ser posicionado antes de colocá-lo no tabuleiro
        if (podePosicionar(tabuleiro, linha, coluna, deltaLinha, deltaColuna)) {
            posicionarNavio(tabuleiro, linha, coluna, deltaLinha, deltaColuna);
        } else {
            printf("Erro ao posicionar navio %d!\n", i + 1);
        }
    }
    
    imprimirTabuleiro(tabuleiro); // Exibe o tabuleiro final com os navios 
    return 0; 
}
