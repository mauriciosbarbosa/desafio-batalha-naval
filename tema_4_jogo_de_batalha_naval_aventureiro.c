#include <stdio.h>

int main() {

    //Inicializando e exibindo o tabuleiro vazio
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    printf("Exibindo tabuleiro vazio...\n");
    printf("    A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) {
        i < 9 ? printf("%d | ", i + 1) : printf("%d| ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("\n");

    // Inicializando navio de tamanho três
    int navio[3] = {3, 3, 3};

    // Inserindo o navio no tabuleiro na horizontal (posição 3B:3D)
    for (int i = 1, j = 0; i < 4 && j < 3; i++, j++) {
        tabuleiro[2][i] = navio[j];
    }

    // Inserindo o navio no tabuleiro na vertical (posição 5H:7H)
    for (int i = 4, j = 0; i < 7 && j < 3; i++, j++) {
        tabuleiro[i][7] = navio[j];
    }

    // Inserindo navios no tabuleiro na diagonal (posições 5A:7C e 5E:3G)
    for (int i = 4, j = 0, k = 0; k < 3; i++, j++, k++) {
        tabuleiro[i][j] = navio[k];
    }
    for (int i = 4, j = 4, k = 0; k < 3; i--, j++, k++) {
        tabuleiro[i][j] = navio[k];
    }

    // Exibindo tabuleiro com os navios
    printf("Exibindo tabuleiro com 4 (quatro) navios. Posições 3B:3D; 5H:7H; 5A:7C e 5E:3G :\n");
    printf("    A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) {
        i < 9 ? printf("%d | ", i + 1) : printf("%d| ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("\n");

    return 0;
}